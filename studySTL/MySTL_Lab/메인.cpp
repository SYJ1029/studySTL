/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910				(5�� 1��)
// 3�� 17�� ������
// �߰����		- 8�� 1��(4�� 24�� �����)
// ��������(30)	- 6�� 1��(4�� 10�� �����)
---------------------------------*/


/*-------------------------------------------------
// Callabe types - ȣ�Ⱑ���� Ÿ�� ==> ��� ȣ�Ⱑ��Ÿ���� ��ǥ�ϴ� function
--------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <ranges>
#include <algorithm>
#include <functional>
#include <chrono>
#include "save.h"
#include "MakeExample.h"


// [��Ȳ] e-class���� �ٿ���� ���� "Dog �ʸ�����"���� 
// ��Ȯ�ϰ� Dog ��ü 10'0000������ ����Ǿ� �ִ�
// ������
//			ofstream out("Dog 10������");
// Dog Ÿ���� ��ü dog��
//			out << dog;
// �ڵ�� �����Ͽ���

class Dog {
private:
	size_t num;					// ���� int ��
	std::string name;			// [3, 60) ������ ���� �ҹ��ڷθ� ����

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.num << " " << dog.name << " ";
	}

	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		return is >> dog.num >> dog.name;
	}

	friend bool operator<(const Dog& dog1, const Dog& dog2) {
		return dog1.name.size() < dog2.name.size();
	}

	friend bool operator>(const Dog& dog1, const Dog& dog2) {
		return dog1.name.size() > dog2.name.size();
	}

};

// [����] ���Ͽ� ����� 10�������� Dog��ü�� ��� �о� �޸𸮿� �����϶�
// ������ ��ü�� ������ ȭ�鿡 ����ϰ� ��µ� ������ �������� �����
// �޸𸮿� �ִ� Dog��ü�� name ���� ���� ������������ �����϶�
// ������ ������ ��ü�� ������ ȭ�鿡 ����ϰ� �������� �����

std::array<Dog, 10'0000> arr;
std::array<Dog, 10'0000> arr2;

//----------------
int main()
//----------------
{
	MakeQuestion("Dog �ʸ�����");


	std::ifstream in("Dog �ʸ�����");

	if (not in) {
		std::cout << "can't open :(" << std::endl;
		exit(15578884);
	}


	for (Dog& dog : arr) {
		in >> dog;
	}

	in.seekg(0, std::ios::beg);

	for (Dog& dog : arr2) {
		in >> dog;
	}

	std::function<bool(const Dog, const Dog)> f{ 
		[](const Dog dog1, const Dog dog2) {
		return dog1 < dog2;
		} 
	};

	auto lamda{ 
		[](const Dog dog1, const Dog dog2) {
		return dog1 > dog2;
		} 
	};

	std::cout << arr.back() << std::endl;

	auto b = std::chrono::high_resolution_clock().now();
	std::sort(arr.begin(), arr.end(), f);
	auto e = std::chrono::high_resolution_clock().now();

	std::cout << "fuction �ҿ� �ð� - " << e - b << std::endl;

	b = std::chrono::high_resolution_clock().now();
	std::sort(arr2.begin(), arr2.end(), lamda);
	e = std::chrono::high_resolution_clock().now();

	std::cout << "lambda �ҿ� �ð� - " << e - b << std::endl;

	{
		using namespace std;
		cout << "function ���� ��� - " << arr.back() << endl;
		cout << "lamda ���� ��� - " << arr2.back() << endl;
	}


	//save("����.cpp");
}
