/*
Name: B. Maximum Absurdity
Online Judge: CodeForces
Tags: Cumulative Sum, priority queue, DP
Complexity: O(nlogn)
Tutorial: for every segment find the next segment that is the biggest and not intersect with her.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;
int sub = 1e6 + 5;
#define ll long long
int main()
{
	int n, k, idx = 1;
	cin >> n >> k;

	vector<ll> cm(n + 1);
	priority_queue<pair<ll, int> > pq;
	for (int x = 1; x <= n; x++)
		cin >> cm[x];
	for (int x = 1; x <= n ; x++)
		cm[x] += cm[x - 1];
	/*
	Add all the segments sum into a pair
	first pair is the sum the second is the index
	substract len from index becuse we wann sort as the min index
	pq sort as the biggest index
	*/
	while (true)
	{
		if (idx + k - 1 > n)break;
		ll sum = cm[idx + k - 1] - cm[idx - 1];
		pq.push(make_pair(sum, sub - idx));
		idx++;
	}

	int a , b; idx = 1;
	ll amx = 0, bmx = 0, left, right;
	pair<ll, int> w;

	/*
	 Now we hold every segment from 1 to n 
	 and check the biggest segment after here and 
	 the nested while loop check that if the segment after 
	 her not intrsect with her or before her
	*/

	while (pq.size() > 1)
	{
		w  = pq.top();
		while (sub - w.second < idx + k && !pq.empty())
		{
			pq.pop();
			w = pq.top();
		}
		left = cm[idx + k - 1] - cm[idx - 1];
		right = w.first;
		if (left + right > amx + bmx && sub - w.second >= idx + k)
		{
			amx = left;
			bmx = right;
			a = idx;
			b = sub - w.second;
		}
		idx++;
	}
	cout << a << " " << b << "\n";

	return 0;

}
