# List of MIsc Sup topic's Resources, Tags, Terminologies and Explanations 

Table of Contents
================= 

- [Resources And Approximate Time](#resources-and-approximate-time)
- [Tags](#tags)
- [Sup Topic Terminologies And Explanations](#sup-topic-terminologies-and-explanations)
- [Two Pointers](#two-pointers)
- [Contiguous Subarray](#contiguous-subaaray)
  * [Cumulative Sum](#cumulative-sum)
  * [Partial Sum](#partial-sum)
  * [Equal Sum](#equal-sum)
  * [Closet Sum](#closet-sum)
  * [Max Sum](#max-sum)
  * [Min Sum](#min-sum)
- [Subsequence](#subsequence)
   
   

## Resources And Approximate Time

Sup Topic Name   | Resources   | Approximate stydying <br> & solving time
-------------| -------------   |-------------   
**Cumulative Sum**|[]()<br>[]()<br> | #
**Sup Topic Name**|[]()<br>[]()<br> | #
**Sup Topic Name**|[]()<br>[]()<br> | #

## Tags
-
-

## Sup Topic Terminologies And Explanations
## Two Pointers
## Contiguous Subarray
### Cumulative Sum
- AKA Prefix Sum Array, you will given an array you need to find the sum of the query [L,R]
  - First find the prefix sum, if we have (a1, a2, a3, ... N), then cm[0] = a1 and for cm[x] = ax + cm[x-1]
  - Now that is the sum from 0 to any cell in the array, to find the sum from any cell to any cell
  - Use inclusive-exculsive principle, so the sum from (L, R) = cm[R] - cm [L-1]
### Partial Sum



