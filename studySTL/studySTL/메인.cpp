//-----------------------------------------------------------------------------
// 2025. 1. STL ��910��910	4�� 28�� ��
// 2025. 5. 5 -> ���� ����(6 / 19 ����)
//-----------------------------------------------------------------------------
// STL Container
// array<T, N> - �����ϰ� ũ�� ����
// vector<T> - random access, []������ ����, O(1)�� ��� ���ҿ� access, O(1) push_back()
// deque<T> - random access, [] ������ ����, O(1)�� ��� ���ҿ� access, O(1) push_front(), push_back()
// list<T> - O(1) insert, delete, �ڷᱸ���� Ȱ���� �����Լ��� ����(remove, sort, splice)
//-----------------------------------------------------------------------------

#include <iostream>
#include <list>
#include "STRING.h"
#include "save.h"
using namespace std;
extern bool ����;


//---------
int main()
//---------
{
	list<STRING> v{ "1", "22", "333", "4444", "55555"};

	//[����] v���� "333"�� �����϶�!
	//vector<int>::iterator newEnd = remove(v.begin(), v.end(), 3);
	���� = true;
	STRING t{ "333" };
	//erase(v, "333");		// ������ ������ ����!
	v.remove(t);
	���� = false;

	for (const STRING& s : v){
		cout << s << " ";
	}
	cout << endl;

	save("����.cpp");
}
 