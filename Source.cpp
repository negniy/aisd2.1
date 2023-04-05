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
#include <fstream>
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
	system("cls");
	std::cout << "���� 2:\n";
	std::cout << "[1] - ������� ������(�� 2� �������� ����� ������������ ������������)\n";
	std::cout << "[2] - �������� ������� � ������\n";
	std::cout << "[3] - ������� ������� ������\n";
	std::cout << "[4] - ������� ������� � ������\n";
	std::cout << "[5] - ��������� �������\n";
	std::cout << "[6] - ���������� ������\n";
	std::cout << "[->] - ��������� ������\n";//77
	std::cout << "[<-] - ���������� ������\n";//75
	std::cout << "[ESC] - �����\n";
}

void print_tree(BT* tree) {
	tree->print();
}

void peresech(BT* tree1, BT* tree2) {

	int size1 = tree1->power();
	int size2 = tree2->power();
	int* result = new int[size1];
	tree1->get_items(&result);
	
	if(size1 == 0 || size2 == 0) {
		cout << "����������� ����� ������� ���������\n";
		return;
	}

	cout << "����������� �����:\n";
	for (int i = 0; i < size1; i++) {
		if(tree2->contains(result[i])) cout << result[i] << " ";
	}
}

void raznost(BT* tree1, BT* tree2) {

	int size = tree1->power();
	int* result = new int[size];
	tree1->get_items(&result);

	if (size == 0) {
		cout << "�������� ����� ������� ���������\n";
		return;
	}

	cout << "�������� �����:\n";
	for (int i = 0; i < size; i++) {
		if (!tree2->contains(result[i])) cout << result[i] << " ";
	}
}

void task(BT* tree1, BT* tree2) {

	system("cls");
	cout << "������ ������: \n";
	print_tree(tree1);
	cout << "\n������ ������: \n";
	print_tree(tree2);

	std::cout << "\n�������� ��������:\n";
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

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

void time_of_creation(int size)
{
	clock_t start, end;
	double average_time = 0;
	int number_of_points = 100;

	std::ofstream out("Node_fill.txt", std::ios::app);
	for (int i = 0; i < number_of_points; i += 1)
	{
		BT tmp;
		start = clock();
		for (int j = 0; j < size; j++) {
			int key = int(lcg());
			while (tmp.contains(key) == true) {
				key = int(lcg());
			}
			tmp.insert(key);
		}
		end = clock();

		double this_time = (end - start) / (CLOCKS_PER_SEC);
		average_time += this_time;

		if (out.is_open())
		{
			out << size << ";" << this_time << std::endl;
		}
	}
	out.close();

	average_time = average_time/number_of_points;
	cout << number_of_points << "������� �������� ������ � " << size <<" ���������� ���������\n";
	cout << "������� ����� ���������: "<< average_time<<"\n";
	get_key();
}

void time_of_searching(int size)
{
	clock_t start, end;
	BT obj;
	double average_time = 0;
	int number_of_points = 1000;

	for (int i = 0; i < size; i++) {
		int key = int(lcg());
		while (obj.contains(key) == true) {
			key = int(lcg());
		}
		obj.insert(key);
	}

	std::ofstream out("Node_search.txt", std::ios::app);

	for (int i = 0; i < number_of_points; i++)
	{
		start = clock();
		obj.contains(int(lcg()));
		end = clock();

		double this_time = (end - start) / (CLOCKS_PER_SEC);
		average_time += this_time;

		if (out.is_open())
		{
			out << size << ";" << this_time << std::endl;
		}

	}
	out.close();

	average_time = average_time / number_of_points;
	cout << number_of_points << "������� ������ � ������ � " << size << " ���������� ���������\n";
	cout << "������� ����� ���������: " << average_time << "\n";
	get_key();
}

void time_of_insert(int size) {

	clock_t start, end;
	double average_time = 0;
	int number_of_points = 1000;

	std::ofstream out("Node_insert.txt", std::ios::app);
	for (int i = 0; i < number_of_points; i++)
	{
		BT obj;
		for (int j = 0; j < size; j++) {
			int key = int(lcg());
			while (obj.contains(key) == true) {
				key = int(lcg());
			}
			obj.insert(key);
		}
		int key = int(lcg());
		start = clock();
		obj.insert(key);
		end = clock();
		double this_time = (end - start) / (CLOCKS_PER_SEC);
		average_time += this_time;
		
		if (out.is_open())
		{
			out << size << ";" << this_time << std::endl;
		}
		
	}
	out.close();
	average_time = average_time / number_of_points;
	cout << number_of_points << "������� ���������� � ������ � " << size << " ����������\n";
	cout << "������� ����� ���������: " << average_time << "\n";
	get_key();
}

void time_of_erace(int size) {
	clock_t start, end;
	double average_time = 0;
	int number_of_points = 1000;

	std::ofstream out("Node_erase.txt", std::ios::app);
	for (int i = 0; i < number_of_points; i++)
	{
		BT obj;
		for (int j = 0; j < size; j++) {
			int key = int(lcg());
			while (obj.contains(key) == true) {
				key = int(lcg());
			}
			obj.insert(key);
		}
		int key = int(lcg());
		start = clock();
		obj.erase(key);
		end = clock();

		double this_time = (end - start) / (CLOCKS_PER_SEC);
		average_time += this_time;

		if (out.is_open())
		{
			out << size << ";" << this_time << std::endl;
		}
	}
	out.close();
	average_time = average_time / number_of_points;
	cout << number_of_points << "������� �������� �� ������ � " << size << " ����������\n";
	cout << "������� ����� ���������: " << average_time << "\n";
	get_key();
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
				if (cur > -1 && cur < 2) task(array[0], array[1]);
				else cout << "��� ��������\n"; get_key();
				break;
			case 54:
				menu_1();
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