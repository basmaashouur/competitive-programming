/*
Name: G. The Tower of Evil
Online Judge: Codeforces
Tags: Mathematics
Complexity:
Tutorial: 
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll t, h, w, d, finx, finy, sub, moves;
	cin >> t;
	while (t--)
	{
		cin >> h >> w >> d;
		
		// find the last x that should make complete diagonal
		if (w == 2 ) finx = h, moves = h - 1;
		else finx = (h / (w - 1)) * (w - 1) + 1, moves = h / (w - 1);
		if (finx < h)finx += w - 1, moves++;

		// find the last y the should make complete diagonal
		if (moves % 2 == 0)finy = 1;
		else finy = w;

		sub = finx - h;
		if (finy == 1)finy += sub;
		else finy -= sub;
		if (finy == d)cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
