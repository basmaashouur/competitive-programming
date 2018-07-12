/*
Name: Black and white painting
Online Judge: UVa
Tags: Maths, Finding Pattern or Formula
Complexity: O(1)
Tutorial: First we the case that the right bottom corner will start with 1 then if 
first bottom row we will walk  (0->8, 10->12, 14-16, until no more coloumns) 
second bottom row we will walk (1->9, 11->13, 15->17 until no more coloumns)
and we will repeat the proces to n - 7, means we cant take no more rows.

if the the right corner start with 0 we will revrese the proces above.

*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

//(0->8, 10->12, 14-16)
int even(int col)
{
	if (col % 2 != 0)col--;
	return (col - 8) / 2 + 1;
}
// (1->9, 11->13, 15->17)
int odd(int col)
{
	if (col % 2 == 0)col--;
	return (col - 9) / 2 + 1;
}
int main()
{
	int n, m, c; long long ans;
	while (true)
	{
		cin >> n >> m >> c; ans = 0;
		if (n == 0 && m == 0 && c == 0)break;
    // nrow means the rows that we will take
		int nrow = n - 7, ev = even(m), od = odd(m);
		int fi = ceil((double)nrow / 2.0), se = nrow / 2;

		if (c == 1)
			ans = (ev * fi) + (od * se);

		else
			ans = (od * fi) + (ev * se);

		cout << ans << endl;
	}

	return 0;
}


