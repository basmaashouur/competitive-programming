/*
Name: B. Non-square Equation
Online Judge:
Tags:
Complexity:
Tutorial: The equation is Quadratic Formula ax^2 + bx + c = 0, which a = 1 and b = s(x) and c = n,
so to find x we need to solve the quadratic equation x= −b± * sqrt(b^2 - 4ac) / 2a
but we don't have the value ob b which is s(x) so let's try all the values between 1 to 99
becauce the max value of x is 9999999999 which is equal 90 so lets try all those value
and see if there is a pstive intger x that make the equation true

*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long  ll;

int main()
{
	ll n, a, b, c;
	ld t; cin >> n;
	for (int x = 1; x <= 90; x++)
	{
		a = 1, b = ll(x), c = -n;
		t = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
		if (t - (ll)t == 0)
		{
			string temp = to_string((ll)t); int see = 0;
			for (int y = 0; y < temp.length(); y++)see += temp[y] - '0';
			if (ll(x) == see) {cout << (ll)t << endl; return 0;}
		}
	}
	cout << -1 << endl;
	return 0;
}
