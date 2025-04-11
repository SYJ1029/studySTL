//----------------------------------------------------------------------------------------
//STL 숙제																시작: 2025. 04. 11
//----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <array>
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
		std::println("이름: {<:16}, 아이디: {<:8} , 점수: {<:8}, 자원수: {<:4}", player.name, player.id, player.score, player.num);

		return os << "저장된 글자: " << player.p.get();
	}

public:

	Player() {
	}

	void write(std::ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p.get(), num);
	}

	void read(std::istream& is) {
		is.read((char*)name.data(), sizeof(std::string));
		is.read((char*)&score, sizeof(Player) - sizeof(std::string));
		p.release();
		p = std::make_unique<char[]>(num);
		is.read((char*)p.get(), num);
	}
};


std::array<Player, 250'0000> players;




void Answer1() {
	std::ifstream is("2025 STL 과제 파일 - 2021184018", std::ios::binary);

	if (not is)
		exit(15578884);


	for (Player& player : players) {
		player.read(is);
	}


}




int main() {
	Answer1();
}