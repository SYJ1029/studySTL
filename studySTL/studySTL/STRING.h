//-------------------------------------------------------------------------
// STRING.h - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작섣
// 
// 2025. 4 . 10 - 시작
// 2025. 4 . 14 - 이동의미론(move semantics) 구현 
// 2025. 5 . 1	- operator==
// 2025. 5. 15	- begin(), end() 제공
// 2025. 5 . 19 - rbegin(), rend() 제공	-> class 여야 함
// 2025. 5 . 22	- 반복자가 대답할 질문에 답하도록 한다.
// 2025. 5 . 22	- begin(), end()가 반복자를 리턴하도록 한다.
// 2025. 5 . 26	- sort가 가능하도록 필요한 연산자를 모두 코딩
//				(C++의 연산자 오버로딩을 모두 이해해야만 가능하다)
//-------------------------------------------------------------------------
#pragma once

#include <memory>
#include <iostream>

// iterator adaptor - 반복자의 인터페이스 제공 but 실제로는 다르게
// 표준 반복자가 제공해야할 다섯가지 타입을 제공한다.


class STRING_Iterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	STRING_Iterator() = default;
	STRING_Iterator(char* p) : p{ p } {};
	// 반복자라면 제공해야할 기본동작이 있다

	// 2025. 5. 26 ++연산자 구현
	STRING_Iterator& operator++() {
		++p;
		return *this;
	}

	//2025. 5. 26
	//이 연산의 결과는 l-value가 아님 -> &를 리턴하고 const를 제거
	char& operator*() {
		return *p;
	}

	// cv-qualifier는 오버로딩으로 구분가능하다
	char& operator*() const {
		return *p;
	}

	//<=> 작성 후 주석처리
	// 뭔가 안되서 다시 살림
	//bool operator==(const STRING_Iterator& rhs) const {
	//	return p == rhs.p;
	//}

	//sort가 동작하도록 필요 연산자 추가
	// 2025. 5. 26
	difference_type operator-(const STRING_Iterator& rhs) const {
		return (p - rhs.p);
	}

	STRING_Iterator operator-(difference_type n) const {
		return p - n;
	}

	STRING_Iterator& operator--() {
		--p;
		return *this;
	}


	//reference operator=(const STRING_Iterator& rhs) {
	//	p = rhs.p;
	//	return *p;
	//}


	//모든 relational operation을 할 수 있게 <=>을 정의
	// <, <=, ==, !=, >=, >

	//auto operator<=>(const STRING_Iterator& rhs) const {
	//	return p <=> rhs.p;
	//}

	auto operator<=>(const STRING_Iterator& rhs) const = default;

	STRING_Iterator operator+(difference_type n) const {
		return p + n;
	}


private:
	char* p{};
};



class STRING_Reverse_Iterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	explicit STRING_Reverse_Iterator(char* p) : p{ p } {};
	// 반복자라면 제공해야할 기본동작이 있다
	void operator++() {
		--p;
	}

	char operator*() const {
		return *(p - 1);
	}

	bool operator==(const STRING_Reverse_Iterator& rhs) const {
		return p == rhs.p;
	}

private:
	char* p;
};



class STRING {
public:
	STRING();			// 진짜 special 함수
	~STRING();				// 이걸 코딩할 이유가 1도 없다. 그냥 그 과정을 따라가고 싶으니 생성한 것


	STRING(const char* str);	// 그냥 생성자임

	// 복사생성자와 복사할당연산자 2025. 4. 10
	STRING(const STRING&);
	STRING& operator=(const STRING&);

	// 이동생성자와 이동할당연산자 2025. 4. 14
	STRING(STRING&&);
	STRING& operator= (STRING&&);


	// 기본정렬을 위한 <		2025. 4. 14
	// 사전식 정렬을 위한 수정 - 2025. 5 .15
	bool operator<(const STRING&) const;
	// 같은 객체인지 비교 ==		2025. 5. 1
	bool operator==(const STRING&) const;

	void write(std::ostream& os);
	bool read(std::istream& is);


	size_t size() const;

	//2025. 5. 15
	STRING_Iterator begin() const;
	STRING_Iterator end() const;

	STRING_Reverse_Iterator rbegin() const;
	STRING_Reverse_Iterator rend() const;
	
private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;						// 2025. 4. 10 관찰을 위한 객체 고유번호

	friend std::ostream& operator<<(std::ostream& os, const STRING&);
	friend std::istream& operator>>(std::istream& is, STRING&);
	
	static size_t gid;				// 2025. 4. 10 고유번호 생성
};