#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <random>

std::default_random_engine dre;
std::uniform_int_distribution uid;
std::uniform_int_distribution uidLen{3, 60};
std::uniform_int_distribution<int> uidName{'a', 'z'};


class Homework {
private:
	size_t num;					// ���� int ��
	std::string name;			// [3, 60) ������ ���� �ҹ��ڷθ� ����

	friend std::ostream& operator<<(std::ostream& os, const Homework& dog) {
		return os << dog.num << " " << dog.name << " ";
	}

public:
	Homework(int len = uidLen(dre)) {
		num = uid(dre);
		
		for (int i = 0; i < len; ++i) {
			name += uidName(dre);
		}
	}
};




void MakeQuestion(std::string filename) {
	std::ofstream out(filename.data());


	for (int i = 0; i < 1'000'0000; ++i) {
		Homework questionMaker;
		out << questionMaker << std::endl;
	}
}