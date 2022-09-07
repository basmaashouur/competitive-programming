
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
  headNode->value = 0;
  headNode->next = NULL;
  node* curr = headNode;

  for(int x = 1 ;x < 5; x++){
    node* temp = new node;
    temp->value = x;
    temp->next = NULL;
    curr->next = temp;
    curr = temp;
  }

  while(headNode != NULL){
    cout << headNode->value << " ";
    headNode = headNode -> next;
  }

  return 0;
}

  ```



  
