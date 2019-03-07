#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int parent[100000];

int find_parent(int idx)
{
	int res = idx;
	if(idx != parent[idx])
		res = find_parent(parent[idx]);
	parent[idx] = res;
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int *left = new int[m];
	int *right = new int[m];
	bool *isCut = new bool[m];
	for(int i = 0; i < n; ++i)
		parent[i] = i;
	for(int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		left[i] = x - 1;
		right[i] = y - 1;
		isCut[i] = false;
	}
	int q;
	cin >> q;
	int *cutEdges = new int[q];
	for(int i = 0; i < q; ++i)
	{
		int idx;
		cin >> idx;
		cutEdges[i] = idx - 1;
		isCut[idx - 1] = true;
	}

	int initialNumPieces = n;
	//first add uncut edges
	for(int i = 0; i < m; ++i)
	{
		if(isCut[i])
			continue;
		int lParent = find_parent(left[i]);
		int rParent = find_parent(right[i]);
		if(lParent != rParent)
		{
			--initialNumPieces;
			parent[rParent] = lParent;
		}
	}

	int *res = new int[q];
	res[0] = initialNumPieces;
	for(int i = q - 1, j = 0; i > 0; --i, ++j)
	{
		res[j + 1] = res[j];
		int idx = cutEdges[i];
		int lParent = find_parent(left[idx]);
		int rParent = find_parent(right[idx]);
		if(lParent != rParent)
		{
			--res[j + 1];
			parent[rParent] = lParent;
		}
	}

	for(int i = q - 1; i >= 0; --i)
		cout << res[i] << " ";

	return 0;
}
