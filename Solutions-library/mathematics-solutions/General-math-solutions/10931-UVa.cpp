/*
Name: 10931 - Parity
Online Judge: UVa
Tags: Base Number Variants
Complexity: 
Tutorial: Convert to binary then count the one digit.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	while (true)
	{
		int n, del, cn = 0; cin >> n;
		if (n == 0)break;
		string bi = std::bitset<64>(n).to_string();
		for (int x = 0; x < bi.length(); x++)
			if (bi[x] == '1') {del = x; break;}
		bi.erase(0, del);
		for (int x = 0; x < bi.length(); x++)
			if (bi[x] == '1')cn++;
		cout << "The parity of " << bi << " is " << cn << " (mod 2)." << endl;
	}
	return 0;
}
