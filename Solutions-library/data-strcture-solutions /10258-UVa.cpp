/*
Name: 10258 - Contest Scoreboard
Online Judge: UVa
Tags: Vectors, 2D Arrays, Sorting, String parsing
Complexity: 
Tutorial: the sort key is (most problems, least penalty, least team number)
so we can sort in this way inside a vector of nested pairs, but first we need to multiply penalty
and team by -1, so when sortin in increasing order it's gonna sort right, and then mutiply it agian by -1
to return it to the original.
Take care of the fact that Penalty time is computed  for the first correct submission for a problem, 
the second correct submission doesn't count.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int test; string s;
        cin >> test; cin.ignore();
        getline(cin, s);
        for(int c = 0; c < test; c++)
        {
                int wro [101][11] = {{0, 0},{0, 0}};
                int acc [101][11] = {{0, 0},{0, 0}};
                vector <pair <pair <int, int>, int> > vec (101);
                for(int x = 0; x <= 100; x++)
                {
                        vec[x].first.first = 0; // problems
                        vec[x].first.second = -1; // penalty
                        vec[x].second =  x * -1; // team number
                }
                while(true)
                {
                        getline(cin, s);
                        if(s == "") break;
                        
                       // string parsing
                       int con = -1, pro = -1, ti = -1;
                        char l; string split;
                        for(int x = 0; x < s.length(); x++)
                        {
                                if(s[x] == ' ')
                                {
                                        if(con == -1) con = stoi(split);
                                        else if (pro == -1) pro = stoi(split);
                                        else ti = stoi(split);
                                        split ="";
                                }
                                else split += s[x];
                        }
                        l = split[0];
                        
                        // know which stand
                        if(l == 'C')
                        {
                                if(vec[con].first.second == -1)
                                        vec[con].first.second = 0;
                                if(acc[con][pro] == 0)
                                {
                                        acc[con][pro] = 1;
                                        vec[con].first.second += ti + (wro[con][pro]*20);
                                        vec[con].first.first++;
                                }

                        }
                        else if(l == 'I')
                        {
                                if(vec[con].first.second == -1)
                                        vec[con].first.second = 0;
                                wro[con][pro]++;
                        }
                        else
                        {
                                if(vec[con].first.second == -1)
                                        vec[con].first.second = 0;
                        }
                }
                
                for(int x = 0; x <= 100; x++)
                        if(vec[x].first.second != -1)
                                vec[x].first.second *=-1;  // penalty

                sort(vec.begin(), vec.end());
                for(int x = 100; x > 0; x--)
                {
                        if(vec[x].first.second != -1)
                        {
                                cout << vec[x].second * -1<< " " << vec[x].first.first;
                                cout << " " << vec[x].first.second* -1 << endl;
                        }
                }
                if(c != test-1)
                        cout << endl;
        }
        return 0;
}
