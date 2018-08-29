# Number Theory

Table of Contents
================= 
 * [Factors](#factors)
     + [Divisor](#divisor)
     + [Prime And Composite](#prime-and-composite)
     + [Prime Factors](#prime-factors)
     + [Factorization](#factorization)
     + [Exponentiation](#exponentiation)
   * [Congruences](#congruences)
     + [Modular Arithmetic](#modular-arithmetic)
     + [Solving Modular Arithmetic](#solving-modular-arithmetic)
     + [Reminder](#reminder)
     + [Solving Congruences](#solving-congruences)
     + [Applications Of Congruence](#applications-of-congruence)
     + [Chinese Reminder](#chinese-reminder)
     + [Fermat Little Theorem](#fermat-little-theorem)
     + [Euler Theorem](#euler-theorem)
     + [Primitive Root](#primitive-root)

   
## Congruences
### Modular Arithmetic
- Find Modular exponentiation 
```cpp
int modpow(int x, int n, int m)
{
	if (n == 0) return 1 % m;
	long long u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1) u = (u * x) % m;
	return u;
}
```
- Find the last digit of a number ^ exp (exp no bigger than 10^4)
- If exp is bigger than 10^4 then find the cycle of last digit and put it in array, then if the cycle is n and repeted again then the last digit is arr[(exp %n)]
- If we wanna find the n last digit make n %m
- If we wanna find the last digit that not zero use while (ans % 10 == 0) ans /= 10;
```cpp
  int numb, exp, ans = 1;
	cin >> numb >> exp;
	for (int i = 1; i <= exp; ++i)
		ans = (ans * numb) % 10;
```
