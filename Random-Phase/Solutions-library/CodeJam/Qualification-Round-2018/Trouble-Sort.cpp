/*
Name: Qualification Round 2018, Trouble Sort
Online Judge: Code Jam
Tags: Sorting
Complexity:
Tutorial:
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

int main()
{
        int t, n; long long v, temp;
        cin >> t;
        for (int y = 1; y <= t; y++)
        {
                cin >> n;
                vector<long long>vec;
                for (int y = 0; y < n; y++)
                {
                        cin >> v;
                        vec.push_back(v);
                }
                int ch = -1, ans = 0;;
                while (true)
                {
                        if (ch == 0)break;
                        ch = 0;
                        for (int x = 0; x < n - 2; x++)
                        {
                                if (vec[x + 2] < vec[x])
                                {
                                        temp = vec[x + 2];
                                        vec[x + 2] = vec[x];
                                        vec[x] = temp;
                                        ch++;
                                }

                        }
                        if (is_sorted(vec.begin(), vec.end()))
                        {
                                ans = 1;
                                break;
                        }
                }
                if (ans)cout << "Case #" << y << ": OK" << endl;
                else
                {
                        for (int x = 0; x < n; x++)
                        {
                                if (x == 0)
                                {
                                        if (vec[x] > vec[x + 1])
                                        {
                                                ans = x;
                                                break;
                                        }
                                }

                                else if (x == n - 1)
                                {
                                        if (vec[x] < vec[x -1])
                                        {
                                                ans = x;
                                                break;
                                        }
                                }
                                else if (vec[x] > vec[x + 1] || vec[x] < vec[x - 1])
                                {
                                        ans = x;
                                        break;
                                }
                        }
                        cout << "Case #" << y << ": " << ans << endl;
                }
        }

        return 0;
}


