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
	if(n == 1) { cout << "1\n"; return 0; }
	if(n == 2) { cout << "1\n"; return 0; }
	if(n == 3) { cout << "2\n"; return 0; }
	int *a = new int[n];
	a[0] = 1, a[1] = 1, a[2] = 2;
	for(int i = 3; i < n; ++i)
		a[i] = a[i - 1] + 1 + a[i - 3];
	cout << a[n - 1] << "\n";
	return 0;
}
