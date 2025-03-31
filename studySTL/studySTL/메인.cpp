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
#include <array>
#include <algorithm>
#include <random>
#include <print>
#include <ranges>
#include "save.h"

//[문제] 값의 범위가 [0, 1'000'0000)인 랜덤 int값 1000만개를 저장할 
// 메모리를 확보하고 값을 채워라
// (시작) qsort로 오름차순 정렬하라
// 정렬한 결과 중에서 앞에서 부터 1000개만 화면에 출력해라


std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 999'9999 };

std::array<int, 1'000'0000> arr;

//----------------
int main()
//----------------
{
	for (int& num : arr)
		num = uid(dre);
	// qsort로 정렬

	//std::qsort((void*)arr.data(), arr.size(), sizeof(int), {});

	int num = 0;
	for (int num : arr | std::views::take(1000))
		std::print("{:8}", arr[num]);
	//save("메인.cpp");
}
