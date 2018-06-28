/*
Name: C. A or B Equals C
Online Judge: Codeforces
Tags: Strings, Mod
Complexity:
Tutorial: If a is 1 and b is 0 then it's impossible, if a is 1 and b is 1 then we have two choices 1 or 0,
otherwise we have only one option, mutliply all those options togther to know the answer.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

int main()
{
	int t, len; cin >> t;
	string a, b;
	while (t--)
	{
		long long ans = 1, ch = 1;
		cin >> len >> a >> b;
		for (int x = 0; x < len; x++)
		{
			if (a[x] == '1' && b[x] == '0')
			{
				ch = 0;
				break;
			}
			else if (a[x] == '1' && b[x] == '1')ans = (ans * 2) % M;
		}
		if (ch)cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
