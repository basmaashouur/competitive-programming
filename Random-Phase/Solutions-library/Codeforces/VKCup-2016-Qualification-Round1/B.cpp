/*
Name: B. Chat Order
Online Judge: Codeforces
Tags: Set, Vector
Complexity: O(n log n)
Tutorial: Just reverse the names and when printing don't print what has already printed,
by using set.
*/

// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{     
        int n;
        string nm;
        set<string>all;
        vector<string>vec;
        cin >> n;
        for (int x = 0; x < n; x++)
        {
                cin >> nm;
                vec.push_back(nm);
        }
        for (int x = n - 1; x >= 0; x--)
        {
                int temp = all.size();
                all.insert(vec[x]);
                if (all.size() > temp)
                        cout << vec[x] << endl;
        
        return 0;
}
