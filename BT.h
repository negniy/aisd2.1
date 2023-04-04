#pragma once
#include <iostream>
#include <stdio.h>
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
	void obhod(BinTree* root) const;
	BinTree* fobhod(BinTree* root, int key) const;
public:
	BT(int value);
	BinTree* create_as(const BinTree* copy) const;
	BT(const BinTree& obj);
	BinTree operator= (const BinTree& obj);
	void print() const;
	bool insert(int key);
	bool contains(int key) const;
	BinTree* find_prev(BinTree* tree, BinTree* elem) const;
	bool erase(int key);
	void delete_all(BinTree* r);
	~BT();
};

