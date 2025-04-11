//-------------------------------------------------------------------------
// STRING.h - STL�� ������ �����ϱ� ���� class / std::string�� �����ϰ� �ۼ�
// 
// 2025. 4 . 10 - ����
//-------------------------------------------------------------------------
#pragma once

#include <memory>
#include <iostream>

class STRING {
public:
	STRING();			// ��¥ special �Լ�
	~STRING();				// �̰� �ڵ��� ������ 1�� ����. �׳� �� ������ ���󰡰� ������ ������ ��


	STRING(const char* str);	// �׳� ��������

	// ��������ڿ� �����Ҵ翬���� 2025. 4. 10
	STRING(const STRING&);
	STRING& operator=(const STRING&);
	size_t size() const;
	
private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;						// 2025. 4. 10 ������ ���� ��ü ������ȣ

	friend std::ostream& operator<<(std::ostream& os, const STRING& s);
	
	static size_t gid;				// 2025. 4. 10 ������ȣ ����
};