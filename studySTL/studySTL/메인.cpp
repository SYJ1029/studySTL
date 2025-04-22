/*--------------------------------
// 2025학년도 1학기 STL 월910수910				(7주 2일)
// 4월 10일 목요일
// 중간고사		- 8주 1일(4월 24일 목요일)
---------------------------------*/


/*----------------------------------------------------------------
// STL Container - Containers are objects that store other objects
// array - 
// vector - at 예제는 하고 가자
------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"


extern bool 관찰;				// 관찰하려면 true로

//[문제] 키보드에서 단어를 모두 입력받아 오름차순으로 정렬한 후 출력하라.

//----------------
int main()
//----------------
{
	관찰 = true;

	std::vector<STRING> v;

	v.emplace_back("12345");	// stack 영역에서 만들어지는 뭔가가 있어서는 안됨

	save("메인.cpp");
}
