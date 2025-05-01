//-----------------------------------------------------------------------------
// 2025. 1. STL 월910목910	4월 28일 월
// 2025. 5. 5 -> 추후 보강(6 / 19 종강)
//-----------------------------------------------------------------------------
// STL Container
// array<T, N> - 유일하게 크기 고정
// vector<T> - random access, []연산자 제공, O(1)에 모든 원소에 access, O(1) push_back()
// deque<T> - random access, [] 연산자 제공, O(1)에 모든 원소에 access, O(1) push_front(), push_back()
// list<T> - O(1) insert, delete, 자료구조를 활용한 전용함수를 제공(remove, sort, splice)
//-----------------------------------------------------------------------------

#include <iostream>
#include <list>
#include "STRING.h"
#include "save.h"
using namespace std;
extern bool 관찰;


//---------
int main()
//---------
{
	list<STRING> v{ "1", "22", "333", "4444", "55555"};

	//[문제] v에서 "333"을 제거하라!
	//vector<int>::iterator newEnd = remove(v.begin(), v.end(), 3);
	관찰 = true;
	STRING t{ "333" };
	//erase(v, "333");		// 실행은 되지만 빵점!
	v.remove(t);
	관찰 = false;

	for (const STRING& s : v){
		cout << s << " ";
	}
	cout << endl;

	save("메인.cpp");
}
 