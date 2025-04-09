/*--------------------------------
// 2025학년도 1학기 STL 월910수910				(5주 1일)
// 3월 17일 월요일
// 중간고사		- 8주 1일(4월 24일 목요일)
// 과제설명(30)	- 6주 1일(4월 10일 목요일)
---------------------------------*/


/*-------------------------------------------------
// class STRING 작성시작 - std::string과 유사한 동작을 한다
--------------------------------------------------*/

#include <iostream>
#include <string>
#include <memory>
#include <array>
#include "save.h"

class STRING {
public:
	STRING() {};

	STRING(const char* str) : num{ strlen(str) } {
		p.release();	// 자원이 있다면 해제하지만 생성 시에 이렇게 할 필요는 없다
		p = std::make_unique<char[]>(num);		// new - delete 짝을 없애기 위해
		std::memcpy(p.get(), str, num);				// DMA가 가능하다(Direct Memory Acces) -> cpu의 개입 없이 이송 가능한 명령어
	}

	STRING(const STRING& str) {
		p.release();
		num = str.num;
		p = std::make_unique<char[]>(num);
		std::memcpy(p.get(), str.p.get(), num);
	}
	size_t size() const {
		return num;
	}

	bool operator=(const STRING& str) {
		p.release();		// 새로운 string을 만들어야 하는 p는 자원을 해제해야 한다고 생각
		num = str.num;
		p = std::make_unique<char[]>(num);
		std::memcpy(p.get(), str.p.get(), num);

		return true;
	}

private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	friend std::ostream& operator<<(std::ostream& os, const STRING& s) {

		for (int i = 0; i < s.num; ++i) {
			os << s.p[i];
		}

		return os;
	}

};

//----------------
int main()
//----------------
{
	STRING s{ "std::string과 유사한 클래스" };
	STRING s2{ "std::string과 유사한 클래스2" };

	std::cout << "s 가 관리하는 자원의 바이트 수 - " << s.size() << std::endl;

	STRING t{ s2 };
	std::cout << t << std::endl;

	t = s;

	std::cout << s << std::endl;
	std::cout << t << std::endl;
	//std::cout << t << std::endl;
	//save("메인.cpp");
}
