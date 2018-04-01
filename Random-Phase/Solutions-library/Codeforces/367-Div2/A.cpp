/*
Name: A. Beru-taxi
Online Judge: Codeforces
Tags: Points
Complexity: O(n)
Tutorial: Find the distance between every driver and Vasiliy, then divide the distance over
the speed, and that would be the time and the answer would be the min of them.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int a , b, n, x, y;
        double s, ans = 10000;
        cin >> a >> b >> n;
        for (int i = 0; i < n; i++)
        {
                cin >> x >> y >> s;
                if (sqrt(pow(abs(x - a), 2) + pow(abs(y - b), 2)) / s < ans)
                        ans = sqrt(pow(abs(x - a), 2) + pow(abs(y - b), 2)) / s;
        }
        cout << fixed << setprecision(20) << ans << endl;

        return 0;
}
