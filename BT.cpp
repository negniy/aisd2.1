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


/*int** BT::get_items(BinTree* r) const
{
	if (r) {

		int size1 = 0;
		int size2 = 0;
		int** res_l = NULL;
		int** res_r = NULL;
		get_items(r->left);
		get_items(r->right);

		if (res_l != NULL) {
			size1 = sizeof(res_l) / sizeof(res_l[0]);
		}
		if (res_r != NULL) {
			size2 = sizeof(res_r) / sizeof(res_r[0]);
		}

		int* res = new int[size1 + size2 + 1];
		res[0] = r->data;

		if (res_l != NULL) {
			for (int i = 0; i < size1; i++) {
				res[i + 1] = res_l[i];
			}
			delete[] res_l;
		}
		
		if (res_r != NULL) {
			for (int i = 0; i < size2; i++) {
				res[i + 1 + size1] = res_r[i];
			}
			delete[] res_r;
		}
	}
}*/



void BT::obhod(BinTree* r, int level) const
{
	if (r)
	{
		obhod(r->right, level + 1);
		for (int i = 0; i < level; i++) cout << "      ";
		cout << r->data << endl;
		obhod(r->left, level + 1);
	}
}

BinTree* BT::fobhod(BinTree* r, int key) const
{
	if (r) {
		if (key == r->data) return r;
		BinTree* a = fobhod(r->left, key);
		BinTree* b = fobhod(r->right, key);
		if (a != NULL) return a;
		else {
			if (b != NULL) return b;
			else return NULL;
		}
	}
	return NULL;
}

BT::BT(int value)
{
	root = new BinTree(value, NULL, NULL);
}

BinTree* BT::create_as(const BinTree* copy) const
{
	BinTree* nov = NULL;
	if (copy != NULL)
	{
		nov = new BinTree(copy->data, NULL, NULL);

		if (copy->left != NULL)
		{
			nov->left = create_as(copy->left);
		}
		else nov->left = NULL;

		if (copy->right != NULL)
		{
			nov->right = create_as(copy->right);
		}
		else
			nov->right = NULL;
	}
	return nov;
}

BT::BT(const BinTree& obj)
{
	root = new BinTree(obj.data, NULL, NULL);
		if (obj.left != NULL)
		{
			root->left = create_as(obj.left);
		}
		else
			root->left = NULL;

		if (obj.right != NULL)
		{
			root->right = create_as(obj.right);
		}
		else
			root->right = NULL;
	
}

BinTree BT::operator=(const BinTree& obj)
{
	BinTree* new_tree = new BinTree(obj.data, NULL, NULL);
	if (obj.left != NULL)
	{
		new_tree->left = create_as(obj.left);
	}
	else
		new_tree->left = NULL;

	if (obj.right != NULL)
	{
		new_tree->right = create_as(obj.right);
	}
	else
		new_tree->right = NULL;
	return *(new_tree);
}

void BT::print() const
{
	obhod(root, 3);
}

bool BT::insert(int key)
{
	BinTree* tmp = root;
	while (tmp)
	{
		if (key < tmp->data)
		{
			if (tmp->left == NULL)
			{
				tmp->left = new BinTree(key, NULL, NULL);
				return true;
			}
			else
				tmp = tmp->left;
		}
		if (key > tmp->data)
		{
			if (tmp->right == NULL)
			{
				tmp->right = new BinTree(key, NULL, NULL);
				return true;
			}
			else
				tmp = tmp->right;
		}
		if (key == tmp->data)
		{
			return false;
		}
	}
}

bool BT::contains(int key) const
{
	if (fobhod(root, key)) return true;
	return false;
}

void BT::counter(BinTree* r, int* i) {
	if (r) {
		counter(r->left, i);
		counter(r->right, i);
		(*i)++;
	}
}

int BT::power() {
	int i = 0;
	counter(root, &i);
	return i;
}

void BT::get_item(BinTree* r, int** res, int* i) const {
	if (r) {
		(*res)[*i] = r->data;
		(*i)++;
		get_item(r->left, res, i);
		get_item(r->right, res, i);
	}
}

void BT::get_items(int** res) const
{
	int i = 0;
	get_item(root, res, &i);
}

BinTree* BT::find_prev(BinTree* r, BinTree* elem) const
{
	if (r) {
		if (elem == r->left || elem == r->right) return r;
		BinTree* a = find_prev(r->left, elem);
		BinTree* b = find_prev(r->right, elem);
		if (a != NULL) return a;
		else {
			if (b != NULL) return b;
			else return NULL;
		}
	}
	return NULL;
}

bool BT::erase(int key)
{
	BinTree* p = fobhod(root, key);

	if (p == NULL) return false;

	if (p == root && root->left==NULL && root->right==NULL) {
		delete root;
		throw error("ÁÅÄÀ, ÌÛ ÓÄÀËÈËÈ ÄÅÐÅÂÎ!");
	}

	if (p->left != NULL && p->right != NULL)
	{
		BinTree* max_l = p->left;
		while (max_l->right)
		{
			max_l = max_l->right;
		}
		int val = max_l->data;
		erase(val);
		p->data = val;
		return true;
	}

	if (p->left == NULL && p->right == NULL)
	{
		BinTree* tmp = find_prev(root, p);
		if (tmp->left == p) {
			tmp->left = NULL;
		}
		if (tmp->right == p) {
			tmp->right = NULL;
		}
		delete p;
		return true;
	}

	if (p->left != NULL || p->right != NULL)
	{
		BinTree* tmp = find_prev(root, p);
		if (!tmp) {
			if (p->left != NULL) {
				root = p->left;
			}
			else {
				root = p->right;
			}
		}
		else {
			if (p->left != NULL) {
				if(p==tmp->left) tmp->left = p->left;
				else tmp->right = p->left;
			}
			else {
				if (p == tmp->left) tmp->left = p->right;
				else tmp->right = p->right;
			}

		}
		delete p;
		return true;
	}
		
}

void BT::delete_all(BinTree* r)
{
	if (r->left != NULL) delete_all(r->left);
	if (r->right != NULL) delete_all(r->right);
	delete r;
	r = NULL;
}

BT::~BT()
{
	delete_all(root);
}
