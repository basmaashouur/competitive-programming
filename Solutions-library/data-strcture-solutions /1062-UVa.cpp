/*
Name: 1062 - Containers
Online Judge: UVa
Tags: Stacks, Sorting, Sets
Complexity: 
Tutorial: We have two cases, first we would be able to minimize the stacks and 
put the elements in a decreasing order in it, so the top element would always be the smallest, 
to do this we need to put the first elemnet that arrive in a stack then the next element
- if it's smaller than the pervious then put in the same stack, 
- if it's bigger make another stack
- if it's smaller but we have more than one stack to put it inside then we would choose 
  the stack that is the nearest (to the right) from that character
The second case that the optimal solution that we would have is s stack for every differnt character, 
the max woulde be 26 stacks,to do this we only need to put all the charcters in a set, 
the answer would be the set size.

*/


// C O D E
