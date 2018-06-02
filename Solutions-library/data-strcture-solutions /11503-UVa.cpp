/*
Name: 11503 - Virtual Friends
Online Judge: UVa
Tags: Union Find Disjoint Sets, Map, Vector
Complexity:
Tutorial: Find if the size of the component using UFDS, we will use maps to convert the string to a numbers so it would be
easy to use UFDS.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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
			// rank is used to keep the tree short
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
	int t, n;
	string u, v;
	cin >> t;
	while (t--)
	{
		cin >> n;
		UnionFind UF(n * 2);
		map<string, int> nodes;
		int cn = 0;
		while (n--)
		{
			cin >> u >> v;
			if (nodes.find(u) == nodes.end())nodes[u] = cn++;
			if (nodes.find(v) == nodes.end())nodes[v] = cn++;
			UF.unionSet(nodes[u], nodes[v]);
			int p =  UF.findSet(nodes[u]);
			cout << UF.sizeOfSet(p) << endl;
		}

	}
	return 0;
}


