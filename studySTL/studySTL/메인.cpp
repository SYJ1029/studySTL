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
#include <fstream>
#include <algorithm>
#include "save.h"

//[����] "����.cpp" ������ �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ� "���� �빮��.cpp"�� �����϶�


//----------------
int main()
//----------------
{
	std::ifstream in{ "����.cpp" };
	if (not in)
		return 15578884;

	std::ofstream out{ "���� �빮��.cpp" };

	// transform�� Ÿ�Կ� ������ ���׸� �Լ�!
	std::transform(std::istreambuf_iterator<char>{in}, {}, 
		std::ostreambuf_iterator<char>{out}, 
		���⿡ �󸶳� �� �� ������);	// ���⵵ ���׸�
	
	//save("����.cpp");
}
