//-----------------------------------------------------------------------------
// 2025. 1. STL ��910��910	5�� 12�� ������
// ������ǰ �߰���ǥ�� 6:40 ����
// 6/19 ����� 15�� 2�� - �⸻ ����
// 5/12 ������  - ������ǰ �߰� ��ǥ ���Ŀ� ����ģ��
//-----------------------------------------------------------------------------
// �ݺ��ڿ� �˰��� �Լ�
// find()
// find_if()
// copy()
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;
extern bool ����;

template<class �ݺ���, class ã����>
�ݺ��� my_find(�ݺ��� b, �ݺ��� e, ã���� v)
{
	for (; b != e; ++b) {
		if (*b == v)
			return b;
	}

	return e;
}

template<class �ݺ���, class ȣ�Ⱑ��Ÿ��>
�ݺ��� my_find_if(�ݺ��� b, �ݺ��� e, ȣ�Ⱑ��Ÿ�� callable) {
	while (b != e) {
		if (callable(*b) == true)
			return b;

		++b;
	}

	return e;
}



//---------
int main()
//---------
{
	STRING s{ "2025. 5. 26" };

	vector<char> v;

	// [����] s�� �����ϴ� ���ڵ��� v�� �����϶�
	copy(s.begin(), s.end(), v.begin());

	//save("����.cpp");
}
 