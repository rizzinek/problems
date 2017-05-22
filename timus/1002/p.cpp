#include <istream>
#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

void initMap(map<char, char> &letterMap);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	string number;
	cin >> number;

	if(number == "-1")
		return 0;

	map<char, char> letterMap;
	initMap(letterMap);

	vector<string> dict;
	int size = 0;
	cin >> size;
	for(int i = 0; i < size; ++i)
	{
		string s;
		cin >> s;
		for(int i = 0; i < s.length(); ++i)
			s[i] = letterMap[s[i]];
		dict.push_back(s);
	}
	sort(dict.begin(), dict.end(), [](string& a, string& b) {
			return a.length() > b.length() || a > b;
			});
	for(auto s : dict)
		cout << s << endl;
	return 0;
}

void initMap(map<char, char> &letterMap)
{
	letterMap['a'] = '2';
	letterMap['b'] = '2';
	letterMap['c'] = '2';

	letterMap['d'] = '3';
	letterMap['e'] = '3';
	letterMap['f'] = '3';

	letterMap['g'] = '4';
	letterMap['h'] = '4';

	letterMap['i'] = '1';
	letterMap['j'] = '1';

	letterMap['k'] = '5';
	letterMap['l'] = '5';

	letterMap['m'] = '6';
	letterMap['n'] = '6';
	
	letterMap['p'] = '7';
	letterMap['r'] = '7';
	letterMap['s'] = '7';

	letterMap['t'] = '8';
	letterMap['u'] = '8';
	letterMap['v'] = '8';

	letterMap['w'] = '9';
	letterMap['x'] = '9';
	letterMap['y'] = '9';

	letterMap['o'] = '0';
	letterMap['q'] = '0';
	letterMap['z'] = '0';
}
