/*
Name: 796 - Critical Links
Online Judge: UVa
Tags: Bridges, Vector, Sorting
Complexity:
Tutorial: Finding the bridges in the graph
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj;
vector<int> low;
vector<int> dfn;
vector<int> parent;
vector  < pair < int,  int >>  bridges;
int timer, rootchild, root, n;

void tarjanBR(int node)
{
	dfn[node] = low[node] = timer++;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];
		if (dfn[child] == -1)
		{
			parent[child] = node;
			tarjanBR(child);
			if (low[child] > dfn[node])
			{
				int mx = max(node, child);
				int mn = min(node, child);
				bridges.push_back(make_pair(mn, mx));
			}
			low[node] = min(low[node], low[child]);
		}
		else if (parent[node] != child)
			low[node] = min(low[node], dfn[child]);
	}
}

int main()
{
	while (cin >> n)
	{
		int u, v; timer = 0; string s;
		adj = vector<vector<int> >(n);
		low = vector<int>(n);
		dfn = vector<int>(n, -1);
		parent = vector<int>(n);
		bridges.clear();
		for (int x = 0; x < n; x++)
		{
			cin >> u >> s;
			s.pop_back();
			s.erase(0, 1);
			int sz = stoi(s);
			while (sz--)
			{
				cin >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (dfn[i] == -1)
			{
				root = i; rootchild = 0;
				tarjanBR(i);
			}
		}
		getline(cin, s);

		sort(bridges.begin(), bridges.end());
		cout << bridges.size() << " critical links" << endl;
		for (int x = 0; x < bridges.size(); x++)
			cout << bridges[x].first << " - " << bridges[x].second << endl;
		cout << endl;
	}

	return 0;
}
