/*
Name: 1260 - Sales
Online Judge: UVa
Tags: Iterative
Complexity: O(n^2)
Tutorial: Find the answer using two nested loops.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int t;
        cin >> t;
        while (t--)
        {
                int n, v, ans = 0;
                vector<int> vec;
                cin >> n;
                for (int x = 0; x < n; x++)
                {
                        cin >> v;
                        vec.push_back(v);
                }
                for (int x = 1; x < n; x++)
                {
                        for (int y = 0; y < x; y++)
                                if (vec[x] >= vec[y])ans++;
                }
                cout << ans << endl;
        }
        return 0;
}
