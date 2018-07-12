/*
Name: 11953 - Battleships
Online Judge: UVa
Tags: Flood Fill, Vectors, 2DArrays
Complexity: O(N+N)
Tutorial: "Still alive" ships means that at least a ship has one x that is a neighbor, so we need to count the number 
of ships that are still alive, fill(x,y) if (x,y) =='x', means that ship still alive,and then we can only fill the neighbor 
cells that are 'x' or '@' only becauce it's mean they are part of the ship, and mark them as visited cells. 
The number of still alive ships is the times that we called the fill function. 
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
int visited[101][101] = {{0, 0}, {0, 0}};
vector<string> vec;
int t, n;
string all;
static int moves[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

void fill(int x, int y)
{
        if (x >= n || y >= n || x < 0 || y < 0 )return;
        if (visited[x][y] == 1)return;
        visited[x][y] = 1;
        if (vec[x][y] == '.')return;
        for (int i = 0; i < 4; i++)
        {
                fill(x + moves[i][0], y + moves[i][1]);
        }
}


int main()
{
        cin >> t;
        for (int z = 1; z <= t; z++)
        {
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                        cin >> all;
                        vec.push_back(all);
                }
                int ans = 0;
                for (int x = 0; x < n; x++)
                        for (int y = 0; y < n; y++)
                                if (vec[x][y] == 'x' && visited[x][y] == 0)
                                {
                                        fill(x, y);
                                        ans ++;
                                }

                cout << "Case " << z << ": " << ans << endl;
                vec.clear();
                memset(visited, 0, sizeof(visited[0][0]) * 101 * 101);
        }

        return 0;
}

