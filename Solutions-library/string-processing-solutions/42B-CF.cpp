/*
Name: B. Letter
Online Judge: Codeforces
Tags: Frequency Counting, Strings
Complexity:
Tutorial: Map the amount of header letters into array and then see if it's gonna cover the letters in the text
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int alpha[52] {0}, check = 0; string h, w;
	getline(cin, h);getline(cin, w);
	for (int x = 0; x < h.length(); x++)
		if (isalpha(h[x]))
		{
			if (islower(h[x]))alpha[(int) h[x] - 71]++;
			else alpha[(int) h[x] - 65]++;
		}

	for (int x = 0; x < w.length(); x++)
		if (isalpha(w[x]))
		{
			if (islower(w[x]))
			{
				if (alpha[(int) w[x] - 71] > 0)
					alpha[(int) w[x] - 71]--;
				else check = 1;
			}
			else
			{
				if (alpha[(int) w[x] - 65] > 0)
					alpha[(int) w[x] - 65]--;
				else check = 1;;

			}
		}
	if (check)cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}
