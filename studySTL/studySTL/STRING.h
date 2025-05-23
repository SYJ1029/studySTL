//-------------------------------------------------------------------------
// STRING.h - STL�� ������ �����ϱ� ���� class / std::string�� �����ϰ� �ۼ�
// 
// 2025. 4 . 10 - ����
// 2025. 4 . 14 - �̵��ǹ̷�(move semantics) ���� 
// 2025. 5 . 1	- operator==
// 2025. 5. 15	- begin(), end() ����
// 2025. 5 . 19 - rbegin(), rend() ����	-> class ���� ��
// 2025. 5 . 22	- �ݺ��ڰ� ����� ������ ���ϵ��� �Ѵ�.
// 2025. 5 . 22	- begin(), end()�� �ݺ��ڸ� �����ϵ��� �Ѵ�.
//-------------------------------------------------------------------------
#pragma once

#include <memory>
#include <iostream>

// iterator adaptor - �ݺ����� �������̽� ���� but �����δ� �ٸ���
// ǥ�� �ݺ��ڰ� �����ؾ��� �ټ����� Ÿ���� �����Ѵ�.


class STRING_Iterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	STRING_Iterator() {};
	STRING_Iterator(char* p) : p{ p } {};
	// �ݺ��ڶ�� �����ؾ��� �⺻������ �ִ�

	// �̰� �ǹ̸� ����� �ڵ��ؾ� �Ѵ�
	void operator++() {
		++p;
	}

	char operator*() const {
		return *p;
	}

	bool operator==(const STRING_Iterator& rhs) const {
		return p == rhs.p;
	}

	//sort�� �����ϵ��� �ʿ� ������ �߰�
	difference_type operator-(const STRING_Iterator& rhs) const {
		return p - rhs.p;
	}

	//difference_type operator+(const STRING_Iterator& rhs) const {
	//	return p + rhs.p;
	//}

	reference operator=(const STRING_Iterator& rhs) {
		p = rhs.p;
		return *p;
	}

	pointer operator--() {
		return --p;
	}



private:
	char* p;
};



class STRING_Reverse_Iterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	explicit STRING_Reverse_Iterator(char* p) : p{ p } {};
	// �ݺ��ڶ�� �����ؾ��� �⺻������ �ִ�
	void operator++() {
		--p;
	}

	char operator*() const {
		return *(p - 1);
	}

	bool operator==(const STRING_Reverse_Iterator& rhs) const {
		return p == rhs.p;
	}

private:
	char* p;
};



class STRING {
public:
	STRING();			// ��¥ special �Լ�
	~STRING();				// �̰� �ڵ��� ������ 1�� ����. �׳� �� ������ ���󰡰� ������ ������ ��


	STRING(const char* str);	// �׳� ��������

	// ��������ڿ� �����Ҵ翬���� 2025. 4. 10
	STRING(const STRING&);
	STRING& operator=(const STRING&);

	// �̵������ڿ� �̵��Ҵ翬���� 2025. 4. 14
	STRING(STRING&&);
	STRING& operator= (STRING&&);


	// �⺻������ ���� <		2025. 4. 14
	// ������ ������ ���� ���� - 2025. 5 .15
	bool operator<(const STRING&) const;
	// ���� ��ü���� �� ==		2025. 5. 1
	bool operator==(const STRING&) const;


	size_t size() const;

	//2025. 5. 15
	STRING_Iterator begin() const;
	STRING_Iterator end() const;

	STRING_Reverse_Iterator rbegin() const;
	STRING_Reverse_Iterator rend() const;
	
private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;						// 2025. 4. 10 ������ ���� ��ü ������ȣ

	friend std::ostream& operator<<(std::ostream& os, const STRING&);
	friend std::istream& operator>>(std::istream& is, STRING&);
	
	static size_t gid;				// 2025. 4. 10 ������ȣ ����
};