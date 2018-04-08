/*
Name: 11831 - Sticker Collector Robot
Online Judge: UVa
Tags: Implicit graph, Vectors
Complexity: O(N+M)
Tutorial: The idea behind it to track the commands if the command D or E then change the destination
 (right, left, up down)
Depends on the current pos 
N (UP) ->    D = L
N (UP) ->    E = O
S (Down) ->  D = O
S (Down) ->  E = L
L (Right) -> D = S
L (Right) -> E = N
O (Left) ->  D = N
O (Left) ->  E = S
if the command forward see if we can move to this cell(no outside the grid or pillar cell) 
with the current destination if yes then see if the cell is sticker then incrment the answer 
and delete the sticker. And so on, until there is no more commands
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

//                           UP        Down      Right     Left

static int moves[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }};
int n, m, s, ex, wy, ans;
vector<string>vec;
void forward(int pos)
{
        int tex = ex + moves[pos][0];
        int twy = wy +  moves[pos][1];
        if (tex < n && twy < m && tex >= 0 && twy >= 0)
        {
                if (vec[tex][twy] == '*')
                {
                        ex = tex;
                        wy = twy;
                        ans++;
                        vec[tex][twy] = '.';
                }
                else if (vec[tex][twy]  == '.')ex = tex, wy = twy;
        }
}


int main()
{
        string arena, command;
        char now;
        while (true)
        {
                cin >> n >> m >> s;
                ans = 0;
                vec.clear();
                if (n == 0 && m == 0 && s == 0)break;
                for (int x = 0; x < n; x++)
                {
                        cin >> arena;
                        for (int y = 0; y < m; y++)
                                if (isalpha(arena[y]))
                                        ex = x, wy = y, now = arena[y], arena[y] = '.';
                        vec.push_back(arena);
                }
                cin >> command;
                for (int x = 0; x < s; x++)
                {
                        if (command[x] == 'D')
                        {
                                if (now == 'N')now = 'L';
                                else if (now == 'S')now = 'O';
                                else if (now == 'L')now = 'S';
                                else now = 'N';

                        }
                        else if (command[x] == 'E')
                        {
                                if (now == 'N')now = 'O';
                                else if (now == 'S')now = 'L';
                                else if (now == 'L')now = 'N';
                                else now = 'S';
                        }
                        else
                        {
                                if (now == 'N')
                                        forward(0);
                                else if (now == 'S')
                                        forward(1);
                                else if (now == 'L')
                                        forward(2);
                                else
                                        forward(3);
                        }
                }
                cout << ans << endl;
        }

        return 0;
}

