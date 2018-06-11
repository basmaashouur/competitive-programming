/*
Name: H. Multiplication Table
Online Judge: CodeForces
Tags: Base Number Variants
Complexity:
Tutorial: Mutiply x*y then convret to radix
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int k; cin >> k;
	for (int x = 1; x < k; x++)
	{
		for (int y = 1; y < k; y++)
		{
			int n = x * y, d; string ans;
			while (n != 0)
			{
				ans += to_string(n % k);
				n /= k;
			}
			reverse(ans.begin(), ans.end());
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;

}
