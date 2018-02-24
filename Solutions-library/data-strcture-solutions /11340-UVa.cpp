/*
Name: 11340 - Newspaper
Online Judge: UVa
Tags: 1D Array, Hashing
Tutorial: Make an array for the ASCII character, then hash the char into that array 
and save the price in cents in that index [Cents can be a float number]
then find that total price for every char in the article using the same hash function.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin >> n;
        while(n--)
        {
                int k, m, cent;
                double alpha [250] = {0}, ans = 0;
                char ch; string article;
                cin >> k;
                for(int x = 0; x < k; x++)
                {
                        cin >> ch >> cent;
                        alpha[(int)ch] = cent;
                }
                cin >> m;
                cin.ignore();
                for(int x = 0; x < m; x++)
                {
                        getline(cin, article);
                        for(int y = 0; y < article.length(); y++)
                                ans += alpha[(int)article[y]];
                }
                cout << fixed << setprecision(2) << ans / 100.0 << "$" << endl;
        }
        return 0;
}
