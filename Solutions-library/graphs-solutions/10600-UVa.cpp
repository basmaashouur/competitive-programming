/*
Name: 10600 - ACM Contest and Blackout
Online Judge: UVa
Tags: Minimum Spanning Tree, Second Best Spanning Tree, Vector
Complexity: O(VE)
Tutorial: Find the second best spanning tree, be carfull to make sure while searching that the finding
graph is spanning tree not somthing else.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
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
	int t; cin >> t;
	while (t--)
	{
		int V, E, u, v, w;
		cin >> V >> E;
		vector< pair<int, ii> > EdgeList;

		for (int i = 0; i < E; i++)
		{
			cin >> u >> v >> w;
			EdgeList.push_back(make_pair(w, ii(u - 1, v - 1)));
		}
		sort(EdgeList.begin(), EdgeList.end());

		int mst_cost = 0, temp_cost = 0, sec_cost = 30001;
		UnionFind UF(V);
		vector<int> exclude;
		for (int i = 0; i < E; i++)
		{
			pair<int, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				mst_cost += front.first;
				exclude.push_back(i);
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		for (int x = 0; x < exclude.size(); x++)
		{
			UnionFind UF(V); temp_cost = 0;
			for (int i = 0; i < E; i++)
			{
				pair<int, ii> front = EdgeList[i];
				if (!UF.isSameSet(front.second.first, front.second.second) && i != exclude[x])
				{
					temp_cost += front.first;
					UF.unionSet(front.second.first, front.second.second);
				}
			}
			int check;
			if (x == 0)check = exclude[1];
			else check = exclude[0];
			if (temp_cost < sec_cost && UF.numDisjointSets() == 1)sec_cost = temp_cost;
		}
		cout << mst_cost << " " << sec_cost << endl;
	}

	return 0;
}
