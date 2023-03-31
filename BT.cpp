#include "BT.h"
#include <iostream>
#include <stdio.h>


void BT::obhod(BinTree* root) const
{
	if (root) {
		obhod(root->left);
		printf("%d", root->data);
		obhod(root->left);
	}
}

bool BT::fobhod(BinTree* root, int key) const
{
	if (root) {
		obhod(root->left);
		if (key == root->data) return true;
		obhod(root->left);
	}
}

BT::BT(int value)
{
	root = new BinTree(value, NULL, NULL);
}

BT::BT(const BinTree& obj)
{
	root = new BinTree(obj.data, obj.left, obj.right);
}

BinTree BT::operator=(const BinTree& obj)
{
	BinTree NewTree(obj.data, obj.left, obj.right);
	return NewTree;
}

void BT::print() const
{
	obhod(root);
}

bool BT::insert(int key)
{
	return false;
}

bool BT::contains(int key) const
{
	if (fobhod(root, key)) return true;
	return false;
}

bool BT::erase(int key)
{
	return false;
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
