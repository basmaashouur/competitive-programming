/*
Name: 10226 - Hardwood Species
Online Judge: UVa
Tags: Maps
Complexity: 
Tutorial: Count the Repetition of every tree inside the map then itrate over the map and 
print the percentage of every tree.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        map<string, int> mp;
        string spe;
        int t;
        double total = 0;

        cin >> t;
        cin.ignore();
        cin.ignore();

        while (t--)
        {
                while(true)
                {
                        getline(cin, spe);
                        if (spe == "") break;
                        mp[spe]++;
                        total++;
                }
                map<string, int>::iterator it;
                for (it = mp.begin(); it != mp.end(); it++)
                {
                        cout << (*it).first << " ";
                        cout << fixed << setprecision(4) << ((*it).second / total) * 100.0 <<endl;
                }

                if(t > 0) cout << endl;
                mp.clear();
                total = 0;
        }
        return 0;
}
