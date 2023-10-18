#include <iostream>
#include <Windows.h>
#include "..\Set\set.h"

#define USE_SET

#ifdef USE_SET
void eratosthenes_alghoritm(int n) {
	std::cout << "---===������ ���������� ����� ���������===---" << std::endl;
	TSet U(n);
	U = ~U;
	std::cout << U;
}
#else
void eratosthenes_alghoritm(int n) {
	// �������� ������ ���������� � �������� ������
}
#endif



const std::string menu = "����:\n\t1) ������ ��������� �;\n\t2) ������ ��������� B;\n\t3) ����� ����������� �������� A + B;\n\t4) ����� �������� ��������� A � B;\n\t5) ����� ����������� �������� A * B;\n\t6) ����� ���������� ���������;\n\t\ta.����� ���������� A;\n\t\tb.����� ���������� B;\n\t7) ��������� ���������������� ������.\n\t8) �����.\n\t��� ����: ";

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool progflag = 1;
	TSet A(1);
	TSet B(1);
	while (progflag) {
		std::cout << menu;
		int mswitch;
		std::cin >> mswitch;
		system("cls");
		switch (mswitch) {
		case 1:
		{
			int n; std::cout << "������� �������� ��������� A: "; std::cin >> n;
			TSet TMP(n);
			std::cout << "������ ����: "; std::cin >> TMP;
			for(int i = 1; i < n;i++){
				std::cin >> TMP;
			}
			A = TMP;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			int n; std::cout << "������� �������� ��������� B: "; std::cin >> n;
			TSet TMP(n);
			std::cout << "������ ����: "; std::cin >> TMP;
			for (int i = 1; i < n; i++) {
				std::cin >> TMP;
			}
			B = TMP;
			std::cout << B;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			TSet TMP(A + B);
			std::cout << TMP;
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			TSet TMP(A * (~B));
			std::cout << TMP;
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			TSet TMP(A * B);
			std::cout << TMP;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			std::cout << "���������� �: " << ~A;
			std::cout << "���������� B: " << ~B;
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			int n;
			std::cout << "������� N: ";
			std::cin >> n;
			eratosthenes_alghoritm(n);
			system("pause");
			system("cls");
			break;
		}
		case 8:
			progflag = 0;
			break;
		}
	}
}