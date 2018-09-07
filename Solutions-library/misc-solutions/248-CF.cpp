/*
Name: B. Kuriyama Mirai's Stones
Online Judge: Code Forces
Tags: Cumulative Sum
Complexity:
Tutorial: Make Cumulative Sum for one array and then sort the other aray and make Cumulative Sum
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

int n = 1e6 + 5;
int main()
{
	int n, m;
	long long v, l, r;
	cin >> n;
	vector<long long>vi(n + 1);
	vector<long long>ui(n + 1);
	for (int x = 1; x <= n; x++)
	{
		cin >> v;
		vi[x] = v;
		ui[x] = v;
	}
	sort(ui.begin(), ui.end());
	for (int x = 1; x <= n; x++)
	{
		vi[x] += vi[x - 1];
		ui[x] += ui[x - 1];
	}
	cin >> m;
	while (m--)
	{
		cin >> v >> l >> r;
		if (v == 1)cout << vi[r] - vi[l - 1] << "\n";
		else cout << ui[r] - ui[l - 1] << "\n";
	}
	return 0;

}
