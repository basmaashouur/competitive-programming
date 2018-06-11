/*
Name: 575 - Skew Binary
Online Judge: UVa
Tags: Base Number Variants
Complexity:
Tutorial: Convert the skew into deciaml following the equation
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	while (true)
	{
		string n; cin >> n;
		if (n == "0")break;
		int sz = n.length();
		unsigned long long ans = 0;
		for (int x = 0; x < n.length(); x++)
		{
			ans += (pow(2, sz--) - 1) * (n[x] - '0');
		}
		cout << ans << endl;
	}
	return 0;

}
