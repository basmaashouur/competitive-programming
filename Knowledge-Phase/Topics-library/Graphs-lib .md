# Graphs

Table of Contents
=================

- [Graphs Terminologies](#graphs-terminologies)
  * [Graph Representation](#graph-representation)
- [Graph Traversal](#graph-traversal)
  * [DFS](#dfs)
  * [BFS](#bfs)
- [Basic Graphs Algorithms](#basic-graphs-algorithms) 
  * [Flood Fill](#flood-fill)
  * [Connected Components](#connected-components)
  * [Topological Sort](#topological-sort)
  * [Bipartite Graph Check](#bipartite-graph-check)
  * [Articulation points and bridges](#articulation-points-and-bridges)
  * [Strongly Connected Components](#strongly-connected-components)
  * [Edge Types and Cyclity Check](#edge-types-and-cyclity-check)
- [Minimum Spanning Tree](#minimum-spanning-tree)
- [Single Source Shortest Paths](#single-source-shortest-paths)

## Graphs Terminologies
### Graph Representation
- Basic code
  ```cpp
   vector<vector<int> > adj;
   vector<bool> visited;

   int main()
   {
   int n, e;
   cin >> n >> e;
   adj = vector<vector<int> >(n);
   visited = vector<bool>(n);
   }

  ```

## Graph Traversal
### DFS
- DFS recursive code (Performs approximately O(V+E))
  ```cpp
   /*
   Function: DFS Exhaustive searches of all the nodes   
   Exhaustive searches of all the nodes by going level after level.by going ahead, if possible,
   else by backtracking. And mark all the visited nodes to not visit it again.
   Parameters: Node: the start node we start traverse from
   Returns: void
  */

  vector<int> adj[1000];
  vector<bool> visited(1000);
  void dfs(int node)
  {
	 visited[node] = true;
	 for (int i = 0; i < adj[node].size(); i++)
	 {
		 int child = adj[node][i];
		 if (!visited[child])
		    	dfs(child);
	 }
  }

  ```

### BFS
- BFS iteration code & Shortest path in unweighted graph (Performs approximately O(V+E)
  ```cpp
   /*
    Function: BFS iteration code
    Exhaustive searches of all the nodes by going level after level.
    Parameters: Node: the start node we start traverse from
    Returns: void

    Shortest path for unweighted:
    Step 1: know the start and destination node.
    Step 2: bfs(start)
    Step 3: trace the shortest path vector from destination until start node and that’s
    would be our path (start  → node → ... →  destination)
    Note: if we have the same destination node and we want to know paths from different starts nodes,
    we will make bfs(destination)
    but if the graph undirected reverse the node u → v will be v → u and repeat
    Step 3 from every start node.
  */

    vector<int> adj[1000];
    vector<bool> visited(1000);
    vector<int>level(1000);
    vector<int> short_path(1000);
    void bfs(int node)
    {
           queue<int>q;
           q.push(node);
           visited[node] = true;
           level[node] = 0; //the first level node
           while (!q.empty())
          {
                  int father = q.front();
                  q.pop();
                  for (int x = 0; x < adj[father].size(); x++)
                  {
                           int child = adj[father][x];
                           if (!visited[child])
                           {
                                  q.push(child);
                                  level[child] = level[father] + 1; //equal the parent level+1
                                  short_path[child] = father;// the father node he comes from
                                 visited[child] = true;
                           }
                   }
          }

  ```
  
  ## Basic Graphs Algorithms
  ### Flood Fill
  - It determines the area connected to a given cell or a node in a multidimensional array.
    ```cpp
    vector<int> matrix[1000];
    int visited[100][100] = {{0, 0}, {0, 0}};
    int n, m;
    static int moves[8][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 1 },
    { -1, -1 }, { 1, -1 }, { 1, 1 } };

    void fill(int x, int y)
    {
	if (x >= n || y >= m || x < 0 || y < 0 )return; // outside the grid
	if(visited[x][y] == true)return; // avoid cycling or infinite loop
	visited[x][y] = true;
	
       //cells that you can't visit it, here is the cell that equal 0 
	if (matrix[x][y] == 0)return;
	
	//in case of 8-connections, to the points at both diagonals
	//not only(up, down, right, left) sharing one side, make the loop i<8
	for (int i = 0; i < 4; i++)
	   fill(x + moves[i][0], y + moves[i][1]);
    }

    ```
  ### Connected Components	 
  ### Topological Sort
  - topological sort  BFS iteration code, Performs approximately O(V+E)
  ```cpp
  /*
  Function: toplog
  Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG
  Step-2: Pick all the vertices with in-degree as 0 and add them into a queue 
  Step-3: Remove a vertex from the queue, put the top element  in the results vector and then:
  1.  Decrease in-degree by 1 for all its neighboring nodes.
  2. If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
  Step-4: Repeat Step 3 until the queue is empty.
  Step-5: if the result vector != n then it’s not DAG(main) 
  
  Parameters: empty
  Returns: void
  */
  
  vector<vector<int> > adj; 
  vector<int>res;
  vector<int>in;
  void toplog()
  {
	priority_queue<int, vector<int>, greater<int> >pq; //sort increasing
	for (int u = 1; u <= n; u++)
		if (in[u] == 0) pq.push(u);

	while (!pq.empty())
	{
		int top = pq.top(), size=adj[top].size();
		pq.pop(); res.pp(top);
	
		for (int x = 0; x < size; x++)
		{
			int u = adj[top][x];
			if (--in[u] == 0)pq.push(u);
		}
	}
  }
  
  ```

  ### Bipartite Graph Check	
  ### Articulation points and bridges
  ### Strongly Connected Components
  ### Edge Types and Cyclity Check	

