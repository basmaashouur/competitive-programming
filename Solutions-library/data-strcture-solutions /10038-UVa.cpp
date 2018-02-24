/*
Name: 10038 - Jolly Jumpers
Online Judge: UVa
Tags: Vectors, Indexing
Tutorial: save the absolute values of the difference between successive elements
in the index that equal that value, then check from 1 to n-1 if there is a value inside it
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n, v, check;
        while(cin>>n)
        {
                vector <int> vec;
                vector <int> fin (3001, -1);
                check = 0;
                for(int x = 0; x < n; x++)
                {
                        cin>>v;
                        vec.push_back(v);
                        if(x != 0)
                                fin[abs(vec[x-1] - vec[x])] = abs(vec[x-1] - vec[x]);
                }

                for(int x = 1; x < n; x++)
                        if(fin[x] != x) check = 1;

                if(check == 1) cout << "Not jolly" << endl;
                else cout << "Jolly" << endl;
        }
        return 0;
}
