/*
Name: 11878 - Homework Checker
Online Judge: UVa
Tags: Strings, Input Parsing
Complexity:
Tutorial: Make vars for a,b,c and see if the equation is true, be carfull when c is ?.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{

	string eq; int ans = 0;
	while (cin >> eq)
	{
		int a, b, c = 201; string temp; char ob;
		for (int x = 0; x < eq.length(); x++)
		{
			if (eq[x] == '+' || eq[x] == '-')
				ob = eq[x], a = stoi(temp), temp = "";
			else if (eq[x] == '=')
				b = stoi(temp), temp = "";
			else temp += eq[x];
			if (x == eq.length() - 1 && isdigit(temp[0]))
				c = stoi(temp);
		}
		if (ob == '+' && (a + b) == c)ans++;
		else if ((a - b) == c)ans++;

	}
	cout << ans << endl;

	return 0;
}
