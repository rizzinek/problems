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
	int left = n / 1000;
	int right = n % 1000;
	
	int lSum = 0, rSum = 0;
	int lastDigit = right % 10;
	for(int i = 0; i < 3; ++i)
	{
		lSum += left % 10;
		left /= 10;
		rSum += right % 10;
		right /= 10;
	}
	
	if(rSum > lSum && lastDigit > 0 || rSum < lSum && lastDigit < 9)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}
