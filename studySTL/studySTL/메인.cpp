//-----------------------------------------------------------------------------
// 2025. 1. STL 월910목910	5월 12일 월요일
// 졸업작품 중간발표로 6:40 시작
// 6/19 목요일 15주 2일 - 기말 시험
// 5/12 월요일  - 졸업작품 중간 발표 이후에 시험친다
//-----------------------------------------------------------------------------
// Assocative Container
// - set<key==val>			: key와 value를 구분하지 않는다
// - map<key, value>		: <아이돌그룹, 멤버>
//-----------------------------------------------------------------------------

#include <iostream>
#include <set>
#include <array>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "STRING.h"
using namespace std;
extern bool 관찰;


//---------
int main()
//---------
{
	
	ifstream in("이상한 나라의 앨리스.txt");

	if (not in) {
		cout << "읎어요!" << endl;
		exit(2021184018);
	}

	//multiset<STRING> s{istream_iterator<STRING>(in), {}};
	set<STRING> s{ istream_iterator<STRING>(in), {} };


	STRING 단어;
	cin >> 단어;

	auto result = s.find(단어);

	if (result != s.end()) {
		cout << *result << " " << distance(s.begin(), result) << endl;
	}

	//save("메인.cpp");

	// [문제] multiset에 저장된 모든 알파벳의 사용 횟수를 다음과 같이 출력하자
	// 사용된 횟수기준 내림차순으로 출력하라
	// 대문자는 소문자로 바꿔서 취급한다
	// e - 13618
	// t - 10716
	// 
	// 
	// z - 78

	//array<size_t, 26> alphaNum{};

	//for (const STRING& 단어 : s) {
	//	for (char c : 단어) {
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
 