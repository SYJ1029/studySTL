//-----------------------------------------------------------------------------
// 2025. 1. STL 월910목910	5월 12일 월요일
// 졸업작품 중간발표로 6:40 시작
// 6/19 목요일 15주 2일 - 기말 시험
// 5/12 월요일  - 졸업작품 중간 발표 이후에 시험친다
//-----------------------------------------------------------------------------
// 반복자 - 각 컨테이너가 자기가 관리하는 원소를 처음부터 끝까지 빠짐없이
// 순회할 수 있도록 제공하는 인터페이스이다
// 컨테이너에 따라서(자료구조는 서로 다르니까) 반복자로 할 수 있는 일은 다름
//-----------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;
extern bool 관찰;


// 반복자는 서로 다르다 - 6개의 categoty

// [문제] 반복자를 인자로 받아 어떤 종류의 반복자인지 화면에 출력하는 
// 함수 f를 정의하라


template <class 반복자>

void f(const 반복자& p)
{

	cout << typeid(반복자::iterator_category).name() << endl;

}



//---------
int main()
//---------
{
	STRING s{"the quick brown fox jumps over the lazy dog"};
	string ss{ "the quick brown fox jumps over the lazy dog" };


	sort(s.begin(), s.end());

	cout << ss << endl;

	//save("메인.cpp");
}
 