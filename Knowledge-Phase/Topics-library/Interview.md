# Famous Interview Topics and Questions

Table of Contents
================= 
- [Arrays](#arrays)
- [Linked List](#linked-list)
- [Stack](#stack)
- [Queue](#queue)
- [Recursion](#recursion)
- [Trees](#trees)


## Arrays
### Matrix
- Expressions, compositions 

## Linked List

### Summary & Definitions
| **Singly Linked List**
- A data structure that consists of nodes, each with some value and a pointer to the next node in the linked list. A linked list node's value and next node are typically stored in value and next properties, respectively.
- The first node in a linked list is referred to as the head of the linked list, while the last node in a linked list, whose next property points to the null value, is known as the tail of the linked list.
- Below is a visual representation of a singly linked list whose nodes hold integer values:
- ``0 -> 1 -> 2 -> 3 -> 4 -> 5 -> null``
- A singly linked list typically exposes its head to its user for easy access. While finding a node in a singly linked list involves traversing through all of the nodes leading up to the node in question (as opposed to instant access with an array), adding or removing nodes simply involves overwriting next pointers (assuming that you have access to the node right before the node that you're adding or removing).
- The following are a singly linked list's standard operations and their corresponding time complexities:
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
- The following are a doubly linked list's standard operations and their corresponding time complexities:
  - Accessing the head: O(1)
  - Accessing the tail: O(1)
  - Accessing a middle node: O(n)
  - Inserting / Removing the head: O(1)
  - Inserting / Removing the tail: O(1)
  - Inserting / Removing a middle node: O(n) to access + 0(1)
  - Searching for a value: O(n)

| **Circular Linked List**
- A linked list that has no clear head or tail, because its "tail" points to its "head," effectively forming a closed circle.
- A circular linked list can be either a singly circular linked list or a doubly circular linked list.

### Base Code
### Techniques & Hints
### Problems & Variants 

- Build
- Reverse Linked list

## Stack

### Curr Max, Min
- 2nd max, 3rd. etc..

### Montonic stack


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
  1. print ourmutaion 
  2. Print all K-length increasing sequences

### Code

- Sum, Keep the ans as param
```cpp
int sum (int n, int ans){
if(n == 0) return ans;
ans += n;
return sum(n-1, ans);
}
```
- Sum, dont keep the ans as param
```cpp
int sum (int n){
if(n == 0) return 0;
return n + sum(n-1);
}
```
## dynmiac Programming
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
