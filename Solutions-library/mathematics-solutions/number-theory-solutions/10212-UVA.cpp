
/*
Name: 10212 - The Last Non-zero Digit.
Online Judge: UVa
Tags: Modular Arithmetic
Complexity:
Tutorial: Like find the last digit function but instead make 1 %m make it several time until there is no ending zeros
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int main()
{
	LL n, m;
	while (cin >> n >> m)
	{
		LL ans = 1;
		for (LL i = n; i > n - m; i--)
		{
			ans *= i;
			while (ans % 10 == 0) ans /= 10;
			ans %= 10000000000;
		}
		cout << ans % 10 << "\n";
	}
	return 0;
}

