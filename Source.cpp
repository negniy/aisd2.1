#include "BT.h"
#include "stdio.h"
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
using namespace std;

/*
� ������ ������ ���������� �������� ���� ����� �� ���������� ������������ ������, ��������� ����������� ���������� ������� ������������ ����������.
1. ����������� �����������, �������� ������������ � ���������� � ������ ������ ������ �������������� ������������ (��. �������� ����� default); ��� ���� �������� ����������� ������ ��������� �������� ������������ ������� (�. �. ������� ��������� ������ ������ �������� ����� ��, ����� � ����).
2. ������ ������ �� ������ �������� �� ����������, �� ������� ���������� �������.
3. � �������� ���� ������ ������ ��������� ����������� ��������� std::vector ��� std::list/std::forward_list (� ����������� �� ����, ������������ �� ������ ��� ������� ������ � ���������� ������������ ������).
4. ��������, ���������� � ������, ������ ���� ���������� ������������ � ������� range-based for loop (for(auto i: v) {}).� ���������, ��� ��������, ��� �� ������ ���������� ������ begin() � end() ��� ������ ������ � ���������� ��������������� ��������.
5. ���������� ��������� ��������� � ������� range - based for loop(for (auto i : v) { }).

*/

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
};

int menu_1()
{
	std::cout << "��������, ��� �� ������ ���������� ������:\n";
	std::cout << "������������� �����������: Enter\n������� � ������ ������������: 1\n�������� �� ������ �����������: 2\n������� � ��������� ���������: 3\n�������� �� ��������� ��������: 4\n��������� ����������� ���������� �����������: 5\n����� �� ����-��: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 27)) return key;
	}
}

int menu_2()
{
	std::cout << "���������: Enter\n����� �� ����-��: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 27)) return key;
	}
}

void print_tree(BT* tree) {
	tree->print();
}


int main() {
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "RUS");
		while (true) {
			system("cls");
			std::cout << "���� 1:\n";
			std::cout << "[1] - ������� ������(�� 2� �������� ����� ������������ ������������)\n";
			std::cout << "[2] - ������� ������� ������\n";
			std::cout << "[3] - ������� ������� � ������\n";
			std::cout << "[4] - ��������� �������\n";
			std::cout << "[5] - ���������� ������\n";
			std::cout << "[->] - ��������� ������\n";//77
			std::cout << "[<-] - ���������� ������\n";//75
			std::cout << "[ESC] - �����\n";

			BT* array[2];
			int size = 0;
			int cur = -1;

			if (cur < 0) {
				std::cout << "��� ��������\n";
			}
			else {
				if (cur >= size) {
					std::cout << "��������� ������������ ���������� ��������\n";
				}
				else print_tree(array[cur]);
			}

			int m = get_key();
			
			switch (m)
			{
			case 49:
				
				break;
			case 50:
				
				break;
			case 51:
				
				break;
			case 52:
				
				break;
			case 53:
				
				break;
			case 77:

				break;
			case 75:

				break;
			case 27:
				return 0;
				break;
			}
		}
	}
}