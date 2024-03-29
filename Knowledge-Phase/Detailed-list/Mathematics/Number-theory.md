# List of Number Theory Sup topic's Resources, Tags, Terminologies and Explanations 

Table of Contents
================= 

- [Resources And Approximate Time](#resources-and-approximate-time)
- [Tags](#tags)
- [Sup Topic Terminologies And Explanations](#sup-topic-terminologies-and-explanations)
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
  * [Diophantine Equations](#diophantine-equations)
     + [Extended Euclid](#extended-euclid)
     + [Solving Linear Diophantine Equation](#solving-linear-diophantine-equation)
     + [Pythagorean Theorem](#pythagorean-theorem)
     + [Fermat Last Theorem](#fermat-last-theorem)
  * [Computational Number Theory](#Computational-number-theory)
     + [Primality Test](#primality-test)
     + [Integer Representation](#integer-representation)

   
   
## Resources And Approximate Time

Sup Topic Name   | Resources   | Approximate stydying <br> & solving time
-------------| -------------   |-------------   
**Factors** |[]()<br>[]()<br> | 4Days
**Congruences**<br>Modular Arithmetic<br> |[Find last digit](https://math.stackexchange.com/questions/1955616/how-do-i-find-the-last-digits-of-large-numbers-using-modular-arithmetic)<br>[Last digit cycle](https://math.stackexchange.com/questions/1714858/do-the-last-digits-of-powers-of-a-number-n-follow-the-same-cycle-as-the-last-d)<br> [Find last digit](https://brilliant.org/wiki/finding-the-last-digit-of-a-power/)<br>| 4Days
**Diophantine Equations**|[]()<br>[]()<br> | 4Days


## Resources from books
- **Competitive Programming 3**
  - Prime Numbers
  - GCD & LCM
  - Factorial
  - Prime Facotrs
  - Modified Sieve
  - Modulo Arithmetic  (Finish)
  - Diophantine Equation
- **Competitive Programmer’s Handbook**
  - Primes and factors 
  - Modular arithmetic  (Finish)
  - Solving equations
  - Other results
- **PROGRAMMING CHALLENGES**
  - Prime Numbers
  - Divisibility
  - Modular Arithmetic  (Finish)
  - Congruences
- **THE ART AND CRAFT OF PROBLEM SOLVING**
  - Primes and Divisibility 
  - Congruence 
  - Number Theoretic Functions
  - Diophantine Equations 
- **Concrete Mathematics**
  - Divisibility 
  - Primes 
  - Prime Examples 
  - Factorial Factors 
  - Relative Primality 
  - The Congruence Relation 
  - Independent Residues 
  - Additional Applications 
  - Phi and Mu
- **Discrete Mathematics and Its Applications**
  - Divisibility and Modular Arithmetic
  - Integer Representations and Algorithms 
  - Primes and Greatest Common Divisors
  - Solving Congruences
  - Applications of Congruences
  - Cryptography

## Tags
-
-

## Sup Topic Terminologies And Explanations

## Factors
### Divisor
![](imgs/div.png)
### Prime And Composite
- **Prime Numbers** 
- If a number n is not prime, it can be represented as a product a· b, where a ≤ sqrt(n) or b ≤ sqrt(n), so it certainly has a factor between 2 and and sqrt(n), becuase if a ≥ sqrt(n) and b ≥ sqrt(n), then a * b ≥ n
- the sequare of prime number have only three divsior, itself and the prime and 1
- Sieve Algo
  - Now that the outer loop's boundaries are defined, let's define the boundaries of the inner loop. We will invariantly pick the next available prime number (a number/index not yet marked in the array as a composite) before entering the inner loop. Say the index we picked from the outer loop is i, then the inner loop will start at i*i and increase by increments of i until it surpasses n. In short, we iterate over every multiple of i between i and n.

  - The question now is why should we start at i*i. Why not start at 2*i to keep things simple? The reason is that all of the previous multiples would already have been covered by previous primes. In number theory, the fundamental theorem of arithmetic, also called the unique factorization theorem or the unique prime factorization theorem, states that every integer greater than 1 either is a prime number itself or can be represented as the product of prime numbers. So the prime numbers smaller than i would have already covered the multiples smaller than i*i. Let's look at the prime number 7 to see how all the multiples up to 7*7 are already covered by primes smaller than '7'.


```
Let's assume that n is 50 (a value greater than 7*7) to demonstrate this claim. 

7 * 2 = 14 = 2 * 7
7 * 3 = 21 = 3 * 7
7 * 4 = 28 = 2 * 2 * 7 = 2 * 14
7 * 5 = 35 = 5 * 7
7 * 6 = 42 = 2 * 3 * 7 = 2 * 21   
```
### Prime Factors
### Factorization
### Exponentiation
## Congruences
### Modular Arithmetic
- A modulo m = finds the remainder of after division by m. In C++, operator is %.
- In modular arithmetic, the set of numbers is limited so that only numbers 0,1,2,...,m−1 are used, where m is a constant. Each number x is represented by the number x mod m.
- (-ve % m) != (+ve % m), so to compute any thing to give us pos result use -> **(n % m + m) % m**
- **Modular Formulas**  we use it most when we compute very large numbers and don't wanna intermediate/final overflow happen.
  - (x+ y) mod m = (x mod m+ y mod m) mod m
  - (x− y) mod m = (x mod m− y mod m) mod m
  - (x · y) mod m = (x mod m· y mod m) mod m
  - x^n mod m = (x mod m)^n mod m
  - x^n mod m = ((x^n/2 mod m) * (x^n/2 mod m)) mod m, when n is even
- **Modular Applications**
  - Finding the Last Digit
     - if we have x^n then itrate n times and every time we gonna mutiply by x and take the mod.
  - Finding the cycle
    - The module would be the cycle length and the n would be the number n%m
### 
### 
### 
###
### 
### 
### 
### 
