/*
Name: B. Choosing Symbol Pairs
Online Judge: CodeForces
Tags: Frequency Counting, Strings
Complexity:
Tutorial: Just count the frequency of every didgit then fond the pairs using the equation of map[x]*map[x]
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{

	string s; cin >> s;
	long long map[36] = {0}, ans = 0;
	for (int x = 0; x < s.length(); x++)
	{
		if (isdigit(s[x]))map[(char)s[x] - 48]++;
		else map[(char)s[x] - 87]++;
	}
	for (int x = 0; x < 36; x++)ans += map[x] * map[x];
	cout << ans << endl;
	return 0;
}
