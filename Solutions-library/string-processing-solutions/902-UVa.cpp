/*
Name: 902 - Password Search
Online Judge: UVa
Tags: Frequency Counting, Strings, Map
Complexity:
Tutorial: Genrerate all the substrings of length n then find the most frequent substring using map.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n; string w, all;
	while (cin >> n >> w)
	{
		all = "";
		map<string, int>freq;
		all.append(w, 0, n);
		freq[all]++;
		for (int x = n; x < w.length(); x++)
		{
			all.erase(0, 1);
			all.push_back(w[x]);
			freq[all]++;
		}
		int mx = 0; string ans;
		for (auto itr = freq.begin(); itr != freq.end(); ++itr)
			if (itr->second > mx)
				mx = itr->second, ans = itr->first;
		cout << ans << endl;

	}

	return 0;

}
