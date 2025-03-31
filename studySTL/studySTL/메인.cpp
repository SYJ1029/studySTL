/*--------------------------------
// 2025학년도 1학기 STL 월910수910 
// 3월 17일 월요일
// 4주 1일
---------------------------------*/


/*-------------------------------------------------
// Callabe types - 호출가능한 타입
// 1. 함수
--------------------------------------------------*/


#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"

//[문제] "메인.cpp" 파일의 소문자를 대문자로 변환하여 "메인 대문자.cpp"에 저장하라


//----------------
int main()
//----------------
{
	std::ifstream in{ "메인.cpp" };
	if (not in)
		return 15578884;

	std::ofstream out{ "메인 대문자.cpp" };

	// transform은 타입에 무관한 제네릭 함수!
	std::transform(std::istreambuf_iterator<char>{in}, {}, 
		std::ostreambuf_iterator<char>{out}, 
		여기에 얼마나 들어갈 수 있을까);	// 여기도 제네릭
	
	//save("메인.cpp");
}
