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
	int n, x, y;
	cin >> n >> x >> y;

#define isOk1(x) (x >= 1 && x <= n)
#define isOk(x, y) isOk1(x) && isOk1(y)

	int nKing = 0;
	for(int i = -1; i <= 1; ++i)
	{
		for(int j = -1; j <= 1; ++j)
		{
			if(i == 0 && j == 0) continue;
			if(isOk(x + i, y + j)) ++nKing;
		}
	}

	int nKnight = 0;
	for(int i = -2; i <= 2; ++i)
	{
		for(int j = -2; j <= 2; ++j)
		{
			if(i == 0 || j == 0 || abs(i) == abs(j)) continue;
			if(isOk(x + i, y + j)) ++nKnight;
		}
	}

	int nBishop = min(x - 1, y - 1) + min(x - 1, n - y) + min(n - x, y - 1) + min(n -x, n - y);

	int nRook = 2 * (n - 1);

	int nQueen = nBishop + nRook;

	cout << "King: " << nKing << "\n"
		<< "Knight: " << nKnight << "\n"
		<< "Bishop: " << nBishop << "\n"
		<< "Rook: " << nRook << "\n"
		<< "Queen: " << nQueen << "\n";

	return 0;
}
