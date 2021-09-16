# List of Data Structure Sup topic's Resources, Tags, Terminologies and Explanations

Table of Contents
=================

- [Resources And Approximate Time](#resources-and-approximate-time)
- [Tags](#tags)
- [Sup Topic Terminologies And Explanations](#sup-topic-terminologies-and-explanations)
  * [Linear DS](#linear-ds)
    + [Static Array](#static-array)
    + [Stl Algorithms](#stl-algorithms)
    + [Dynamically Resizable Arrays](#dynamically-resizable-arrays)
    + [Dynamically Resizable Data Structure](#dynamically-resizable-data-structure)
  * [Non Linear DS](#non-linear-ds)
    + [Balanced Binary Search Tree](#balanced-binary-search-tree)
    + [Heap](#heap)
    + [Hash Table](#hash-table)
  * [Self Written DS](#self-written-ds)
    + [Union Find Disjoint Sets](#union-find-disjoint-sets)
    + [Segment Trees](#segment-trees)
    + [Fenwick Trees](#fenwick-trees)
    + [Sparse Table](#sparse-table)


## Resources and Approximate time

Sup Topic Name   | Resources   | Approximate stydying <br> & solving time
-------------| -------------   |-------------   
**Linear DS**<br>Static Arrays<br> Stl Algorithms <br> Dynamically-Resizable Arrays<br>Bitmasks<br>BitSets<br>LinkedList<br>Stacks<br>Queues<br>Dequeues|[Bits](https://graphics.stanford.edu/~seander/bithacks.html)<br> [Bitwise](https://en.wikipedia.org/wiki/Bitwise_operation)<br> [masks](https://en.wikipedia.org/wiki/Mask_(computing))<br> [Bit manipulation](https://en.wikipedia.org/wiki/Bit_manipulation)<br> [Bit subset](http://codesam.blogspot.com.eg/2011/03/find-all-subsets-of-given-set.html)<br> [Bitset](https://www.geeksforgeeks.org/c-bitset-and-its-application/)|4Days
**Non Linear DS**<br>Balanced Binary Search Tree<br>Heap<br>Hash Table|[Performance](https://stackoverflow.com/questions/222658/multiset-map-and-hash-map-complexity?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)<br>[Set differnces](https://www.geeksforgeeks.org/difference-set-multiset-unordered_set-unordered_multiset/)<br> | 4Days
**Self Written DS**<br>Union Find Disjoint Sets<br> || 4Days

## Tags
- 1D Array (static arrays) (linear DS)
- 2D Array (static arrays) (linear DS)
- Stl Algorithms
- Vector (linear DS)
- Bitmask (linear DS)
- List (linear DS)
- Stack (linear DS)
- Queue (linear DS)
- Dequeue (linear DS)
- Map (BBST) (Non-linear DS)
- Multimap (BBST) (Non-linear DS)
- Set (BBST) (Non-linear DS)
- Multiset (BBST) (Non-linear DS)
- Priority Queue (Heap) (Non-linear DS)
- Unordered Map (Hash Table) (Non-linear DS)
- Unordered Multimap (Hash Table) (Non-linear DS)
- Unordered Set (Hash Table) (Non-linear DS)
- Unordered Multiset (Hash Table) (Non-linear DS)
- Union Find Disjoint Sets (Self Written DS)


## Sup Topic Terminologies And Explanations

### Linear DS
- Data items are organized sequentially or linearly where data elements attached one after another OR Collection of variables that are of similar data types and it's elements form a linear sequence.

#### Static Array 
* is array which you can't change it's size once declared.
* **1D Array** store single list of elements, can be distinctly accessed by specifying its index.
  * array is quicker than vectors, so it's better to use it in problems that we change the values of array alot
* **2D Array || Matrix** multi-dimensional array is an array of arrays, for an array of size N×M, the rows and columns are numbered from 0 to N−1 and columns are numbered from 0 to M−1.
  * matrix problems alwys try to find the hidden pattern of the matrix rows and coumns and how they are working togther 
* **ND Array**
* **Memset** use it to initialize all elements of an integer array to 0 or -1 but not the other values.
*  **Frequency array** is how many times a particular item occurs in a data set
#### Stl Algorithms
* **Next permutation** Given a word, find lexicographically greater permutation of it.
#### Dynamically Resizable Arrays
* **Vector** are similar to an array but are dynamically sized.
#### Dynamically Resizable Data Structure
* **Bitset** an array of booleans with useful opeartions like rest() and set().
* **Bitmask** are technique of representing a subset of a set using a bit vector, where ith bit of the vector is set iff the corresponding element belongs to the subset. Eg, S={a,b,c,d}, then bit vector b=(1,0,1,1) would represent the subset S′={a,c,d}. An int is stored is in a string of bits AKA (bitmask), we can use bit manipulation whick make it more efficient than bitset or vector<bool>.
* **Bitwise Manipulation** is the act of algorithmically manipulating bits using bits operators(&, |, ^, ~, <<, >>)
* **LinkedList** store data with structures so that we can automatically create a new place to store a new data.
* **Stack** are a type of container adaptors with Last In First Out feature.
* **Queue** are a type of container adaptors with First In First Out feature.
* **Dequeue** are like vectors but double ended.


 ### Non Linear DS
 - Data items are not organized sequentially. In other words, A data elements of the non linear data structure could be connected to more than one elements to reflect a special relationship among them. All the data elements in non linear data structure can not be traversed in single run.

#### Balanced Binary Search Tree
* The BST is one way to organize data in a tree structure. In each subtree rooted at x,
the following BST property holds: Items on the left subtree of x are smaller than x and items on the right subtree
of x are greater than (or equal to) x. allows for O(log n) search(key), insert(key), findMin()/findMax(), successor(key)/predecessor(key), and delete(key).
 * **Map**  is an associative container that store elements formed by a pair of a key value
  and a mapped value (key --> value),following a specific order and it will only store each value once for a specific key.
 * **Multimap** stores pairs of (key --> value) where both key and value can appear several times.
 * **Set** is a container that store unique elements following a specific order, set cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.
  * **Multiset** is a container that store elements following a specific order, and where multiple elements can have equivalent values.
#### Heap 
* Is a tree-based data structure in which all the parent nodes it's child is either greater than or equal them (in a max heap) or less than or equal them (in a min heap). The maximum number of children of a node in a heap depends on the type of heap. However, in the more commonly-used heap type, there are at most children of a node and it's known as a Binary heap.
* **Priority Queue** is a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains.
#### Hash Table
* **Unordered Map**
* **Unordered Multimap**
* **Unordered Set**
* **Unordered Multiset**

### Self Written DS
- important data structures that do not have built-in support yet in C++ STL.
#### Union Find Disjoint Sets
- Is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
- The main innovation of this data structure is in choosing a representative ‘parent’ item
to represent a set.
- A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
   * **Find:** Determine which subset a particular element is in. This can be used for determining if two elements are in      the same subset.
   * **Union:** Join two subsets into a single subset.
- **UFDS is using in the following problems:**
  * Finding connected components in an undirected graph, to detrmine if the two nodes exist in the same component.
  * Detect a Cycle in a Graph.
- **Steps of UFDS Algorthim:**
  * Store the index of the parent item and (the upper bound of)the height of the tree of each set (vi p and vi rank in our    implementation).
  *  p[i] stores the immediate parent of item i.If item i is the representative item of a certain disjoint set, then p[i] = i, i.e. a self-loop.
  * rank[i] yields (the upper bound of) the height of the tree rooted at item i.
  * We initialize the data structure such that each item is a disjoint set by itself with rank 0 and the parent of each item    is initially set to itself.
  * To unite two disjoint sets, we set the representative item (root) of one disjoint set to be
the new parent of the representative item of the other disjoint set.
  * We can use the information contained in vi rank to set the representative item
of the disjoint set with higher rank to be the new parent of the disjoint set with lower rank, if both ranks are the same, we arbitrarily choose one of them as the new parent and increase the resultant root’s rank.
  * To find if two sets are in the same big set we see if both of them have the same parent or not
