//-----------------------------------------------------------------------------
// 2025. 1. STL ��910��910	5�� 12�� ������
// ������ǰ �߰���ǥ�� 6:40 ����
// 6/19 ����� 15�� 2�� - �⸻ ����
// 5/12 ������  - ������ǰ �߰� ��ǥ ���Ŀ� ����ģ��
//-----------------------------------------------------------------------------
// STL Container
// array<T, N> - �����ϰ� ũ�� ����
// vector<T> - random access, []������ ����, O(1)�� ��� ���ҿ� access, O(1) push_back()
// deque<T> - random access, [] ������ ����, O(1)�� ��� ���ҿ� access, O(1) push_front(), push_back()
// list<T> - O(1) insert, delete, �ڷᱸ���� Ȱ���� �����Լ��� ����(remove, sort, splice)
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "STRING.h"
#include "save.h"
using namespace std;
extern bool ����;


class Test {
	char x[1'000'000];
};


//---------
int main()
//---------
{
	//[����] "����.cpp"�� �ܾ list�� ��� �����϶�
	ifstream in("����.cpp");
	if (not in)
		return 2021184018;

	list<STRING> �ܾ��{ istream_iterator<STRING>(in), {} };

	//[����] �ܾ� �߿��� ���̰� 5�� �͵鸸 ȭ�鿡 �⤩��

	copy(�ܾ��.begin(), �ܾ��.end(), ostream_iterator<STRING>(cout, " * "));

	// �����ð��� �ٽ� �ڵ��ϰ� �ݺ��� �Ұ����� ����

	save("����.cpp");
}
 