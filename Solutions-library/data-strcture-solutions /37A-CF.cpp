
/*
Name: Towers
Online Judge: Code Forces
Tags: Frequence array
Complexity:
Tutorial: the height is max frequency number, and the total is total of numbers not repeated.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr [1001] = {0};
	int n, v, h = 0, t = 0;
	cin >> n;
	for (int x = 0; x < n; x++)
	{
		cin >> v;
		arr [v]++;
	}
	for (int x = 0; x < 1001; x++)
	{
		if (arr[x] != 0)t++;
		h = max(h, arr[x]);
	}
	cout << h << " " << t << "\n";

	return 0;
}

