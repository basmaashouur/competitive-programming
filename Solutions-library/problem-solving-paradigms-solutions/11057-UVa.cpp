/*
Name: 11057 - Exact Sum
Online Judge: UVa
Tags: Sorting, Binary search, Vector
Complexity: O(n log n)
Tutorial: Sort thr vector and see if two numbers equal m, using lower bound,
be carefull lower bound return the value equal or greater, so the value no exist
it may return the end of vector, or may return a number bigger than the value
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
        int n, m, v, a, b, mn;
        while (cin >> n)
        {
                vector<int>vec;
                for (int x = 0; x < n; x++)
                {
                        cin >> v;
                        vec.push_back(v);
                }
                cin >> m;
                sort(vec.begin(), vec.end());
                mn =  1000001;
                for (int x = 0; x < n; x++)
                {
                        int temp = abs(vec[x] - m);
                        auto low = lower_bound(vec.begin(), vec.end(), temp);
                        //found
                        if (low != vec.end() && *low == temp)
                        {
                                if (abs(vec[x] - temp) < mn)
                                {
                                        a = vec[x];
                                        b =  temp;
                                        mn = abs(vec[x] - temp);
                                }
                        }
                }
                cout << "Peter should buy books whose prices are ";
                cout << min(a, b) << " and " << max(a, b) << "." << endl << endl;
        }

        return 0;
}
