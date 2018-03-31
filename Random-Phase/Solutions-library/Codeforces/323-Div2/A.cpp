
/*
Name: A. Asphalting Roads
Online Judge: Codeforces
Tags: 1D Array, Vector
Complexity: O(n^2)
Tutorial: Check for evry query if both vertical and horizontal indices both of them are false,
then print the query number, and make those indices true.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int n, a, b, h[100] = {0}, v[100] = {0};
        vector<int>ans;
        cin >> n;
        for (int x = 1; x <= n * n; x++)
        {
                cin >> a >> b;
                if (h[a] == 0 && v[b] == 0)
                {
                        ans.push_back(x);
                        h[a] = 1, v[b] = 1;
                }

        }
        for (int x = 0; x < ans.size(); x++)
        {
                cout << ans[x];
                if (x == ans.size() - 1)cout << endl;
                else cout << " ";
        }
        return 0;
}
