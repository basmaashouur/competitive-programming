/*
Name: 924 - Spreading The News
Online Judge: UVa
Tags: SSSP BFS, Vector, Map, Queue
Complexity:
Tutorial: Finding the level that have max nodes, the level that have nodes is the day and the number of nodes
in that level is daily boom size, we will find them using starightforward BFS
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int e, p, u, s;
	cin >> e;
	vector<vector<int> > adj(e);

	for (int x = 0; x < e; x++)
	{
		cin >> s;
		while (s--)
		{
			cin >> u;
			adj[x].push_back(u);
		}
	}
	cin >> p;
	while (p--)
	{
		cin >> u;
		vector<int> visited(e);
		vector<int> level(e);
		queue<int>q; map<int, int>cn;
		q.push(u);
		visited[u] = 1; level[u] = 1;
		while (!q.empty())
		{
			int father = q.front();
			q.pop();
			for (int x = 0; x < adj[father].size(); x++)
			{
				int child = adj[father][x];
				if (!visited[child])
				{
					q.push(child);
					level[child] = level[father] + 1;
					cn[level[father]]++;
					visited[child] = 1;
				}
			}
		}
		if (cn.empty())cout << 0 << endl;
		else
		{
			int day = 0, max =  0;
			for (auto it = cn.begin(); it != cn.end(); ++it)
				if (it ->second > max)
					day = it->first, max = it->second;
			cout << max << " " << day << endl;
		}

	}
	return 0;
}
