/*
Name: 12210 - A Match Making Problem
Online Judge: UVa
Tags: Greedy, Sorting, Binary search, List, Vector
Complexity: O(n log n)
Tutorial: We will take the max bach and find the girl to marry him, search for her using binary search
in a list and find the best match, then delete her from the list and delete him from the vector
, take care of all the corner test cases while handling the list.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
        int b, s, v, ca = 1;
        while (true)
        {
                cin >> b >> s;
                vector<int>bach;
                list<int>spin;
                if (b == 0 && s == 0)break;
                for (int x = 0; x < b; x++)
                {
                        cin >> v;
                        bach.push_back(v);
                }
                for (int x = 0; x < s; x++)
                {
                        cin >> v;
                        spin.push_back(v);
                }
                sort(bach.begin(), bach.end());
                spin.sort();
                for (int x = b - 1; x >= 0; x--)
                {
                        if (!spin.empty())
                        {
                                auto low = lower_bound(spin.begin(), spin.end(), bach[x]);
                                // didn't find an element bigger or equal it
                                // so the last girl is the best match
                                if (low == spin.end())
                                {
                                        --low, spin.erase(low);
                                        bach.pop_back();

                                }
                                // best match lay at first, then she is the best
                                // or  only have one girl then she is the bes
                                else if (low == spin.begin() || spin.size() == 1)
                                {
                                        spin.erase(low);
                                        bach.pop_back();
                                }
                                // see what is best match
                                else
                                {
                                        auto one = low, two = --low;
                                        if (abs(bach[x] - *one) < abs(bach[x] - *two))
                                        {
                                                spin.erase(one);
                                                bach.pop_back();
                                        }
                                        else
                                        {
                                                spin.erase(two);
                                                bach.pop_back();
                                        }
                                }
                        }
                        else break;
                }
                cout << "Case " << ca << ": " << bach.size();;
                if (!bach.empty())
                        cout << " " <<  bach[0];
                cout << endl;
                ca++;
        }
        return 0;
}
