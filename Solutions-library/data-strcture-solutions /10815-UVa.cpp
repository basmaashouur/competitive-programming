
/*
Name: 10815 - Andy's First Dictionary
Online Judge: UVa
Tags: Set, String Parsing
Complexity: 
Tutorial: Store the words in a set
*/

// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        string line, fin;
        set<string>ans;
        while (cin >> line)
        {
                fin ="";
                for (int x = 0; x < line.length(); x++)
                {
                        if (isalpha(line[x]))
                        {
                                fin += tolower(line[x]);
                        }
                        else 
                                if (fin != "")ans.insert(fin), fin="";
                }
                if (fin != "") ans.insert(fin);
        }

        for ( auto it = ans.begin(); it != ans.end(); ++it)
                cout << *it << endl;
        return 0;
}
