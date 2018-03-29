
/*
Name: 1237 - Expert Enough?
Online Judge: UVa
Tags: Iterative
Complexity: O(n*q)
Tutorial: Itrate over the prices for each query and find the answer
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
                int n, l, r, q, v, cn, in;
                string mk;
                vector<pair<int, int> > price;
                vector<string> nm;
                cin >> n;
                for (int x = 0; x < n; x++)
                {
                        cin >> mk >> l >> r;
                        price.push_back(make_pair(l, r));
                        nm.push_back(mk);
                }
                cin >> q;
                while (q--)
                {
                        cn = 0, in = 0;
                        cin >> v;
                        for (int x = 0; x < n; x++)
                        {
                                if (v >= price[x].first && v <= price[x].second)
                                        cn++, in = x;

                        }
                        if (cn == 1)cout << nm[in] << endl;
                        else cout << "UNDETERMINED" << endl;
                }
                if (t > 0)cout << endl;
        }
        return 0;
}
