/*
Name: The Playboy Chimp
Online Judge: UVa
Tags: BS
Complexity:
Tutorial: Just use upper and lower bound
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, q, v;
	vector<int>vec;
	cin >> n;
	for (int x = 0; x < n; x++)
	{
		cin >> v;
		vec.push_back(v);
	}
	cin >> q;
	while (q--)
	{
		cin >> v;
		auto up  = upper_bound(vec.begin(), vec.end(), v);
		auto low = lower_bound(vec.begin(), vec.end(), v);
		int a = up - vec.begin(), b = low - vec.begin();
		if (vec[b] >= v)b--;

		if (b < 0)cout << "X ";
		else cout << vec[b] << " ";
		if (a == n)cout << "X" << endl;
		else cout << vec[a] << endl;
	}
	return 0;
}
