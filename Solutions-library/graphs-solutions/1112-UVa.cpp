/*
Name: 1112 - Mice and Maze
Online Judge: UVa
Tags: SSSP Djkstra, Single destination multi source, Vector
Complexity:
Tutorial: Finding the SP using djkstra but run from destination, and be carfull the graph is dircted then 
when we revrse running from destination instead of from source then we need to revrse the dirction of the nodes.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main()
{
	int t;  cin >> t;
	string ln; getline(cin, ln);
	while (t--)
	{
		int V, E, exist, time, u, v, w, ans = 0;
		vector<vii> AdjList;
		cin >> V >> exist >> time >> E;
		AdjList.assign(V, vii());

		for (int i = 0; i < E; i++)
		{
			cin >> u >> v >> w;
			AdjList[v - 1].push_back(ii(u - 1, w));
		}

		// Dijkstra
		vi dist(V, INF); dist[exist - 1] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, exist - 1));
		while (!pq.empty())
		{
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;
			for (int j = 0; j < (int)AdjList[u].size(); j++)
			{
				ii v = AdjList[u][j];
				if (dist[u] + v.second < dist[v.first])
				{
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}

		for (int x = 0; x < dist.size(); x++)
			if (dist[x] <= time)ans++;
		cout << ans << endl;
		if (t) {getline(cin, ln); cout << endl;}
	}

	return 0;
}
