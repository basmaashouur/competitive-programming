/*
Name: 11838 - Come and Go
Online Judge: UVa
Tags: Strongly Connected Components, Vector
Complexity:
Tutorial: Find if the whole graph is SCC or not.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<vector<int> > scc;
vector<int> low;
vector<int> dfn;
vector<bool> visited;
vector<int>curr;
int timer = 0, n, m, u, v, p;

void tarjanSCC(int node)
{
	visited[node] = true;
	dfn[node] = low[node] = timer++;
	curr.push_back(node);

	for (int i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];
		if (!dfn[child])
			tarjanSCC(child);
		if (visited[child])
			low[node] = min(low[node], low[child]);
	}
	if (dfn[node] == low[node])
	{
		while (true)
		{
			int v = curr.back();
			scc[node].push_back(v);
			curr.pop_back(); visited[v] = false;
			if (v == node) break;

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true)
	{
		cin >> n >> m;
		adj = vector<vector<int> >(n);
		scc = vector<vector<int> >(n);
		visited = vector<bool>(n);
		low = vector<int>(n);
		dfn = vector<int>(n);
		curr.clear();
		if (n == 0 && m == 0)break;
		for (int x = 0; x < m; x++)
		{
			cin >> u >> v >> p;
			adj[u - 1].push_back(v - 1);
			if (p == 2)adj[v - 1].push_back(u - 1);
		}
		tarjanSCC(1);
		int check = 0;
		for (int x = 0; x < n; x++)
		{
			if (scc[x].size() == n)check = 1;
		}
		cout << check << endl;
	}

	return 0;
}


