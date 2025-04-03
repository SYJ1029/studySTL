/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910 
// 3�� 17�� ������
// 4�� 1��
---------------------------------*/


/*-------------------------------------------------
// Callabe types - ȣ�Ⱑ���� Ÿ��
// 1. �Լ�
--------------------------------------------------*/


#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <print>
#include <ranges>
#include "save.h"

//[����] ���� ������ [0, 1'000'0000)�� ���� int�� 1000������ ������ 
// �޸𸮸� Ȯ���ϰ� ���� ä����
// (����) qsort�� �������� �����϶�
// ������ ��� �߿��� �տ��� ���� 1000���� ȭ�鿡 ����ض�


std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 999'9999 };

std::array<int, 1'000'0000> arr;

//----------------
int main()
//----------------
{
	for (int& num : arr)
		num = uid(dre);
	// qsort�� ����

	//std::qsort((void*)arr.data(), arr.size(), sizeof(int), {});

	int num = 0;
	for (int num : arr | std::views::take(1000))
		std::print("{:8}", arr[num]);
	//save("����.cpp");
}
