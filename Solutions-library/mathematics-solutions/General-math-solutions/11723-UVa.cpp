/*
Name: 11723 - Numbering Roads
Online Judge: UVa
Tags: Ad-hoc math
Complexity:
Tutorial: Itrate over 26 char and see if put it in the current numbers would it fit and make all the roads.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t = 1;
	while (true)
	{
		int r, u, check = 0, ans = 0;
		cin >> r >> u;
		if (r == 0 && u == 0)break;
		for (int i = 0; i <= 26; i++)
		{
			if (u * i + u >= r)
			{
				check = 1;
				ans = i;
				break;
			}
		}
		cout << "Case " << t++ << ": ";
		if (check)cout << ans << endl;
		else cout << "impossible" << endl;

	}


	return 0;
}
