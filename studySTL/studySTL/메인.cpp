//-----------------------------------------------------------------------------
// 2025. 1. STL 월910목910	5월 12일 월요일
// 졸업작품 중간발표로 6:40 시작
// 6/19 목요일 15주 2일 - 기말 시험
// 5/12 월요일  - 졸업작품 중간 발표 이후에 시험친다
//-----------------------------------------------------------------------------
// STL Container
// array<T, N> - 유일하게 크기 고정
// vector<T> - random access, []연산자 제공, O(1)에 모든 원소에 access, O(1) push_back()
// deque<T> - random access, [] 연산자 제공, O(1)에 모든 원소에 access, O(1) push_front(), push_back()
// list<T> - O(1) insert, delete, 자료구조를 활용한 전용함수를 제공(remove, sort, splice)
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "STRING.h"
#include "save.h"
using namespace std;
extern bool 관찰;


class Test {
	char x[1'000'000];
};


//---------
int main()
//---------
{
	//[문제] "메인.cpp"의 단어를 list에 모두 저장하라
	ifstream in("메인.cpp");
	if (not in)
		return 2021184018;

	list<STRING> 단어들{ istream_iterator<STRING>(in), {} };

	//[문제] 단어 중에서 길이가 5인 것들만 화면에 출ㄹ력

	copy(단어들.begin(), 단어들.end(), ostream_iterator<STRING>(cout, " * "));

	// 다음시간에 다시 코딩하고 반복자 소개에서 시작

	save("메인.cpp");
}
 