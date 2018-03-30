/*
Name: 10487 - Closest Sums
Online Judge: UVa
Tags: Iterative
Complexity: O(n^2 * q)
Tutorial: For every query itrate over the numbers and sum every two diffent numbers,
and see what is closet sum to the query.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int n, v, q, diff, ans, ca = 1;
        while (true)
        {
                cin >> n;
                vector<int>vec;
                if (n == 0)break;
                for (int x = 0; x < n; x++)
                {
                        cin >> v;
                        vec.push_back(v);
                }
                cin >> q;
                cout << "Case " << ca << ":" << endl;
                ca++;
                while (q--)
                {
                        cin >> v;
                        diff = 10000000;
                        for (int x = 0; x < n; x++)
                        {
                                for (int y = x + 1; y < n; y++)
                                {
                                        if (abs(vec[x] + vec[y] - v) < diff)
                                                ans = vec[x] + vec[y], diff = abs(vec[x] + vec[y] - v);
                                }
                        }
                        cout << "Closest sum to " << v << " is " << ans << "." << endl;
                }
        }
        return 0;
}
