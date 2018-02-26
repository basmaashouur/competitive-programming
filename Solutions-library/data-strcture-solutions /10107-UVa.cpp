/*
Name: 10107 - What is the Median?
Online Judge: UVa
Tags: Vectors, Sorting
Complexity: 
Tutorial: Sort every time you push into the vector then find the median.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long x;
        vector <long long> vec;
        while(cin >> x)
        {
                vec.push_back(x);
                sort(vec.begin(), vec.end());
                if(vec.size() % 2 == 1)
                        cout << vec[vec.size()/2] << endl;
                else
                        cout << (vec[vec.size()/2] +vec[vec.size()/2 -1]) /2 << endl;

        }
}
