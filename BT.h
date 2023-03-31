#pragma once
#include <iostream>
#include <stdio.h>
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
	bool fobhod(BinTree* root, int key) const;
public:
	BT(int value);
	BT(const BinTree& obj);
	BinTree operator= (const BinTree& obj);
	void print() const;
	bool insert(int key);
	bool contains(int key) const;
	bool erase(int key);
	void delete_all(BinTree* r);
	~BT();
};

