//-----------------------------------------------------------------------------
// 2025. 1. STL 월910목910	5월 12일 월요일
// 졸업작품 중간발표로 6:40 시작
// 6/19 목요일 15주 2일 - 기말 시험
// 5/12 월요일  - 졸업작품 중간 발표 이후에 시험친다
//-----------------------------------------------------------------------------
// 반복자와 알고리즘 함수
// find()
// find_if()
// copy()
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;
extern bool 관찰;

template<class 반복자, class 찾을값>
반복자 my_find(반복자 b, 반복자 e, 찾을값 v)
{
	for (; b != e; ++b) {
		if (*b == v)
			return b;
	}

	return e;
}

template<class 반복자, class 호출가능타입>
반복자 my_find_if(반복자 b, 반복자 e, 호출가능타입 callable) {
	while (b != e) {
		if (callable(*b) == true)
			return b;

		++b;
	}

	return e;
}



//---------
int main()
//---------
{
	STRING s{ "2025. 5. 26" };

	vector<char> v;

	// [문제] s가 관리하는 문자들을 v에 복사하라
	copy(s.begin(), s.end(), v.begin());

	//save("메인.cpp");
}
 