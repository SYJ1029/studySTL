#include <iostream>



int main() {
	STRING s{ "2025년 6월 19일 기말시험" };
	cout << s << endl;
	STRING t;
	cin >> t;
	cout << t << endl;
	// "2025년 6월 19일 기말시험" 입력
   // "2025년" 만 출력됨
}