/*
Name: 10986 - Sending email
Online Judge: UVa
Tags: SSSP  Dijkstra, Vector
Complexity:
Tutorial: Just find the SSSP using  Dijkstra
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
	int N; cin >> N;
	for (int x = 1; x <= N; x++)
	{
		int V, E, s, t, u, v, w;
		vector<vii> AdjList;
		cin >> V >> E >> s >> t;

		AdjList.assign(V, vii());
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v >> w;
			AdjList[u].push_back(ii(v, w));
			AdjList[v].push_back(ii(u, w));
		}

		vi dist(V, INF); dist[s] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
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
		cout << "Case #" << x << ": ";
		if (dist[t] == INF)cout << "unreachable" << endl;
		else cout << dist[t] << endl;
	}
	return 0;
}
