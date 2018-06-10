/*
Name: 11875 - Brick Game
Online Judge: UVa
Tags: Ad-hoc math
Complexity:
Tutorial: Just take the middle number while scanning the numbers
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t, n, v, ans;
	cin >> t;
	for (int x = 1; x <= t; x++)
	{
		cin >> n;
		for (int y = 0; y < n; y++)
		{
			cin >> v;
			if (y == n / 2)ans = v;

		}
		cout << "Case " << x << ": " << ans << endl;
	}

	return 0;
}
