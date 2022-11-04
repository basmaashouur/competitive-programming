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
- Build
- Reverse Linked lisr

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

```
