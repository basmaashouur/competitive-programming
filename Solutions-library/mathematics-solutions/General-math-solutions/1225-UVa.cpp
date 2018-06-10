/*
Name: 1225 - Digit Counting
Online Judge: UVa
Tags: Brute Force Math
Complexity:
Tutorial: Convert the numbers to  chars and count them
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t, n; cin >> t;
	while (t--)
	{
		cin >> n;
		int arr [10] = {0};
		for (int x = 1; x <= n; x++)
		{
			string temp = to_string(x);
			for (int y = 0; y < temp.length(); y++)
				arr[temp[y] -'0']++;
		}
		for (int x = 0; x < 10; x++)
		{
			cout << arr[x];
			if (x == 9)cout << endl;
			else cout << " ";
		}
	}
	return 0;
}
