/*
Name: 11228 - Transportation system.
Online Judge: UVa
Tags: Minimum Spanning Tree, Vector, Euclidean distance
Complexity:
Tutorial: The states are the number of disjoint sets, the road is the weight of the bridges that can connect,
the railroads are the numbers of the bridges that cannot connect due they are bigger than r, but it must be the min
bridges.
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
	int E, r, t, ex, wy;
	cin >> t;
	for (int b = 1; b <= t; b++)
	{
		cin >> E >> r;
		vector< pair<double, ii> > EdgeList;
		vector<ii> coorid;

		for (int i = 0; i < E; i++)
		{
			cin >> ex >> wy;
			coorid.push_back(make_pair(ex, wy));
		}

		for (int x = 0; x < E; x++)
		{
			for (int y = 1; y < E; y++)
			{
				double dist = sqrt(double(pow(coorid[x].first - coorid[y].first, 2) +
				                          pow(coorid[x].second - coorid[y].second, 2)));
				EdgeList.push_back(make_pair(dist, ii(x, y)));
			}
		}

		sort(EdgeList.begin(), EdgeList.end());
		double road = 0, railroad = 0;
		UnionFind UF(E);
		for (int i = 0; i < EdgeList.size(); i++)
		{
			pair<double, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second) && front.first <= r)
			{
				UF.unionSet(front.second.first, front.second.second);
				road += front.first;
			}
		}
		int states =  UF.numDisjointSets();
		for (int i = 0; i < EdgeList.size(); i++)
		{
			pair<double, ii> front = EdgeList[i];
		 if (!UF.isSameSet(front.second.first, front.second.second) && front.first > r)
			{
				UF.unionSet(front.second.first, front.second.second);
				railroad += front.first;
			}
		}
		cout << "Case #" << b << ": " << states  << " " << round(road) << " " << round(railroad) << endl;

	}

	return 0;
}


