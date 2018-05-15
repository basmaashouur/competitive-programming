# List of Graphs Sup topic's Resources, Tags, Terminologies and Explanations

Table of Contents
=================

- [Resources And Approximate Time](#resources-and-approximate-time)
- [Tags](#tags)
- [Sup Topic Terminologies And Explanations](#sup-topic-terminologies-and-explanations)
  * [Graphs Terminologies](#graphs-terminologies)
  * [Graph Traversal](#graph-traversal)
  * [Basic Graphs Algorithms](#basic-graphs-algorithms)   
  * [Minimum Spanning Tree](#minimum-spanning-tree)
  * [Single Source Shortest Paths](#single-source-shortest-paths)

## Resources And Approximate Time

Sup Topic Name   | Resources   | Approximate stydying <br> & solving time
-------------| -------------   |-------------   
**Graphs Terminologies**|[]()<br>[]()<br> | 4Days
**Graph Traversal**<br>DFS<br>BFS <br> |[]()<br>[]()<br> | 4Days
**Basic Graphs Algorithms**<br>Flood Fill<br>Connected Components	 <br>Topological Sort	<br>Bipartite Graph Check	<br>Articulation points and bridges	 <br>Strongly Connected Components	 <br>Edge Types and Cyclity Check	 <br>|[]()<br>[]()<br> | 4Days
**Minimum Spanning Tree**<br>Standard<br>Variants <br> |[]()<br>[]()<br> | 4Days
**Single Source Shortest Paths**<br>Unweighted Graph BFS<br>Weighted Graph Dijkstra's	 <br>Bellman Ford's |[]()<br>[]()<br> | 4Days


## Tags
- DFS (Graph Traversal)
- BFS (Graph Traversal)
- Implicit graph (Graph Traversal)
- Flood Fill (Basic Graphs Algorithms)
- Connected Components (Basic Graphs Algorithms)
- Topological Sort (Basic Graphs Algorithms)
- Bipartite Check (Basic Graphs Algorithms)
- Articulation points and bridges (Basic Graphs Algorithms)
- Strongly Connected Components (Basic Graphs Algorithms)
- Edge Types and Cyclity Check (Basic Graphs Algorithms)
- Standard Minimum Spanning Tree
- Variants Minimum Spanning Tree
- Unweighted Graph BFS	(Single Source Shortest Paths)
- Weighted Graph Dijkstra's	(Single Source Shortest Paths)
- Bellman Ford's (Single Source Shortest Paths)

## Sup Topic Terminologies And Explanations

### Graphs Terminologies
* **Graphs** which are mathematical structures used to model pairwise relations between objects. A graph in this context is made up of vertices, nodes, or points which are connected by edges, arcs, or lines. graph (G = (V,E)) in its basic form is simply a set of vertices (V ) and edges (E storing
connectivity information between vertices in V).
* **Type of Graphs**
  1. **Directed Graph** if the edges can be traversed in one direction only. all the edges are unidirectional.
  2. **Undirected graph** An undirected graph is a graph in which all the edges are having  bidirectional relationship. All the edges do not point in any specific direction.
  3. **Connected graph** if there is path between any two nodes.
  4. **Weighted graph** each edge is assigned a weight. Often the weights are interpreted as edge lengths.
* **Nodes** These are the most important components in any graph. Nodes are entities whose relationships are expressed using edges.
* **Root node** The root node is the ancestor of all other nodes in a graph. It does not have any ancestor. Each graph consists of exactly one root node. root node has no parent. Generally, you must start traversing a graph from the root node.
* **Leaf nodes** In a graph, leaf nodes represent the nodes that do not have any successors. These nodes only have ancestor nodes. They can have any number of incoming edges but they will not have any outgoing edges.
* **Adjacent Nodes** Two nodes are neighbors or adjacent if there is an edge between them.
* **Node degree** The degree of a node is the number of its neighbors.
* **Edges** Edges are the components that are used to represent the relationships between various nodes in a graph. An edge between two nodes expresses a one-way or two-way relationship between the nodes.
* **Path** path leads from node a to node b through edges of the graph. The length of a path is the number of edges in it.
* **Cyclic graph or cycle path** A graph is cyclic if the graph comprises a path that starts from a vertex and ends at the same vertex. That path is called a cycle.
* **Simple graph, acyclic graph or simple path** A graph is simple if no edge starts and ends at the same node, and there are no multiple edges between two nodes.That path is called a simple.
* **Implicit graph** is a graph whose vertices or edges are not represented as explicit objects in a computer's memory, but rather are determined algorithmically from some more concise input.
### Graph Traversal
* **DFS** The algorithm begins at a starting node or source node, and proceeds to all other unvisited neighbor(s) nodes that are reachable from the starting node using the edges in the graph.The DFS algorithm is a recursive algorithm that uses the idea of backtracking, backtrack means that when you are moving forward and there are no more nodes along the current path, you move backwards on the same path to find nodes to traverse. All the nodes will be visited on the current path till all the unvisited nodes have been traversed after which the next path will be selected.
  * **Apps**
    * Reachability between two nodes
    * Graph Connectivity
* **BFS** The algorithm begins at a starting node or source node, and proceeds to all other unvisited neighbor(s) nodes that are reachable from the starting node using the edges in the graph.The BFS algorithm is an iterative algorithm that uses the idea of levels, First move horizontally and visits all the nodes of the current level then it’s move to the next level.
  * **Apps**
    * Reachability between two nodes
    * Graph Connectivity
    * Shortest path in unweighted graph
### Basic Graphs Algorithms
* **Flood Fill**  Is an algorithm that determines the area connected to a given node in a multi-dimensional array.
* **Connected Components** A graph is said to be disconnected if it is not connected, i.e. if two nodes exist in the graph such that there is no edge in between those nodes. In an undirected graph, a connected component is a set of vertices in a graph that are linked to each other by paths.
* **Topological Sort** Is a linear ordering of the vertices in the DAG so that vertex u comes before vertex v if edge (u → v)
exists in the DAG, the graph must not contain any cycles, the algorithm begins at all the nodes that have no incoming nodes to them, and proceeds to their children and decrease them by one because we had enqueue their father node u that's mean there won't be no edge as edge u → v. the results vector will be in an increasing order. 
We can use dfs as well but dfs will also work in the graph that is not DAG so the answer would be wrong.
* **Bipartite Graph Check** A graph is bipartite if its nodes can be colored using two colors so that there are no adjacent nodes with the same color. The idea is to set the starting node with 0, all its neighbors 1, and so on. If at some point of the search we notice that two adjacent nodes have the same color, this means that the graph is not bipartite.
* **Graph Edges Property Check via DFS Spanning Tree**
  * **Spanning tree**  is a subset of Graph G, which has all the vertices covered with minimum possible number of edges. Hence, a spanning tree does not have cycles and it cannot be disconnected, Running DFS on a connected graph generates a spanning tree.
  * **Spanning forest** It's like a spanning tree but when there are multiple connected components, Running DFS generates a spanning forest.
  * **Tree edge** If v is visited for the first time as we traverse the edge (u, v) then the edge is a tree edge.
  * **Back edge** If v is an ancestor of u, then edge (u, v) is a back edge, (Make a cycle).
  * **Forward edge** If v is a descendant of u, then edge (u, v) is a forward edge.
  * **Cross edge** If v is neither an ancestor or descendant of u, then edge (u, v) is a cross edge.
* **Articulation points** A vertex in an undirected connected graph is an articulation point iff removing it and all the edges associated with it disconnects the graph.
* **Bridges** An edge in a graph between vertices say U and V is called a Bridge, if after removing it, there will be no path left between U and V, and the the components will increase by one, **every bridge is not part of a cycle**. 
* **Strongly Connected Components** A directed graph is SCC if there is a path between all pairs of vertices and it's either a cycle or an individual vertex, A SCC of a directed graph is a maximal strongly connected subgraph. 
### Minimum Spanning Tree
### Single Source Shortest Paths
