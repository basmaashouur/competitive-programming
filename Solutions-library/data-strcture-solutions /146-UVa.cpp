/*
Name: 146 - ID Codes
Online Judge: UVa
Tags: STL Algorithm
Tutorial: Find the next greater permutation, if there is no next greater permutation
print No Successor
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        while(true)
        {
                string s;
                cin >> s;
                if(s == "#") break;
                bool val = next_permutation(s.begin(), s.end());
                if (val == false)
                        cout << "No Successor" << endl;
                else
                        cout << s << endl;
        }
        return 0;
}
