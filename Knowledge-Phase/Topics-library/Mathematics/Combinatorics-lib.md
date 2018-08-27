# Topic

Table of Contents
================= 
* [Introduction To Counting](#Introduction-to-counting)
  + [Product Rule](#product-rule)
  + [Inclusion Exclusion](#inclusion-exclusion)
  + [Permutations And Combinations](#permutations-and-combinations)
  + [Combinatorial Arguments](#combinatorial-arguments)
  + [Pascals Triangle](#pascals-triangle)
  + [Binomial Coefficients](#binomial-coefficients)
  + [The Pigeonhole Principle](#the-pigeonhole-principle)
* [Partitions And Bijections](#partitions-and-bijections)
  + [Counting Subsets](#counting-subsets)
* [Counting Sequences](#counting-sequences)
  + [Fibonacci Numbers](#fibonacci-numbers)
  + [Catalan Numbers](#catalan-numbers)
* [Recurrence](#recurrence)
* [Burnsides Lemma](#burnsides-lemma)
* [Cayleys Formula](#cayleys-formula)
  
  
  
## Introduction To Counting
### Product Rule
```cpp
	// How many words of 3 letters of only B, C
  // means have 3 pos, and every pos may have 2 ways
	// 2 * 2 * 2 = 2^3 = 8 differnt words
	// generate it use 3 nested loops

	string let = "BC";
	for (int i = 0; i < 2; i++)
	{
		for (int ii = 0; ii < 2; ii++)
		{
			for (int iii = 0; iii < 2; iii++)
			{
				cout << let[i] << let[ii] << let[iii] << "\n";
			}
		}
	}
```
### Inclusion Exclusion
- Find the numbers that divide by 2, 3, 5 or 7 to 100
```cpp
	int n, ans = 0, ans2 = 0; string all;
	// n = 100, all = 2357
	cin >> n >> all;


	/*
	use this for small n
	*/
	for (int x = 1; x <= n; x++)
		if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 ||  x % 7 == 0)
			ans2++;


		
	/*
	use this for big n
	*/

	// generate all the subsets
	deque<string>subset;
	subset.push_back("");
	for (int x = 0; x < all.length(); x++)
	{
		int t = subset.size();
		for (int y = 0; y < t; y++)
			subset.push_back(subset[y] + all[x]);
	}
	// delete empty set
	subset.pop_front();
	// Compute each subset intersection
	for (int x = 0; x < subset.size(); x++)
	{
		/*
		if I have subset 237 then split it then
		multiply them togther then divide by 100
		to find the numbers that is divde by 2, 3 and 7
		*/
		int temp = 1;
		for (int y = 0; y < subset[x].length(); y++)
		{
			temp *= subset[x][y] - '0';
		}
		temp = n / temp;

		// odd subet then include
		if (subset[x].length() % 2 != 0)ans += temp;
		// even subset then exulde it
		else ans -= temp;
	}
	cout << ans << " " << ans2 << endl;
```
  
