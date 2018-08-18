
/*
Name: 11697 - Playfair Cipher
Online Judge: UVa
Tags: String
Complexity:
Tutorial: if they are not in the same row or column
mean to shift the row of both letters until its in the same row of the other letter
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;


int main()
{

	int t; cin >> t;
	cin.ignore();
	while (t--)
	{
		string key, text, ans;
		char kee [5][5];
		set<char>sett;
		vector<char>vec;
		getline(cin, key);
		getline(cin, text);

		// put the key text into the key matrix
		for (int x = 0; x < key.length(); x++)
		{
			int temp = sett.size();
			if (key[x] != ' ')sett.insert(key[x]);
			if (sett.size() > temp)vec.push_back(key[x]);
		}
		for (int x = 0; x < 26; x++)
		{
			// != q
			int temp = sett.size();
			if (x != 16)sett.insert(char(x + 97));
			if (sett.size() > temp)vec.push_back(char(x + 97));
		}
		int tt = 0;
		for (int x = 0; x < 5; x++)
			for (int y = 0; y < 5; y++)
				kee[x][y] = vec[tt++];

		// encrypt the text
		vec.clear();
		vec.push_back(text[0]);
		for (int x = 1; x < text.length(); x++)
		{
			if (text[x] != ' ')
			{
				// means the char I hold go with the top of the char in the vector
				// becuase if the size is odd means need another char to make pairs
				if (vec.size() % 2 != 0 && vec[vec.size() - 1] == text[x])
					vec.push_back('x');
				vec.push_back(text[x]);
			}
		}
		if (vec.size() % 2 != 0)vec.push_back('x');

		// hold two chars and encrypt them
		for (int x = 0; x < vec.size(); x += 2)
		{
			int fx, fy, sx, sy;
			char fi = vec[x], se = vec[x + 1];
			for (int i = 0; i < 5; i++)
			{
				for (int ii = 0; ii < 5; ii++)
				{
					if (kee[i][ii] == fi)fx = i, fy = ii;
					else if (kee[i][ii] == se)sx = i, sy = ii;
				}
			}
			// same row
			if (fx == sx)
			{
				ans.push_back(kee[fx][(fy + 1) % 5]);
				ans.push_back(kee[sx][(sy + 1) % 5]);
			}
			// same column
			else if (fy == sy)
			{
				ans.push_back(kee[(fx + 1) % 5][fy]);
				ans.push_back(kee[(sx + 1) % 5][sy]);

			}
			// not same
			else
			{
				ans.push_back(kee[fx][sy]);
				ans.push_back(kee[sx][fy]);
			}
		}
		for (int x = 0; x < ans.length(); x++)
			ans[x] = toupper(ans[x]);
		cout << ans << endl;

	}

	return 0;
}

