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
