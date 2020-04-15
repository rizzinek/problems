#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	double k[3] = {0.0, 0.0, 0.0};
	cin >> k[0] >> k[1] >> k[2];
	double sum = k[0] + k[1] + k[2];
	double max = 0;
	//cout << "sum = " << sum << endl;

	for(int i = 0; i < 3; ++i)
	{
		double betCoef = 1 / (1 + k[i] / k[(i + 1) % 3] + k[i] / k[(i + 2) % 3]);
		double bet = 1000. * betCoef;
		double win = bet * k[i];
		if(win > max)
			max = win;
		//cout << k[i] << " / " << (sum - k[i]) / sum << " / " << bet << " / " <<  win << endl;
	}
	printf("%d\n", (int)round(max));

	return 0;
}
