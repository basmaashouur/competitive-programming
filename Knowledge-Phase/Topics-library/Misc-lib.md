# Misc

Table of Contents
================= 
- [Two Pointers](#two-pointers)
- [Subarray](#subaaray)
  * [Cumulative Sum](#cumulative-sum)
    + [1D](#1d)
    + [2D](#2d)
  * [Partial Sum](#partial-sum)
  * [Equal Sum](#equal-sum)
  * [Closet Sum](#closet-sum)
  * [Biggest Sum](#biggest-sum)
  * [Smallest Sum](#smallest-sum)
-[Subsequence](#subsequence)

# Two Pointers
```cpp
```
# Subarray
## Cumulative Sum
### 1D Use one based
```cpp
int n; cin >> n;
	vector<int> cm(n + 1);
	for (int x = 1; x <= n; x++)
		cin >> cm[x];

	for (int x = 2; x <= n ; x++)
	{
		cm[x] += cm[x - 1];
		cout << cm[x] << endl;
	}
	
	// to find any sum of cell [L,R]
 // L & R are inclusive and 1 based
	int ans, l, r;
	cin >> l >> r;
	ans = cm[r] - cm[l - 1];
	cout << ans << endl;
```
### 2D Use two based
```cpp
```

## Partial Sum
```cpp
```

