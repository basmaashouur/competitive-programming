#include <bits/stdc++.h>
using namespace std;
int n, e, u, v;
vector<vector<int> > adj;
vector<bool> visited;
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
                cin >> n>>v;
                adj = vector<vector<int> >(n);
                visited = vector<bool>(n);
                for(int x =0;x<e;x++)
                {
                        cin>>u>>v;
                        vec[u].push_back(v);
                        vec[v].push_back(u);
                }


        }
      
        return 0;
}
