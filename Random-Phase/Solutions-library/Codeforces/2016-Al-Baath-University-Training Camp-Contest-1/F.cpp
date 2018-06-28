/*
Name: F. Good Words
Online Judge: Codeforces
Tags: Strings
Complexity:
Tutorial: First check if the string b is a substring of the string a, if no check almost good
by holding three chars, and try to insert all the chars of b inside it in all the differnt four psotions and see
if that will make it a substring or not, otherwise it's nither.
*/


// C O D E


#include <bits/stdc++.h>
#define pp push_back
using namespace std;

main()
{
	int t, g, ag; cin >> t;
	string a, b, temp;
	while (t--)
	{
		cin >> a >> b; g = ag = 0;

		// check good
		temp = "";
		for (int x = 3; x < a.length(); x++)
		{
			if (temp == "")temp = a.substr(0, 4);
			else
			{
				temp.push_back(a[x]);
				temp.erase(0, 1);
			}
			if (temp == b)g = 1;
		}

		// check almost good
		if (!g)
		{
			temp = "";
			for (int x = 2; x < a.length(); x++)
			{
				if (temp == "")temp = a.substr(0, 3);
				else
				{
					temp.push_back(a[x]);
					temp.erase(0, 1);
				}
				for (int f = 0; f < 4; f++)
				{
					if (b[f] + temp == b)ag = 1;
					if (temp + b[f] == b)ag = 1;
					string i, ii;
					i.pp(temp[0]); i.pp(b[f]); i.pp(temp[1]); i.pp(temp[2]);
					ii.pp(temp[0]); ii.pp(temp[1]); ii.pp(b[f]); ii.pp(temp[2]);
					if ( i == b)ag = 1;
					if ( ii == b)ag = 1;
				}
			}
		}
		
		if (g)cout << "good" << endl;
		else if (ag)cout << "almost good" << endl;
		else cout << "none" << endl;
	}

	return 0;
}
