//-----------------------------------------------------------------------------
// 2025. 1. STL 월910목910	5월 12일 월요일
// 졸업작품 중간발표로 6:40 시작
// 6/19 목요일 15주 2일 - 기말 시험
// 5/12 월요일  - 졸업작품 중간 발표 이후에 시험친다
//-----------------------------------------------------------------------------
// concepts - compile-time에 template 함수에 전달된 인자(타입, non-type)이
// concept에 맞는지 안 맞는지 판단하기 위한 C++ 언어의 문법
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <ranges>
#include <numeric>
#include <print>
#include "save.h"
#include "STRING.h"
using namespace std;
extern bool 관찰;

void STRING::write(std::ostream& os)
{
	os.write((char*)&num, sizeof(size_t));
	os.write(p.get(), num);
}

bool STRING::read(std::istream& is)
{
	if (is.read((char*)&num, sizeof(size_t))) {
		p = std::make_unique<char[]>(num);
		is.read(p.get(), num);
	}
	else
		return false;


	return true;
}




//---------
int main()
//---------
{


	{

		vector<STRING> v;

		ifstream is("시험.txt");

		STRING s;

		while (s.read(is))
		{
			v.push_back(s);
		}

		for (const STRING& ss : v) {
			cout << ss << endl << endl;
		}

		cout << v.size() << endl;
		cout << v.capacity() << endl;


		ptrdiff_t words{ 0 };
		for (STRING& ss : v) {
			auto itr = count(ss.begin(), ss.end(), ' ');
			words += itr;

		}

		double avg = (double)words / v.size();
		print("{:.2f}\n", avg);
	

	
		vector<STRING> v2;

		ifstream is2("단어들.txt");
		STRING s2;
		while (is2 >> s2) {
			v2.push_back(s2);
		}

		//for (const STRING& ss : v) {
		//	cout << ss << endl;
		//}

		cout << v2.size();


		//auto p = partition(v2.begin(), v2.end(), [](const STRING& a, const STRING& b) {
		//	return !(a < b);
		//	});


		//sort(v.begin(), v.end());

		for (const STRING& ss : v2) {
			for (const STRING& sss : v) {
				auto token = find(sss.begin(), sss.end(), ss);

				if (token != sss.end())
					cout << ss;
			}
		}
	}

}
 
