/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910 
// 3�� 13�� �����
// 2�� 1��
---------------------------------*/


/*-------------------------------------------------
// Generic Programming �ٽ� Ű���� - template 
--------------------------------------------------*/


#include <iostream>
#include "save.h"

//using namespace std;	// �������� �̷��� ���� ������

// [����] main ���� ���� �ǵ���� ����ǰ� �ڵ��϶�
// Dog�� Ŭ������

// �����Ϸ��� ����

class Dog {
public:
	Dog() = default;
	Dog(int n) : num{ n } {}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog){
		return os << dog.num;
	}
private:
	int num;
};


// [����] ����ü �� ���� change�� ����� �ǰڴ�?
// -> c++ ����� �ڷ��� ������ �? -> ���Ѵ�
// -> �ڵ� ������ �ڵ�ȭ����


// ���ø��� ����� ���Ǹ� ���ÿ� �ؾ߸� �Ѵ�
template <class T>
void change(T& num1, T& num2) {
	T temp{ num1 };
	num1 = num2;
	num2 = temp;

}
// �ڷ����� ���� ���� �װ� �����̵��� ���� 
// ������ ����(�˰���) ���� ����� �����ϴ� ��  
// Generic Programming


std::tuple<std::string, int> example_List(int id) 
{
	switch (id) {
	case 0: return { "�ۿ���", 2021184018 };
	case 1: return { "���ؼ�", 4018202118 };
	case 2: return { "SongYoungJun", 888484 };
	}

	throw std::invalid_argument("id");
}

//----------
int main()
//----------
{
	{
		Dog a{ 1 }, b{ 2 }; // ǥ�� ǥ���
		change(a, b); // �� ȣ���ϴ°���
		// 1. change(Dog, Dog);
		// 2. change(Dog&, Dog&);
		// 3. �����Ϸ��� ���� ���� �� ����? -> template!
		std::cout << a << ", " << b << std::endl;	// [���] 2, 1
	}

	{
		int a{ 1 }, b{ 2 }; // ǥ�� ǥ���
		change(a, b);
		std::cout << a << ", " << b << std::endl;	// [���] 2, 1
	}

	auto idiot0 = example_List(0);

	std::cout << std::get<std::string>(idiot0) << std::endl;
	std::cout << std::get<1>(idiot0) << std::endl;

	auto idiot2 = example_List(2);

	std::cout << std::get<std::string>(idiot2) << std::endl;
	std::cout << std::get<1>(idiot2) << std::endl;

	//save("����.cpp");
}

