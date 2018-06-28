/*
Name: D. X and paintings
Online Judge: Codeforces
Tags: Arrays
Complexity:
Tutorial: Change all the postions of the rectangle to the it's char, be carefull sstore in an array not vector
because array is much faster, otherwise you get run time error.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
char fin [105][105];
int main()
{
	int t, r, c, i, a, b, w, m;
	char col; cin >> t;
	while (t--)
	{
		cin >> r >> c >> i;
		for (int x = 0; x < r; x++)
			for (int y = 0; y < c; y++)
				fin[x][y] = '.';
		while (i--)
		{
			cin >> a >> b >> w >> m >> col;
			a -= 1, b -= 1;
			for (int x = a; x < w; x++)
				for (int y = b; y < m; y++)
					fin[x][y] = col;
		}
		for (int x = 0; x < r; x++)
		{
			for (int y = 0; y < c; y++)
				cout << fin[x][y];
			cout << endl;
		}
	}
	return 0;
}
