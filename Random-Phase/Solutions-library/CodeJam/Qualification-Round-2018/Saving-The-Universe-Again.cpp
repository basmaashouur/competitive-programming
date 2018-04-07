/*
Name: Qualification Round 2018, Saving The Universe Again
Online Judge: Code Jam
Tags: Greedy
Complexity: 
Tutorial: 
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

int main()
{
        int t, d;
        string p;
        cin >> t;
        for (int x = 1; x <= t; x++)
        {
                cin >> d >> p;
                vector<int>shoot;
                int charge = 1, all = 0, cn = 0;
                for (int y = 0; y < p.length(); y++)
                {
                        if (p[y] == 'C')charge *= 2;
                        else shoot.push_back(charge), all += charge;

                }
                for (int z = 0; z < shoot.size(); z++)
                {
                        if (all <= d)break;
                        while (true)
                        {
                                if (shoot[z] == 1 || all <= d)break;
                                all -=  shoot[z] / 2;
                                shoot[z] /= 2;
                                cn++;
                        }
                }
                if (all <= d) cout << "Case #" << x << ": " << cn << endl;
                else cout << "Case #" << x << ": "  << "IMPOSSIBLE" << endl;;
        }

        return 0;
}


