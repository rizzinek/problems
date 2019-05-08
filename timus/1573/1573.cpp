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
	int colors[3];
	cin >> colors[0] >> colors[1] >> colors[2];
	int k;
	cin >> k;
	bool isUsed[3];
	isUsed[0] = isUsed[1] = isUsed[2] = false;
	for(int i = 0; i < k; ++i)
	{
		string s;
		cin >> s;
		if(s == "Blue")
			isUsed[0] = true;
		else if(s == "Red")
			isUsed[1] = true;
		else if(s == "Yellow")
			isUsed[2] = true;
	}
	int result = 1;
	for(int i = 0; i < 3; ++i)
		if(isUsed[i])
			result *= colors[i];
	cout << result << "\n";
	return 0;
}
