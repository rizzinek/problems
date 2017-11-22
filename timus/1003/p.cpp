#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

struct interval
{
	int l;
	int r;
	interval(int left = 0, int right = 0)
	{
		l = left;
		r = right;
	}
};

struct node
{
	interval in;
	//0 / 1 - result of x % 2, 2 - unknown value
	int value;
	node* parent;
	vector<node> children;

	node(int l, int r, int v)
		: in(l, r), value(v), parent(nullptr)
	{}

	bool addNode(node n)
	{
		if(n.l < in.l || n.r > in.r)
			return false;

		return true;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int n = 0;

	while(true)
	{
		cin >> n;
		if(n == -1)
			break;
		node root(1, n, 2);
		cin >> n;
		int res = n;
		for(int i = 0; i < n; ++i)
		{
			int l = 0, r = 0;
			cin >> l >> r;
			string val;
			cin >> val;
			node newNode(l, r, val == "even" ? 0 : 1);
			if(!root.addNode(newNode))
			{
				res = i;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}
