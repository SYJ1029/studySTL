//----------------------------------------------------------------------------------------
//STL ����																����: 2025. 04. 11
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
		p.release();		// �����ÿ� p�� ������ �Ҵ�޾Ƽ��� �ȵȴ�

	}
private:
	std::string name; // �̸�, ����[3, 15],  ['a', 'z']�θ� ����
	int score; // ����
	size_t id; // ���̵�, ��ġ�� ���̵� ���� �� ����
	size_t num; // free store�� Ȯ���� ����Ʈ ��
	std::unique_ptr<char[]> p; // free store�� Ȯ���� �޸�

	friend std::ostream& operator<<(std::ostream& os, const Player& player) {
		return os << "�̸�:  " <<  player.name << " ���̵�: " << player.id << " ����: " << player.score << " �ڿ���: " << player.num
			<< std::endl << "����� ���� : " << player.p.get();
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


std::array<Player, 250'0000> players; // ARRAY�� �����°ǰ�


void Answer1() {

	//1. ���Ͽ� ������ ��� Player ������ �о� �����̳ʿ� �����϶�.
	//	���� ������ Player�� ������ ������ ���� �������� ȭ�鿡 ����϶�.

	std::ifstream is("2025 STL ���� ���� - 2021184018", std::ios::binary);

	if (not is)
		exit(15578884);


	for (Player& player : players) {
		player.read(is);
	}



	std::cout << players.back() << std::endl;
	
}

void Answer2() {

	//2. ������ ���� ū Player�� ã�� ȭ�鿡 ����϶�.
	//	Player�� ��� ������ ����Ͽ� ȭ�鿡 ����϶�.

	auto result = std::max_element(players.begin(), players.end(),[](const Player& p1, const Player& p2) {

		return p1.ScoreLess(p2);
	});


	std::cout << *result << std::endl << std::endl;

	int sum = std::accumulate(players.begin(), players.end(), 0, [](int result, const Player& p) {
		return result += p;
	});

	std::cout << "���: " << sum / players.size() << std::endl;
}

void Answer3bySort() {
	//	id�� ���� ���� ��ü�� ã�� "�������̵�.txt"�� ����϶�.
	//	id�� ���� ��ü�� ��� �� ������ ȭ�鿡 ����϶�.
	//	���Ͽ��� id�� ���� Player ��ü�� �̸��� ���̵� �� �� �� ����Ѵ�

	
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