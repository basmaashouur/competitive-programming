/*
Name: 10295 - Hay Points
Online Judge: Uva
Tags: Map
Complexity: Count the repetition of the words in the description paragraph then 
find the money of that word if it's exist in the jobs.
Tutorial: 
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int m, n, money;
        string job, desc, word, check;
        cin >> m >> n;
        vector <pair <string, int> > vec;
        for (int x = 0; x < m; x++)
        {
                cin >> job >> money;
                vec.push_back(make_pair(job, money));
        }
        cin.ignore();
        while (n--)
        {
                long long ans = 0;
                map <string, int> mp;
                while (true)
                {
                        getline(cin, desc);
                        word = "", check="";
                        for(int x = 0; x< desc.length();x++)
                                if(desc[x]!=' ')check+=desc[x];
                        if (check == ".")break;
                        for (int x = 0; x < desc.length(); x++)
                        {
                                if (desc[x] == ' ')mp[word]++, word = "";
                                else word += desc[x];
                        }
                        mp[word]++;
                }
                for (int x = 0; x < m; x++)
                {
                        map<string, int>::iterator itr = mp.find(vec[x].first);
                        if (itr != mp.end()) ans += itr->second * vec[x].second;
                }
                
                cout << ans << endl;
        }

        return 0;
}
