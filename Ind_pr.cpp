#define _CRT_SECURE_NO_WARNINGS
#include "library.h"
using namespace std;

void First_way()
{
	Input_0();
	Choice_N();
}

void Second_way()
{
	int com;
	do
	{
		cout << "Ввести квадрат вручную: нажмите 1\n Считать квадрат из файла: нажмите 2\n Выход: нажмите 0\n"; cin >> com;
		switch (com)
		{
		case 0: {cout << "Выход" << endl; break; }
		case 1: {Input();  break; }
		case 2: {File(); break; }
		default: {cout << "error" << endl; break; }
		}
	} while ((com != 0) && (com != 1) && (com != 2));
	Check_Summ();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int k, t;
	do
	{
		cout << "Выберите режим работы с программой. \n Вычисление магического квадрата: нажмите 1\n Проверка квадрата, введенного пользователем: нажмите 2\n Выход: нажмите 0\n"; cin >> k;
		switch (k)
		{
		case 0: {cout << "Выход" << endl; break; }
		case 1: {First_way();  break; }
		case 2: {Second_way(); break; }
		default: {cout << "error" << endl; break; }
		}
	} while ((k != 0) && (k != 1) && (k != 2));

	do
	{
		cout << "Вывести квадрат на экран: нажмите 1\n Сохранить квадрат в виде файла: нажмите 2\n Выход: нажмите 0\n"; cin >> t;
		switch (t)
		{
		case 0: {cout << "Выход" << endl; break; }
		case 1: {Output();  break; }
		case 2: {InFile(); break; }
		default: {cout << "error" << endl; break; }
		}
	} while (t != 0);

	system("pause");
	return 0;
}
