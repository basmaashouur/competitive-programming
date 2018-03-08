/*
Name: 11933 - Splitting Numbers
Online Judge: UVa
Tags: Bits
Complexity: 
Tutorial: We number the 1's digits from 1 to S, where s the number of 1's digits in N, 
then A contains all the odd digits and B all the even digits.
Ex: 0 1 0 1 1 0 1
      4   3 2   1   
A:  0 0 0 1 0 0 1
B:  0 1 0 0 1 0 0 

So we will itrate through N  and then after finding the 1 digit know if it's belongs to A or B,
then add the value of pow(2, index) to A or B.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        while(true)
        {
                cin >> n;
                if(n == 0) break;
                string bi = bitset<32>(n).to_string();;
                int a = 0, b = 0, index = 1;
                for(int x =  bi.length()-1; x >= 0; x--)
                {
                        if(bi[x] == '1'  && index % 2 != 0)
                                a +=  pow(2, 31 - x), index++;
                        else if(bi[x] == '1'  && index % 2 == 0)
                                b += pow(2, 31 - x), index++;
                }
                cout << a << " " << b << endl;
        }
        return 0;
}
