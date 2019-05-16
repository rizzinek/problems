#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

const int NMAX = 100000;

int cache[NMAX];

int a(int i)
{
	if(cache[i] >= 0)
		return cache[i];

	int result = 0;
	if((i & 1) == 0)
		result = a(i / 2);
	else
		result = a(i / 2) + a(i / 2 + 1);
	cache[i] = result;
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	memset(cache, -1, sizeof(int) * NMAX);
	cache[0] = 0;
	cache[1] = 1;
	for(int i = 2; i < NMAX; ++i)
		a(i);

	int n;
	while(true)
	{
		cin >> n;
		if(n == 0)
			break;

		int res = cache[n];
		for(int i = n - 1; i >= 0; --i)
			if(cache[i] > res)
				res = cache[i];

		cout << res << "\n";
	}
	return 0;
}
