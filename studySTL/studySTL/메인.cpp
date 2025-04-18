/*--------------------------------
// 2025학년도 1학기 STL 월910수910				(7주 1일)
// 4월 10일 목요일
// 중간고사		- 8주 1일(4월 24일 목요일)
---------------------------------*/


/*----------------------------------------------------------------
// STL Container - Containers are objects that store other objects
// 다른 객체들을 저장할 수 있는 컨테이너
//
------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"


extern bool 관찰;				// 관찰하려면 true로



//----------------
int main()
//----------------
{
	std::vector<int> v;

	std::cout << "원소 개수						- " << v.size() << std::endl;
	std::cout << "담을 수 있는 원소 개수		- " << v.capacity() << std::endl;
	std::cout << "원소의 위치					- " << v.data() << std::endl;

	std::cout << std::endl;

	std::cout << "원소 1개 추가한 후 vector v의 field" << std::endl;
	v.push_back(1);

	std::cout << "원소 개수						- " << v.size() << std::endl;
	std::cout << "담을 수 있는 원소 개수		- " << v.capacity() << std::endl;
	std::cout << "원소의 위치					- " << v.data() << std::endl;

	save("메인.cpp");
}
