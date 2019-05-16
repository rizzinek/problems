#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

#include <cmath>
#include <cfloat>

using namespace std;

const double pi = 3.1415926535;
const double g = 10.;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int v, angle;
	double k;
	cin >> v >> angle >> k;
	k = sqrt(k);
	double alpha = (double)angle / 180. * pi;
	double vx = v * cos(alpha);
	double vy = v * sin(alpha);

	double distance = 0.;
	double delta = 0.;

	do
	{
		double t = 2 * vy / g;
		delta = vx * t;
		vx /= k;
		vy /= k;
		distance += delta;

	} while(delta > DBL_EPSILON);

	printf("%.2f\n", distance);

	return 0;
}
