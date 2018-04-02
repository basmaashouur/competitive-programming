/*
Name: 11292 - Dragon of Loowater
Online Judge: UVa
Tags: Greedy, Sorting
Complexity: O(n log n)
Tutorial: Sort the dargons and the knights, starting from the knight that have least hight then he must 
cut the dragon's head that have least diameter, then compute the cost of that knight, if any dragon's head remians without
cutting or if the dragons heads more than the knights, then they failed.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int n , m, v, cn, ans, ch;
        while (true)
        {
                cin >> n >> m;
                vector<int>d;
                vector<int>k;
                if (n == 0 && m == 0)break;
                ch = 0;
                if (n > m) ch = 1;
                for (int x = 0; x < n; x++)
                {
                        cin >> v;
                        d.push_back(v);
                }
                for (int x = 0; x < m; x++)
                {
                        cin >> v;
                        k.push_back(v);
                }
                sort(d.begin(), d.end());
                sort(k.begin(), k.end());
                cn = 0, ans = 0;
                for (int x = 0; x < m; x++)
                {
                        if (k[x] >= d[cn])ans += k[x], cn++;
                        if (cn == n)break;
                }
                if (cn != n || ch)
                        cout << "Loowater is doomed!" << endl;
                else cout << ans << endl;
        }
        return 0;
}
