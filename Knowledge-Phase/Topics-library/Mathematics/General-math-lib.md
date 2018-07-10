Table of Contents
================= 
- [Arithmetic](#arithmetic)
    * [High Precision Integers](#high-precision-integers)
    * [High Precision Arithmetic](#high-precision-arithmetic)
    * [Numerical Bases And Conversion](#numerical-bases-and-conversion)
    * [Real Numbers](#real-numbers)
 - [Algebra](#sup-topic-name)
    * [Polynomials](#polynomials)
    * [Inequalities](#inequalities)
    * [Root Finding](#root-finding)
    * [Logarithms](#logarithms)
    * [Exponentiations](#exponentiations)
    * [Integer Functions](#integer-functions)
    * [Rrearrange The Equation](#rearrange-the-equation)
 - [Other](other)
    * [Grid](#grid)
    * [Finding Pattern Or Formula](#finding-pattern-or-formula)
    * [Mathematical Simulation](#mathematical-simulation)
   
## Arithmetic
### High Precision Integers
- Big int
  ```cpp
  ```
### High Precision Arithmetic
- Big int opertions
  ```cpp
  ```
### Numerical Bases And Conversion
- Convert from Deciaml to any Radix(Base)
```cpp
int main()
{
	// Convert from decimal to any radix

	int n, base; string ans;
	cin >> n >> base;
	while (n != 0)
	{
		ans += to_string(n % base);
		n /= base;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	
	return 0;
}
  ```
- Convert from Decimal to binary
```cpp
int n; cin >> n;
string bi = std::bitset<64>(n).to_string();
```
- Convert from Binary to Decimal
- If we wanna convert from any base other than bi to decimal, just change the power to that base pow(base, n--)
```cpp
int main()
{
	// Convert from binary to any decimal

	string bi; cin >> bi;
	int n = bi.length() - 1, dec = 0;
	for (int x = 0; x < bi.length(); x++)
		dec += pow(2, n--) * (bi[x] - '0');
	cout << dec << endl;
	
	return 0;
}

```
### Real Numbers
- Dealing With Fractions
```cpp
// The basic arithmetic operations on rationals c = x1/y1 and d = x2/y2 are easy to program,
// but first we shoud reduce fractions to their simplest representation,replace 2/4 by 1/2
// The secret is to cancel out the greatest common divisor of the numerator and the denominator
// we simplify it to not lead to a significant danger of overflows

double gcd(double a, double b)
{
	if (a == 0)return b;
	return gcd(b % a, a);
}
int main()
{
	double x1, y1, x2, y2, div1, div2;

	// reduce fractions to their simplest representation
	div1 = gcd(x1, y1), div2 = gcd(x2, y2);
	x1 /= div1, y2 /= div1, x2 /= div2, y2 /= div2;

	// sum two fractions c = x1/y1, d = x2/y2
	double sum = (x1 * y2 + x2 * y1) / (y1 * y2);

	// subtract two fractions c = x1/y1, d = x2/y2
	double sub = (x1 * y2 - x2 * y1) / (y1 * y2);

	// Multiply two fractions c = x1/y1, d = x2/y2
	double multi = (x1 * x2) / (y1 * y2);

	// divide two fractions c = x1/y1, d = x2/y2
	double div = (x1 * y2) / (x2 * y1);

	return 0;
}

```
- Hints and tricks for dealing with flaot numbers
```cpp
// Checking equality
#define EPS 1e-9
bool AreSame(double a, double b)
{
    return fabs(a - b) < EPS;
}
// Floor rounds off the given value to the
// closest integer which is less than the given value
cout << floor(1.411) << endl; // 1
cout << floor(2) << endl; // 2

// Ceil rounds off the given value to the 
// closest integer which is more than the given value
cout << ceil(1.411) << endl; // 2
cout << ceil(2) << endl; // 2

// Trunc rounds removes digits after decimal point
cout << trunc(1.411) << endl; // 1
 
// Rounds given number to the closest integer
cout << round(1.411) << endl; // 1 
cout << round(1.500) << endl; // 2
// Round x to be divisible by m
round(x / m) * m; //round(x,m)

// Setprecision when used along with ‘fixed’ provides precision to floating 
// point numbers correct to decimal numbers mentioned in the brackets of the setprecison
  cout << fixed << setprecision(2) << 3.14159265 <<endl; // 3.41

```

## Algebra
### Polynomials
- 
```cpp
```
