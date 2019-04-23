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
	if(n < 2 || n > 8 || n % 2 == 1)
	{
		cout << "0" << endl;
		return 0;
	}

	n /= 2;
	int m = 9 * n + 1;

	//q[i][j] = number of ways to get sum equal to j using i + 1 digits

	int **q = new int*[n];
	for(int i = 0; i < n; ++i)
	{
		q[i] = new int[m];
		for(int j = 0; j < m; ++j)
			q[i][j] = 0;
	}

	for(int i = 0; i < 10; ++i)
		q[0][i] = 1;

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < 9 * (i + 1) + 1; ++j)
		{
			int result = 0;
			for(int k = 0; k <= j; ++k)
			{
				result += q[0][k] * q[i - 1][j - k];
			}
			q[i][j] = result;
		}
	}

	int result = 0;
	for(int j = 0; j < m; ++j)
		result += q[n - 1][j] * q[n - 1][j];
	cout << result << "\n";

	return 0;
}
