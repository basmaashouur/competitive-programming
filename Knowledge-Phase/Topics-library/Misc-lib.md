# Misc

Table of Contents
================= 
- [Two Pointers](#two-pointers)
- [Contiguous Subarray Sum](#contiguous-subaaray)
  * [Cumulative Sum](#cumulative-sum)
    + [1D](#1d)
    + [2D](#2d)
  * [Partial Sum](#partial-sum)
  * [Equal Sum](#equal-sum)
  * [Closest Sum](#closest-sum)
  * [Max And Min Sum](#max-and-min-sum)
  * [Zero Sum](#zero-sum)
  * [Equilibrium Index](#equilibrium-index)
  * [Longest Increasing Subarray](#longest-increasing-subarray)
  * [Max Element Range](#max-element-range)
- [Subsequence](#subsequence)

# Two Pointers
```cpp
```
# Contiguous Subarray Sum
## Cumulative Sum
### 1D
- Use one based, O(n)
```cpp
        int n; cin >> n;
	vector<int> cm(n + 1);
	for (int x = 1; x <= n; x++)
		cin >> cm[x];

	for (int x = 1; x <= n ; x++)
		cm[x] += cm[x - 1];
	
       // to find any sum of cell [L,R]
       // one based index inclusive
	int ans, l, r;
	cin >> l >> r;
	ans = cm[r] - cm[l - 1];
	cout << ans << endl;
```
### 2D
- Use one based, O(n * m)
```cpp
	int n, m, v;
	cin >> n >> m;
	vector<vector<int>> cm;
	cm.resize(n + 5, vector<int>(m + 5, 0));

	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			cin >> cm[x][y];

	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= m; y++)
		{
			// sum rows
			cm[x][y] += cm[x][y - 1];
			// sum columns
			cm[x][y] += cm[x - 1][y];
			// Exulde the inclusion
			cm[x][y] -= cm[x - 1][y - 1];
		}
	}

	// to find any sum of cell [L(x,y),R(x,y)]
	// one based index inclusive
	int lx, ly, rx, ry;
	cin >> lx >> ly >> rx >> ry;
	int ans = cm[rx][ry] - cm[rx][ly - 1] - cm[lx - 1][ry] + cm[lx - 1][ly - 1];
	cout << ans << "\n";
```

## Partial Sum
- Find the final sum of index after range of queries on it, O(n)
```cpp
	int n, q, l, r, v;
	cin >> n >> q;
	vector<int>pr(n + 2, 0);
	while (q--)
	{
		cin >> l >> r >> v;
		pr[l] += v; pr[r + 1] += -v;
	}
	for (int x = 1; x <= n; x++)
		pr[x] += pr[x - 1];
    // now check every index to know the final sum of it
```
## Equal Sum
- O(nlogn)
```cpp
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> cm(n + 1);
	unordered_map<int, int> eq;
	for (int x = 1; x <= n; x++)
		cin >> cm[x];

	for (int x = 1; x <= n ; x++)
	{
		cm[x] += cm[x - 1];
		auto itr = eq.find(cm[x] - k);
		if (itr != eq.end())ans += itr->second;
		eq[cm[x]]++;
	}
	cout << ans << "\n";
```
## Closest Sum
- O(n)
```cpp
	int n, k, v;
	int maxSum = 0, currSum = 0, currEl = 0, maxEl = 0, left = 0;
	vector<int> closest;
	cin >> n >> k;

	for (int x = 0; x < n; x++)
	{
		cin >> v;
		closest.push_back(v);
	}
	for (int right = 0; right < n; right++)
	{
		currSum += closest[right];
		currEl++;
		while (currSum > k)
		{
			currSum -= closest[left++];
			currEl--;
		}
		if (currEl > maxEl) maxEl = currEl, maxSum = currSum;
	}
	cout << maxSum << " " << maxEl << endl;
```
## Max And Min Sum
## Zero Sum
- O(nlogn)
```cpp
	int n, ans = 0;
	cin >> n;
	vector<int> cm(n + 1);
	unordered_map<int, int> zero;
	for (int x = 1; x <= n; x++)
		cin >> cm[x];

	for (int x = 1; x <= n ; x++)
	{
		cm[x] += cm[x - 1];
		auto itr = zero.find(cm[x]);
		if ( cm[x] == 0 || itr != zero.end())ans = 1;
		zero[cm[x]]++;
	}
	cout << ans << "\n";
```
## Equilibrium Index
- O(n), index is one based
```cpp
	int n, leftSum = 0, rightSum = 0, ans = -1;
	cin >> n;
	vector<int> cm(n + 2);
	for (int x = 1; x <= n; x++)
	{
		cin >> cm[x];
		if (x != 1)rightSum += cm[x];
	}

	for (int x = 1; x <= n ; x++)
	{
		leftSum += cm[x];
		rightSum -= cm[x + 1];
		cout << leftSum << " " << rightSum << endl;
		if (leftSum == rightSum && x + 1 < n)ans = x + 1;
	}
	cout << ans << "\n";
```
## Check overlap between two intervals
```cpp
/*
What does it mean for the ranges to overlap? It means there exists some number C which is in both ranges, i.e.

x1 <= C <= y1
and

x2 <= C <= y2
Now, if we are allowed to assume that the ranges are well-formed (so that x1 <= x2 and y1 <= y2) then it is sufficient to test
*/

if(x1 <= y2 && x2 <= y1){//overlap}
```
