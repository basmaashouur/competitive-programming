
/*
Name: 11242 - Tour de France
Online Judge: UVa
Tags: Iterative
Complexity: O(r * f)
Tutorial: divde all the rear over the front, then sort all of these ratios, then divide every two consecutive ratios
and the answer would be the max of them.
*/


// C O D E

#include <bits/stdc++.h>
using namespace std;


int main()
{
        int f, r;
        double v, ans;
        while (true)
        {
                cin >> f;
                if (f == 0)break;
                cin >> r;
                vector <double>front;
                vector<double>rear;
                vector<double>ratio;
                for (int x = 0; x < f; x++)
                {
                        cin >> v;
                        front.push_back(v);
                }
                for (int y = 0; y < r; y++)
                {
                        cin >> v;
                        rear.push_back(v);
                }

                for (int x = 0; x < r; x++)
                {
                        for (int y = 0; y < f; y++)
                                ratio.push_back(rear[x] / front[y]);
                }
                sort(ratio.begin(), ratio.end());
                ans = 0;
                for (int x = 1; x < ratio.size(); x++)
                {
                        if (ans < ratio[x] / ratio[x - 1])ans = ratio[x] / ratio[x - 1];
                }
                cout << fixed << setprecision(2) << ans << endl;
        }
        return 0;
}
