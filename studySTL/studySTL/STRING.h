//-------------------------------------------------------------------------
// STRING.h - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작섣
// 
// 2025. 4 . 10 - 시작
//-------------------------------------------------------------------------
#pragma once

#include <memory>
#include <iostream>

class STRING {
public:
	STRING();			// 진짜 special 함수
	~STRING();				// 이걸 코딩할 이유가 1도 없다. 그냥 그 과정을 따라가고 싶으니 생성한 것


	STRING(const char* str);	// 그냥 생성자임

	// 복사생성자와 복사할당연산자 2025. 4. 10
	STRING(const STRING&);
	STRING& operator=(const STRING&);
	size_t size() const;
	
private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;						// 2025. 4. 10 관찰을 위한 객체 고유번호

	friend std::ostream& operator<<(std::ostream& os, const STRING& s);
	
	static size_t gid;				// 2025. 4. 10 고유번호 생성
};