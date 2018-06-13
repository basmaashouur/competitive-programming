/*
Name: 10878 - Decode the tape
Online Judge: UVa
Tags: Ciphering, Strings
Complexity:
Tutorial: first we will stop getlime when we get two of  "___________", then just decode the encoded string by
converting the ' ' into '0' and the 'o' into '1', and igonre anything else, that will give as a binary number
of 8 bits, now convret the binary into a decimal, then the decimal into a char and print that char.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int cn = 0;
	string ln;
	while (true)
	{
		if (cn == 2)break;
		getline(cin, ln);
		if (ln == "___________")cn++;
		else
		{
			string ch; int dec = 0, ind  = 7;
			for (int x = 0; x < ln.length(); x++)
			{
				if (ln[x] == 'o')ch += "1";
				else if (ln[x] == ' ')ch += "0";
			}
			for (int x = 0; x < ch.length(); x++)
			{
				int temp;
				if (ch[x] == '0')temp = 0;
				else temp = 1;
				dec += (temp * pow(2, ind--));
			}
			cout << (char)dec;

		}
	}
	return 0;

}
