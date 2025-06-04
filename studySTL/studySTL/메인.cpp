//-----------------------------------------------------------------------------
// 2025. 1. STL ��910��910	5�� 12�� ������
// ������ǰ �߰���ǥ�� 6:40 ����
// 6/19 ����� 15�� 2�� - �⸻ ����
// 5/12 ������  - ������ǰ �߰� ��ǥ ���Ŀ� ����ģ��
//-----------------------------------------------------------------------------
// Assocative Container
// - set<key==val>			: key�� value�� �������� �ʴ´�
// - map<key, value>		: <���̵��׷�, ���>
//-----------------------------------------------------------------------------

#include <iostream>
#include <set>
#include <array>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "STRING.h"
using namespace std;
extern bool ����;


//---------
int main()
//---------
{
	
	ifstream in("�̻��� ������ �ٸ���.txt");

	if (not in) {
		cout << "�����!" << endl;
		exit(2021184018);
	}

	//multiset<STRING> s{istream_iterator<STRING>(in), {}};
	set<STRING> s{ istream_iterator<STRING>(in), {} };


	STRING �ܾ�;
	cin >> �ܾ�;

	auto result = s.find(�ܾ�);

	if (result != s.end()) {
		cout << *result << " " << distance(s.begin(), result) << endl;
	}

	//save("����.cpp");

	// [����] multiset�� ����� ��� ���ĺ��� ��� Ƚ���� ������ ���� �������
	// ���� Ƚ������ ������������ ����϶�
	// �빮�ڴ� �ҹ��ڷ� �ٲ㼭 ����Ѵ�
	// e - 13618
	// t - 10716
	// 
	// 
	// z - 78

	//array<size_t, 26> alphaNum{};

	//for (const STRING& �ܾ� : s) {
	//	for (char c : �ܾ�) {
	//		if (isalpha(c)) {
	//			c = tolower(c);
	//			alphaNum[c - 'a']++;
	//		}
	//	}
	//}

	//for (int i = 0; i < alphaNum.size(); ++i) {
	//	cout << static_cast<char>('a' + i) << +" - " << alphaNum[i] << endl;
	//}

}
 