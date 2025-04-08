//-----------------------------------------------------------
// save.cpp - ���б⸦ �� �����ϴ� �Լ�
//													2025.3.13
//-----------------------------------------------------------


#include <string_view>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>

//------------------------------------
void save(std::string_view filename)
//------------------------------------
{
	// const qualifier�� ����� �Ű������� �б��� �������� ����
	// --> �� ��ġ�� ū string�̾�� �ұ�?
	//  string_view�� �� ����
	// -> Release ���� ������ c++14�� ����ϰ� �־���

	// 1. ���ڷ� ���޵� filename�� �б���� ����
	std::ifstream filein{ filename.data() }; // RAII -> �ڿ��� �̿��ؼ� �����ϱ�

	if (not filein) //�������� ���� not ���� 
	{
		std::cout << filename << "�� �� �� �����ϴ�" << std::endl;
		exit(202503210); // ���� return
	}

	// 1.5) �����ߴٴ� ����� ȭ�鿡 ǥ��
	std::cout << filename << "(" << std::filesystem::file_size(filename)
		<< "bytes) save" << std::endl;



	// 2. ������� ������ ������ [�����̱� ����] ����
	std::ofstream fileout{ "2025 1�б� stl �� 910��910 �������� 5���� 2��.txt", std::ios::app };

	using namespace std::chrono_literals;
	// �ð��� �������
	auto now = std::chrono::system_clock::now();	// epoch�� ���� ����� tick ���� ��´�
	auto utc = std::chrono::system_clock::to_time_t(now); // utc
	auto lt = std::localtime(&utc); // �����ð����� ����

	auto old = fileout.imbue(std::locale("ko_KR")); // ��� ��Ʈ���� �ѱ������� �ٲٴ� '�߿���'��ȭ
	// ������ ���� ������ ���̺� �ؾ���


	fileout << '\n' << '\n';
	fileout << "==================================" << '\n';
	fileout << "������ �ð�: " << std::put_time(lt, "%c %A") << '\n';
	fileout << "==================================" << '\n';
	fileout << '\n';
	// {}�� uniform initializer ��� �̸� 
	// std::ios::app �� �����̱� ������� �����ϴ� �ڵ�

	fileout.imbue(old); // ���󺹱�

	// 3. ����� ������ �о ������ ���Ͽ� �����̱�


	std::vector<char> v(std::filesystem::file_size(filename));
	// vector�� ()�� ����� �� �´� ����Ʈ Ȯ���� �����ϴ�
	std::copy(std::istreambuf_iterator{ filein }, {}, std::ostreambuf_iterator{ fileout });

}