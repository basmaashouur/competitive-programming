/*
Name: B. Bonapity
Online Judge: Codeforces
Tags: Strings
Complexity:
Tutorial: Change all chars to lowers case, then change all p to b and all i to e and see if the
two strings equal now
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	string fi, se;
	while (t--)
	{
		cin >> fi >> se;
		if (fi.length() != se.length())cout << "No" << endl;
		else
		{
			for (int x = 0; x < fi.length(); x++)
			{
				fi[x] = tolower(fi[x]);
				se[x] = tolower(se[x]);
				if (fi[x] == 'p')fi[x] = 'b';
				if (se[x] == 'p')se[x] = 'b';
				if (fi[x] == 'i')fi[x] = 'e';
				if (se[x] == 'i')se[x] = 'e';
			}
			if (fi == se)cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}
