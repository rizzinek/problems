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
	uint64_t v;
	node* next;
	node(uint64_t _v): v(_v), next(nullptr) {}
};

bool addNode(node* root, uint64_t v)
{
	node* parent = root;
	node* n = new node(v);
	while(parent->next != nullptr && !(parent->v > v && parent->next->v <= v))
		parent = parent->next;
	n->next = parent->next;
	parent->next = n;

	return (n->next != nullptr && v == n->next->v || v == parent->v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	node* root = nullptr;
	for(int i = 0; i < 3; ++i)
	{
		uint64_t x;
		cin >> x;
		node *n = new node(x);
		if(root == nullptr)
		{
			root = n;
			continue;
		}
		if(x > root->v)
		{
			n->next = root;
			root = n;
		}
		else if(addNode(root, x))
		{
			cout << "1\n";
			return 0;
		}
	}
	//for(node* curNode = root; curNode != nullptr; curNode = curNode->next)
	//	cout << curNode->v << " ";
	uint64_t steps = 0;
	while(true)
	{
		++steps;
		node* minNode = root;
		uint64_t minDelta = -1;
		for(node* curNode = root; curNode->next != nullptr; curNode = curNode->next)
		{
			uint64_t delta = curNode->v - curNode->next->v;
			if(delta < minDelta)
			{
				minDelta = delta;
				minNode = curNode;
			}
		}
		if(addNode(minNode, minDelta))
		{
			cout << steps + 1 << "\n";
			return 0;
		}
	}
	return 0;
}
