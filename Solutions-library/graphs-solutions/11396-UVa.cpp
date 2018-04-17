/*
Name: 11396 - Claw Decomposition
Online Judge: UVa
Tags: Bipartite Check
Complexity:
Tutorial: it's just a bipartite graph check
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int>col;
int n, u, v, check = 0;

void dfs(int node, int ncol)
{
        visited[node] = true;
        col[node] = ncol;
        for (int i = 0; i < adj[node].size(); i++)
        {
                int child = adj[node][i];
                if (!visited[child])
                {
                        int chicol;
                        if (ncol == 1)chicol = 0;
                        else chicol = 1;
                        dfs(child, chicol);
                }
                else if (col[child] == col[node])check = 1;
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        while (true)
        {
                cin >> n;
                adj = vector<vector<int> >(n);
                visited = vector<bool>(n);
                col = vector<int>(n);
                if (n == 0)break;
                while (true)
                {
                        cin >> u >> v;
                        if (u == 0 && v == 0)break;
                        adj[u - 1].push_back(v - 1);
                        adj[v - 1].push_back(u - 1);
                }
                dfs(0, 0);
                if (check == 1)cout << "NO" << '\n';
                else cout << "YES" << '\n';
                check = 0;
        }

        return 0;
}
