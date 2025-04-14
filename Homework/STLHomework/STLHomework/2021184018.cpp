//----------------------------------------------------------------------------------------
//STL 숙제																시작: 2025. 04. 11
//----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <memory>
#include <algorithm>
#include <numeric>
#include <print>


class Player {
public:

	Player() {
		p.release();		// 생성시에 p가 공간을 할당받아서는 안된다

	}
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

	friend int operator+=(int& num, const Player& player) {
		return num += player.score;
	}
public:

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
	
	bool ScoreLess(const Player& other) const {
		return score < other.score;
	}

	bool IdLess(const Player& other) const {
		return id < other.id;
	}

};


std::array<Player, 250'0000> players; // ARRAY는 못쓰는건가


void Answer1() {

	//1. 파일에 저장한 모든 Player 정보를 읽어 컨테이너에 저장하라.
	//	제일 마지막 Player의 정보를 다음과 같은 형식으로 화면에 출력하라.

	std::ifstream is("2025 STL 과제 파일 - 2021184018", std::ios::binary);

	if (not is)
		exit(15578884);


	for (Player& player : players) {
		player.read(is);
	}



	std::cout << players.back() << std::endl;
	
}

void Answer2() {

	//2. 점수가 가장 큰 Player를 찾아 화면에 출력하라.
	//	Player의 평균 점수를 계산하여 화면에 출력하라.

	auto result = std::max_element(players.begin(), players.end(),[](const Player& p1, const Player& p2) {

		return p1.ScoreLess(p2);
	});


	std::cout << *result << std::endl << std::endl;

	int sum = std::accumulate(players.begin(), players.end(), 0, [](int result, const Player& p) {
		return result += p;
	});

	std::cout << "평균: " << sum / players.size() << std::endl;
}

void Answer3bySort() {
	//	id가 서로 같은 객체를 찾아 "같은아이디.txt"에 기록하라.
	//	id가 같은 객체는 모두 몇 개인지 화면에 출력하라.
	//	파일에는 id가 같은 Player 객체의 이름과 아이디를 한 줄 씩 기록한다

	
	std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {
		return p1.IdLess(p2);
		});


	
}

int main() {
	Answer1();
	std::cout << std::endl;
	Answer2();
	std::cout << std::endl;
	Answer3bySort();
}