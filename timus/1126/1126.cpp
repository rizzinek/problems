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
	int m;
	cin >> m;
	int *w = new int[m];
	int i = 0;
	while(true)
	{
		int n;
		cin >> n;
		if(n == -1)
			break;
		w[i % m] = n;
		++i;
		if(i < m)
			continue;
		int max = w[0];
		for(int j = 1; j < m; ++j)
			if(w[j] > max)
				max = w[j];
		cout << max << "\n";
	}
	delete[] w;
	return 0;
}
