#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

#include <cstdlib>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	srand(0);

	const int numLetters = 1000000;
	for(int i = 0; i < numLetters; ++i)
	{
		printf("%c", 'a' + rand() % 26);
	}
	printf("\n");
	return 0;
}
