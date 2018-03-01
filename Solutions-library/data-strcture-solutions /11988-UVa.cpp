/*
Name: 11988 - Broken Keyboard (a.k.a. Beiju Text)
Online Judge: UVa
Tags: Lists
Complexity: 
Tutorial: If Home key then insert at the beginning and if the End key insert at the end.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        string s;
        while(cin >> s)
        {
                list <char> mylist;
                list<char>::iterator it;
                it = mylist.begin();
                for(int x = 0; x < s.length(); x++)
                {
                        if(s[x] == '[') it = mylist.begin();
                        else if(s[x] == ']') it = mylist.end();
                        else mylist.insert(it, s[x]);

                }
                for (it=mylist.begin(); it!=mylist.end(); ++it)
                        cout << *it;
                cout << endl;
        }

        return 0;
}
