#include <iostream>
#include <iterator>
#include <array>
#include <forward_list>
#include <list>
#include <deque>
#include <vector>
#include <concepts>
#include <chrono>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;
extern bool 관찰;


// 반복자는 서로 다르다 - 6개의 categoty

// [문제] 반복자를 인자로 받아 어떤 종류의 반복자인지 화면에 출력하는 
// 함수 f를 정의하라


template <class 반복자>

void f(const 반복자& p)
{


	if constexpr (contiguous_iterator<반복자>)
		cout << typeid(반복자::iterator_concept).name() << endl;
	else
	{
		cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;

	}



}



//---------
int main()
//---------
{

	f(ostream_iterator<char>{cout});

	f(istream_iterator<char>{cin});

	f(forward_list<char>{}.begin());

	deque<std::string> d;
	f(d.rbegin());

	list<int> l;
	f(l.begin());

	f(vector<int>{}.cbegin());




	f(array<int, 10>{}.begin());

	int* p;
	f(p);




	save("메인.cpp");
}