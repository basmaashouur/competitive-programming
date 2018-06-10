/*
Name: 382 - Perfection
Online Judge: UVa
Tags: Brute Force math
Complexity:
Tutorial: Find the sum of all the divsiors of a number then check it's type.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	cout << "PERFECTION OUTPUT" << endl;
	while (true)
	{
		int n, ans = 0;
		cin >> n;
		if (n == 0)
		{
			cout << "END OF OUTPUT" << endl;
			break;
		}
		for (int x = 1; x <= n/2 ; x++)
		{
			if (n % x == 0)ans += x;
		}
		printf("%5d  ", n);
		if (ans == n) cout << "PERFECT" << endl;
		if (ans > n)cout << "ABUNDANT" << endl;
		if (ans < n)cout << "DEFICIENT" << endl;

	}
	return 0;
}
