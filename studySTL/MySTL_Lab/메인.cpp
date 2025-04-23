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
#include <string>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "STRING.h"


extern bool 관찰;				// 관찰하려면 true로

//[문제] 키보드에서 단어를 모두 입력받아 오름차순으로 정렬한 후 출력하라.

//----------------
int main()
//----------------
{
	std::ifstream in("메인.cpp");
	std::vector<std::string> v{ std::istream_iterator<std::string>{std::cin}, {} };

	std::sort(v.begin(), v.end());

	for (const std::string& s : v) {
		std::cout << s << std::endl;
	}

	//save("메인.cpp");
}
