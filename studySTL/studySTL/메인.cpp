//-----------------------------------------------------------------------------
// 2025. 1. STL 월910목910	4월 28일 월
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
	vector<STRING> v{ 단어들.begin(), 단어들.end()};

	//[문제] 사용자가 입력한 단어가 리스트에 있는 지 알려주자
	// 단어가 없으면 없다고 출력하고 있으면 리스트의 몇 번쨰 단어인지 출력하라.

	while (true) {
		cout << "찾을 단어는? ";
		STRING 단어;
		cin >> 단어;

		auto result = find(단어들.begin(), 단어들.end(), 단어);
		
		if (result != 단어들.end()) {
			cout << "없음!" << endl;
		}
		else {
			cout << *result << endl;
		}
	}


	save("메인.cpp");
}
 