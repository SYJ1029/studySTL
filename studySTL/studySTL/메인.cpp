/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910 
// 3�� 17�� ������
// 4�� 1��
---------------------------------*/


/*-------------------------------------------------
// Callable
--------------------------------------------------*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <filesystem>
#include <memory>
#include "save.h"

//[����] "����.cpp" ������ �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ� "���� �빮��.cpp"�� �����϶�

void Load(const std::string filename, std::string& str) {
	std::ifstream in(filename.data());
	
	if (not in) {
		std::cout << "can't open" << std::endl;
	}

	//std::cout << line << std::endl;



	str.resize(std::filesystem::file_size(filename));
	in.read((char*)str.data(), std::filesystem::file_size(filename));
	


}

void SaveUpperCase(std::string str) {
	std::ofstream out("���� �빮��.cpp");
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return std::toupper(c); });
	std::copy(str.begin(), str.end(), std::ostreambuf_iterator{ out });	// copy�� �� �� str.end()�� �ٿ��� �ߴ� ������ �����ϱ�?
}


//----------------
int main()
//----------------
{
	std::string str;

	Load("����.cpp", str);
	SaveUpperCase(str);
	
	//save("����.cpp");
}
