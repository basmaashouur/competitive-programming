/*
Name: A. Codeforces Rating
Online Judge: Codeforces
Tags: Sum
Complexity:
Tutorial: Sum the score to the init and see if it equal r
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, r, v, cn;
	cin >> t;
	while (t--)
	{
		cn = 1500;
		cin >> n >> r;
		while (n--)
		{
			cin >> v;
			cn += v;
		}
		if (cn == r)cout << "Correct" << endl;
		else cout << "Bug" << endl;
	}
	return 0;
}
