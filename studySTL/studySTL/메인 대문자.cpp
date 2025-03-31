/*--------------------------------
// 2025학년도 1학기 STL 월910수910 
// 3월 17일 월요일
// 4주 1일
---------------------------------*/


/*-------------------------------------------------
// CALLABE TYPES - 호출가능한 타입
// 1. 함수
--------------------------------------------------*/


#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"

//[문제] "메인.CPP" 파일의 소문자를 대문자로 변환하여 "메인 대문자.CPP"에 저장하라


//----------------
INT MAIN()
//----------------
{
	STD::IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN)
		RETURN 15578884;

	STD::OFSTREAM OUT{ "메인 대문자.CPP" };

	// TRANSFORM은 타입에 무관한 제네릭 함수!
	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, 
		STD::OSTREAMBUF_ITERATOR<CHAR>{OUT}, 
		[](CHAR C) { 
			RETURN STD::TOUPPER(C); 
		});	// 여기도 제네릭
	
	SAVE("메인.CPP");
}
