/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910
// 3�� 17�� ������
// 3�� 2��
---------------------------------*/


/*-------------------------------------------------
// ���� ���� �ڷḦ �ٷ�� - Dog�� �а� �� �� �־��
--------------------------------------------------*/


#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <random>
#include "save.h"



//[�ǽ�2] name�� �� ���� ���ڰ� �� �� �ֵ��� �غ���, 16�ڸ� �ѱ� �� ������?


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

	//Dog_Save("��¥ ���� Dog 10����");


	Load("��¥ ���� Dog 10����");

	for (const Dog& dog : dogs2) {
		std::cout << dog << std::endl;
	}
	// ����ؼ� ����
	//save("����.cpp");
}
