/*
Name: 978 - Lemmings Battle!
Online Judge: UVa
Tags: Multiset, simulation
Complexity: O(N*(2*10^5))
Tutorial: Simulate the process using multiset, erase the soldiers after every battle then insert the winning soldier
with his new power, and check if any of the blue or green or both soldier having no remaining then soldier then 
the battle is over, be carefull of the arrangment of the if condtions.  
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int t;
        cin >> t;
        while (t--)
        {
                int b, sg, sb, v;
                multiset<int>green;
                multiset<int>blue;
                cin >> b >> sg >> sb;
                while (sg--)
                {
                        cin >> v;
                        green.insert(v);
                }
                while (sb--)
                {
                        cin >> v;
                        blue.insert(v);
                }

                while (true)
                {

                        std::multiset<int>::reverse_iterator itb, itg;
                        vector<int> blu;
                        vector<int> gre;

                        // itarte to b
                        if (blue.size() >= b && green.size() >= b)
                        {
                                int st = 0;
                                for (itb = blue.rbegin(), itg = green.rbegin();; ++itb, ++itg)
                                {
                                        if (st == b)break;
                                        blu.push_back(*itb);
                                        gre.push_back(*itg);
                                        st++;
                                }
                                // erase
                                for (int x = 0 ; x < b; x++)
                                {
                                        green.erase(--green.end());
                                        blue.erase(--blue.end());
                                }
                                for (int x = 0; x < b; x++)
                                {
                                        if (blu[x] > gre[x])blue.insert(blu[x] - gre[x]);
                                        else if (gre[x] > blu[x])green.insert(gre[x] - blu[x]);
                                }
                                blu.clear();
                                gre.clear();
                        }

                        else if (blue.empty() &&  green.empty())
                        {
                                cout << "green and blue died" << endl;;
                                break;

                        }

                        else if (green.empty())
                        {
                                cout << "blue wins" << endl;
                                for (auto it = blue.rbegin(); it != blue.rend(); ++it)
                                        cout << *it << endl;
                                break;

                        }

                        else if (blue.empty())
                        {
                                cout << "green wins" << endl;
                                for (auto it = green.rbegin(); it != green.rend(); ++it)
                                        cout << *it << endl;
                                break;
                        }

                        // if blue or green or both smaller than battle
                        // take the min of them, and itrate to that mint
                        else if (blue.size() < b || green.size() < b)
                        {
                                int st = 0, mn = min(blue.size(), green.size());
                                for (itb = blue.rbegin(), itg = green.rbegin();; ++itb, ++itg)
                                {
                                        if (st == b)break;
                                        blu.push_back(*itb);
                                        gre.push_back(*itg);
                                        st++;
                                }
                                // erase
                                for (int x = 0 ; x < mn; x++)
                                {
                                        green.erase(--green.end());
                                        blue.erase(--blue.end());
                                }
                                for (int x = 0; x < mn; x++)
                                {
                                        if (blu[x] > gre[x])blue.insert(blu[x] - gre[x]);
                                        else if (gre[x] > blu[x])green.insert(gre[x] - blu[x]);
                                }
                                blu.clear();
                                gre.clear();
                        }
                }
                if ( t > 0)cout << endl;

        }
        return 0;
}
