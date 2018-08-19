# Strings

Table of Contents
================= 
- [Representing Strings](#representing-strings)
- [Character Codes](#character-codes)
- [String Functions](#string-functions) 
- [String Algorithms](#string-algorithms) 
  + [Input Parsing](#input-parsing)
  + [Output Formatting](#output-formatting)
  + [String Comparison](#string-comparison) 
- [String Matching](#string-matching)
- [Suffix Structures](#suffix-structures)	
   
## Representing Strings
1. Strings
```cpp
string w; cin >> w;
// or getline if there is spaces
cin.ignore(); // if use cin before
getline(cin, w);

// Convert a string to char of array
string cppstr = "this is a string";
char target[1024];
strcpy(target, cppstr.c_str());
```
2. Array of chars
```cpp
char s[12];

/* Reads characters from the standard input (stdin) and stores them as a C string 
into str until a newline character or the end-of-file is reached.
*/
gets(s);
// print the string + it's length
cout << s << " " <<  strlen(s) << endl; 

// Convert a char of array to string
char arr[] = "this is a string";
string target = string(arr);
```

## Character Codes
```cpp
string s; int i; char c;

// Convert a string to int
i = stoi(s); // "97" = 97

// Convert an int to string
s = to_string(i); // 97 = "97"

// Convert char to int
i = x - '0';  // '1' = 1

// Convert int to char
c = x + '0'; // 1 = '1'

// Cast a char, read the value as an ascii code
s = int(c); // 'a' = 97

// Cast an int, read the ascii code to char
c = char(i); 97 = 'a'
```
## String Functions
- C Library String Functions
```cpp
int isalpha(char c); /* true if c is either upper or lower case */
int isupper(char c); /* true if c is upper case */
int islower(char c); /* true if c is lower case */
int isdigit(char c); /* true if c is a numerical digit (0-9) */
int ispunct(char c); /* true if c is a punctuation symbol */
int isxdigit(char c); /* true if c is a hexadecimal digit (0-9,A-F) */
int isprint(char c); /* true if c is any printable character */
char toupper(char c); /* convert c to upper case -- no error checking */
char tolower(char c); /* convert c to lower case -- no error checking */
```
- C++ String Library Functions
```cpp
string::size() /* string length */
string::empty() /* is it empty */
string::c_str() /* return a pointer to a C style string */
string::operator [](size_type i) /* access the ith character */
string::append(s) /* append to string */
string::erase(n,m) /* delete a run of characters */
string::insert(size_type n, const string&s) /* insert string s at n */
string::find(s)
string::rfind(s) /* search left or right for the given string */
string::first()
string::last() /* get characters, also there are iterators */
```
## String Algorithms
### Input Parsing
- Removing spaces from a string
```cpp
string str = "12341 414112 absca", temp;
stringstream ss; ss << str;

	while (!ss.eof())
	{
		ss >> temp;
		cout << temp << endl;

	}
```
- Splitting a string
```cpp
	char str[] = "- This, a sample string.";
	char * pch;
  // put all the chars that when see it then take all the chars behind it
	pch = strtok (str, " ,.-");
	while (pch != NULL)
	{
		printf ("%s\n", pch);
		pch = strtok (NULL, " ,.-");
	}
```
### Output Formatting
### String Comparison
- strcmp() compares the two strings lexicographically
```cpp
char leftStr[] = "g f g";
char rightStr[] = "g f g";
int res = strcmp(leftStr, rightStr);
if (res==0) // equa
else if (res > 0)// not equal and leftStr have the greater ASCII value
else if (res < 0)// not equal and rightStr have the greater ASCII value
```
