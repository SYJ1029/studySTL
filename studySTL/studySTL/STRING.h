//-------------------------------------------------------------------------
// STRING.h - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작섣
// 
// 2025. 4 . 10 - 시작
// 2025. 4 . 14 - 이동의미론(move semantics) 구현 
// 2025. 5 . 1	- operator==
// 2025. 5. 15	- begin(), end() 제공
//-------------------------------------------------------------------------
#pragma once

#include <memory>
#include <iostream>

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


	size_t size() const;

	//2025. 5. 15
	char* begin() const;
	char* end() const;
	
private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;						// 2025. 4. 10 관찰을 위한 객체 고유번호

	friend std::ostream& operator<<(std::ostream& os, const STRING&);
	friend std::istream& operator>>(std::istream& is, STRING&);
	
	static size_t gid;				// 2025. 4. 10 고유번호 생성
};