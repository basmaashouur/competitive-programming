/*
Name: 374 - Big Mod
Online Judge: UVa
Tags: Modular Arithmetic
Complexity:
Tutorial: Just find the power modulu m.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

int modpow(long long x, long long n, long long m)
{
	if (n == 0) return 1 % m;
	long long u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1) u = (u * x) % m;
	return u;
}

int main()
{
	long long x, n, m;
	while (cin >> x)
	{
		cin >> n >> m;
		cout << modpow(x, n, m) << endl;
		string temp;
		getline(cin, temp);
	}
	return 0;
}

