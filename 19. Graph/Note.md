# Graph

### Q1 For a graph with n nodes, how many edges are there in a complete graph?
* Number of edges in a complete graph of n nodes is nC2 = (n!/(n-2)! * 2!) 

### Q2 Minimum number of edges to make a graph on n nodes is?
* 0, since the nodes which are not at all connected still make graph. It is known as a void graph

### Q3 Minimum number of edges to make a connected graph of n nodes?
*  n-1 nodes, which make up a tree as well.

### Q4 Insertion and deletion of edges is fastest in ___ ?
* Adjacency Matrix, bs it takes O(1) in oth insertion and deletionL

### Q5 Which representation should be used if we have a graph with a large number of nodes (>108) but with a few edges between them?
* Adjacency Matrix, as it takes O(1) in O(1) insertion and deletion.

### Q6 Can adjacencyMatrix[i][j] != adjacencyMatrix[j][i] in any case? If yes, what would be the type of graph called?
*  It is possible when the graph is directed.

### Q7 For a graph with n nodes, how many edges are there in a complete graph?
* nC2: We can choose any two nodes out of n nodes and then connect them.

### Q8 Minimum number of edges to make a graph on n nodes is?
* 0, since the nodes which are not at all connected still make graph. It is known as a void graph

### Q9 Minimum number of edges to make a connected graph of n nodes?
* n-1 nodes, which make up a tree as well.



### Q12 Consider a directed graph with 4 nodes (1, 2, 3, 4) and the following edges: (1->2), (2->3), (3->4), (4->1). Represent this graph using an Edge List.


### Q11 Given the following adjacency matrix for a directed graph:

[[0, 1, 0, 0],

[0, 0, 1, 0],

[0, 0, 0, 1],

[0, 0, 0, 0]]

What is the indegree of vertex 3?


### Q10 Given the following adjacency list for an undirected graph:

[

    [1, 2],

    [0, 3],

    [0, 3],

    [1, 2]

]

What are the adjacent vertices of vertex 1?


### Q13 What is the maximum number of edges in a simple undirected graph with n nodes?




### Q14 What is the minimum number of edges in a simple undirected connected graph with n
nodes?




### Q15 What is the minimum number of colors needed to color the nodes of a graph such that
no two adjacent nodes have the same color?


### Q16 What is the minimum cut of a graph?


### Q17 What is the minimum number of nodes required to create a cycle in a directed graph?


### Q18 What is the degree of a vertex in a graph?


### Q19 Consider a graph with 5 nodes, A, B, C, D, and E. The following edges are present in the graph:

A -> B

B -> C

C -> D

D -> E

E -> A


What is the degree of vertex C?




### Q20 What is the time complexity of finding the minimum spanning tree of a graph using Prim's algorithm?
* The time complexity of finding the minimum spanning tree of a graph using Prim's algorithm is O(|E| + |V| log |V|), where |E| is the number of edges in the graph and |V| is the number of vertices in the graph.

### Q21 In a complete graph, what is the sum of the degrees of all the vertices?




### Q22 If a graph has 10 vertices and 25 edges, is it a tree?




### Q23 How many edges can be removed from a complete graph with 6 vertices to make it a tree?




### Q24 How many vertices are there in a graph with 12 edges and a maximum degree of 4?




### Q25 What is the diameter of a complete graph with 10 vertices?



### Q26 In a simple graph with 4 vertices and 3 edges, is there a cycle?



