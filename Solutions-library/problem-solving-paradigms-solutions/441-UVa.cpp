/*
Name: 441 - Lotto
Online Judge: UVa
Tags: Iterative
Complexity: O(13!)
Tutorial: Find all the permutations of the set in length of six, using six nested loops.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int k, v, test =0;
        while (true)
        {
                cin >> k;
                if (k == 0)break;
                if(test != 0)cout << endl;
                test++;
                vector <int>vec;
                vector<string>ans;
                for (int x = 0; x < k; x++)
                {
                        cin >> v;
                        vec.push_back(v);
                }
                sort(vec.begin(), vec.end());

                for (int i = 0; i < k; i++)
                        for (int ii = i + 1; ii < k; ii++)
                                for (int iii = ii + 1; iii < k; iii++)
                                        for (int iv = iii + 1; iv < k; iv++)
                                                for (int v = iv + 1; v < k; v++)
                                                        for (int vi = v + 1; vi < k; vi++)
                                                        {
                                                                ans.push_back(to_string(vec[i]) + " " +
                                                                              to_string(vec[ii]) + " " +
                                                                              to_string(vec[iii]) + " " +
                                                                              to_string(vec[iv]) + " " +
                                                                              to_string(vec[v]) + " " +
                                                                              to_string(vec[vi]));
                                                        }
                for (int x = 0; x < ans.size(); x++)
                        cout << ans[x] << endl;
        }
        return 0;
}
