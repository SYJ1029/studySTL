/*--------------------------------
// 2025�г⵵ 1�б� STL ��910��910				(5�� 1��)
// 3�� 17�� ������
// �߰����		- 8�� 1��(4�� 24�� �����)
// ��������(30)	- 6�� 1��(4�� 10�� �����)
---------------------------------*/


/*-------------------------------------------------
// class STRING �ۼ����� - std::string�� ������ ������ �Ѵ�
--------------------------------------------------*/

#include <iostream>
#include <string>
#include <memory>
#include <array>
#include "save.h"

class STRING {
public:
	STRING() {};

	STRING(const char* str) : num{ strlen(str) } {
		p.release();	// �ڿ��� �ִٸ� ���������� ���� �ÿ� �̷��� �� �ʿ�� ����
		p = std::make_unique<char[]>(num);		// new - delete ¦�� ���ֱ� ����
		std::memcpy(p.get(), str, num);				// DMA�� �����ϴ�(Direct Memory Acces) -> cpu�� ���� ���� �̼� ������ ��ɾ�
	}

	STRING(const STRING& str) {
		p.release();
		num = str.num;
		p = std::make_unique<char[]>(num);
		std::memcpy(p.get(), str.p.get(), num);
	}
	size_t size() const {
		return num;
	}

	bool operator=(const STRING& str) {
		p.release();		// ���ο� string�� ������ �ϴ� p�� �ڿ��� �����ؾ� �Ѵٰ� ����
		num = str.num;
		p = std::make_unique<char[]>(num);
		std::memcpy(p.get(), str.p.get(), num);

		return true;
	}

	void append(const char* str) {
		num += strlen(str);
	}

private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	friend std::ostream& operator<<(std::ostream& os, const STRING& s) {

		for (int i = 0; i < s.num; ++i) {
			os << s.p[i];
		}

		return os;
	}

};

//----------------
int main()
//----------------
{
	STRING s{ "std::string�� ������ Ŭ����" };
	std::string s2{ "std::string�Դϴ�" };

	std::cout << "s �� �����ϴ� �ڿ��� ����Ʈ �� - " << s.size() << std::endl;

	s2.append(" �ݰ����ϴ�");
	s.append("�Դϴ�");

	std::cout << s << std::endl;
	std::cout << s2 << std::endl;
	//std::cout << t << std::endl;
	//save("����.cpp");
}
