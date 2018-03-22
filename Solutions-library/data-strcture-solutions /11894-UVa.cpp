
/*
 * Name: 11849 - CD
 * Online Judge: UVa
 * Tags: Sets
 * Complexity: 
 * Tutorial: know the Repetition of the number using sets.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n, m, v, ans;
        while (true)
        {
                cin >> n >> m;
                set<int> all;
                ans = 0;
                if (n == 0 && m == 0)break;
                while (n--)
                {
                        cin >> v;
                        all.insert(v);
                }
                while (m--)
                {
                        cin >> v;
                        int sz = all.size();
                        all.insert(v);
                        if (sz == all.size())ans++;
                }
                cout << ans << endl;
        }
        return 0;
}
