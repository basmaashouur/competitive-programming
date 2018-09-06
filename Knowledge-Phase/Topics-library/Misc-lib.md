# Misc

Table of Contents
================= 
- [Two Pointers](#two-pointers)
- [Contiguous Subarray](#contiguous-subaaray)
  * [Cumulative Sum](#cumulative-sum)
    + [1D](#1d)
    + [2D](#2d)
  * [Partial Sum](#partial-sum)
  * [Equal Sum](#equal-sum)
  * [Closet Sum](#closet-sum)
  * [Max Sum](#max-sum)
  * [Min Sum](#min-sum)
  * [Zero Sum](#zero-sum)
  * [Equilibrium Index](#equilibrium-index)
  * [](#)
  * [](#)
  * [](#)
  * [](#)
  * [Max Element Range](#max-element-range)
- [Subsequence](#subsequence)

# Two Pointers
```cpp
```
# Subarray
## Cumulative Sum
### 1D
- Use one based
```cpp
        int n; cin >> n;
	vector<int> cm(n + 1);
	for (int x = 1; x <= n; x++)
		cin >> cm[x];

	for (int x = 2; x <= n ; x++)
		cm[x] += cm[x - 1];
	
       // to find any sum of cell [L,R]
       // one based index inclusive
	int ans, l, r;
	cin >> l >> r;
	ans = cm[r] - cm[l - 1];
	cout << ans << endl;
```
### 2D
- Use one based
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
```cpp
```

