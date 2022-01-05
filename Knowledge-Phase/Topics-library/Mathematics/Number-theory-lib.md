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

## Factors
### Divisor
- Get divisors
```cpp
vector<ll> getDivisors(ll n)
{
  vector<ll> ret;
  for(int i=1; i*i<=n; i++)
  {
    if(n % i == 0)
    {
      ret.push_back(i);
      if(n != i * i)
        ret.push_back(n / i);
    }
  }
  return ret;
}
```
- GCD
```cpp
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
```
- LCM
```cpp
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
```
### Prime And Composite
- Find primes 
```cpp
// Sieve
const int N = 1e6;
bool f[N + 5];
vector < int > primes;

void seive() 
{
  f[0] = f[1] = 1;
  // we can go sqrt(N) since any nymber divided by N or any number less than N is gonna be in the bound from (2, sqrt(N)) since sqrt(N) * sqrt(N) = N
  for (int i = 1; i <= N; i++) 
  {
  // means its not a prime number, and all its multiplication has been marked beofre from its divisor
    if (f[i])continue;
    primes.push_back(i);
    for (ll j = (ll) i * i; j <= N; j += i)
      f[j] = 1;
  }
}
```
### Prime Factors
- Get factors
```cpp
vector < ll > getFactors(ll n) 
{ 
  vector < ll > ret;
  ll tmp = n, cnt = 1;
  for (ll i = 2; i * i <= n; i++) 
  {
    ll x = 1;
    while (tmp % i == 0) 
    {
      ret.push_back(i);
      tmp /= i;
      ++x;
    }
    cnt *= x;
  }
  if (tmp != 1) 
  {
    ret.push_back(tmp);
    cnt *= 2;
  }
  return ret;
}
```
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
