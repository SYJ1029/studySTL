/*--------------------------------
// 2025학년도 1학기 STL 월910수910 
// 3월 17일 월요일
// 4주 1일
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

//[문제] "메인.cpp" 파일의 소문자를 대문자로 변환하여 "메인 대문자.cpp"에 저장하라

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
	std::ofstream out("메인 대문자.cpp");
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return std::toupper(c); });
	std::copy(str.begin(), str.end(), std::ostreambuf_iterator{ out });	// copy를 할 때 str.end()를 붙여야 했던 이유는 무엇일까?
}


//----------------
int main()
//----------------
{
	std::string str;

	Load("메인.cpp", str);
	SaveUpperCase(str);
	
	//save("메인.cpp");
}
