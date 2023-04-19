#pragma once
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
#include "errors.h"
using namespace std;
/*����� ������ ������������ ����� �������� ������ ������.
����������� ���������� � �������� ����� ������ �� ������������.

����� ������ �������������, ��� �������, ��������� �������:

����������� �����������; +
����������; +
�������� ������������; +
void print() � ������ �����������; +
bool insert(int key) � ������� ��������;
bool contains(int key) -  �������� ������� ��������;
bool erase(int key) � �������� ��������;
*/

struct BinTree
{
	int data;
	BinTree* left;
	BinTree* right;

	BinTree(int data, BinTree* left, BinTree* right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};


class BT
{ 
private:
	BinTree* root;
	void obhod(BinTree* root, int level) const;
	BinTree* fobhod(BinTree* root, int key) const;
	//int** get_items(BinTree* r) const;
	void counter(BinTree* r, int* i);
	void get_item(BinTree* r, int** res, int* i) const;
public:
	BT(int value = 10);
	BinTree* create_as(const BinTree* copy) const;
	BT(const BinTree& obj);
	BinTree operator= (const BinTree& obj);
	void print() const;
	bool insert(int key);
	bool contains(int key) const;
	int power();
	void get_items(int** result) const;
	BinTree* find_prev(BinTree* tree, BinTree* elem) const;
	bool erase(int key);
	void delete_all(BinTree* r);
	~BT();
};

