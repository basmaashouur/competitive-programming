/*
Name: 11385 - Da Vinci Code
Online Judge: UVa
Tags: Ciphering, Strings
Complexity:
Tutorial: First Generate the fib series, then after take fib number know ehich index does it belong,
know map every capital char with it's fib, then print it in order and take care of spaces of missings fib
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long fib[50] = {0};
	fib[0] = 1; fib[1] = 2;
	for (int x = 2; x < 50; x++)
		fib[x] = fib[x - 1] + fib[x - 2];

	int t; cin >> t;
	while (t--)
	{
		int n, cn = 0; cin >> n;
		long long v; string ln;
		vector<pair<int, char> > vec;

		// get the fib and know what index it's in
		for (int x = 0; x < n; x++)
		{
			cin >> v; int temp;
			for (int i = 0; i < 50; i++)
				if (v == fib[i])temp = i;
			vec.push_back(make_pair(temp, '*'));
		}
		// get the chars and put every char what the it's fib
		cin.ignore(); getline(cin, ln);
		for (int x = 0; x < ln.length(); x++)
		{
			if (cn == n)break;
			if (isalpha(ln[x]) && isupper(ln[x]))
				vec[cn++].second = ln[x];
		}

		// sort the fib to print them in order 1->2->3..
		sort(vec.begin(), vec.end());
		// know the mx fib index so that would be the size of the answer
		int mx = vec[n - 1].first + 1;
		string ans(mx, ' ');
		// put the chars into ans so that of there is no fib will put space
		for (int x = 0; x < n; x++)
			ans[vec[x].first] = vec[x].second;

		cout << ans << endl;

	}

	return 0;

}
