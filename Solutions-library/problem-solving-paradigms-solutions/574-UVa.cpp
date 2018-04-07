/*
Name: 574 - Sum It Up
Online Judge: UVa
Tags: Backtracking, Combinatorics, Vectors, Sets
Complexity:O(2^n)
Tutorial:  Find all the subsets, then find which of them equal target, if it's equal to the next process to prevent repetition
Step1: Sort all the numbers in the vector in decreasing order
Step2: Put them in a string and seprate them with "+" sign
Step3: Put the string in a set
Step4: Print the set values in decreasing order
*/


// C O D E
#include <bits/stdc++.h>
using namespace std;

int target, n, v;
vector<int>vec;
set<string>seen;

void subset(int index, int s, vector<int> all)
{
        if (index == n)
        {
                if (s == target)
                {
                        sort(all.begin(), all.end());
                        string temp = "";
                        for (int x = all.size() - 1; x >= 0; x--)
                        {
                                temp += to_string(all[x]);
                                if (x != 0)temp += "+";
                        }
                        seen.insert(temp);
                }
                return;
        }

        subset(index + 1, s, all);
        all.push_back(vec[index]);
        subset(index + 1, s + vec[index],all);
}

int main()
{
        while (true)
        {
                cin >> target >> n;
                if (target == 0 && n == 0)break;
                for (int x = 0; x < n; x++)
                {
                        cin >> v;
                        vec.push_back(v);
                }
                vector<int>sor;
                subset(0, 0, sor);
                cout << "Sums of " << target << ":" << endl;
                if (seen.size() == 0)cout << "NONE" << endl;
                else
                        for (auto it = seen.rbegin(); it != seen.rend(); ++it)
                                cout << *it << endl;
                vec.clear(); seen.clear();


        }
        return 0;
}

