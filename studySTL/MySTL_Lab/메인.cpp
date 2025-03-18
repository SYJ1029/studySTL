/*--------------------------------
// 2025학년도 1학기 STL 월910수910 
// 3월 13일 목요일
// 2주 1일
---------------------------------*/


/*-------------------------------------------------
// Generic Programming 핵심 키워드 - template 
--------------------------------------------------*/


#include <iostream>
#include "save.h"

//using namespace std;	// 여러분은 이렇게 하지 마세요

// [문제] main 변경 없이 의도대로 실행되게 코딩하라
// Dog는 클래스로

// 컴파일러의 동작

class Dog {
public:
	Dog() = default;
	Dog(int n) : num{ n } {}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog){
		return os << dog.num;
	}
private:
	int num;
};


// [질문] 도대체 몇 개의 change를 만들면 되겠니?
// -> c++ 언어의 자료형 개수는 몇개? -> 무한대
// -> 코드 생성을 자동화하자


// 템플릿은 선언과 정의를 동시에 해야만 한다
template <class T>
void change(T& num1, T& num2) {
	T temp{ num1 };
	num1 = num2;
	num2 = temp;

}
// 자료형에 관계 없이 그게 무엇이든지 간에 
// 절차에 따라(알고리즘) 같은 기능을 보장하는 것  
// Generic Programming


std::tuple<std::string, int> example_List(int id) 
{
	switch (id) {
	case 0: return { "송영준", 2021184018 };
	case 1: return { "영준송", 4018202118 };
	case 2: return { "SongYoungJun", 888484 };
	}

	throw std::invalid_argument("id");
}

//----------
int main()
//----------
{
	{
		Dog a{ 1 }, b{ 2 }; // 표준 표기법
		change(a, b); // 뭘 호출하는거임
		// 1. change(Dog, Dog);
		// 2. change(Dog&, Dog&);
		// 3. 컴파일러인 내가 만들 순 없나? -> template!
		std::cout << a << ", " << b << std::endl;	// [출력] 2, 1
	}

	{
		int a{ 1 }, b{ 2 }; // 표준 표기법
		change(a, b);
		std::cout << a << ", " << b << std::endl;	// [출력] 2, 1
	}

	auto idiot0 = example_List(0);

	std::cout << std::get<std::string>(idiot0) << std::endl;
	std::cout << std::get<1>(idiot0) << std::endl;

	auto idiot2 = example_List(2);

	std::cout << std::get<std::string>(idiot2) << std::endl;
	std::cout << std::get<1>(idiot2) << std::endl;

	//save("메인.cpp");
}

