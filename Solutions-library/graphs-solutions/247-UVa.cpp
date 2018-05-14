/*
Name: 247- Calling Circles
Online Judge: UVa
Tags: Strongly Connected Components, Vector, Map, Stack
Complexity:
Tutorial: Find all the SCC using tarjan but be carfull from the disconnceted graph, so be sure to itratte over
all the graphs and findind SCC.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

map<string, vector<string> > adj;
map<string, int> low;
map<string, int> dfn;
map<string, int>  visited;
stack<string>curr;
int timer = 1;

void tarjanSCC(string node)
{
	visited[node] = true;
	dfn[node] = low[node] = timer++;
	curr.push(node);

	for (int i = 0; i < adj[node].size(); i++)
	{
		string child = adj[node][i];
		if (!dfn[child])
			tarjanSCC(child);
		if (visited[child])
			low[node] = min(low[node], low[child]);
	}
	if (dfn[node] == low[node])
	{
		while (true)
		{
			string v = curr.top();
			cout << v;
			if (v != node)cout << ", ";
			curr.pop(); visited[v] = false;
			if (v == node) {cout << endl; break;}

		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, cn = 1;
	string fi, se;
	bool blank = false;
	while (true)
	{
		cin >> n >> m;
		set<string>all;
		if (n == 0 && m == 0)break;
		if (blank)cout << endl;
		blank = true;
		for (int x = 0; x < m; x++)
		{
			cin >> fi >> se;
			all.insert(fi);
			all.insert(se);
			adj[fi].push_back(se);
		}
		cout << "Calling circles for data set " << cn++ << ":" << endl;;
		for (auto it = all.begin(); it != all.end(); ++it)
		{
			if (!dfn[*it])
				tarjanSCC(*it);
		}

		adj.clear(); low.clear(); dfn.clear();
		visited.clear(); curr = stack<std::string>();
		timer = 1;
	}
	return 0;
}
