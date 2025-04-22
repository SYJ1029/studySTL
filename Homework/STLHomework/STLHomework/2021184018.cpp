//----------------------------------------------------------------------------------------
//STL ����																����: 2025. 04. 11
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
		p.release();		// �����ÿ� p�� ������ �Ҵ�޾Ƽ��� �ȵȴ�

	}

	Player(const Player& other) {
		*this = other;
	}

	Player(Player&& other) {
		*this = other;
	}

private:
	std::string name; // �̸�, ����[3, 15],  ['a', 'z']�θ� ����
	int score; // ����
	size_t id; // ���̵�, ��ġ�� ���̵� ���� �� ����
	size_t num; // free store�� Ȯ���� ����Ʈ ��
	std::unique_ptr<char[]> p; // free store�� Ȯ���� �޸�

	friend std::ostream& operator<<(std::ostream& os, const Player& player) {
		return os << "�̸�:  " << player.name << " ���̵�: " <<  player.id <<std::endl;
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
		std::cout << "�̸�:  " << name << " ���̵�: " << id << " ����: " << score << " �ڿ���: " << num
			<< std::endl << "����� ���� : ";

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

	//1. ���Ͽ� ������ ��� Player ������ �о� �����̳ʿ� �����϶�.
	//	���� ������ Player�� ������ ������ ���� �������� ȭ�鿡 ����϶�.

	std::ifstream is("2025 STL ���� ���� - 2021184018", std::ios::binary);

	if (not is)
		exit(15578884);


	for (Player& player : players) {
		player.read(is);
	}



	players.back().Show();
	
}

void Answer2() 
{

	//2. ������ ���� ū Player�� ã�� ȭ�鿡 ����϶�.
	//	Player�� ��� ������ ����Ͽ� ȭ�鿡 ����϶�.


	std::cout << scoreMap.rbegin()->second.front().get() << std::endl << std::endl;

	int sum = std::accumulate(players.begin(), players.end(), 0, [](int result, const Player& p) {
		return result += p;
	});

	std::cout << "���: " << sum / players.size() << std::endl;
}

void Answer3() 
{
	//	id�� ���� ���� ��ü�� ã�� "�������̵�.txt"�� ����϶�.
	//	id�� ���� ��ü�� ��� �� ������ ȭ�鿡 ����϶�.
	//	���Ͽ��� id�� ���� Player ��ü�� �̸��� ���̵� �� �� �� ����Ѵ�
	
	std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {
		return p1.IdLess(p2);
	});

	std::ofstream out ("�������̵�.txt");


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
	// id�� �׷��� �ϴ� �� '����'�� �ʿ����� �ʴ�
	// ���̽��� dist�� ������ unordered_map �ڷᱸ���� Ȱ���غ���
	// id�� key, name�� value�� ���� map �ڷᱸ���� �����ϸ� O(n)�����ε� id ���� �׷��� �� �� �ִ�

	for (const Player& player : players) {
		idmap[player.getId()].push_back(std::ref(player));

	}
}





void Answer4() 
{
	//4. Player�� ��� p�� ����Ű�� �޸𸮿��� ���Ͽ��� ���� num���� char��
	//	����Ǿ� �־�� �Ѵ�
	//	�޸𸮿� ����� char�� ������������ �����϶�.
	//	'a'�� 10���� �̻��� Player�� ������ ȭ�鿡 ����϶�.

	std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {

		return strcmp(p1.getBuffer().first, p2.getBuffer().first) < 0;
	});

	int cnt{ 0 };

	for (const Player& player : players) {
		if (std::count(player.getBuffer().first, player.getBuffer().first + player.getBuffer().second, 'a') >= 10) {
			++cnt;
		}
	}

	std::cout << "�� ����: " << cnt << std::endl;
}


void Answer5()
{
	int id{ 0 };
	std::cout << "id �˻�: ";
	std::cin >> id;

#if NOT_USING_MAP_FLAG		// map�� ������� �ʾҴ�

#else						// map�� ����ߴ�

	if (idmap.contains(id)) {
		// id�� ������ �Դٸ�

		int64_t index{ &idmap[id].front().get()  - players.data()};		// �迭�� �ε��� ���
		std::cout << index << std::endl;

		int temp{ id - 1 };			// ����  �ö���
		while (idmap.contains(temp) == false && temp >= 0) {
			--temp;		// ã�� ������
		}

		for (const Player& p : idmap[temp]) {
			if (temp <= 0)
				break;

			std::cout << temp << std::endl;
			p.Show();
		}

		temp = id + 1;

		while (idmap.contains(temp) == false && temp <= 250'0000) {
			++temp;		// ã�� ������
		}

		for (const Player& p : idmap[temp]) {
			if (temp >= 250'0000)
				break;
			std::cout << temp << std::endl;
			p.Show();
		}
		
		players[index - 1].Show();
		players[index + 1].Show();

		// players_score���� ���°�ΰ�
		
		scoreMap[players[index].getScore()];
	}
	else {
		std::cout << "�׷� id�� �����ϴ�" << std::endl;
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