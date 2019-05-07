#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

struct node
{
	int v;
	node *left, *right;
	node *parent;

	node() : v(0), left(nullptr), right(nullptr), parent(nullptr) {}

	void setLeftChild(node *child)
	{
		left = child;
		child->parent = this;
		//cout << v << " got left child " << child->v << "\n";
	}

	void setRightChild(node *child)
	{
		right = child;
		child->parent = this;
		//cout << v << " got right child " << child->v << "\n";
	}

	~node()
	{
		delete left;
		delete right;
	}
};

void build_tree(int idx, int *order, node* root)
{
	if(idx < 0)
		return;
	node *nd = new node();
	nd->v = order[idx];

	node *targetParent = root;

	while(true)
	{
		if(nd->v > targetParent->v)
		{
			if(targetParent->right != nullptr)
				targetParent = targetParent->right;
			else break;
		}
		else if(nd->v < targetParent->v)
		{
			if(targetParent->left != nullptr)
				targetParent = targetParent->left;
			else break;
		}
	}

	if(targetParent->v > nd->v)
		targetParent->setLeftChild(nd);
	else targetParent->setRightChild(nd);
}

void traverse_tree(node *nd)
{
	if(nd->right != nullptr)
		traverse_tree(nd->right);

	if(nd->left != nullptr)
		traverse_tree(nd->left);

	cout << nd->v << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int n;
	cin >> n;

	int *order = new int[n];

	for(int i = 0; i < n; ++i)
		cin >> order[i];

	node *root = new node();
	root->v = order[n - 1];

	for(int i = n - 2; i >= 0; --i)
		build_tree(i, order, root);

	traverse_tree(root);

	delete root;
	return 0;
}
