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
  * [Graph Edges Property](#graph-edges-property)
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
  - We are giving nodes and edges and we wanna find the number of connected graphs using DFS or BFS.
  ```cpp
   int conumb = 0;
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false)
		{
			dfs(i); // or bfs(i);
                      conumb++;
		}
	}

  ```
  ### Topological Sort
  - topological sort  BFS iteration code, Performs approximately O(V+E)
  ```cp
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
  - Using DFS or BFS.
  ```cpp
  void dfs(int node, int ncol)
  {
      visited[node] = true;
      col[node] = ncol;
      for (int i = 0; i < adj[node].size(); i++)
      {
          int child = adj[node][i];
          if (!visited[child])
          {
              int chicol;
              if (ncol == 1)chicol = 0;
              else chicol = 1;
              dfs(child, chicol);
          }
          else
              if (col[child] == col[node]);// not Bipartite
      }
  }
  //dfs(node, 0);

  ```
  ### Graph Edges Property
  * We need first to make a vector of pair representing all the vertcies, and check the starting visiting time and the finishing visiting time of each of them, Time(start, finish), we will initialize it at first with (-1, -1).
  * We will have 3 cases of the vertcies:
    1. Unvisited (-1, -1)
    2. Explored (1, -1)
    3. Finished (1, 2)
  * That will cause four types of edges:
    1. Tree edge with (U) will be EXPLORED to a (V) UNVISITED
    2. Back edge with (U) will be EXPLORED to a (V) EXPLORED
    3. Forward edge with (U) will be EXPLORED to a (V) FINISHED, start time[u] < start time[v].
    4. Cross edge with (U) will be EXPLORED to a (V) FINISHED, start time[u] > start time[v].
  ```cpp
  vector < int > adj[1000];
  vector < bool > visited(1000);
  vector < pair < int, int > > time(1000, make_pair(-1, -1));
  int timer = 1;

  void dfs(int node) 
  {
    visited[node] = true;
    // start
    time[child].first = timer++;
    for (int i = 0; i < adj[node].size(); i++) 
    {
      int child = adj[node][i];
    
      // tree edge
      if (!visited[child])
        dfs(child);

      else
       {
        // back edge , cycle
        if (time[child].second == -1)
        // forward edge
        else if (time[child].first < time[child].first)
        // cross edge
        else if (time[child].first > time[child].first)
      }
    }
   // finish
   time[child].second = timer++;
  }

  ```
  ### Articulation points and bridges
  ### Strongly Connected Components
  - Finding SCC using Tarjan's DFS
  ```cpp
  vector<int> adj[1000];
  vector<int> low(1000, -1);
  vector<int> dfn(1000, -1); // start visit
  vector<bool> visited(1000);
  stack<int>curr;
  int timer = 0, sccnumb = 0;

  void tarjanSCC(int node)
  {
	visited[node] = true;
	dfn[node] = low[node] = timer++;
	curr.push(node); // push curent SCC in a stack

	for (int i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];
		if (dfn[node] == -1)
			tarjanSCC(child);
		if (visited[child]) // if it's visited then it's may be back edge cause a cycle
			// change the parent the node to the min of it and it's cild
			low[node] = min(low[node], low[child]);
	}
	// if the low equal start then this node is a root node
	if (dfn[node] == low[node])
	{
		sccnumb++;
		// see the child nodes of the root node that are SCC
		while (true)
		{
			int v = curr.top();
			cout << v << " ";
			curr.pop(); visited[v] = false;
			if (v == node) {cout << endl; break;}

		}
	}
  }

  ```
  ### Edge Types and Cyclity Check	

