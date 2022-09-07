
# LinkedList

Table of Contents
================= 

- [Single LinkedList](#single-linkedlist

   
## Single LinkedList

- Basic code
```cpp
  
struct node
{
    int value;
    node *next;
};
int main() {
  node* headNode = new node;
  headNode->value = 1;
  headNode->next = NULL;
  node* prevNode = headNode;

  for(int x = 2;x < 6; x++){
      node* currNode = new node;
      currNode -> value = x;
      currNode -> next = NULL;
      prevNode->next = currNode;
      prevNode = currNode;
  }

  while(headNode != NULL){
    cout << headNode->value << " ";
    headNode = headNode -> next;
  }

  return 0;
}

  ```



  
