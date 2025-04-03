/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910 
// 3�� 17�� ������
// 4�� 1��
---------------------------------*/


/*-------------------------------------------------
// CALLABE TYPES - ȣ�Ⱑ���� Ÿ��
// 1. �Լ�
--------------------------------------------------*/


#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <STRING>
#INCLUDE <ALGORITHM>
#INCLUDE <FILESYSTEM>
#INCLUDE <MEMORY>
#INCLUDE "SAVE.H"

//[����] "����.CPP" ������ �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ� "���� �빮��.CPP"�� �����϶�

VOID LOAD(CONST STD::STRING FILENAME, STD::STRING& STR) {
	STD::IFSTREAM IN(FILENAME.DATA());
	
	IF (NOT IN) {
		STD::COUT << "CAN'T OPEN" << STD::ENDL;
	}

	STR.RESIZE(STD::FILESYSTEM::FILE_SIZE(FILENAME));
	IN.READ((CHAR*)STR.DATA(), STD::FILESYSTEM::FILE_SIZE(FILENAME));
	


}

VOID SAVEUPPERCASE(STD::STRING STR) {
	STD::OFSTREAM OUT("���� �빮��.CPP");
	STD::TRANSFORM(STR.BEGIN(), STR.END(), STR.BEGIN(), [](UNSIGNED CHAR C) {RETURN STD::TOUPPER(C); });
	STD::COPY(STR.BEGIN(), STR.END(), STD::OSTREAMBUF_ITERATOR{ OUT });	// COPY�� �� �� STR.END()�� �ٿ��� �ߴ� ������ �����ϱ�?
}


//----------------
INT MAIN()
//----------------
{
	{
		STD::STRING STR;
		LOAD("����.CPP", STR);
		SAVEUPPERCASE(STR);
	}

	STD::IFSTREAM IN{ "����.CPP" };
	IF (NOT IN)
		RETURN 15578884;

	STD::OFSTREAM OUT{ "���� �빮��.CPP" };

	CHAR C;
	IN >> STD::NOSKIPWS;
	WHILE (IN >> C) {
		C = STD::TOUPPER(C);
		OUT << C;
	}
	
	//SAVE("����.CPP");
}
