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
	int n, s;
	cin >> n >> s;
	int *d = new int[n];
	int *k = new int[n];
	int prod = 1;
	for(int i = 0; i < n; ++i)
	{
		cin >> d[i];
		if(i > 0)
		{
			k[i] = d[i - 1] / d[i];
			prod *= k[i];
		}
	}
	k[0] = s / prod;
	for(int i = 0; i < n; ++i)
		cout << k[i] - 1 << " ";
	delete[] d;
	delete[] k;
	return 0;
}
