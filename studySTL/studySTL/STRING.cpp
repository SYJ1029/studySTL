//-------------------------------------------------------------------------
// STRING.cpp - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작섣
// 
// 2025. 4 . 10 - 시작
// 2025. 4 . 10 - 복사생성/복사할당연산자, 스페셜 함수의 동작 관찰
// 2025. 4 . 14 - 선택적 관찰하도록 전역변수를 사용
// 2025. 4 . 14 - 이동의미론(move semantics) 구현 
// 2025. 5 . 1	- operator==
// 2025. 5 . 15	- std::string처럼 사전식 정렬하도록 수정
// 2025. 5 . 15	- begin(), end()
// 2025. 5 . 19 - rbegin(), rend()
//-------------------------------------------------------------------------

#include <memory>	// 상관 없음 중복 실행 안함
#include <print>
#include <algorithm>
#include "STRING.h"

size_t STRING::gid{ 0 };				// 2025. 4. 10 고유번호 생성

bool 관찰{ false };

STRING::STRING()
	: id{ ++gid }
{
	//std::println("[{:6}]", id);
	if (관찰) {
		std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, "디폴트 생성", num, (void*)this, (void*)p.get());
	}

	// 형식을 가진 포인터는 특정 자료형에 종속되므로 고수준 가공이 불가능하다
}

STRING::~STRING()
{
	if (관찰) {
		std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, "소멸자", num, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* str)
	: num{ strlen(str) }, id{ ++gid }
{
	p.release();	// 자원이 있다면 해제하지만 생성 시에 이렇게 할 필요는 없다
	p = std::make_unique<char[]>(num);		// new - delete 짝을 없애기 위해
	std::memcpy(p.get(), str, num);				// DMA가 가능하다(Direct Memory Acces) -> cpu의 개입 없이 이송 가능한 명령어

	if (관찰) {
		std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, "생성자(char*)", num, (void*)this, (void*)p.get());
	}
};

// 복사생성자와 복사할당연산자
STRING::STRING(const STRING& other)
	: num{ other.num }, id{ ++gid }
{
	//*this = other;			// 복사 생성은 할당을 이용하라

	num = other.num;
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (관찰) {
		std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, "복사 생성자(char*)", num, (void*)this, (void*)p.get());
	}

}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	p.release();		// 포인터를 반환해서 이용할 수 있음
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (관찰) {
		std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, " copy opertator=", num, (void*)this, (void*)p.get());
	}
	return *this;
}


STRING::STRING(STRING&& other)
	: num{ other.num }, id{ ++gid }
{
	p.reset(other.p.release());

	other.num = 0;		// 안 해도 된다
	// sort는 대상을 명시적으로 쓰지 않기 때문에 필요가 없다

	if (관찰) {
		std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, "이동 생성자", num, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	p.release();			//내가 확보한 자원을 해제
	p.reset(other.p.release());

	other.num = 0;		// 안 해도 된다
	if (관찰) {
		std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
			id, "mover operator=", num, (void*)this, (void*)p.get());
	}
	return *this;
}



size_t STRING::size() const
{
	return num;
}

STRING_Iterator STRING::begin() const
{
	return STRING_Iterator(&p[0]);			// return p.get();
}

STRING_Iterator STRING::end() const
{
	return STRING_Iterator(&p[num]);
}

STRING_Reverse_Iterator STRING::rbegin() const
{
	return STRING_Reverse_Iterator(&p[num]);
}
STRING_Reverse_Iterator STRING::rend() const
{

	return STRING_Reverse_Iterator(&p[0]);
}


std::ostream& operator<<(std::ostream& os, const STRING& s)
{

	for (int i = 0; i < s.num; ++i) {
		os << s.p[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, STRING& s)
{
	std::string str;
	is >> str;

	s.num = str.size();
	s.p.release();
	s.p = std::make_unique<char[]>(s.num);
	memcpy(s.p.get(), str.data(), s.num);

	return is;
}

// 기본정렬을 위한 <		2025. 4. 14
// 사전식으로 정렬			2025. 5 .15
bool STRING::operator<(const STRING& rhs) const
{
	return std::lexicographical_compare(p.get(), p.get() + num, rhs.p.get(), rhs.p.get() + rhs.num);
}



// 같은 객체인지 비교 ==		2025. 5. 1
bool STRING::operator==(const STRING& rhs) const
{
	return std::equal(p.get(), p.get() + num, &rhs.p[0], &rhs.p[num]);
}

