/*
Name: 414 - Machined Surfaces
Online Judge: UVa
Tags: Vector, Count

Tutorial: It's a straightforward problem, count all the 'X' in every row, and save the max value, 
then substract all the counting from that max value and the answer will be the addtion of that substraction.
We shouldn't use 2D array, due the problem we gonna face while cin the space char, so we should use strings and  
then cin the whole row using getline() function.

*/


// C O D E

#include <bits/stdc++.h>

using namespace std;

int main()
{
  while (true) 
  {
  int row, cn = 0, mx = 0, ans = 0;
  vector < int > vec;
  char arr[13][25];
  string val;

  cin >> row;
  if (row == 0) break;
  cin.ignore();

  for (int x = 0; x < row; x++) 
  {
    getline(cin, val);

    for (int y = 0; y < 25; y++)
      if (val[y] == 'X') cn++;

    if (cn > mx) mx = cn;
    vec.push_back(cn);
    cn = 0;
  }

  for (int x = 0; x < row; x++) ans += mx - vec[x];
  cout << ans << endl;

}
  return 0;
}
