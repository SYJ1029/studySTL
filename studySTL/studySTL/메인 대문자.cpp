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
#INCLUDE <STRING>
#INCLUDE <ALGORITHM>
#INCLUDE <FILESYSTEM>
#INCLUDE <MEMORY>
#INCLUDE "SAVE.H"

//[문제] "메인.CPP" 파일의 소문자를 대문자로 변환하여 "메인 대문자.CPP"에 저장하라

VOID LOAD(CONST STD::STRING FILENAME, STD::STRING& STR) {
	STD::IFSTREAM IN(FILENAME.DATA());
	
	IF (NOT IN) {
		STD::COUT << "CAN'T OPEN" << STD::ENDL;
	}

	STR.RESIZE(STD::FILESYSTEM::FILE_SIZE(FILENAME));
	IN.READ((CHAR*)STR.DATA(), STD::FILESYSTEM::FILE_SIZE(FILENAME));
	


}

VOID SAVEUPPERCASE(STD::STRING STR) {
	STD::OFSTREAM OUT("메인 대문자.CPP");
	STD::TRANSFORM(STR.BEGIN(), STR.END(), STR.BEGIN(), [](UNSIGNED CHAR C) {RETURN STD::TOUPPER(C); });
	STD::COPY(STR.BEGIN(), STR.END(), STD::OSTREAMBUF_ITERATOR{ OUT });	// COPY를 할 때 STR.END()를 붙여야 했던 이유는 무엇일까?
}


//----------------
INT MAIN()
//----------------
{
	{
		STD::STRING STR;
		LOAD("메인.CPP", STR);
		SAVEUPPERCASE(STR);
	}

	STD::IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN)
		RETURN 15578884;

	STD::OFSTREAM OUT{ "메인 대문자.CPP" };

	CHAR C;
	IN >> STD::NOSKIPWS;
	WHILE (IN >> C) {
		C = STD::TOUPPER(C);
		OUT << C;
	}
	
	//SAVE("메인.CPP");
}
