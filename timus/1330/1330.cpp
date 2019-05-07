#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int n;
	cin >> n;
	int *v = new int[n];
	for(int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		if(i == 0)
			v[i] = k;
		else v[i] = v[i - 1] + k;
	}
	int q;
	cin >> q;
	for(int r = 0; r < q; ++r)
	{
		int i, j;
		cin >> i >> j;
		--i; --j;
		if(i == 0)
			cout << v[j] << "\n";
		else cout << v[j] - v[i - 1] << "\n";
	}
	delete[] v;
	return 0;
}
