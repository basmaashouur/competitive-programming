/*
Name: 11094 - Continents
Online Judge: UVa
Tags: Flood Fill, Vectors, 2DArray
Complexity: O(N + M)
Tutorial: First know what is the land cell, and that would be the initial continent cell, then mark all the initial continent
cells, now try to find the max connected continent cells using flood fill, be carefull you can reach from any 
first column cell to any last column cell and vice versa, (x, 0) --> <-- (x, m - 1).
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
int visited[21][21] = {{0, 0}, {0, 0}};
vector<string> vec;
int n, m, ex, wy, ans[500] = {0};
string all;
static int moves[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

void fill(int x, int y, char go, int index)
{
        if (x >= n || y >= m || x < 0 || y < 0 )return;
        if (visited[x][y] == 1)return;
        visited[x][y] = 1;
        if (vec[x][y] != go)return;
        ans[index]++;
        if (isalpha(vec[x][y]))vec[x][y] = '*';
        else vec[x][y] = 'a';
        for (int i = 0; i < 4; i++)
        {
                fill(x + moves[i][0], y + moves[i][1], go, index);
                if (y == 0)fill(x, m - 1, go, index);
                if (y == m - 1)fill(x, 0, go, index);
        }
}


int main()
{
        while (cin >> n >> m)
        {
                for (int i = 0; i < n; i++)
                {
                        cin >> all;
                        vec.push_back(all);
                }
                cin >> ex >> wy;
                char go = vec[ex][wy];
                fill(ex, wy, go, 0);
                int index = 0;
                ans[0] = 0;
                for (int x = 0; x < n; x++)
                        for (int y = 0; y < m; y++)
                                if (visited[x][y] == 0)
                                        fill(x, y, go, index), index++;
                int mx = 0;
                for (int x = 0; x < 400; x++)
                        if (ans[x] > mx)mx = ans[x];
                cout << mx << endl;
                vec.clear();
                memset(ans, 0, sizeof(ans));
                memset(visited, 0, sizeof(visited[0][0]) * 21 * 21);
                string f; getline(cin, f);
        }

        return 0;
}

