/*
Name: 11389 - The Bus Driver Problem
Online Judge: UVa
Tags: Greedy
Complexity: 
Tutorial: Sort the both morning and afternoon trips, and to minmize the answer take the 
biggest from morning to the min from afternoon.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int n, d, r, v;
        while (true)
        {
                cin >> n >> d >> r;
                if (n == 0 && d == 0 && r == 0)break;
                vector<int>m;
                vector<int>e;
                for (int x = 0; x < n * 2; x++)
                {
                        cin >> v;
                        if (x >= n)e.push_back(v);
                        else m.push_back(v);
                }
                sort(m.begin(), m.end());
                sort(e.begin(), e.end());
                long long ans = 0;
                for (int x = 0 , y = n - 1; x < n; x++, y--)
                {
                        if (m[x] + e[y] > d)ans += (m[x] + e[y] - d) * r;
                }
                cout << ans << endl;
        }
        return 0;
}
