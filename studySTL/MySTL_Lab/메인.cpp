/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910				(7�� 2��)
// 4�� 10�� �����
// �߰����		- 8�� 1��(4�� 24�� �����)
---------------------------------*/


/*----------------------------------------------------------------
// STL Container - Containers are objects that store other objects
// array -
// vector - at ������ �ϰ� ����
------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "STRING.h"


extern bool ����;				// �����Ϸ��� true��

//[����] Ű���忡�� �ܾ ��� �Է¹޾� ������������ ������ �� ����϶�.

//----------------
int main()
//----------------
{
	std::ifstream in("����.cpp");
	std::vector<std::string> v{ std::istream_iterator<std::string>{std::cin}, {} };

	std::sort(v.begin(), v.end());

	for (const std::string& s : v) {
		std::cout << s << std::endl;
	}

	//save("����.cpp");
}
