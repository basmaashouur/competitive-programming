# List of MIsc Sup topic's Resources, Tags, Terminologies and Explanations 

Table of Contents
================= 

- [Resources And Approximate Time](#resources-and-approximate-time)
- [Tags](#tags)
- [Sup Topic Terminologies And Explanations](#sup-topic-terminologies-and-explanations)
- [Two Pointers](#two-pointers)
- [Contiguous Subarray Sum](#contiguous-subaaray)
  * [Cumulative Sum](#cumulative-sum)
  * [Partial Sum](#partial-sum)
  * [Equal Sum](#equal-sum)
  * [Closest Sum](#closest-sum)
  * [Max And Min Sum](#max-and-min-sum)
  * [Zero Sum](#zero-sum)
  * [Equilibrium Index](#equilibrium-index)
  * [](#)
  * [](#)
  * [](#)
  * [](#)
- [Subsequence](#subsequence)
   
   

## Resources And Approximate Time

Sup Topic Name   | Resources   | Approximate stydying <br> & solving time
-------------| -------------   |-------------   
**Contiguous Subarray Sum**|[Equal Sum](https://leetcode.com/problems/subarray-sum-equals-k/solution/)<br>[Max Subarray](https://en.wikipedia.org/wiki/Maximum_subarray_problem)<br> | #
**Subsequence**|[]()<br>[]()<br> | #
**Two Pointers**|[]()<br>[]()<br> | #

## Tags
-
-

## Sup Topic Terminologies And Explanations
## Two Pointers
## Contiguous Subarray Sum
### Cumulative Sum
- AKA Prefix Sum Array, you will given an array you need to find the sum of the query [L,R]
  - First find the prefix sum, if we have (a1, a2, a3, ... N), then cm[0] = a1 and for cm[x] = ax + cm[x-1]
  - Now that is the sum from 0 to any cell in the array, to find the sum from any cell to any cell
  - Use **inclusive-exculsive principle**, so the sum from (L, R) = cm[R] - cm [L-1]
  - The same logic for 2D matrix to find a rectangle sum use cm[rx][ry] - cm[rx][ly - 1] - cm[lx - 1][ry] + cm[lx - 1][ly - 1]
### Partial Sum
- AKA Maximum Intersection, when you make a query in some range and add some value in all the indicies lay in that range, then you need to find the final value in some index.
   - we wanna add 4 from range (l,r) then arr[l] = 4, arr[r+1] = -4, then make Cumulative sum.

### Equal Sum
- Find how many sum that equals K
  - If the (prefix sum - K) is exist before as prefix sum then K exist
  - Use HashMap and make map[prefixsum]++
### Closest Sum
- Find the max sum **closest sum** sub array and the sum less than or equal k
  - What you do is add the j-th value (right itr) to the current sum, and while the sum is larger than t, subtract the i-th value (left itr) and shift i one space forward. After each step is done, check whether the current interval size is larger than the maximum recorded so far and you're done.
### Max And Min Sum
- 
### Zero Sum
### Equilibrium Index

