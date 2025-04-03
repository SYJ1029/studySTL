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

	save("����.cpp");
}

