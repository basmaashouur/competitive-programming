/*
Name: I. March Rain
Online Judge: Codeforces
Tags: Binary Search
Complexity: 
Tutorial: Use Binary search the answer(min val) and find if that answer can cover 
the holes using upper bound to check if I take answer with that length and have that kcan it cover them all
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
vector<long long>vec;
int t; long long k, n, v;

int can(long long val)
{
	int curCover = 0;
	for (int x = 0; x < k; x++)
	{
		curCover = upper_bound(vec.begin(), vec.end(),  vec[curCover] + val - 1) - vec.begin();
		if (curCover == n)return 1;

	}
	return 0;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int x = 0; x < n; x++)
		{
			cin >> v;
			vec.push_back(v);
		}
		long long ans, start = 0, end = 1e9 + 5, mid;

		while (start <= end)
		{
			mid = (start + end) / 2;
			if (can(mid))ans = mid, end = mid - 1;
			else start = mid + 1;
		}
		cout << ans << "\n";
		vec.clear();
	}

	return 0;
}


