/*--------------------------------
// 2025학년도 1학기 STL 월910수910				(5주 1일)
// 3월 17일 월요일
// 중간고사		- 8주 1일(4월 24일 목요일)
// 과제설명(30)	- 6주 1일(4월 10일 목요일)
---------------------------------*/


/*-------------------------------------------------
// Callabe types - 호출가능한 타입 ==> 모든 호출가능타입을 대표하는 function
--------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <ranges>
#include <algorithm>
#include <functional>
#include "save.h"


// [상황] e-class에서 다운받은 파일 "Dog 십만마리"에는 
// 정확하게 Dog 객체 10'0000마리가 저장되어 있다
// 파일은
//			ofstream out("Dog 10만마리");
// Dog 타입의 객체 dog는
//			out << dog;
// 코드로 저장하였다

class Dog {
private:
	size_t num;					// 랜덤 int 값
	std::string name;			// [3, 60) 까지의 랜덤 소문자로만 구성

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.num << " " << dog.name << " ";
	}

	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		return is >> dog.num >> dog.name;
	}

	friend bool operator<(const Dog& dog1, const Dog& dog2) {
		return dog1.name.size() < dog2.name.size();
	}

	friend bool operator>(const Dog& dog1, const Dog& dog2) {
		return dog1.name.size() > dog2.name.size();
	}

};

// [문제] 파일에 저장된 10만마리의 Dog객체를 모두 읽어 메모리에 저장하라
// 마지막 객체의 정보를 화면에 출력하고 출력된 내용을 답지에도 적어라
// 메모리에 있는 Dog객체를 name 길이 기준 오름차순으로 정렬하라
// 정렬한 마지막 객체의 정보를 화면에 출력하고 답지에도 적어라

std::array<Dog, 10'0000> arr;


//----------------
int main()
//----------------
{

	std::ifstream in("Dog 십만마리");

	if (not in) {
		std::cout << "can't open :(" << std::endl;
		exit(15578884);
	}


	for (Dog& dog : arr) {
		in >> dog;
	}

	std::function<bool(const Dog, const Dog)> f = [](const Dog dog1, const Dog dog2) {
		return dog1 < dog2;
		};

	auto lamda = [](const Dog dog1, const Dog dog2) {
		return dog1 > dog2;
		};

	std::cout << arr.back() << std::endl;

	std::sort(arr.begin(), arr.end(), lamda);

	std::cout << arr.back() << std::endl;


	//save("메인.cpp");
}
