# Famous Interview Topics and Questions, Solutions are in (Java, C++)

## Topic Name
### Summary And Definitions
### Techniques And Hints
### Problems And Variants 
Table of Contents
================= 
- [Arrays](#arrays)
  - [Summary And Definitions](#summary-and-definitions)  
  - [Base Code](#base-code)
  - [Techniques And Hints](#techniques-and-hints)
  - [Problems And Variants](#problems-and-variants)
- [Linked List](#linked-list)
  - [Summary And Definitions](#summary-and-definitions)  
  - [Base Code](#base-code)
  - [Techniques And Hints](#techniques-and-hints)
  - [Problems And Variants](#problems-and-variants)
    - [Insert](#insert) 
    - [Delete](#delete) 
    - [Reverse](#reverse) 
    - [Merge](#merge) 
    - [LRU Cache](#lru-cache) 
    - [Palindrome](#palindrome)
    - [Intersection of Two Linked Lists](#intersection-of-two-linked-lists)
- [Stack](#stack)
- [Queue](#queue)
- [Recursion](#recursion)
- [Trees](#trees)
  - [Summary And Definitions](#summary-and-definitions)  
  - [Base Code](#base-code)
  - [Techniques And Hints](#techniques-and-hints)
  - [Problems And Variants](#problems-and-variants)
    - [Insert](#insert) 
- [String](#string)
- [Sort And search](sort-and-search)


## Arrays
### Summary And Definitions
- A linear collection of data values that are accessible at numbered indices, starting at index 0.
- The following are an array's standard operations and their corresponding time complexities:
- Accessing a value at a given index: O(1)
- Updating a value at a given index: O(1)
- Inserting a value at the beginning: O(n)
- Inserting a value in the middle: O(n)
- Inserting a value at the end:
  - amortized O(1) when dealing with a dynamic array
  - O(n) when dealing with a static array
- Removing a value at the beginning: O(n)
- Removing a value in the middle: O(n)
- Removing a value at the end: O(1)
= Copying the array: O(n)
- A static array is an implementation of an array that allocates a fixed amount of memory to be used for storing the array's values. Appending values to the array therefore involves copying the entire array and allocating new memory for it, accounting for the extra space needed for the newly appended value. This is a linear-time operation.

- A dynamic array is an implementation of an array that preemptively allocates double the amount of memory needed to store the array's values. Appending values to the array is a constant-time operation until the allocated memory is filled up, at which point the array is copied and double the memory is once again allocated for it. This implementation leads to an amortized constant-time insertion-at-end operation.
### Techniques And Hints
### Problems And Variants 


### Matrix
- Expressions, compositions 

## Linked List
### Summary And Definitions
| **Singly Linked List**
- A data structure that consists of nodes, each with some value and a pointer to the next node in the linked list. A linked list node's value and next node are typically stored in value and next properties, respectively.
- The first node in a linked list is referred to as the head of the linked list, while the last node in a linked list, whose next property points to the null value, is known as the tail of the linked list.
- Below is a visual representation of a singly linked list whose nodes hold integer values:
- ``0 -> 1 -> 2 -> 3 -> 4 -> 5 -> null``
- A singly linked list typically exposes its head to its user for easy access. While finding a node in a singly linked list involves traversing through all of the nodes leading up to the node in question (as opposed to instant access with an array), adding or removing nodes simply involves overwriting next pointers (assuming that you have access to the node right before the node that you're adding or removing).
- The following is a singly linked list's standard operations and their corresponding time complexities:
  -  Accessing the head: 0(1)
  -  Accessing the tail: O(n)
  -  Accessing a middle node: O(n)
  -  Inserting / Removing the head: O(1)
  -  Inserting / Removing the tail: O(n) to access + 0(1)
  -  Inserting / Removing a middle node: O(n) to access + 0(1)
  -  Searching for a value: O(n)

| **Doubly Linked List**
- Similar to a singly linked list, except that each node in a doubly linked list also has a pointer to the previous node in the linked list. The previous node is typically stored in a prev property.
Just as the next property of a doubly linked list's tail points to the null value, so too does the prev property of a doubly linked list's head.
- Below is a visual representation of a doubly linked list whose nodes hold integer values:
- ``null <- 0 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 -> null``
- While a doubly linked list typically exposes both its head and tail to its user, as opposed to just its head in the case of a singly linked list, it otherwise behaves very similarly to a singly linked list.
- The following is a doubly linked list's standard operations and their corresponding time complexities:
  - Accessing the head: O(1)
  - Accessing the tail: O(1)
  - Accessing a middle node: O(n)
  - Inserting / Removing the head: O(1)
  - Inserting / Removing the tail: O(1)
  - Inserting / Removing a middle node: O(n) to access + 0(1)
  - Searching for a value: O(n)

| **Circular Linked List**
- A linked list that has no clear head or tail, because its "tail" points to its "head," effectively forming a closed circle.
- A circular linked list can be either a single circular linked list or a doubly circular linked list.

### Base Code
- C++
 ```cpp
// Singly Linked List
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
  };


// Doubly Linked List
struct ListNode {
   int val;
   ListNode *next;
   ListNode *prev;
   ListNode() : val(0), next(nullptr), prev(nullptr) {}
   ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
  };

```
- Java
 ```java

// Singly-linked lists
class ListNode<T> {
    T value;
    ListNode<T> next;
    ListNode(T value)
    {
        this.value = value;
        this.next = null;
    }
}

 
// Doubly Linked List
class ListNode<T> {
    T value;
    ListNode<T> next;
    ListNode<T> prev;
    ListNode(T value)
    {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}
```

### Techniques And Hints
### Problems And Variants 
#### Insert 
- Java
- You need to keep track of the before the node
```java
// Insert a target into a sorted linked list
ListNode<Integer> solution(ListNode<Integer> list, int target) {
    ListNode<Integer> newNode = new ListNode(target);
    if(list == null)return newNode;
    // insert 1st
    if(target < list.value){
        newNode.next = list;
        return newNode;
    }
    ListNode<Integer> curr = list;
    while(curr != null){
        if(curr.value < target && (curr.next == null || curr.next.value > target)){
            newNode.next = curr.next;
            curr.next = newNode;
            return list;
        }
        curr = curr.next;
    }
    
    return list;
}

```
- Java
```java
// Insert an elemnt value before target
ListNode<Integer> solution(ListNode<Integer> head, int target, int value) {
    ListNode<Integer> curr = head;
    ListNode<Integer> newNode = new ListNode(value);
     if(curr.value == target){
         newNode.next = curr;
         return newNode;
     }
     ListNode<Integer> currNext = head.next;
     while(currNext != null){
         if(currNext.value == target){
             newNode.next = currNext;
             curr.next = newNode;
             return head;
         }
         curr = curr.next;
         currNext = currNext.next;
     }
     
     return head;
}
```

#### Delete

- Java
- Delete a target node
```java
ListNode<Integer> solution(ListNode<Integer> head, int target, int value) {
    ListNode<Integer> curr = head;
     if(curr.value == target){
         head = curr.next;
         return head;
     }
     ListNode<Integer> currNext = head.next;
     while(currNext != null){
         if(currNext.value == target){
             curr.next = currNext.next;
             return head;
         }
         curr = curr.next;
         currNext = currNext.next;
     }
     
     return head;
}
```
- C++
- Given a node only delete it from a list
```cpp
   // change the curr node value to next value, and the last node make it null
    void deleteNode(ListNode* node) {
        while(true){
            node -> val = node->next->val;
            if(node->next->next == NULL){
                node->next = NULL;
                break;
            }
            node = node -> next;
        } 
    }
```
- C++ 
- Delete a middle node in a songle pass
```cpp
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr)return nullptr;
        ListNode* slow = head;
        ListNode* prev = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev ->next = slow->next;
        return head;
        
    }
```
#### Reverse 
- C++
- You need to keep track with the prev node so you can redirect the curr element to point to the prev instead of next
```cpp
// recursive
   ListNode* recReverseList(ListNode* curr, ListNode* prev) {
       if(curr == NULL)return prev;
       ListNode* temp = curr->next;
       curr->next = prev;
       return recReverseList(temp, curr);

   }
    ListNode* reverseList(ListNode* head) {
        return recReverseList(head, NULL);
    }
    
// Iterative 
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(curr == NULL || curr->next == NULL)return head;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
        
    }
```
#### Merge
- C++
```cpp
LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
  // starting with a temp node
  LinkedList* head = new LinkedList(-1);
  LinkedList* curr = head;

  while(headOne != NULL && headTwo != NULL){
      if(headOne->value >= headTwo->value){
        curr->next = headTwo;
        headTwo = headTwo->next;
      }
      else {
        curr->next = headOne;
        headOne = headOne->next;
      }
  
    curr = curr->next;
  }
  // 1 -> 2 -> 3
  // 2 -> 3 -> 5 -> 6 -> 7
  // will be ->5
  // make next to the node which is not null
  curr->next = headOne == NULL? headTwo:headOne;

  // returning .next cuz the head is originally was -1
  return head->next;
}

```
- Merge K Lists
```cpp
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty() || ( lists.size() ==1 &&lists[0] == nullptr))return nullptr;
        while(lists.size() > 1){
            int n = lists.size();
            // call merge two linked lists function
            ListNode* newList = mergeLinkedLists(lists[n-1], lists[n- 2]);
            lists.pop_back();lists.pop_back();
            lists.push_back(newList);
        }
        return lists[lists.size()-1];
    }
```
#### [LRU Cache](https://www.interviewcake.com/concept/java/lru-cache)
- C++
- The main Functions of the LRU Cache
  1. Add a (key, value)
    1.1 hit -> update as most recent, update its new value
    2.2 miss -> add a new node and make a hit update ad most recent, if the cache size is bigger than max, then delete the tail
  2. Get a key
    2.2 Hit -> update it as most recent then return
```cpp
class LRUCache {
public:

struct ListNode {
   int key;
   int val;
   ListNode *next;
   ListNode *prev;
   ListNode() : key(-1),val(-1), next(nullptr), prev(nullptr) {}
   ListNode(int y,int x) : key(y),val(x), next(nullptr), prev(nullptr) {}
  };
  
  int maxSize, currSize;
  unordered_map<int,ListNode*>mostRecent;
  ListNode *head;
  ListNode *tail;

    LRUCache(int maxSize) {
      this->maxSize = maxSize;
      head = new ListNode(); 
      tail = new ListNode();
      head->next = tail;
      tail->prev = head;
      currSize = 0;
    }
    
    void updateMostRecent(ListNode *newNode){
        ListNode * headNext = head->next;
        head->next = newNode;
        newNode->next = headNext;
        newNode->prev = head;
        headNext->prev = newNode;
      }


    void removeTail(){
        mostRecent.erase(tail->prev->key);
        tail->prev =  tail->prev->prev;
        tail->prev->next = tail;
        currSize--;
      }

    void removeNode(ListNode *node){
        ListNode *prevNode = node->prev;
        ListNode *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
      }

    
    int get(int key) {
        // cache hit
        if(mostRecent.find(key) != mostRecent.end()){
            ListNode *hitNode = mostRecent[key];
            // remove from its pos
            removeNode(hitNode);
            // update make it most recent
            updateMostRecent(hitNode);
            return hitNode->val;
            }

        // cache miss
         return -1;
        }
    
    void put(int key, int value) {
      // cache hit
      if(mostRecent.find(key) != mostRecent.end()){
        ListNode *hitNode = mostRecent[key];
        removeNode(hitNode);
        updateMostRecent(hitNode);
        // update map with the new value
        hitNode->val = value;
      }

      // cache miss
      else{
           currSize++;
           if(currSize > maxSize)removeTail();
           ListNode *newNode = new ListNode(key, value);
           updateMostRecent(newNode);
           mostRecent.insert({key, newNode});
      }

    }

};

```
#### Palindrome 
- C++
- First, get the mod of the list by fast and slow pointers
- Reverse the 1st or the 2nd half, a list is palindrome if the 1st = 2nd half after reversing 
- Check if its a palindrome
```cpp
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        // get the mid of the list (slow)
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the 2nd half
        while(slow != NULL){
            ListNode* temp = slow -> next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // check if its palindrome

        ListNode* right = prev;
        ListNode* left = head;
        while(right != NULL){
            if(left->val != right ->val)return false;
            left = left->next;
            right = right->next;

        }
        return true;
    }
```

### Intersection of Two Linked Lists
- C++
- One way is to find the size of each lis, and then make the bigger size list to point on a node where the remaining nodes will equal to the other list node
  1. Calculate NNN; the length of list A.
  2. Calculate MMM; the length of list B.
  3. Set the start pointer for the longer list.
  4. Step the pointers through the list together.
```cpp
LinkedList* mergingLinkedLists(LinkedList* linkedListOne, LinkedList* linkedListTwo) {
  // Write your code here.
  int oneSz = 0, twoSz = 0;
  LinkedList* curr = linkedListOne;

  while(curr != nullptr){
    oneSz++;
    curr = curr->next;
  }
  curr = linkedListTwo;
    while(curr != nullptr){
    twoSz++;
    curr = curr->next;
  }
  LinkedList *low, *hi;
  int mx, mn;
  if(oneSz > twoSz){
    low = linkedListTwo;
    hi = linkedListOne;
  }
  else{
    low = linkedListOne;
    hi = linkedListTwo;
  }
  mx = mxVal(oneSz, twoSz);
  mn = -mxVal(-oneSz, -twoSz);

  while(low != nullptr){
    if(low == hi)return low;
    if(mx != mn){
      mx--;
    }
    else{
       low = low->next;
    }
    hi = hi->next;
    
  }
  return nullptr;
}

```

- same as the previous approach but with one loop,  we say that *c* is the shared part, *a* is the exclusive part of list A and *b* is the exclusive part of list B, then we can have one pointer that goes over a + c + b and the other that goes over b + c + a. then they will meet again at C
```cpp
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
        
        // Note: In the case, lists do not intersect, the pointers for A and B
        // will still line up in the 2nd iteration, just that there won't be
        // a common node down the list and both will reach their respective ends
        // at the same time. So pA will be NULL in that case.
    }
```

## Stack

### Curr Max, Min
- 2nd max, 3rd. etc..

### Montonic stack
### next greater element 


## Queue

### Hot Potat
  ```cpp
  //This program creates a simulation of hot potato.

string hotPotato(string nameArray[], int num) {
    queue<string> simqueue;
    int namelsLenght = nameArray->length();
    for (int i = 0; i < namelsLenght; i++) {
        //puts the entire array into a queue.
        simqueue.push(nameArray[i]);
    }

while (simqueue.size() > 1) { //loop continues until there is one remaining item.
        for (int i = 0; i < num; i++) {
            simqueue.push(simqueue.front());
            simqueue.pop();
        }
        simqueue.pop();
    }

    return simqueue.front();
}

int main() {
    string s[] = {"Bill", "David", "Susan", "Jane", "Kent", "Brad"};

    cout << hotPotato(s, 7) << endl;

    return 0;
}

  ```


## Recursion
### Steps
1. Base case
2. Return
3. Merge Answers
4. Famous problems
  1. print permutation 
  2. Print all K-length increasing sequences

### Code

- Sum, Keep the ans as a param
```cpp
int sum (int n, int ans){
if(n == 0) return ans;
ans += n;
return sum(n-1, ans);
}
```
- Sum, don't keep the ans as a param
```cpp
int sum (int n){
if(n == 0) return 0;
return n + sum(n-1);
}
```
## dynamic Programming
- Kadane Algo


## Trees

## Grpah

### BFS right view return
```java
int[] solution(Tree<Integer> t) {
    int[] arr = {};
    if(t == null)return arr;
           Queue<Tree<Integer>> queue = new LinkedList<Tree<Integer>>();
           List<Integer> vals = new ArrayList<Integer>();
           List<Integer> levels = new ArrayList<Integer>();
           List<Integer> ans = new ArrayList<Integer>();
           Map<Tree<Integer>, Integer> levelOfParent = new HashMap<>();
           queue.add(t);
           vals.add(t.value);
           levels.add(0);
           levelOfParent.put(t, 0);
           
           while (!queue.isEmpty()) {
               Tree<Integer> parent = queue.poll();
               if (parent.left != null) {
                   queue.add(parent.left);
                   vals.add(parent.left.value);
                   levels.add(levelOfParent.get(parent) +1);
                   levelOfParent.put(parent.left, levelOfParent.get(parent) +1);

               }
               if (parent.right != null){ 
                   queue.add(parent.right);
                   vals.add(parent.right.value);
                   levels.add(levelOfParent.get(parent) +1);
                   levelOfParent.put(parent.right, levelOfParent.get(parent) +1);
               }
       }
       levels.add(1000000);
       for(int x = 0; x < levels.size()-1; x++){
           if(levels.get(x) != levels.get(x+1)){
               ans.add(vals.get(x));
           }
       }
        arr = ans.stream().mapToInt(i->i).toArray();

      return arr;

}

// return level by level
int[][] solution(Tree<Integer> t) {
    int[][] arr = {{}};
    if(t == null)return arr;
    Queue<Tree<Integer>> queue = new LinkedList<Tree<Integer>>();
    List<Integer> vals = new ArrayList<Integer>();
    List<Integer> levels = new ArrayList<Integer>();
    List<Integer> ans = new ArrayList<Integer>();
    Map<Tree<Integer>, Integer> levelOfParent = new HashMap<>();
    queue.add(t);
    vals.add(t.value);
    levels.add(0);
    levelOfParent.put(t, 0);
    while (!queue.isEmpty()) {
        Tree<Integer> parent = queue.poll();
        if (parent.left != null) {
            queue.add(parent.left);
            vals.add(parent.left.value);
            levels.add(levelOfParent.get(parent) +1);
            levelOfParent.put(parent.left, levelOfParent.get(parent) +1);
            }
        if (parent.right != null){ 
            queue.add(parent.right);
            vals.add(parent.right.value);
            levels.add(levelOfParent.get(parent) +1);
            levelOfParent.put(parent.right, levelOfParent.get(parent) +1);
            }
       }
       levels.add(1000000);
               ArrayList<ArrayList<Integer> > aList = 
                  new ArrayList<ArrayList<Integer> >();
       for(int x = 0; x < levels.size()-1; x++){
           ans.add(vals.get(x));
           if(levels.get(x) != levels.get(x+1)){
               aList.add(new ArrayList<Integer>(ans));
               ans.clear();
           }
       }
         arr = aList.stream()
                .map(l -> l.stream().mapToInt(Integer::intValue).toArray())
                .toArray(int[][]::new);
      return arr;

}

```

### Binary search

## Shifted the binary search
