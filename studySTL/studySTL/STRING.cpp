//-------------------------------------------------------------------------
// STRING.cpp - STL�� ������ �����ϱ� ���� class / std::string�� �����ϰ� �ۼ�
// 
// 2025. 4 . 10 - ����
// 2025. 4 . 10 - �������/�����Ҵ翬����, ����� �Լ��� ���� ����
// 2025. 4 . 14 - ������ �����ϵ��� ���������� ���
// 2025. 4 . 14 - �̵��ǹ̷�(move semantics) ���� 
// 2025. 5 . 1	- operator==
// 2025. 5 . 15	- std::stringó�� ������ �����ϵ��� ����
// 2025. 5 . 15	- begin(), end()
// 2025. 5 . 19 - rbegin(), rend()
//-------------------------------------------------------------------------

#include <memory>	// ��� ���� �ߺ� ���� ����
#include <print>
#include <algorithm>
#include "STRING.h"

size_t STRING::gid{ 0 };				// 2025. 4. 10 ������ȣ ����

bool ����{ false };

STRING::STRING()
	: id{ ++gid }
{
	//std::println("[{:6}]", id);
	if (����) {
		std::println("[{:6}] {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, "����Ʈ ����", num, (void*)this, (void*)p.get());
	}

	// ������ ���� �����ʹ� Ư�� �ڷ����� ���ӵǹǷ� ����� ������ �Ұ����ϴ�
}

STRING::~STRING()
{
	if (����) {
		std::println("[{:6}] {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, "�Ҹ���", num, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* str)
	: num{ strlen(str) }, id{ ++gid }
{
	p.release();	// �ڿ��� �ִٸ� ���������� ���� �ÿ� �̷��� �� �ʿ�� ����
	p = std::make_unique<char[]>(num);		// new - delete ¦�� ���ֱ� ����
	std::memcpy(p.get(), str, num);				// DMA�� �����ϴ�(Direct Memory Acces) -> cpu�� ���� ���� �̼� ������ ��ɾ�

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, "������(char*)", num, (void*)this, (void*)p.get());
	}
};

// ��������ڿ� �����Ҵ翬����
STRING::STRING(const STRING& other)
	: num{ other.num }, id{ ++gid }
{
	//*this = other;			// ���� ������ �Ҵ��� �̿��϶�

	num = other.num;
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, "���� ������(char*)", num, (void*)this, (void*)p.get());
	}

}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	p.release();		// �����͸� ��ȯ�ؼ� �̿��� �� ����
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, " copy opertator=", num, (void*)this, (void*)p.get());
	}
	return *this;
}


STRING::STRING(STRING&& other)
	: num{ other.num }, id{ ++gid }
{
	p.reset(other.p.release());

	other.num = 0;		// �� �ص� �ȴ�
	// sort�� ����� ��������� ���� �ʱ� ������ �ʿ䰡 ����

	if (����) {
		std::println("[{:6}] {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, "�̵� ������", num, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	p.release();			//���� Ȯ���� �ڿ��� ����
	p.reset(other.p.release());

	other.num = 0;		// �� �ص� �ȴ�
	if (����) {
		std::println("[{:6}] {:<16} �ڿ���: {:4}, �ּ�: {:16} �ڿ��� �ּ�: {:16}",
			id, "mover operator=", num, (void*)this, (void*)p.get());
	}
	return *this;
}



size_t STRING::size() const
{
	return num;
}

STRING_Iterator STRING::begin() const
{
	return STRING_Iterator(&p[0]);			// return p.get();
}

STRING_Iterator STRING::end() const
{
	return STRING_Iterator(&p[num]);
}

STRING_Reverse_Iterator STRING::rbegin() const
{
	return STRING_Reverse_Iterator(&p[num]);
}
STRING_Reverse_Iterator STRING::rend() const
{

	return STRING_Reverse_Iterator(&p[0]);
}


std::ostream& operator<<(std::ostream& os, const STRING& s)
{

	for (int i = 0; i < s.num; ++i) {
		os << s.p[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, STRING& s)
{
	std::string str;
	is >> str;

	s.num = str.size();
	s.p.release();
	s.p = std::make_unique<char[]>(s.num);
	memcpy(s.p.get(), str.data(), s.num);

	return is;
}

// �⺻������ ���� <		2025. 4. 14
// ���������� ����			2025. 5 .15
bool STRING::operator<(const STRING& rhs) const
{
	return std::lexicographical_compare(p.get(), p.get() + num, &rhs.p[0], &rhs.p[num]);
}


// ���� ��ü���� �� ==		2025. 5. 1
bool STRING::operator==(const STRING& rhs) const
{
	return std::equal(p.get(), p.get() + num, &rhs.p[0], &rhs.p[num]);
}

