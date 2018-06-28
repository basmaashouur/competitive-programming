/*
Name: J. X and Beasts
Online Judge: Codeforces
Tags: DP, Exponent
Complexity:
Tutorial: It's a dp problem of Maximum Sum Increasing Subsequence, but instead of sum the numbers sum the 
maximum power of two that divides that number.
*/


// C O D E


#include <bits/stdc++.h>
#define lowBit(S) (S & (-S))
using namespace std;

int pow(int v)
{
	/*int t = lowBit(v);
	return (log(t) / log(2));*/
	int cn = 0;
	while (v % 2 == 0)
		cn++, v /= 2;
	return cn;
}

int main()
{
	int t, n, v, mx;
	cin >> t;
	while (t--)
	{
		cin >> n; mx = 0;
		vector<int>vec; vector<int>dp;
		for (int x = 0; x < n; x++)
		{
			cin >> v; vec.push_back(v);
			if (v % 2 == 0)dp.push_back(pow(v));
			else dp.push_back(0);
		}

		for (int i = 1; i < n; i++)
			for ( int j = 0; j < i; j++)
			{
				int temp = 0;
				if (vec[i] % 2 == 0) temp = pow(vec[i]);
				if (vec[i] > vec[j])
					dp[i] = max(dp[i], dp[j] + temp);
				mx = max(mx, dp[i]);
			}
		for (int i = 0; i < n; i++)
			mx = max(mx, dp[i]);
		cout << mx << endl;
	}
	return 0;
}
