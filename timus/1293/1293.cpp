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
	int n, a, b;
	cin >> n >> a >> b;
	cout << 2 * a * b * n << "\n";
	return 0;
}
