/*
Name: 10346 - Peter's Smokes
Online Judge: UVa
Tags: Brute force math
Complexity:
Tutorial: Just simulate the prcocess untill there is no remaining butts to make cigarettes from.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int s, k, b;
	while (cin >> s >> k)
	{
		int ans = 0;
		ans += s, b = s, s = 0;
		while (true)
		{
			if ((b / k ) > 0)
			{
				// new cigrates
				s = b / k;
				// remian butts
				b = b % k;
				// put cigratt into ans
				ans += s;
				// put drinking cigrate into but
				b += s;
			}
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}
