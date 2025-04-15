/*--------------------------------
// 2025학년도 1학기 STL 월910수910				(5주 1일)
// 4월 10일 목요일
// 중간고사		- 8주 1일(4월 24일 목요일)
---------------------------------*/


/*-------------------------------------------------
// class STRING 작성시작 - STL의 표준 컨테이너가 되도록 발전시킨다
//						   벡터의 동작을 진짜 자세히 이해하려고...

// "표준 컨테이너"가 되고싶다면 어떻게 해야하는가
--------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "save.h"
#include "STRING.h"

// 다음시간 관찰메시지 해석에서 
STRING x{ "수업시간이 너무 짧아" };

extern bool 관찰;				// 관찰하려면 true로


//[문제] "메인.cpp"에 있는 있는 단어를 처음부터 50개를 메모리(STRING)에 저장하자.
// 전체 단어를 길이 오름차순으로 정렬하자
// 결과를 화면출력하라
// 제일 첫 단어를 답지에 적어라

std::array<STRING, 50> words;

//----------------
int main()
//----------------
{
	std::ifstream in("메인.cpp");
	if (not in)
		return 15578884;

	STRING s;

	for (STRING& word : words) {
		in >> word;
	}



	std::sort(words.begin(), words.end());		// 17이후의 기본 연산자는 less<STRING> {}()


	// 다음 시간에 STL 이란 무엇인가?
	for (auto i = words.rbegin(); i != words.rend(); ++i) {
		std::cout << *i << std::endl;
	}

	save("메인.cpp");
}
