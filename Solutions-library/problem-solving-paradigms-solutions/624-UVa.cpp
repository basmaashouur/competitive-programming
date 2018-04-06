/*
Name: 624 - CD
Online Judge: 
Tags: Backtracking, Combinatorics
Complexity: O(2^n)
Tutorial: Generate all the possible sum subsest and take the biggest one that is equal or less than the target.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

int target, sum, n, v, mx = -1;
string ans = "";
vector<int>vec;

void subset(int index, int s, string all)
{
        if (index == n)
        {
                // the end of recursion call (leaf)
                if (s > mx && s <= target)
                        mx = s, ans = all;
                return;
        }

        subset(index + 1, s, all);
        subset(index + 1, s + vec[index], all += to_string(vec[index]) + " ");
}

int main()
{
        while (cin >> target)
        {
                cin >> n;
                for (int x = 0; x < n; x++)
                {
                        cin >> v;
                        vec.push_back(v);
                }
                subset(0, 0, "");
                cout << ans << "sum:" << mx << endl;
                vec.clear(); mx = -1;
                ans = "";
        }
        return 0;
}

   
