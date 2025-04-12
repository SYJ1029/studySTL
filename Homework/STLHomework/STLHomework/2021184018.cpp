//----------------------------------------------------------------------------------------
//STL ����																����: 2025. 04. 11
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
	std::string name; // �̸�, ����[3, 15],  ['a', 'z']�θ� ����
	int score; // ����
	size_t id; // ���̵�, ��ġ�� ���̵� ���� �� ����
	size_t num; // free store�� Ȯ���� ����Ʈ ��
	std::unique_ptr<char[]> p; // free store�� Ȯ���� �޸�

	friend std::ostream& operator<<(std::ostream& os, const Player& player) {
		return os << "�̸�:  " <<  player.name << " ���̵�: " << player.id << " ����: " << player.score << " �ڿ���: " << player.num
			<< std::endl << "����� ���� : " << player.p.get();
	}

public:

	Player() {
		p.release();		// �����ÿ� p�� ������ �Ҵ�޾Ƽ��� �ȵȴ�
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


std::array<Player, 250'0000> players; // ARRAY�� �����°ǰ�



void Answer1() {
	std::ifstream is("2025 STL ���� ���� - 2021184018", std::ios::binary);

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