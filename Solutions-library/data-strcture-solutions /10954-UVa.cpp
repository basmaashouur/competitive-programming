/*
Name: 10954 - Add All
Online Judge: UVa
Tags: 
Complexity: O(T*(N log N))
Tutorial: To  minimize the cost, then I have to add the smallest two numbers. 
by using priority queue(min), then push the cost of those two numbers into the qeueu,
and repeat the process until we have a queue of size 1.
EX:
priority_queue [1,2,3,4,5]
summation priority_queue
1+2=3 [3,3,4,5]
3+3=6 [4,5,6]
4+5=9 [6,9]
6+9=15 [15] here size = 1,
sum=33 so loop will terminate here
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n, v, on, tw;
        while (true)
        {
                priority_queue<long long, std::vector<long long>, greater<long long> > qu;
                long long ans = 0;
                cin >> n;
                if (n == 0)break;
                while (n--)
                {
                        cin >> v;
                        qu.push(v);
                }
                while (qu.size() != 1)
                {
                        on = qu.top();
                        qu.pop();
                        tw = qu.top();
                        qu.pop();
                        ans += on + tw;
                        qu.push(on + tw);
                }
                cout << ans << endl;
        }
        return 0;
}
