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
	long x, y;
	cin >> x >> y;
	if(x <= 0 || y <= 0 || ((x + y) & 1) == 0)
		cout << x << " " << y << "\n";
	else cout << y << " " << x << "\n";
	return 0;
}
