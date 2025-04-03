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
#include <random>
#include <print>
#include <ranges>
#include <algorithm>
#include <chrono>
#include "save.h"

//[문제] 값의 범위가 [0, 1'000'0000)인 랜덤 int값 1000만개를 저장할 
// 메모리를 확보하고 값을 채워라
// (시작) qsort로 오름차순 정렬하라
// 정렬한 결과 중에서 앞에서 부터 1000개만 화면에 출력해라


std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 999'9999 };

std::array<int, 1'000'0000> arr;
std::array<int, 1'000'0000> arrq;


bool 내림차순(int a, int b)
{
	return a > b; // greater 연산자일 경우 내림차순
}

bool 오름차순(int a, int b)
{
	return a < b;	// less 연산자일 경우 오름차순
}

int 오름차순q(const void* a, const void* b)
{

	return *(int*)a - *(int*)b;
}

int 내림차순q(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

//----------------
int main()
//----------------
{
	for (int& num : arr)
		num = uid(dre);
	for (int& numq : arrq)
		numq = uid(dre);
	// stl의 sort로 내림차순 정렬

	int(*정렬기준)(const void*, const void*) = 오름차순q;


	//스톱워치 시작
	auto b = std::chrono::high_resolution_clock::now();
	std::sort(arrq.begin(), arrq.end(), 내림차순);		// 더 간단해졌다 -> 디폴트가 오름차순이다
	auto e = std::chrono::high_resolution_clock::now();

	// 스톱워치 끝

	std::cout << "sort 정렬에 걸린 시간" << e - b << std::endl << std::endl;	// 경과시간


	//2차 스톱워치 시작
	auto b2 = std::chrono::high_resolution_clock::now();
	std::qsort(arr.data(), arr.size(), sizeof(int), 정렬기준);
	auto e2 = std::chrono::high_resolution_clock::now();
	//2차 스톱워치 종료

	std::cout << "qsort 정렬에 걸린 시간" << e2 - b2 << std::endl << std::endl;	// 경과시간


	int num = 0;
	for (int num : arr | std::views::take(1000))		// 확률적으로 uniform 하다(범위에 대해 골고루 퍼진 값)
		std::print("{:8}", arr[num]);
	std::cout << std::endl;
	//save("메인.cpp");
}
