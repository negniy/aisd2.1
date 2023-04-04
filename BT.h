#pragma once
#include <iostream>
#include <stdio.h>
#include "errors.h"
using namespace std;
/* ласс должен представл€ть собой двоичное дерево поиска.
—тандартные контейнеры в качестве полей класса не использовать.

 ласс должен предоставл€ть, как минимум, следующие функции:

конструктор копировани€; +
деструктор; +
оператор присваивани€; +
void print() Ц печать содержимого; +
bool insert(int key) Ц вставка элемента;
bool contains(int key) -  проверка наличи€ элемента;
bool erase(int key) Ц удаление элемента;
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

