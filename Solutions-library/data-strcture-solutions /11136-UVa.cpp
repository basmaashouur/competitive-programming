/*
 * Name: 11136 - Hoax or what
 * Online Judge: UVa
 * Tags: Multisets
 * Complexity: 
 * Tutorial: Substract the smallest and the biggest number from the multiset then delete them.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long n, k, v, ans;
        while (true)
        {
                cin >> n;
                if (n == 0)break;
                multiset<int>bill;
                ans = 0;
                while (n--)
                {
                        cin >> k;
                        while (k--)
                        {
                                cin >> v;
                                bill.insert(v);
                        }
                        auto beg = bill.begin();
                        auto en = bill.rbegin();
                        ans +=  (*en) - (*beg);
                        bill.erase(beg);
                        bill.erase(--bill.end());
                }
                cout << ans << endl;
        }
        return 0;
}
