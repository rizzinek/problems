#include <iostream>
#include <cstdio>
#include <cstring>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int cache[9][81];

int f(int n, int s) //number of ways to get S as the sum of N digits
{
	if(cache[n - 1][s - 1] >= 0)
		return cache[n - 1][s - 1];

	int result = 0;
	if(n == 1)
	{
		result = (s <= 9 ? 1 : 0);
	}
	else
	{
		for(int i = 1; i <= 9 && (s - i > 0); ++i)
		{
			result += f(n - 1, s - i);
		}
		result += f(n - 1, s);
	}
	cache[n - 1][s - 1] = result;
	//cout << n << ", " << s << " = " << result << "\n";
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int s;
	cin >> s;

	memset(cache, -1, sizeof(int) * 9 * 81);

	int result = 0;
	for(int i = 1; i <= 9; ++i)
		result += f(i, s);

	if(s == 1) //10^9
		++result;
	cout << result << "\n";

	return 0;
}
