#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

map<int, int> even;

int find_parent(map<int, int> &m, int n)
{
	auto iter = m.find(n);
	if(iter == m.end())
	{
		m[n] = n;
		return n;
	}
	int p = (*iter).second;
	if(p != n)
		p = find_parent(m, p);
	m[n] = p;
	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int length = 0, queries = 0;

	while(true)
	{
		even.clear();
		cin >> length;
		if(length == -1)
			break;
		cin >> queries;
		int res = queries;
		for(int q = 0; q < queries; ++q)
		{
			int left = 0, right = 0;
			cin >> left >> right;
			string response;
			cin >> response;
			if(res < queries)
				continue;

			if(left <= 0 || right > length)
			{
				res = q;
				continue;
			}

			//disjointed sets. Set element T is equivalent to the "oddness" of all the digits up to T (inclusive)
			//set element -T is equivalent to the opposite value of T
			//a b even => 0..a-1 and 0..b have same oddness
			//a b odd => 0..a-1 and 0..b have different oddness
			//
			//I use T / -T pairs. If I do --left; then I will have 0 in my system, that doesn't have a pair.
			//use ++right instead
			//--left;
			++right;
			int oddEven = response == "even" ? 0 : 1;

			int lp = find_parent(even, left);
			int nlp = find_parent(even, -left);
			int rp = find_parent(even, right);
			int nrp = find_parent(even, -right);

			if(oddEven == 0)
			{
				if(lp == nrp || nlp == rp)
				{
					res = q;
					continue;
				}
				even[rp] = lp;
				even[nrp] = nlp;
			}
			else
			{
				if(lp == rp || nlp == nrp)
				{
					res = q;
					continue;
				}
				even[rp] = nlp;
				even[nrp] = lp;
			}
		}
		cout << res << endl;
	}
	return 0;
}
