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
#include <memory>
#include "save.h"
#include "STRING.h"


extern bool ����;				// �����Ϸ��� true��

//[����] Ű���忡�� �ܾ ��� �Է¹޾� ������������ ������ �� ����϶�.

//----------------
int main()
//----------------
{
	using namespace std;
	unique_ptr<int> p;
	while (1) {
		p = make_unique<int>(1557);
		p.reset();		// ��¥��????????
	}

	//save("����.cpp");
}
