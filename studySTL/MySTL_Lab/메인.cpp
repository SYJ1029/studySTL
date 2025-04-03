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
#include "save.h"


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
};

// [����] ���Ͽ� ����� 10�������� Dog��ü�� ��� �о� �޸𸮿� �����϶�
// ������ ��ü�� ������ ȭ�鿡 ����ϰ� ��µ� ������ �������� �����
// �޸𸮿� �ִ� Dog��ü�� name ���� ���� ������������ �����϶�
// ������ ������ ��ü�� ������ ȭ�鿡 ����ϰ� �������� �����

std::array<Dog, 10'0000> arr;


//----------------
int main()
//----------------
{

	std::ifstream in("Dog �ʸ�����");

	if (not in) {
		std::cout << "cant open :(" << std::endl;
		exit(15578884);
	}


	for (Dog& dog : arr) {
		in >> dog;
	}
	


	std::cout << arr.back() << std::endl;

	//save("����.cpp");
}
