/*
Name: 12405 - Scarecrow
Online Judge: UVa
Tags: Greedy
Complexity: O (t * n)
Tutorial: Every time you find a crop then put a scarecrow in it, a scarecrows cover three cells of crops,
that would cover all the range without leaving cells empty
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int t, n, ans;
        string grid;
        cin >> t;
        for (int x = 1; x <= t; x++)
        {
                ans = 0;
                cin >> n >> grid;
                for (int y = 0; y < n; y++)
                        if (grid[y] == '.')
                                ans++, y += 2;
                cout << "Case " << x << ": " << ans << endl;
        }
        return 0;
}


// another sloution 



#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t;
	string p;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> n >> p;
		int ans = 0;
		p += "..";
		for (int x = 0; x < n; x++)
		{
			if (p[x] == '.')
			{
				ans++;
				p[x] = '#';
				p[x + 1] = '#';
				p[x + 2] = '#';
			}
		}

		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}
