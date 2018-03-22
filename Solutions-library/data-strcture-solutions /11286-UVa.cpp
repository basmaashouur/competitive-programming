/*
Name: 11286 - Conformity
Online Judge: UVa
Tags: Maps, Sorting
Complexity: 
Tutorial: count the repetition of every combination, to do so you need first to sort every combination 
so the same combinations would be the same, then find the max combination and how many of them exist, 
and that would be the answer.
*/


// C O D E 

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        while (true)
        {
                cin >> n;
                if (n == 0)break;
                cin.ignore();
                map <string, int>mp;
                int ans = 0, mx  = 0;
                string comb;
                while (n--)
                {
                        vector<string>vec;
                        for (int x = 0; x < 5; x++)
                        {
                                cin >> comb;
                                vec.push_back(comb);
                        }
                        comb = "";
                        sort(vec.begin(), vec.end());
                        for (int x = 0; x < 5; x++)
                                comb += vec[x];
                        mp[comb]++;
                }
                map<string, int>::iterator it;
                for (it = mp.begin(); it != mp.end(); it++)
                        if ((*it).second > mx)mx = (*it).second;
                for (it = mp.begin(); it != mp.end(); it++)
                        if ((*it).second == mx)ans += mx;

                cout << ans << endl;
        }
        return 0;
}
