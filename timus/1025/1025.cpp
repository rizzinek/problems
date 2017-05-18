#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	vector<int> groups;
	for(int i = 0; i < n; ++i)
	{
		int k = 0;
		scanf("%d", &k);
		groups.push_back(k);
	}
	sort(groups.begin(), groups.end());
	int result = 0;
	for(int i = 0; i < (groups.size() + 1) / 2; ++i)
		result += (groups[i] + 1) / 2;
	printf("%d\n", result);
	return 0;
}
