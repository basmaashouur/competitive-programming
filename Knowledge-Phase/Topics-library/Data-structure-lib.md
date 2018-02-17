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
   


   
