/*
Name: E. Teams
Online Judge: Codeforces
Tags: GCD
Complexity:
Tutorial: Find the GCD between all numbers that would be the size of each team, to find the number of teams
divide that gcd over the number of contestants from each university, and sum all the result.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int t, n, v, gcdal;
	long long teams; cin >> t;
	while (t--)
	{
		vector<int>vec; cin >> n;
		for (int x = 0; x < n; x++)
		{cin >> v; vec.push_back(v);}
		gcdal = vec[0], teams = 0;
		for (int x = 1; x < n; x++)
			gcdal = gcd(gcdal, vec[x]);
		for (int x = 0; x < n; x++)
			teams += vec[x] / gcdal;
		cout << gcdal << " " << teams << endl;
	}
	return 0;
}
