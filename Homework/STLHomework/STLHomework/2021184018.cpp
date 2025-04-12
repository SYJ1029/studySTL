//----------------------------------------------------------------------------------------
//STL 숙제																시작: 2025. 04. 11
//----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <memory>
#include <print>


class Player {
private:
	std::string name; // 이름, 길이[3, 15],  ['a', 'z']로만 구성
	int score; // 점수
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	std::unique_ptr<char[]> p; // free store에 확보한 메모리

	friend std::ostream& operator<<(std::ostream& os, const Player& player) {
		return os << "이름:  " <<  player.name << " 아이디: " << player.id << " 점수: " << player.score << " 자원수: " << player.num
			<< std::endl << "저장된 글자 : " << player.p.get();
	}

public:

	Player() {
		p.release();		// 생성시에 p가 공간을 할당받아서는 안된다
	}

	void write(std::ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p.get(), num);
	}

	void read(std::istream& is) {
		is.read((char*)name.data(), sizeof(Player));
		p.release();
		p = std::make_unique<char[]>(num);
		is.read((char*)p.get(), num);
	}
};


std::array<Player, 250'0000> players; // ARRAY는 못쓰는건가



void Answer1() {
	std::ifstream is("2025 STL 과제 파일 - 2021184018", std::ios::binary);

	if (not is)
		exit(15578884);


	for (Player& player : players) {
		player.read(is);
	}



	for (Player& player : players) {
		std::cout << player << std::endl;
	}
}




int main() {
	Answer1();
}