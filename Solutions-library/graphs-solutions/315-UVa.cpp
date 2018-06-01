/*
Name: 315 - Network
Online Judge: UVa
Tags: Articulation points, Vector
Complexity:
Tutorial: Find the Articulation points in the graph
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj;
vector<int> low;
vector<int> dfn;
vector<int> parent;
vector<int>cutp;
int timer, rootchild, root;

void tarjan_AP_BR(int node)
{
	dfn[node] = low[node] = timer++;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];
		if (dfn[child] == -1)
		{
			parent[child] = node;
			if (node == root)rootchild++;
			tarjan_AP_BR(child);
			if (low[child] >= dfn[node])cutp[node] = 1;
			low[node] = min(low[node], low[child]);
		}
		else if (parent[node] != child)
			low[node] = min(low[node], dfn[child]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true)
	{
		int n, cn = rootchild =  0;
		string ln; cin >> n;
		if (n == 0)break; timer = 0;
		adj = vector<vector<int> >(n + 1);
		low = vector<int>(n + 1);
		dfn = vector<int>(n + 1, -1);
		parent = vector<int>(n + 1);
		cutp = vector<int>(n + 1);
		cin.ignore();
		while (true)
		{
			vector<int>vec; string temp;
			getline(cin, ln);
			if (ln == "0")break;
			for (int x = 0; x < ln.length(); x++)
			{
				if (ln[x] != ' ') temp += ln[x];
				else vec.push_back(stoi(temp)), temp = "";
			}
			vec.push_back(stoi(temp));

			for (int x = 1; x < vec.size(); x++)
			{
				adj[vec[0]].push_back(vec[x]);
				adj[vec[x]].push_back(vec[0]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (dfn[i] == -1)
			{
				root = i; rootchild = 0;
				tarjan_AP_BR(i);
				cutp[root] = (rootchild > 1);
			}
		}
		for (int x = 0; x <= n; x++)
			if (cutp[x] == 1)cn++;
		cout << cn << endl;
	}

	return 0;
}


