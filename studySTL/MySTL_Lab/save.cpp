//-----------------------------------------------------------
// save.cpp - 한학기를 잘 저장하는 함수
//													2025.3.13
//-----------------------------------------------------------


#include <string_view>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>

//------------------------------------
void save(std::string_view filename)
//------------------------------------
{
	// const qualifier를 사용해 매개변수가 읽기모드 전용임을 강조
	// --> 꼭 덩치가 큰 string이어야 할까?
	//  string_view가 왜 없지
	// -> Release 모드는 여전히 c++14를 사용하고 있었음

	// 1. 인자로 전달된 filename을 읽기모드로 열기
	std::ifstream filein{ filename.data(), std::ios::binary }; // RAII -> 자원을 이용해서 실행하기

	if (not filein) //가독성을 위해 not 으로 
	{
		std::cout << filename << "을 열 수 없습니다" << std::endl;
		exit(202503210); // 굳이 return
	}

	// 1.5) 저장했다는 사실을 화면에 표시
	std::cout << filename << "(" << std::filesystem::file_size(filename)
		<< "bytes) save" << std::endl;



	// 2. 쓰기모드로 저장할 파일을 [덧붙이기 모드로] 열기
	std::ofstream fileout{ "실습 5주차 1일.txt", std::ios::app };

	using namespace std::chrono_literals;
	// 시간을 기록하자
	auto now = std::chrono::system_clock::now();	// epoch로 부터 경과된 tick 수를 얻는다
	auto utc = std::chrono::system_clock::to_time_t(now); // utc
	auto lt = std::localtime(&utc); // 지역시간으로 변경

	auto old = fileout.imbue(std::locale("ko_KR")); // 모든 스트림을 한국식으로 바꾸는 '중요한'변화
	// 때문에 원래 파일을 세이브 해야함


	//fileout << '\n' << '\n';
	//fileout << "==================================" << '\n';
	//fileout << "저장한 시간: " << std::put_time(lt, "%c %A") << '\n';
	//fileout << "==================================" << '\n';
	//fileout << '\n';
	// {}는 uniform initializer 라는 이름 
	// std::ios::app 가 덧붙이기 모드임을 강조하는 코드

	fileout.imbue(old); // 원상복구

	// 3. 사용할 파일을 읽어서 저장할 파일에 덧붙이기


	std::vector<char> v(std::filesystem::file_size(filename));
	// vector는 ()를 사용해 딱 맞는 바이트 확보가 가능하다
	std::copy(std::istreambuf_iterator{ filein }, {}, std::ostreambuf_iterator{ fileout });

}