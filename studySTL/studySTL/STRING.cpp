//-------------------------------------------------------------------------
// STRING.cpp - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작섣
// 
// 2025. 4 . 10 - 시작
// 2025. 4 . 10 - 복사생성/복사할당연산자, 스페셜 함수의 동작 관찰
//-------------------------------------------------------------------------

#include <memory>	// 상관 없음 중복 실행 안함
#include <print>
#include "STRING.h"

size_t STRING::gid{ 0 };				// 2025. 4. 10 고유번호 생성

STRING::STRING()
	: id{ ++gid }
{
	//std::println("[{:6}]", id);
	std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}", 
		id, "디폴트 생성자(char*)", num, (void*)this, (void*)p.get());

	// 형식을 가진 포인터는 특정 자료형에 종속되므로 고수준 가공이 불가능하다
}

STRING::~STRING() 
{
	std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, "소멸자", num, (void*)this, (void*)p.get());
}

STRING::STRING(const char* str)
	: num{ strlen(str) }, id{ ++gid }
{
	p.release();	// 자원이 있다면 해제하지만 생성 시에 이렇게 할 필요는 없다
	p = std::make_unique<char[]>(num);		// new - delete 짝을 없애기 위해
	std::memcpy(p.get(), str, num);				// DMA가 가능하다(Direct Memory Acces) -> cpu의 개입 없이 이송 가능한 명령어

	std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, "생성자(char*)", num, (void*)this, (void*)p.get());
};

// 복사생성자와 복사할당연산자
STRING::STRING(const STRING& other)
	: num{ other.num }
{
	//*this = other;			// 복사 생성은 할당을 이용하라

	num = other.num;
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, "복사 생성자(char*)", num, (void*)this, (void*)p.get());

}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	p.release();		// 포인터를 반환해서 이용할 수 있음
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);


	std::println("[{:6}] {:<16} 자원수: {:4}, 주소: {:16} 자원의 주소: {:16}",
		id, " copy opertator=", num, (void*)this, (void*)p.get());
	return *this;
}


size_t STRING::size() const
{
	return num;
}

std::ostream& operator<<(std::ostream& os, const STRING& s)
{

	for (int i = 0; i < s.num; ++i) {
		os << s.p[i];
	}

	return os;
}
