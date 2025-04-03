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
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"

//[����] "����.CPP" ������ �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ� "���� �빮��.CPP"�� �����϶�


//----------------
INT MAIN()
//----------------
{
	STD::IFSTREAM IN{ "����.CPP" };
	IF (NOT IN)
		RETURN 15578884;

	STD::OFSTREAM OUT{ "���� �빮��.CPP" };

	// TRANSFORM�� Ÿ�Կ� ������ ���׸� �Լ�!
	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, 
		STD::OSTREAMBUF_ITERATOR<CHAR>{OUT}, 
		[](CHAR C) { 
			RETURN STD::TOUPPER(C); 
		});	// ���⵵ ���׸�
	
	SAVE("����.CPP");
}
