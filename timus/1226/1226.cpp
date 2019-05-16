#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	string s;
	int start = -1, end;
	while(getline(cin, s))
	{
		for(int i = 0; i < s.size(); ++i)
		{
			bool isLetter = isalpha(s[i]);
			if(isLetter && start == -1)
				start = i;
			else if(start != -1 && (!isLetter || i == s.size() - 1))
			{
				int end = (!isLetter ? i - 1 : i);
				for(int j = 0; j < (end - start + 1) / 2; ++j)
				{
					char t = s[start + j];
					s[start + j] = s[end - j];
					s[end - j] = t;
				}
				start = -1;
			}
		}
		cout << s << '\n';
		s.clear();
	}
	return 0;
}
