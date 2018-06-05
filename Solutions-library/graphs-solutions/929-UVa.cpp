/*
Name: 929 - Number Maze
Online Judge: UVa
Tags: SSP Dijkstra
Complexity:
Tutorial: First convert the 2D array into 1D and put all the weights, then run SSP from source,
be carefull to add the weight of the first cell [0][0]
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

static int moves[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, m, w, V, t, s = 0;
		cin >> n >> m; V = n * m;
		t = ((n - 1) * m) + m - 1;
		vector<vii> AdjList;
		vector<vector<int>>weights(n * m);
		AdjList.assign(V, vii());
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				cin >> w;
				weights[x].push_back(w);
			}
		}

		// convert 2D array into 1D array and build the graph
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				for (int i = 0; i < 4; i++)
				{
					int ex = x + moves[i][0], wy = y + moves[i][1];
					if (ex < n && wy < m && ex >= 0 && wy >= 0)
						AdjList[x * m + y].push_back(ii(ex * m + wy, weights[ex][wy]));
				}
			}
		}

		// SSSP
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
		cout << dist[t] + weights[0][0] << endl;
	}

	return 0;
}
