/*
Name: 11995 - I Can Guess the Data Structure!
Online Judge: UVa
Tags: Queue, Stack, Priority_queue
Complexity: O(t*n)
Tutorial: Just push the values in the (queue, stack, priority_queue) and when you want to reomve it
just see which one we can reomve it from. The data stacrture that we were able to remove all elements 
from it is the answer.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n, v, op;
        while (scanf("%d", &n) != EOF)
        {
                queue<int> q;
                stack<int> s;
                priority_queue<int> pq;

                int qu = 0, st = 0, pqu = 0, totdel = 0;
                for (int x  = 0; x < n; x++)
                {
                        cin >> op >> v;
                        if (op == 1)
                        {
                                q.push(v);
                                s.push(v);
                                pq.push(v);
                        }
                        else
                        {
                                totdel++;
                                if (!q.empty()&&q.front() == v)qu++, q.pop();
                                if (!s.empty()&&s.top() == v)st++, s.pop();
                                if (!pq.empty()&&pq.top() == v)pqu++, pq.pop();
                        }
                }
                if ((st == totdel && qu == totdel) ||
                                (st == totdel && pqu == totdel) ||
                                (pqu == totdel && qu == totdel))
                        cout << "not sure" << endl;
                else if (qu == totdel)cout << "queue" << endl;
                else if (st == totdel)cout << "stack" << endl;
                else if (pqu == totdel)cout << "priority queue" << endl;
                else cout << "impossible" << endl;
        }
        return 0;
}
