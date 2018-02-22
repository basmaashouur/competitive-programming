# Data Structure Library
## Content table



## Linear DS


### Static Arrays
* **Tag**: 1D Array
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
  * You can make an indexed array for the alphabet characters and every characater will have an index.
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
 
 * **Tag**: 2D Array
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
   
### Dynamically-Resizable Arrays
* **Tag**: Vector
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
* **Tag**: Bitmasks
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
* **Tag**: List
  * Basic code
  ``` cpp
  // Declaration 
   list <int> li;
   
   // Initialization
   int val;
   li.push_back(val);
   li.push_front(val);
   li.insert(it, val);
   
   // Accessing Complexity is O(N) 
   list <int> :: iterator it;
   for(it = li.begin(); it != li.end(); ++it)
        cout << '\t' << *it;
        
  ```

### Stacks
* **Tag**: Stacks
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
* **Tag**: Queues
  * Basic code
  ``` cpp
  // Declaration 
  queue <int> qu;
   
   // Initialization
   int val;
   qu.push(val);
   
   // Accessing Complexity is O(N)  [only can access the fron and back of it]
   cout << qu.front();
   cout << qu.back();
        
  ```
  
  ### Dequeues
* **Tag**: Dequeues
  * Basic code
  ``` cpp
  // Declaration 
    deque <int> deq (size);
    
   // Initialization
   int val, index;
   deq.push_back(val);
   deq.push_front(val);
   deq[index] = val;
   
   // Accessing Complexity is O(N) 
   cout << deq.front();
   cout << deq.back();
   cout << deq[index];
        
  ```
  
