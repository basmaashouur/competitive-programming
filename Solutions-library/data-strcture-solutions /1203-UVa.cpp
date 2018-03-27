/*
Name: 1203 - Argus
Online Judge: UVa
Tags:  Priority Queue, Sorting
Complexity: O(n log n)
Tutorial: Push in min heap Priority Queue the period, then increase the min period and pop it from the queue
and repush the new value of it after increasing, repaeat these process untill we got the K Qnum.
Becarefull if we have two period with the same time we print the less qnum
ex: [50,10] , [100,10]
we print 50, because both have same period 10 but 50 is less qnum
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
        priority_queue<pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>> > mpq;
        vector<pair <int, int> > in;
        vector <int> ans;
        string op;
        int qn, pe, k;
        while (true)
        {
                cin >> op;
                if (op == "#")break;
                cin >> qn >> pe;
                in.push_back(make_pair(qn, pe));
        }
        cin >> k;
        // so the qnum with less number would be the first
        sort(in.begin(), in.end());
        for (int x = 0; x < in.size(); x++)
        {
                // push in queue the periods and the index that contain info about it
                mpq.push(make_pair(in[x].second, x));
        }
        while (ans.size() <= k)
        {
                // top of mpq is the pair[period, index of that period in the vector]
                pair<int , int> temp =  mpq.top();
                mpq.pop();
                // push in the ans the qnum which we can get it by this way
                ans.push_back(in[temp.second].first);
                temp.first += in[temp.second].second;
                mpq.push(temp);
        }
        for (int x = 0; x < k; x++)
                cout << ans[x] << endl;

        return 0;
}
