/*
Name: 11631 - Dark roads
Online Judge: UVa
Tags: Minimum Spanning Tree, Vector
Complexity:
Tutorial: Finding the MST cost and the total cost, and then substract them to know how much did they save.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vii> AdjList; // vector of vector of pairs
class UnionFind
{

private:
	vi p, rank, setSize;
	int numSets;

public:

	UnionFind(int N)
	{
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}

	int findSet(int i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
			{
				p[y] = x; setSize[x] += setSize[y];
			}
			else
			{
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}

	int numDisjointSets() { return numSets; }

	int sizeOfSet(int i) { return setSize[findSet(i)]; }

};

int main()
{
	int V, E, u, v, w;
	while (true)
	{
		cin >> V >> E;
		if (V == 0 && E == 0)break;

		AdjList.assign(V, vii());
		vector< pair<int, ii> > EdgeList;
		int mst_cost = 0, tot_cost = 0;

		for (int i = 0; i < E; i++)
		{
			cin >> u >> v >> w;
			tot_cost += w;
			EdgeList.push_back(make_pair(w, ii(u, v)));
			AdjList[u].push_back(ii(v, w));
			AdjList[v].push_back(ii(u, w));
		}
		sort(EdgeList.begin(), EdgeList.end());

		UnionFind UF(V);
		for (int i = 0; i < E; i++)
		{
			pair<int, ii> front = EdgeList[i];
			// u & v are not connected
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				// weight
				mst_cost += front.first;
				// connect u & v
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		cout << tot_cost - mst_cost << endl;
	}

	return 0;
}
