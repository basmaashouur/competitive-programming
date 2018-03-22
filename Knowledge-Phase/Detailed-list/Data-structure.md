# List of Data Strcture Sup topic's Resources, Tags, Terminologies and Explanations 

## Content table


## Resources and Approximate time

Sup Topic Name   | Resources   | Approximate stydying & solving time 
-------------| -------------   |-------------   
**Linear DS**<br>Static Arrays<br> Stl Algorithms <br> Dynamically-Resizable Arrays<br>Bitmasks<br>BitSets<br>LinkedList<br>Stacks<br>Queues<br>Dequeues|[Bits](https://graphics.stanford.edu/~seander/bithacks.html)<br> [Bitwise](https://en.wikipedia.org/wiki/Bitwise_operation)<br> [masks](https://en.wikipedia.org/wiki/Mask_(computing))<br> [Bit manipulation](https://en.wikipedia.org/wiki/Bit_manipulation)<br> [Bit subset](http://codesam.blogspot.com.eg/2011/03/find-all-subsets-of-given-set.html)<br> [Bitset](https://www.geeksforgeeks.org/c-bitset-and-its-application/)|4Days
**Non-Linear DS**<br>BST<br>Heap<br>Hash Table| | 4Days

## Tags
- 1D Array (static arrays) (linear DS)
- 2D Array (static arrays) (linear DS)
- Stl Algorithms
- Vectors (linear DS)
- Bitmasks (linear DS)
- List (linear DS)
- Stacks (linear DS)
- Queues (linear DS)
- Dequeues (linear DS)
- Maps (BBST)
- Sets (BBST)
- Multisets (BBST)
- Unordered_set (BBST)
- Unordered_multiset (BBST)


## Sup Topic Terminologies and Explanations 

### Linear DS
- Data items are organized sequentially or linearly where data elements attached one after another OR Collection of variables that are of similar data types and it's elements form a linear sequence.

* **Static Array** is array which you can't change it's size once declared.
  * **1D Array** store single list of elements, can be distinctly accessed by specifying its index.
  * **2D Array || Matrix** multi-dimensional array is an array of arrays, for an array of size N×M, the rows and columns are numbered from 0 to N−1 and columns are numbered from 0 to M−1.
  * **ND Array** 
  * **Memset** use it to initialize all elements of an integer array to 0 or -1 but not the other values.
* **Stl Algorithms**
  * **Next permutation** Given a word, find lexicographically greater permutation of it. 
* **Vectors** are similar to an array but are dynamically sized.
* **Bitsets** an array of booleans with useful opeartions like rest() and set().
* **Bitmasks** are technique of representing a subset of a set using a bit vector, where ith bit of the vector is set iff the corresponding element belongs to the subset. Eg, S={a,b,c,d}, then bit vector b=(1,0,1,1) would represent the subset S′={a,c,d}. An int is stored is in a string of bits AKA (bitmask), we can use bit manipulation whick make it more efficient than bitset or vector<bool>.
  * **Bitwise Manipulation** is the act of algorithmically manipulating bits using bits operators(&, |, ^, ~, <<, >>)
* **LinkedList** store data with structures so that we can automatically create a new place to store a new data.
* **Stacks** are a type of container adaptors with Last In First Out feature.
* **Queues** are a type of container adaptors with First In First Out feature.
* **Dequeues** are like vectors but double ended.
 
 
 ### Non-Linear DS
 - Data items are not organized sequentially. In other words, A data elements of the non linear data structure could be connected to more than one elements to reflect a special relationship among them. All the data elements in non linear data structure can not be traversed in single run.

* **Balanced Binary Search Tree** The BST is one way to organize data in a tree structure. In each subtree rooted at x,
the following BST property holds: Items on the left subtree of x are smaller than x and items on the right subtree 
of x are greater than (or equal to) x. allows for O(log n) search(key), insert(key), findMin()/findMax(), successor(key)/predecessor(key), and delete(key).
  * **STL Map**  is an associative container that store elements formed by a combination of a key value 
  and a mapped value (Key --> Data)
