//----------------------------------------------------------------------------------------
//STL 숙제																시작: 2025. 04. 11
//----------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
#include <print>

#define NOT_USING_MAP_FLAG 0


class Player 
{
public:

	Player() {
		p.release();		// 생성시에 p가 공간을 할당받아서는 안된다

	}

	Player(const Player& other) {
		*this = other;
	}

	Player(Player&& other) {
		*this = other;
	}

private:
	std::string name; // 이름, 길이[3, 15],  ['a', 'z']로만 구성
	int score; // 점수
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	std::unique_ptr<char[]> p; // free store에 확보한 메모리

	friend std::ostream& operator<<(std::ostream& os, const Player& player) {
		return os << "이름:  " << player.name << " 아이디: " <<  player.id <<std::endl;
	}

	friend int operator+=(int& num, const Player& player) {
		return num += player.score;
	}

public:


	void operator=(const Player& other){
		name = other.name;
		score = other.score;
		id = other.id;
		num = other.num;

		p.release();
		p = std::make_unique<char[]>(num);
		memcpy(p.get(), other.p.get(), num);
	}

	void operator=(Player&& other) {
		name = other.name;
		score = other.score;
		id = other.id;
		num = other.num;

		p.reset(other.p.release());
	}

	void write(std::ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p.get(), num);
	}

	void read(std::istream& is) {
#ifdef _DEBUG
		is.read((char*)name.data(), sizeof(Player) - sizeof(p));
#else
		is.read((char*)name.data(), sizeof(Player));
#endif


		p.release();
		p = std::make_unique<char[]>(num);
		is.read((char*)p.get(), num);
	}
	
	void Show() const {
		std::cout << "이름:  " << name << " 아이디: " << id << " 점수: " << score << " 자원수: " << num
			<< std::endl << "저장된 글자 : ";

		for (int i = 0; i < num; ++i) 
			std::cout << p[i];
		std::cout << std::endl;

	}

	int getId() const {
		return id;
	}

	int getScore() const {
		return score;
	}

	bool ScoreLess(const Player& other) const {
		return score < other.score;
	}

	bool IdLess(const Player& other) const {
		return id < other.id;
	}

	bool IdSame(const Player& other) const {
		return id == other.id;
	}

	int size() {
		return sizeof(Player) + num;
	}

	std::pair<char*, int> getBuffer() const {

		return { p.get(), num };
	}

	std::string getName() const {
		return name;
	}
};


std::array<Player, 250'0000> players;
std::map<int, std::vector<std::reference_wrapper<const Player>>> scoreMap{};
void SortScore()
{
	for (Player& player : players) {
		scoreMap[player.getScore()].push_back(std::ref(player));
	}


	std::cout << scoreMap.rbegin()->second.front().get() << std::endl;
}


void Answer1() 
{

	//1. 파일에 저장한 모든 Player 정보를 읽어 컨테이너에 저장하라.
	//	제일 마지막 Player의 정보를 다음과 같은 형식으로 화면에 출력하라.

	std::ifstream is("2025 STL 과제 파일 - 2021184018", std::ios::binary);

	if (not is)
		exit(15578884);


	for (Player& player : players) {
		player.read(is);
	}



	players.back().Show();
	
}

void Answer2() 
{

	//2. 점수가 가장 큰 Player를 찾아 화면에 출력하라.
	//	Player의 평균 점수를 계산하여 화면에 출력하라.


	std::cout << scoreMap.rbegin()->second.front().get() << std::endl << std::endl;

	int sum = std::accumulate(players.begin(), players.end(), 0, [](int result, const Player& p) {
		return result += p;
	});

	std::cout << "평균: " << sum / players.size() << std::endl;
}

void Answer3() 
{
	//	id가 서로 같은 객체를 찾아 "같은아이디.txt"에 기록하라.
	//	id가 같은 객체는 모두 몇 개인지 화면에 출력하라.
	//	파일에는 id가 같은 Player 객체의 이름과 아이디를 한 줄 씩 기록한다
	
	std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {
		return p1.IdLess(p2);
	});

	std::ofstream out ("같은아이디.txt");


	std::cout << players.back() << std::endl;
	int cnt{ 1 };


	Player temp{ players.front() };


	for (const Player& player : players) {
		if (&player != &players.front() && temp.IdSame(player)) {

			if (cnt == 1) 
				out << temp;
			out << player;

			++cnt;
		}
		else {
			if (cnt > 1) {
				std::cout << cnt << std::endl;
			}
			cnt = 1;
			temp = player;
			
		}
	}
	
}


std::map<int, std::vector<std::reference_wrapper<const Player>>> idmap{};

void SetMap() 
{
	// id로 그룹핑 하는 건 '정렬'이 필요하지 않다
	// 파이썬의 dist와 유사한 unordered_map 자료구조를 활용해보자
	// id를 key, name을 value로 갖는 map 자료구조를 생성하면 O(n)만으로도 id 별로 그룹핑 할 수 있다

	for (const Player& player : players) {
		idmap[player.getId()].push_back(std::ref(player));

	}
}





void Answer4() 
{
	//4. Player의 멤버 p가 가리키는 메모리에는 파일에서 읽은 num개의 char가
	//	저장되어 있어야 한다
	//	메모리에 저장된 char를 오름차순으로 정렬하라.
	//	'a'가 10글자 이상인 Player의 개수를 화면에 출력하라.

	std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {

		return strcmp(p1.getBuffer().first, p2.getBuffer().first) < 0;
	});

	int cnt{ 0 };

	for (const Player& player : players) {
		if (std::count(player.getBuffer().first, player.getBuffer().first + player.getBuffer().second, 'a') >= 10) {
			++cnt;
		}
	}

	std::cout << "그 개수: " << cnt << std::endl;
}


void Answer5()
{
	int id{ 0 };
	std::cout << "id 검색: ";
	std::cin >> id;

#if NOT_USING_MAP_FLAG		// map을 사용하지 않았다

#else						// map을 사용했다

	if (idmap.contains(id)) {
		// id에 반응이 왔다면

		int64_t index{ &idmap[id].front().get()  - players.data()};		// 배열의 인덱스 얻기
		std::cout << index << std::endl;

		int temp{ id - 1 };			// 위로  올라가자
		while (idmap.contains(temp) == false && temp >= 0) {
			--temp;		// 찾을 때까지
		}

		for (const Player& p : idmap[temp]) {
			if (temp <= 0)
				break;

			std::cout << temp << std::endl;
			p.Show();
		}

		temp = id + 1;

		while (idmap.contains(temp) == false && temp <= 250'0000) {
			++temp;		// 찾을 때까지
		}

		for (const Player& p : idmap[temp]) {
			if (temp >= 250'0000)
				break;
			std::cout << temp << std::endl;
			p.Show();
		}
		
		players[index - 1].Show();
		players[index + 1].Show();

		// players_score에서 몇번째인가
		
		scoreMap[players[index].getScore()];
	}
	else {
		std::cout << "그런 id는 없습니다" << std::endl;
	}

#endif
}



void NameSort() {


}


int main() {
	Answer1();
	std::cout << std::endl;
	SortScore();
	Answer2();
	std::cout << std::endl;
	Answer3();
	std::cout << std::endl;
	Answer4();

	std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {
		return p1.getName() < p2.getName();
	});

	SortScore();
	SetMap();
	while (1) {
		Answer5();
	}
}