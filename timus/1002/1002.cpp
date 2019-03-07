#include <istream>
#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct word
{
	string w;
	string d;
};

void initMap(map<char, char> &letterMap);

void solve(vector<word> &dict, string &number, vector<int> &res)
{
	const int maxWordLen = dict[dict.size() - 1].d.length();
	vector<int> *d = new vector<int>[number.length() + 1];

	for(int length = 1; length <= number.length(); ++length)
	{
		int curMinSize = 0;
		int curMinIdx = 0;
		int curMinWordIdx = 0;
		for(int j = 0; j < length; ++j)
		{
			string prefix;
			for(int k = 0; k < d[j].size(); ++k)
				prefix += dict[d[j][k]].d;
			string suffix = number.substr(prefix.length(), length - prefix.length());

			if(suffix.length() > maxWordLen)
				continue;

			for(int k = 0; k < dict.size(); ++k)
			{
				if(suffix.length() < dict[k].d.length())
					break;
				if(suffix.length() > dict[k].d.length())
					continue;
				bool fits = true;
				for(int r = 0; r < suffix.length(); ++r)
				{
					if(suffix[r] != dict[k].d[r])
					{
						fits = false;
						break;
					}
				}
				if(fits)
				{
					int newSize = d[j].size() + 1;
					if(curMinSize == 0 || newSize < curMinSize)
					{
						curMinSize = newSize;
						curMinIdx = j;
						curMinWordIdx = k;
					}
				}
			}
		}

		if(curMinSize > 0)
		{
			d[length] = d[curMinIdx];
			d[length].push_back(curMinWordIdx);
		}
	}
	res = d[number.length()];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	map<char, char> letterMap;
	initMap(letterMap);

	string number;
	vector<word> dict;
	int size = 0;
	vector<int> res;
	map<string, vector<string> > cache;

	while(number != "-1")
	{
		cin >> number;

		if(number == "-1")
			return 0;

		cin >> size;
		for(int i = 0; i < size; ++i)
		{
			string s;
			cin >> s;
			word w;
			w.w = s;
			for(int i = 0; i < s.length(); ++i)
				s[i] = letterMap[s[i]];
			w.d = s;
			dict.push_back(w);
		}
		//sort in ascending order: shortest words first, words of the same length are sorted lexicographically
		sort(dict.begin(), dict.end(), [](word& a, word& b) {
				return a.d.length() < b.d.length() || (a.d.length() == b.d.length() && a.d < b.d);
				});
		//prune the words that are larger than the input word
		for(int i = dict.size() - 1; i >= 0; --i)
			if(dict[i].w.length() > number.length())
				dict.pop_back();
		res.clear();

		//solution start
		solve(dict, number, res);
		//solution end

		if(res.size() == 0)
			cout << "No solution.\n";
		else
		{
			for(int j = 0; j < res.size(); ++j)
			{
				if(j == 0)
					cout << dict[res[j]].w;
				else
					cout << " " << dict[res[j]].w;
			}
			cout << "\n";
		}
	}
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
