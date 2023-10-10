#include <iostream>
#include <Windows.h>
#include "set.h"

#define USE_SET

#ifdef USE_SET
void eratosthenes_alghoritm () {
	// алгоритм решета Эратосфена с множествами
}
#else
void eratosthenes_alghoritm() {
	// алгоритм решета Эратосфена с битовыми полями
}
#endif



const std::string menu = "МЕНЮ:\n\t1) Задать множество А;\n\t2) Задать множество B;\n\t3) Найти объединение множеств A + B;\n\t4) Найти разность множества A – B;\n\t5) Найти пересечение множеств A * B;\n\t6) Найти дополнение множества;\n\t\ta.Найти дополнение A;\n\t\tb.Найти дополнение B;\n\t7) Запустить демонстрационный пример.\n\t8) Выход.\n\tВаш ввод: ";

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
				int n; std::cout << "Введите мощность множества A: "; std::cin >> n;
				TSet TMP(n);
				std::cout << "Задать поле: "; std::cin >> TMP;
				A = TMP;
				std::cout << A;
				system("pause");
				system("cls");
				break;
			}
		case 2:
			{
				int n; std::cout << "Введите мощность множества B: "; std::cin >> n;
				TSet TMP(n);
				std::cout << "Задать поле: "; std::cin >> TMP;
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
				std::cout << "Дополнение А: " << ~A;
				std::cout << "Дополнение B: " << ~B;
				system("pause");
				system("cls");
				break;
			}
		case 7:
			{
				break;
			}
		case 8:
			progflag = 0;
			break;
		}
	}
}