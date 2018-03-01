/*
Name: 1062 - Containers
Online Judge: UVa
Tags: Stacks, Sorting, Sets
Complexity: 
Tutorial: We have two cases, first we would be able to minimize the stacks and 
put the elements in a decreasing order in it, so the top element would always be the smallest, 
to do this we need to put the first elemnet that arrive in a stack then the next element
- if it's smaller than the pervious then put in the same stack, 
- if it's bigger make another stack
- if it's smaller but we have more than one stack to put it inside then we would choose (prove) code works without!!
  the stack that is the nearest (to the right) from that character
The second case that the optimal solution that we would have is s stack for every differnt character, 
the max woulde be 26 stacks,to do this we only need to put all the charcters in a set, 
the answer would be the set size.

*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        string cont;
        int cn = 0;
        while(true)
        {
                cin >> cont;
                set <char> sett;
                vector<stack<char> > st (26);
                if(cont == "end") break;
                cn++;
                int ans = -1, check = -1;

                for(int x = 0; x < cont.length(); x++)
                        sett.insert(cont[x]);

                for(int x = 0; x < cont.length(); x++)
                {
                        check = 0;
                        for(int y = 0; y < 26; y++)
                        {
                                if(!st[y].empty() && st[y].top() >= cont[x])
                                {
                                        st[y].push(cont[x]);
                                        check = 1;
                                        break;
                                }
                                else if(st[y].empty())
                                {
                                        st[y].push(cont[x]);
                                        check = 1;
                                        break;
                                }
                        }
                        // can't find a place in the stack for a new character
                        // need more stack, so the set size would be smaller
                        if (check == 0)
                        {
                                ans = sett.size();
                                break;
                        }
                }
                // set size
                if(ans != -1) cout << "Case " << cn << ": " << ans << endl;
                else
                {
                        ans = 0;
                        for(int x = 0; x < 26; x++)
                                if(!st[x].empty()) ans++;

                        if(sett.size()> ans)
                                cout << "Case " << cn << ": " << ans << endl;
                        else cout << "Case " << cn << ": " << sett.size() << endl;
                }
        }
        return 0;
}
