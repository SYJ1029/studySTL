/*--------------------------------
// 2025학년도 1학기 STL 월910수910
// 3월 17일 월요일
// 3주 2일
---------------------------------*/


/*-------------------------------------------------
// 많은 수의 자료를 다루기 - Dog를 읽고 쓸 수 있어야
--------------------------------------------------*/


#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <random>
#include "save.h"



//[실습2] name에 더 많은 글자가 들어갈 수 있도록 해보자, 16자를 넘길 수 있을까?


std::default_random_engine dre{ std::random_device{}() };
std::uniform_int_distribution<int> uid('a', 'z');

class Dog {
private:
	std::string name;
	int id;
	static int sid;
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << "id - " << dog.id << std::endl << "name - " << dog.name << std::endl;
	}

	friend std::istream& operator>>(std::istream& is, Dog& dog) {

		return is.read((char*)&dog, sizeof(dog));
	}
public:
	Dog() : id{ ++sid } {
		for (int i = 0; i < 64; ++i)
			name += uid(dre);
	}

	void show() {
		std::cout << "id - " << id << std::endl;
		std::cout << "name - " << name << std::endl;
	}

};

int Dog::sid{};

std::array<Dog, 10'0000> dogs;
std::array<Dog, 10'0000> dogs2;


void Dog_Save(std::string filename) {

	std::ofstream out(filename, std::ios::binary);

	out.write((char*)dogs.data(), sizeof(Dog) * dogs.size());
}

void Load(std::string filename) {

	std::ifstream in(filename, std::ios::binary);
	if (not in)
		exit(888484);

	in.read((char*)dogs2.data(), dogs2.size());

}

//----------------
int main()
//----------------
{

	//Dog_Save("진짜 랜덤 Dog 10만개");


	Load("진짜 랜덤 Dog 10만개");

	for (const Dog& dog : dogs2) {
		std::cout << dog << std::endl;
	}
	// 출력해서 검증
	//save("메인.cpp");
}
