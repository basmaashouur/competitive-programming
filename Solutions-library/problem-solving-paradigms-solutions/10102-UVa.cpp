/*
Name: 10102 - The path in the colored field
Online Judge: UVa
Tags: 
Complexity: 
Tutorial: independent on the initial state sentence means wherever we place the answer is the same for every 1 to 3,
so we need to find a fixed number for the distance between 1 and three which would satisfy for all initial states,
by finding evry min distance between every 1 and 3, and then the max of them would satisfy for all initial states,
and that would be our answer.
By code find the pos of all the ones and threes, and then for every one find the min ditsance to the three,
then for all the min distance the max of them would be our answer.

so thats why we take the maximum here

(satisfy all)

*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int m;
        string f;
        while (cin >> m)
        {
                vector<pair<int, int> >one;
                vector<pair<int, int> >three;
                vector<int>mn;
                for (int x = 0; x < m; x++)
                {
                        cin >> f;
                        for (int y = 0; y < m; y++)
                        {
                                if (f[y] == '1')one.push_back(make_pair(x, y));
                                else if (f[y] == '3')three.push_back(make_pair(x, y));
                        }
                }
                for (int x = 0; x < one.size(); x++)
                {
                        int mindis = 100000;
                        for (int y = 0; y < three.size(); y++)
                        {
                                if (abs(one[x].first - three[y].first) +
                                                abs(one[x].second - three[y].second) < mindis)
                                        mindis = abs(one[x].first - three[y].first) +
                                                 abs(one[x].second - three[y].second);
                        }
                        mn.push_back(mindis);
                }
                int ans = mn[0];
                for (int x = 1; x < mn.size(); x++)
                        ans = max(ans, mn[x]);
                cout << ans << endl;

        }
        return 0;
}
