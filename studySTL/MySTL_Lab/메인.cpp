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
#include <random>
#include <print>
#include <ranges>
#include <algorithm>
#include <chrono>
#include "save.h"

//[����] ���� ������ [0, 1'000'0000)�� ���� int�� 1000������ ������ 
// �޸𸮸� Ȯ���ϰ� ���� ä����
// (����) qsort�� �������� �����϶�
// ������ ��� �߿��� �տ��� ���� 1000���� ȭ�鿡 ����ض�


std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 999'9999 };

std::array<int, 1'000'0000> arr;
std::array<int, 1'000'0000> arrq;


bool ��������(int a, int b)
{
	return a > b; // greater �������� ��� ��������
}

bool ��������(int a, int b)
{
	return a < b;	// less �������� ��� ��������
}

int ��������q(const void* a, const void* b)
{

	return *(int*)a - *(int*)b;
}

int ��������q(const void* a, const void* b)
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
	// stl�� sort�� �������� ����

	int(*���ı���)(const void*, const void*) = ��������q;


	//�����ġ ����
	auto b = std::chrono::high_resolution_clock::now();
	std::sort(arrq.begin(), arrq.end(), ��������);		// �� ���������� -> ����Ʈ�� ���������̴�
	auto e = std::chrono::high_resolution_clock::now();

	// �����ġ ��

	std::cout << "sort ���Ŀ� �ɸ� �ð�" << e - b << std::endl << std::endl;	// ����ð�


	//2�� �����ġ ����
	auto b2 = std::chrono::high_resolution_clock::now();
	std::qsort(arr.data(), arr.size(), sizeof(int), ���ı���);
	auto e2 = std::chrono::high_resolution_clock::now();
	//2�� �����ġ ����

	std::cout << "qsort ���Ŀ� �ɸ� �ð�" << e2 - b2 << std::endl << std::endl;	// ����ð�


	int num = 0;
	for (int num : arr | std::views::take(1000))		// Ȯ�������� uniform �ϴ�(������ ���� ���� ���� ��)
		std::print("{:8}", arr[num]);
	std::cout << std::endl;
	//save("����.cpp");
}
