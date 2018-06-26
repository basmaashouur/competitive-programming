# List of Problem Solving Paradigms Sup topic's Resources, Tags, Terminologies and Explanations 

Table of Contents
================= 

- [Resources And Approximate Time](#resources-and-approximate-time)
- [Tags](#tags)
- [Sup Topic Terminologies And Explanations](#sup-topic-terminologies-and-explanations)
  * [Brute Force](#brute-force)
    + [When Use Brute Force](#when-use-brute-force)
    + [When Brute Force Fails](#when-brute-force-fails)
    + [Brute Force Techniques](#brute-force-techniques)
    + [Brute Force Examples](#brute-force-examples)
    + [Iterative](#iterative)
    + [Recursive](#recursive)
  * [Greedy](#greedy)
    + [When Use Greedy](#when-use-greedy)
    + [When Greedy Fails](#when-greedy-fails)
    + [Greedy Techniques](#greedy-techniques)
    + [Classical Greedy Examples](#classical-greedy-examples)
  * [Divide and Conquer](#divide-and-conquer)
    + [Divide and Conquer Techniques](#divide-and-conquer-techniques)
    + [Binary Search](#binary-search)
  * [Sliding Window](#sliding-window)
    + [Sup Sup Topic Name](#sup-sup-topic-name)
   
   

## Resources And Approximate Time
Sup Topic Name   | Resources   | Approximate stydying <br> & solving time
-------------| -------------   |-------------   
**Brute Force**<br>Iterative<br> Recursive |[Brute force wiki](https://en.wikipedia.org/wiki/Brute-force_search)<br>[Brute force search](http://intelligence.worldofcomputing.net/ai-search/brute-force-search.html#.Wr8xeHVubeR)<br> [Backtracking](http://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html)<br>[Backtracking Notes](http://jeffe.cs.illinois.edu/teaching/algorithms/notes/03-backtracking.pdf)| 4Days
**Greedy** |[Greedy Algorithms](https://www.geeksforgeeks.org/greedy-algorithms/)<br>[Basic of greedy](https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/tutorial/)<br> [Activity Selection Problem](https://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/)<br>| 4Days
**Divide and Conquer**<br>Binary Seacrh<br> |[Divide and Conquer Algorithms](https://www.geeksforgeeks.org/divide-and-conquer-introduction/)<br>[Bisection](https://en.wikipedia.org/wiki/Bisection_method)<br> | 4Days
**Sliding Window**|[]()<br>[]()<br> | 4Days

## Tags
- Iterative (Brute Force)
- Backtracking (Recursive) (Brute Force)
- Greedy
- Binary search (Divide and Conquer)

## Sup Topic Terminologies And Explanations

## Brute Force
* Is a general method that can be used to solve almost any algorithm problem, it's solving a problem by traversing the entire (or part of the) search space to obtainthe required solution. During the search, we are allowed to prune (that is, choose not to explore) parts of the search space if we have determined that these parts have no possibility of containing the required solution.
* **Speeding up brute-force searches** 
  * [Heuristic technique](https://en.wikipedia.org/wiki/Heuristic)
### When Use Brute Force
### When Brute Force Fails
### Brute Force Techniques
* **Pruning the search**
* **Meet in the middle**
### Brute Force Examples  
* **Memoization**
* **Generating subsets**
  * **How to solve Iteratively**  
    1. Choose first element from input and put it in a vector
    2. put an empty element in a vector
    3. Itrate over n-1 remaining elements
    4. append the ith element in the elemnts in the vector
  * **How to solve Recursively**  
    1. Choose first element from input
    2. Can either include it in current subset or not
    3. Recursively form subsets including it
    4. Recursively form subsets excluding it 
* **Generating permutations**
  * **How to solve Recursively**  
    1. Choose the first element from input
    2. Recursively permute remaining input
### Iterative
* 
### Recursive
* Function do some logic calls itself in(sub problem) until reaches a base case.
* **When to use**
  * Whenever you see that you can solve a given problem if you could have solved a similar smaller problem.
  * As smaller input will call less smaller one, we will end at one of them, then when we need terminating state
   AKA (base case).
*  **Approach to write recurrence**
    1. Have a Base Case which is a condition that allows the algorithm to stop recursing.
    2. A recursive algorithm must change it’s state and move towards the base case.4
*  **Recursion types**
   1. Linear Recursion: only 1 sub-call or when no pending operation involves another recursive call to the function, Ex: Factorial Function.
   2. Tree Recursion: Non-linearly recursive or Binary Recursion when the pending operation involves another recursive call to the function, Ex: Fibonacci Function.
      * Recursive definition: Number of leaves or nodes in the tree
   3. Tail Recursion:  If there are no pending operations to be performed on return from a recursive call, means the recursion call is at the end o the function
   4. Removal of Recursion: The method of converting a recursive function into a iterative with the help of looping
      * Convert the recursive function to the Tail recursive.
      * Convert the tail recursive function to iterative.
* **Backtracking** is a form of recursion in order to explore all the possibilities until you get the best result for the problem
  * State and Transition
  * Objective function and Optimization
## Greedy
* A greedy algorithm obtains an optimal solution to a problem by making a sequenceof choices. At each decision point, the algorithm makes choice that seems best at the moment. Greedy algorithms are used for optimization problems but this strategy does not always produce an optimal solution
### When Use Greedy
* At every step, we can make a choice that looks best at the moment.
* We get the optimal solution of the complete p.roblem.
* If the input size given in the problem statement are too large even for the best Complete Search or DP algorithm.
* **Greedy Steps**
  1. Determine the optimal substructure of the problem.
  2. Develop a recursive solution.
  3. Show that if we make the greedy choice, then only one subproblem remains.
  4. Prove that it is always safe to make the greedy choice. (Steps 3 and 4 can occur in either order.)
  5. Develop a recursive algorithm that implements the greedy strategy.
  6. Convert the recursive algorithm to an iterative algorithm.
### When Greedy Fails
i. Sometimes in general cases 
   * In coin change when the coins used not euro{1, 5, 10, 20, 50, 100, 200}.
### Greedy Techniques
* It is helpful to memorize greedy classical problems solutions.
*  It's easy to find a greedy sloution that doesn't give TLE but it's hard to proof it's right or generalized.
### Classical Greedy Examples
* **[Interval scheduling](https://en.wikipedia.org/wiki/Interval_scheduling) AKA Activity-selection problem** Given n events with their starting and ending times, find a schedule that includes as many events as possible, and are compatible if the intervals _(si, fi)_ and _(sj, fj)_ do not overlap.
  * **How to solve** 
    * Always selects the next possible event that ends as early as possible.
  * **Proof**
* **Coin Change** Given a set of coins and our task is to form a sum of money n using the coins. The values of the coins are coins = {c1, c2,..., ck}, and each coin can be used as many times we want. What is the minimum number of coins needed?
  * **How to solve** 
    * Always selects the largest possible coin, until the required sum of money has been constructed.
  * **Proof**
* **[Job Sequencing](https://www.geeksforgeeks.org/job-sequencing-problem-set-1-greedy-algorithm/)** Given a set of jobs has a deadline and associated profit if the job is finished before the deadline, every job takes single unit of time, what is the max total profit we can get?
  * **How to solve** 
    * Always selects the largest possible Profit tht can fit in the current result sequence without missing the deadline.
  * **Proof** 
    * every time taking a largest profit that it's not it place then it replaced with smaller one missing the deadline so it's win win.
* **Tasks and deadlines** Given a set of tasks with durations and deadlines and associated score for each task,we earn d − x points where d is the task’s deadline and x is the moment when we finish the task. What is the max total score?
  * **How to solve**  
    *  Always selects the task that have the smallest duration.
  * **Proof**
* **Minimizing sums**
  * **How to solve**  
    *  
  * **Proof**
* **Data compression**
  * **How to solve**  
    *  
  * **Proof**
* **Huffman coding**
  * **How to solve**  
    *  
  * **Proof**
## Divide and Conquer
### Divide and Conquer Techniques
1. Divide: break the original problem into sub-problems usually by half or nearly half.
2. Conquer: find (sub)-solutions for each of these sub-problems—which are now easier.
3. Combine: If needed, combine the sub-solutions to get a complete solution for the main problem.
### Binary Search
- Binary search splits the search space into two parts. The item being searched for can either be "here", or "there". This duality of options is a binary system, a system with only 2 parts. Thus, "Binary Search".
#### Normal BS
- The canonical usage of Binary Search is searching for an item in a static sorted array. We check the middle of the sorted array to determine if it contains what we arelooking for. If it is or there are no more items to consider, stop. Otherwise, we can decide whether the answer is to the left or right of the middle element and continue searching.
- We also use Binary Search in Arrays with duplicates (finding first/last occurence).
#### BS Built In
- The C++ standard library contains the following functions that are based on binary search and work in logarithmic time:
  * Lower-bound: searching for the first element that is greater or equal than x.
  * Upper-bound: searching for the first element that is strictly greater than x.
  * Equal_range: searching for sub-range within a given range (first, last) that has all the elements equivalent to x.
#### BS on Uncommon DS
#### Bisection Method
- The bisection method in mathematics is a root-finding(x will be called a solution or a root if it satisfies the equation) method that repeatedly bisects an interval and then selects a subinterval in which a root must lie for further processing.
- The method is based on The **Intermediate Value Theorem** which states that if f(x) is a continuous function and there are two real numbers a and b such that f(a)*f(b) 0 and f(b) < 0), then it is guaranteed that it has at least one root between them.
#### BS the Answer
- Search for an answer that make the equation true between two intervals.
## Sliding Window
### Sup Sup Topic Name
