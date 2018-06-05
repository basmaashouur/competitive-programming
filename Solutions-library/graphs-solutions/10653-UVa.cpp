/*
Name: 10653 - Bombs! NO they are Mines!!
Online Judge: UVa
Tags: SSSP BFS, Flood Fill, Vector
Complexity:
Tutorial: we will convert the 2D array into 1D using this forumla adj[x][y] = adj[x*m+y]
which m is the number of coloumns, now after convert it, build the graph and know the neghbors
of every node and remove the neghbors that contain bombs, now run a BFS to know the SSSP
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

static int moves[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

int main()
{
	int n, m, b, s, ex, wy, sx, sy, dx, dy, node, dest, ans = 0;
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		int bomb[1000][1000] = {{0, 0}, {0, 0}};
		vector<bool> visited(n * m);
		vector<int>short_path(n * m);
		vector<vector<int > >adj(n * m);
		cin >> b;
		while (b--)
		{
			cin >> ex >> s;
			while (s--)
			{
				cin >> wy;
				bomb[ex][wy] = 1;
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
					if (ex < n && wy < m && ex >= 0 && wy >= 0 && bomb[ex][wy] != 1)
						adj[x * m + y].push_back(ex * m + wy);
				}
			}
		}

		cin >> sx >> sy >> dx >> dy;
		node = sx * m + sy, dest = dx * m + dy;
		queue<int>q; q.push(node); visited[node] = true;
		while (!q.empty())
		{
			int father = q.front(); q.pop();
			for (int x = 0; x < adj[father].size(); x++)
			{
				int child = adj[father][x];
				if (!visited[child])
				{
					q.push(child);
					short_path[child] = father;
					visited[child] = true;
				}
			}
		}
		while (true)
		{
			if (short_path[dest] == node)break;
			else ans++, dest = short_path[dest];
		}
		cout << ans << endl;
	}
	return 0;
}
