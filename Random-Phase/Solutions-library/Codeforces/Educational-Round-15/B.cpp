
/*
Name: B. Powers of Two
Online Judge: Codeforces
Tags: Map, Set, Hashing, Counting
Complexity: O(n log n)
Tutorial: First count all the numbers repetition using map, then itrate over the map
and check if there a complementary in the map that summing both of them will equal any power of two,
if exist we would  have two possibilities the both numbers are the same or differnt, if the same
then using the equation (n*(n-1))/2 will find all the combinations, if differnt then the quation (n*m);
Becarefull don't calculate the combinations of some number twice so using set will help in this.
Ex: 1, 7
only (1*7)
don't (7*1) again
*/

// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{

	map <long long, long long> all;
	set<pair<long long, long long>> seen;
	long long v, ans = 0;
	int n; cin >> n;
	for (int x = 0; x < n; x++)
	{
		cin >> v;
		all[v]++;
	}
	for (auto it = all.begin(); it != all.end(); ++it)
	{
		// genrate all power of two
		for (long long x = 1; x <= 34; x++)
		{
			auto itr = all.find(pow(2, x) - it->first);
			if (itr != all.end())
			{
				long long a = min(itr->first, it->first);
				long long b = max(itr->first, it->first);
				int temp = seen.size();
				seen.insert(make_pair(a, b));
				if (seen.size() > temp)
				{
					if (it->first !=  itr->first)
						ans += (it->second * itr->second);
					else ans += (it->second * (it->second - 1)) / 2;
				}

			}
		}
	}
	cout << ans << endl;
	return 0;
}