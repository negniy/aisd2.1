#include "BT.h"
#include "errors.h"
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

int check() {
	int a = 0;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n�������� ��������\n";
	}
	return a;
}

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

void peresech(BT* tree1, BT* tree2) {

	int* array = tree1->get_items();
	int size = 0;
	if (array != NULL) {
		size = sizeof(array) / sizeof(array[0]);
	}
	else {
		cout << "����������� ����� ������� ���������\n";
		return;
	}
	cout << "����������� �����:\n";
	for (int i = 0; i < size; i++) {
		if(tree2->contains(array[i])) cout << array[i] << " ";
	}
}

void raznost(BT* tree1, BT* tree2) {

	int* array = tree1->get_items();
	int size = 0;
	if (array != NULL) {
		size = sizeof(array) / sizeof(array[0]);
	}
	else {
		cout << "�������� �����:\n";
		print_tree(tree1);
		return;
	}
	cout << "�������� �����:\n";
	for (int i = 0; i < size; i++) {
		if (!tree2->contains(array[i])) cout << array[i] << " ";
	}
}

void task(BT* tree1, BT* tree2) {

	system("cls");
	cout << "������ ������: \n";
	print_tree(tree1);
	cout << "������ ������: \n";
	print_tree(tree2);

	std::cout << "�������� ��������:\n";
	std::cout << "[1] - ����� �����������\n";
	std::cout << "[2] - ����� ��������\n";

	int m = get_key();

	switch (m)
	{
	case 49:
		peresech(tree1, tree2);
		break;
	case 50:
		std::cout << "�������� ��������:\n";
		std::cout << "[1] - ������� �� ������� ��������� ������\n";
		std::cout << "[2] - ������� �� ������� ��������� ������\n";
		int m1 = get_key();
		if (m1 == 49) raznost(tree1, tree2);
		if (m1 == 50) raznost(tree2, tree1);
		break;
	}
	get_key();
}

bool delete_item(BT* tree) {

	system("cls");
	cout << "������� �������, ������� ������ ������� � ������: \n";
	bool flag;
	int i_v = check();

	while (tree->contains(i_v) == false)
	{
		cout << "������ �������� ��� � ������\n";
		i_v = check();
	}

	flag = tree->erase(i_v);
	return flag;
}

void delete_tree(BT* tree) {

	delete tree;
}

BT* create_tree() {
	system("cls");
	cout << "������� ���-�� ��������� � ������: \n";
	int n = check();
	while (n < 1)
	{
		cout << "�������� ��������\n";
		n = check();
	}

	cout << "������� �������� �����: \n";
	int r_v = check();

	BT* tree = new BT(r_v);

	for (int i = 0; i < n - 1; i++)
	{
		cout << "������� ��������:\n" ;
		int i_v = check();
		while (tree->insert(i_v) == false)
		{
			cout << "�������� ��� ����������, ��������� ����\n" ;
			i_v = check();
		}
	}
	return tree;

}

void add_item(BT* tree) {

	system("cls");
	cout << "������� �������, ������� ������ �������� � ������: \n";

	int i_v = check();

	while (!tree->insert(i_v)) {

		cout << "����� ������� ��� ���� � ������, ��������� �������\n";
		int i_v = check();

	}

	cout << "������� ������� �������� � ������\n";
}

int main() {
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "RUS");

		BT** array = new BT * [2];
		int size = 0;
		int cur = -1;

		while (true) {

			system("cls");
			std::cout << "���� 1:\n";
			std::cout << "[1] - ������� ������(�� 2� �������� ����� ������������ ������������)\n";
			std::cout << "[2] - �������� ������� � ������\n";
			std::cout << "[3] - ������� ������� ������\n";
			std::cout << "[4] - ������� ������� � ������\n";
			std::cout << "[5] - ��������� �������\n";
			std::cout << "[6] - ���������� ������\n";
			std::cout << "[->] - ��������� ������\n";//77
			std::cout << "[<-] - ���������� ������\n";//75
			std::cout << "[ESC] - �����\n";

			if (size == 0) {
				std::cout << "��� ��������\n";
			}
			else {
				if (cur >= size) {
					cur--;
				}
				else print_tree(array[cur]);
			}

			int m = get_key();
			
			switch (m)
			{
			case 49:
				if (size == 2) cout << "��������� ������������ ���������� ��������\n";
				else { 
					size++;
					cur++;
					array[cur] = create_tree();
				}
				break;
			case 50:
				if (cur > -1 && cur < 2) {
					add_item(array[cur]);
				}
				else cout << "���������� ����������\n"; get_key();
				break;
			case 51:
				if (cur > -1 && cur < 2) {
					delete_tree(array[cur]);
					array[cur] = NULL;
					if (cur == 0) {
						array[cur] = array[cur + 1];
						array[cur + 1] = NULL;
					}
					else cur--;
					size--;
				}
				else cout << "�������� ����������\n"; get_key();
				break;
			case 52:
				if (cur > -1 && cur < 2) {
					try {
						if(delete_item(array[cur])) cout << "�������� ������ �������\n";
						else cout << "��������� ������\n";
					}
					catch (error smth_bad) {
						cout << "������ ���� �������, ��� ��� ����� ������\n";
						get_key();
						array[cur] = NULL;
						if (cur == 0) {
							array[cur] = array[cur + 1];
							array[cur + 1] = NULL;
						}
						else cur--;
						size--;
					}
				}
				else cout << "�������� ����������\n"; get_key();
				break;
			case 53:
				task(array[0], array[1]);
				break;
			case 54:
				menu_2();
				break;
			case 77:
				if (cur < 1) cur++;
				break;
			case 75:
				if(cur > 0) cur--;
				break;
			case 27:
				for (int i = 0; i < size; i++) {
					delete[] array[i];
				}
				delete[] array;
				return 0;
			}

		}
	}
}