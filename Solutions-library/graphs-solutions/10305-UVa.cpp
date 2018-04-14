/*
Name: 10305 - Ordering Tasks
Online Judge: UVa
Tags: Toplogical sort, Vectors
Complexity:
Tutorial: Just make direct toplogical sort
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int>res;
vector<int>in;
int n, m, u, v;
void toplog()
{
        priority_queue<int, vector<int>, greater<int> >pq; 
        for (int u = 1; u <= n; u++)
                if (in[u] == 0) pq.push(u);

        while (!pq.empty())
        {
                int top = pq.top(), size = adj[top].size();
                pq.pop(); res.push_back(top);

                for (int x = 0; x < size; x++)
                {
                        int u = adj[top][x];
                        if (--in[u] == 0)pq.push(u);
                }
        }
}

int main()
{

        while (true)
        {
                cin >> n >> m;
                adj = vector< vector<int> >(n + 1);
                in = vector<int>(n + 1);
                res.clear();
                if (n == 0 && m == 0)break;
                for (int x = 0; x < m; x++)
                {
                        cin >> u >> v;
                        adj[u].push_back(v);
                        in[v]++;
                }
                toplog();
                for (int x = 0; x < res.size(); x++)
                        cout << res[x] << " ";
                cout << endl;


        }

        return 0;
}
