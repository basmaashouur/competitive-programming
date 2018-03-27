
/*
Name: 11462 - Age Sort
Online Judge: UVa
Tags: Counting Sort
Complexity: O(n * 100)
Tutorial: count the frequencies of distinct elements of the array ana map it in an array, then print
the frequencies index.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        while (true)
        {
                int n, v, arr[101] = {0};
                vector<int>ans;
                cin >> n;
                if (n == 0)break;
                for (int x = 0; x < n; x++)
                {
                        cin >> v;
                        arr[v]++;
                }
                for (int x = 1; x < 101; x++)
                {
                        while (arr[x]--)ans.push_back(x);
                }
                for (int x = 0; x < n; x++)
                {
                        cout << ans[x];
                        if (x < n - 1)cout << " ";
                        else  cout << endl;
                }
        }

        return 0;
}
