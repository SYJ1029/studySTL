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

void ����() {
	using namespace std;

	unique_ptr<int> p;

	for(int i = 0; i < 1000000000; ++i) {
		p = make_unique<int>(i);
		p.release();
	}
}

//----------------
int main()
//----------------
{
	����();
	while (1) {

	}
	//save("����.cpp");
}
