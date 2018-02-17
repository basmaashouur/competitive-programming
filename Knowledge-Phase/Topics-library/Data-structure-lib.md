# Data Structure Library
## Content table



## Linear DS

### Static Arrays

* **Tag**: 1D Array
  * Basic code
  ```cpp
  // Declaration 
  int arr[20] = {0}; 
  // or create a dynamic defined array
  int size = 20;
  int arr = new int (size);
  // use the following to free the memory
  delete [] arr;
  
  // Initialization
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
