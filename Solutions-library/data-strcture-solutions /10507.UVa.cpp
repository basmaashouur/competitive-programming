
/*
Name: 10507 - Waking up brain
Online Judge: UVa
Tags: Vectors, brute force
Complexity:
Tutorial: check every unwake cell, and see if it has more than 3 parent are awake then we should awake it,
but be carfull the 3 awake parent must be awaken in pervious stages not the same as it's satge
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, e;
	string ln, on, edg;
	while (cin >> n)
	{
		cin >> e >> on;
		vector<vector<int>> adj;
		vector<int>awake;
		int check = 0, years = 0;
		adj.resize(26);
		awake.assign(26, 0);
		awake[int(on[0]) - 65] = 1;
		awake[int(on[1]) - 65] = 1;
		awake[int(on[2]) - 65] = 1;
		while (e--)
		{
			int v, u;
			cin >> edg;
			v = int(edg[0]) - 65;
			u = int(edg[1]) - 65;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int f = 0; f < 26; f++)
		{
			int cn = 0;
			for (int m = 0; m < 26; m++)cn += awake[m];
			if (cn == n)break;
			years++;
			// check who is awake in this stage
			vector<int>temp;
			for (int x = 0; x < 26; x++)
			{
				int awcn = 0;
				if (awake[x] == 0)
				{
					for (int y = 0; y < adj[x].size(); y++)
					{
						check = 0;
						// to check who is in this stage
						// to not make his child awake too
						// because they should wait another year mean wait the other stage
						for (int z = 0; z < temp.size(); z++)
							if (adj[x][y] == temp[z])check = 1;
						
						if (check == 0)awcn += awake[adj[x][y]];
					}
					if (awcn > 2)
						awake[x] = 1, temp.push_back(x);
				}
			}
		}

		int cn = 0;
		for (int m = 0; m < 26; m++)cn += awake[m];
		if (cn < n) check = 1;
		if (check == 1)cout << "THIS BRAIN NEVER WAKES UP\n";
		else cout << "WAKE UP IN, " << years << ", YEARS\n";
		getline(cin, ln);
	}
	return 0;
}

