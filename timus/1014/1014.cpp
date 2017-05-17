#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);

	if(n == 0)
	{
		printf("10");
		return 0;
	}

	if(n == 1)
	{
		printf("1");
		return 0;
	}
	//todo: divide by 9, 8 and so on and then write it out in reverse order
	const int factors[] = {2, 3, 4, 5, 6, 7, 8, 9};
	int counts[] = {0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 7; i >= 0; --i)
	{
		while(n % factors[i] == 0)
		{
			n /= factors[i];
			++counts[i];
		}
	}
	if(n > 1)
	{
		printf("-1");
		return 0;
	}

	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < counts[i]; ++j)
		{
			printf("%d", i + 2);
		}
	}
	return 0;
}
