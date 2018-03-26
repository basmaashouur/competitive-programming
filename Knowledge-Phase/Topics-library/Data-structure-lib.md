# Data Structure Library

##### Table of Contents  
- [NonLinear-DS](#LinearDS)
  * [StaticArrays](#StaticArrays)
    + [1DArray](#1DArray)

<!-- toc -->

## LinearDS
### StaticArrays
#### 1DArray
  * Basic code
  ```cpp
  // Declaration 
  int arr[20];
  // Initialize it with zeros
  int arr[20] = {0}; 
  // or
  memset(arr,0,sizeof(arr));
  // or create a dynamic defined array
  int size = 20;
  int* arr = new int (size);
  // use the following to free the memory
  delete [] arr;
  
  // Initialization
  int arr[5] = {4, 12, 7, 15, 9};
  //or
  int val = 5;
  arr[index] = val;
  
  // Accessing Complexity is O(1) if direct access, but it will be more when doing operations
  cout << arr[index]; // will print the value in this index
  ```
  * You can make an indexed array(Hashing) for the alphabet characters and every characater will have an index.
   ```cpp
   int alpha [26] = {0};
   /* 'a' in ascii = 97
   'A' in ascii = 65 
   */
   (int)'a'; // will equal 97
   (int)'a' - 97; // will equal 0
   arr[(int)'a' - 97]++; // means I have one 'a' characater
   cout << char(0 + 97); // will print a
   
   ```
 
 #### 2D-Array
   * Basic code 
   ```cpp
   // Declaration 
   int arr[3][5];
   // Initialize it with zeros
   int arr[3][5] = {{0, 0},{0, 0}};
   // or
   memset(arr, 0, sizeof(arr[0][0]) * 3 * 5);
   // or create a dynamic defined array
   int col = 20, row = 30;
   int** arr = new int*[row];
   for(int i = 0; i < row; ++i)
    arr[i] = new int[col];
   
   // Initialization
   int arr[3][5] = {{5, 12, 17, 9, 3}, {13, 4, 8, 14, 1}, {9, 6, 3, 7, 21}};
   //or
   int val = 5;
   arr[row][col] = val;
  
   // Accessing Complexity is O(1) [direct access]
   cout << arr[row][col]; // will print the value in this index
   
   ```
 
 ### STL-Algorthims
 #### Next-permutation
   * Given an array of objects a[] that represents a permutation, the next permutation can be found as follows:  
   * Let i be the greatest index where a[i] < a[i+1]
   * Let j be the greatest index where a[j] > a[i]   
   * Swap a[i] and a[j]   
   * Reverse all elements from i+1 to the end of the array   
   * for example, if the array is 8 items long, and i = 3, then swap a[4] and a[7], and swap a[5] and a[6].
   * Or use the next permutation in C++
   ```cpp
    string s;
    bool val = next_permutation(s.begin(), s.end());
    if (val == false)
        cout << "No Next permutation" << endl;
    else
        cout << s << endl;
   ```
   
  
### Dynamically-Resizable Arrays
#### Vector
  * 1D Vector 
  ```cpp
   // Declaration 
   vector<int> vec;
   
   // Initialization
  int val;
  vec.push_back(val);
  
  // Or we can declare it and initialize at the same time
  vector<int>vec(size, default_init);
  
   // Accessing Complexity is O(1) [direct access]
   cout << vec[index]; // will print the value inside this index
   
   ```
   * Vector of pairs 
   ```cpp
    // Declaration 
    vector<pair<int, int> > vec;
   
    // Initialization
   int a, b;
   vec.push_back(make_pair(a, b));
  
   // Or we can declare it and initialize at the same time
   vector<pair<int,int> >vec (size, make_pair(def_init1, def_init2));
  
    // Accessing Complexity is O(1) [direct access]
    cout << vec[index].first; // will print the first pair value inside this index
   
    ```
    
   * 2D vectors
   ```cpp
    // Declaration 
    vector<vector<int> > vec (size);
   
    // Initialization
   int val;
   vec[row].push_back(val);
  
    // Accessing Complexity is O(1) [direct access]
    cout << vec[row][col]; // will print value inside this index
   
    ```

### Bitmasks
#### Bitmasks
  * Bitwise Manipulation
  - turn on j-th: {00001} --> shift left by j-th times
  - turn off j-th and turn on the remaining: {00001} -->  shift left by j-th times, then use NOT
  ```cpp
  /* 
  To multiply/divide an integer by 2, we only need
  to shift the bits in the integer left/right
  */
  S = S << 1; // multiply by 2
  S = S >> 2; // divide by 4
  S = S >> 1; // divide by 2
  
  /*
  To set/turn on the j-th item of the set S, make another bitmask where j-th item is only on, 
  doing it by shiffing the on bit j-th time, then use the bitwise OR with those two bitmaks
  (1 << j) means we have bitmask=0001 we need to shift to left j times, if j = 3 then bitmask=1000
  */
  #define setBit(S, j) (S |= (1 << j))
  
  /*
  To check if the j-th item of the set S is on, make another bitmask where j-th item is only on,
  then use the bitwise AND with those two bitmaks, if the j-th item of the result is on
  [not a zero int] then it's true, if it's off [zero int] then it's false
  */
  #define isOn(S, j) (S & (1 << j))
  int S = 42;
  int T = isOn(S, 3); 
  // will print ON, the result is 8 which is true
  printf("T = %d, %s\n", T, T ? "ON" : "OFF"); 
  
  /*
  To clear/turn off the j-th item of the set S, make another bitmask where j-th item is only off,
  doing it by turn on the j-th item then use bitwise NOT operation,
  then use the bitwise AND with those two bitmaks
  */
  #define clearBit(S, j) (S &= ~(1 << j))
  
  /*
  To toggle (flip the status of) the j-th item of the set S, make another bitmask where j-th 
  item is only on, then use bitwise XOR operation
  */
  #define toggleBit(S, j) (S ^= (1 << j))
  
  /*
  To get the value of the least significant bit that is on, make another bitmask
  which is two’s complement of the first bitmask, then use AND bitwise
  the result would [00001000] the on bit is the least significant bit that is on,
  the intger of that bitmask is always power of 2, so we should know which power of two
  so we would be able to know the index of the least significant bit that is on
  */
  #define lowBit(S) (S & (-S))
  #define isPowerOfTwo(S) (!(S & (S - 1)))
  int S = 40; // 101000
  int T = lowBit(S); // = 8 which is 0100 means (3rd bit from right is on)
  int index = isPowerOfTwo(T); // = 3
  
  /*
  To turn on all bits in a set of size n,  make another bitmask where n-th
  is on, then substract every bit from 1, n bits{000} --> {1000} -1 --> {0111}
  */
  #define setAll(S, n) (S = (1 << n) - 1)
  
  ```

### LinkedList
#### List
  * Basic code
  ``` cpp
  // Declaration 
   list <int> li;
   
   // Initialization
   int val;
   li.push_back(val);
   li.push_front(val);
   // insert in that pos
   // 1 2 3
   //   ^
   // if I wanna insert in two pos
   // 1 10 2 3
   //      ^
   // 1 10 11 2 3
   //        ^
   // the itreator will increment every time I add by it selt
   li.insert(it, val);
   
   // Accessing Complexity is O(N) 
   list <int> :: iterator it;
   for(it = li.begin(); it != li.end(); ++it)
        cout << '\t' << *it;
        
  ```

### Stacks
#### Stacks
  * Basic Code
  ``` cpp
  // Declaration 
   stack <int> st;
   
   // Initialization
   int val;
   st.push(val);
   
   // Accessing Complexity is O(N) [only can access the top of it]
    cout <<st.top(); 
        
  ```
  
### Queues
#### Queues
  * Basic code
  ``` cpp
  // Declaration 
  queue <int> qu;
   
   // Initialization
   int val;
   qu.push(val);
   
   // Accessing Complexity is O(n)  [only can access the fron and back of it]
   cout << qu.front();
   cout << qu.back();
        
  ```
 

### Dequeues
#### Dequeues
  * Basic code
  ``` cpp
    // Declaration 
    deque <int> deq (size);
    
   // Initialization
   int val, index;
   deq.push_back(val);
   deq.push_front(val);
   deq[index] = val;
   
   // Accessing Complexity is O(n) 
   cout << deq.front();
   cout << deq.back();
   cout << deq[index];
        
  ```
  

## Non-Linear DS

### Balanced Binary Search Tree
#### Map
  * Basic code
  ``` cpp
    // Declaration 
    map<string,int>m; //key_type is of type string and data_type is of type int.
    
   // Initialization
   m.insert(make_pair("hello",9));
   
   // Check if a key exist incement it, if not insert it then incrment
   // it will also find how many values of that key exist
   string check;
   m[check]++;
   
   // Finding an element Complexity is O(log n)
   map<string,int>::iterator itr=m.find(key);
   if(itr != m.end()) cout<< itr->second; // if find it will print it
   
   // erasing an element Complexity is O(log n)
   m.erase(key);
   m.erase(itr);
   
   // Accessing Complexity is O(log n)
   int val = m[key];
   
  // interesting usage of lower_bound and upper_bound
  // display data between ["f".."m") ('felix' is included, martin' is excluded)
  for (map<string, int>::iterator it = mapper.lower_bound("f"); it != mapper.upper_bound("m"); it++)
    printf("%s %d\n", ((string)it->first).c_str(), it->second);
    
  ```
#### Multimap
  * Basic code
  ``` cpp
   // Declaration 
   multimap <string,int> m;
    
   // Initialization
   m.insert(make_pair("hello",9));
   
   // Finding an element Complexity is O(log n)
   map<string,int>::iterator itr=m.find(key); // find the first element that equal that key
   if(itr != m.end()) cout<< itr->second; // if find it will print it
   
   // erasing an element Complexity is O(log n)
   m.erase(key); // will erase all the elements that equal that key
   m.erase(itr); // will erase only the element that the itr points to
   
   // Accessing Complexity is O(log n)
   int val = m[key];
    
  ```
#### Set
  * Basic code
  ``` cpp
   // Declaration 
   set <int> s;
    
   // Initialization
   s.insert(12);
     
   // Finding an element Complexity is O(log n)
   set<int>::iterator itr = s.find(val);
   
   // erasing an element Complexity is O(log n)
   s.erase(itr);
    
  ```
#### Multiset
  * Basic code
  ``` cpp
   // Declaration 
   multiset <int> s;
    
   // Initialization
   s.insert(12);
   
   // Finding an element Complexity is O(log n)
   set<int>::iterator itr = s.find(val); // find the first element that equal that key
      
   // erasing an element Complexity is O(log n)
   
   s.erase(itr); // erase the element that the itr point to
   s.erase(val); // erase all the values that are the same to that val
   
  ```

### Heap
#### Priority_queue
  * Basic code
  ``` cpp
    // Declaration 
    priority_queue<int> pq; // max heap
    priority_queue<int, vector<int>, greater<int> > mpq; // min heap
    
   // Initialization
   for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);
   
   // erasing an element Complexity is O(1)
   pq.pop();
   
   // Accessing Complexity is O(n)
    pq.top();

  ```
