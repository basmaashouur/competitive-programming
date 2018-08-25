# List of Combinatorics Sup topic's Resources, Tags, Terminologies and Explanations 

Table of Contents
================= 

- [Resources And Approximate Time](#resources-and-approximate-time)
- [Tags](#tags)
- [Sup Topic Terminologies And Explanations](#sup-topic-terminologies-and-explanations)
  * [Introduction To Counting](#Introduction-to-counting)
    + [Product Rule](#product-rule)
    + [Sum Rule](#sum-rule)
    + [Inclusion Exclusion](#inclusion-exclusion)
    + [Divide Rule](#divide-rule)
    + [Permutations And Combinations](#permutations-and-combinations)
    + [Combinatorial Arguments](#combinatorial-arguments)
    + [Pascals Triangle](#pascals-triangle)
    + [Binomial Coefficients](#binomial-coefficients)
    + [The Pigeonhole Principle](#the-pigeonhole-principle)
  * [Partitions And Bijections](#partitions-and-bijections)
    + [Counting Subsets](#counting-subsets)
  * [Counting Sequences](#counting-sequences)
    + [Fibonacci Numbers](#fibonacci-numbers)
    + [Catalan Numbers](#catalan-numbers)
  * [Recurrence](#recurrence)
  * [Burnsides Lemma](#burnsides-lemma)
  * [Cayleys Formula](#cayleys-formula)

## Resources And Approximate Time

Sup Topic Name   | Resources   | Approximate stydying <br> & solving time
-------------| -------------   |-------------   
**Introduction To Counting**<br>tag<br>tag <br> |[]()<br>[]()<br> | #
**Partitions And Bijections**<br>tag<br>tag <br> |[]()<br>[]()<br> | #
**The Principle Of Inclusion Exclusion**<br>tag<br>tag <br> |[]()<br>[]()<br> | #
**Recurrence**<br>tag<br>tag <br> |[]()<br>[]()<br> | #
**Counting Sequences**<br>tag<br>tag <br> |[]()<br>[]()<br> | #
**Burnsides Lemma**<br>tag<br>tag <br> |[]()<br>[]()<br> | #
**Cayleys Formula**<br>tag<br>tag <br> |[]()<br>[]()<br> | #

## Resources from books
- **Competitive Programming 3**
  - Fibonacci Numbers 
  - Binomial Coefficients 
  - Catalan Numbers 
- **Competitive Programmer’s Handbook**
  - Binomial coefficients 
  - Catalan numbers 
  - Inclusion-exclusion 
  - Burnside’s lemma 
  - Cayley’s formula 
- **PROGRAMMING CHALLENGES**
  - Basic Counting Techniques 
  - Recurrence Relations 
  - Binomial Coefficients
  - Counting Sequences
  - Recursion and Induction
- **THE ART AND CRAFT OF PROBLEM SOLVING**
  - Introduction to Counting
  - Partitions and Bijections 
  - The Principle of Inclusion-Exclusion
  - Recurrence
- **Discrete Mathematics and Its Applications**
  - The Basics of Counting
  - The Pigeonhole Principle 
  - Permutations and Combinations
  - Binomial Coefficients and Identities
  - Generalized Permutations and Combinations
  - Generating Permutations and Combinations 

## Tags
-
-

## Sup Topic Terminologies And Explanations

## Introduction To Counting
### Product Rule
- Suppose that a procedure can be broken down into a sequence of two tasks If there are |n1| ways(possibilities) to do the first task, there are |n2| ways(V) to do the second task, then there are |n1| x |n2| ways(possibilities) to do the procedure.
- **Product Rule Functions**
  - **Counting Functions** How many functions are there from a set with m elements to a set with n elements?
  - Means m elements in the domain may map to one of elements of n, for element m1 we have n choices, and for element m2 we have n choices, and so on, so we have (n * n * ... * n) = n^m.
  - **Counting One-to-One Functions** A function for which every element of the range of the function corresponds to exactly one unique element of the domain, so how many one-to-one functions are there from a set with m elements to one with n elements? it must be n >= m because every element in m must map to one eleemnt from n 
  - Means m elements in the domain may map to one unique elements of n, so for m1 we have n choices, and for m2 we have n-1
  choices (because the value used for a1 cannot be used again), so we have (n)(n − 1)(n − 2) ··· (n − m + 1).
### Sum Rule
- Suppose If a task can be done either in one of |n1| ways or in one of |n2| ways(possibilities), assuming the elements of n1 and n2 are distinct., then there are |n1| + |n2| ways(possibilities) to do the task.
### Inclusion Exclusion
![](img/in-ex.png)
- 
### Divide Rule
### Permutations And Combinations
### Combinatorial Arguments
### Pascals Triangle
### Binomial Coefficients
### The Pigeonhole Principle

