/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910				(7�� 1��)
// 4�� 10�� �����
// �߰����		- 8�� 1��(4�� 24�� �����)
---------------------------------*/


/*----------------------------------------------------------------
// STL Container - Containers are objects that store other objects
// �ٸ� ��ü���� ������ �� �ִ� �����̳�
//
------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"


extern bool ����;				// �����Ϸ��� true��



//----------------
int main()
//----------------
{
	std::vector<int> v;

	std::cout << "���� ����						- " << v.size() << std::endl;
	std::cout << "���� �� �ִ� ���� ����		- " << v.capacity() << std::endl;
	std::cout << "������ ��ġ					- " << v.data() << std::endl;

	std::cout << std::endl;

	std::cout << "���� 1�� �߰��� �� vector v�� field" << std::endl;
	v.push_back(1);

	std::cout << "���� ����						- " << v.size() << std::endl;
	std::cout << "���� �� �ִ� ���� ����		- " << v.capacity() << std::endl;
	std::cout << "������ ��ġ					- " << v.data() << std::endl;

	save("����.cpp");
}
