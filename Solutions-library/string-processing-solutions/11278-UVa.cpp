/*
Name: 11278 - One-Handed Typist
Online Judge: UVa
Tags: Ciphering, Strings
Complexity:
Tutorial: Map from qwerty into dvoark, if you didn't find the char in qwerty means it's the same so leave it as it's.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{
	string qwerty = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	string qwertyShift = "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	string dvoark = "123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
	string dvoarkShift = "!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
	string ln;
	while (getline(cin, ln))
	{
		for (int x = 0; x < ln.length(); x++)
		{
			int seen = 0;
			for (int y = 0; y < qwerty.length(); y++)
				if (ln[x] == qwerty[y])
				{
					ln[x] = dvoark[y];
					seen = 1;
					break;
				}
			if (!seen)
				for (int y = 0; y < qwertyShift.length(); y++)
					if (ln[x] == qwertyShift[y])
					{
						ln[x] = dvoarkShift[y];
						break;
					}
		}
		cout << ln << endl;
	}
	return 0;

}
