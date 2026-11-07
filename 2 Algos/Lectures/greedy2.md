# Spanning Tree 
A **Spanning Tree** of a connected, undirected graph \(G\) is a subgraph that:
1. Contains **all vertices** of \(G\).
2. Is **connected**.
3. Contains **no cycles** (acyclic).
4. Has exactly \(V-1\) edges, 
> where \(V\) is the number of vertices.

## 2. Important Properties
| Property | Spanning Tree |
|---|---|
| Number of vertices | \(V\) — all vertices of the original graph |
| Number of edges | \(V-1\) |
| Connected | Yes | 
| Contains cycles | No |
| Is a subgraph of original graph | Yes |
| Minimum edges needed to connect all vertices | \(V-1\) |
| Removing any edge | Makes it disconnected |
| Adding an extra edge | Creates a cycle |
**Remember:** A spanning tree is a connected and acyclic subgraph containing every vertex of the original graph.

## 3. How to Identify a Spanning Tree
For a graph with \(V\) vertices, check these conditions:
- All vertices are included.
- Exactly \(V-1\) edges are selected.
- The selected edges connect every vertex.
- No cycle exists.
If any condition fails, it is not a spanning tree.

### Common traps
| Situation | Spanning Tree? | Reason |
|---|---|---|
| All vertices included, but graph is disconnected | No | Not connected |
| Connected graph containing a cycle | No | Not acyclic |
| Connected and acyclic with all vertices | Yes | Satisfies all properties |
| \(V\) vertices and fewer than \(V-1\) edges | No | Cannot connect all vertices |
| \(V\) vertices and \(V-1\) edges, but disconnected | No | Edge count alone is insufficient |

## 4. Number of Spanning Trees in a Complete Graph
For a complete graph \(K_n\), every pair of distinct vertices is connected by an edge.
- The number of distinct spanning trees is given by **Cayley's Formula**: for complete graph
> n^n-2
Here, \(n\) is the number of vertices.

### Important values
| Complete Graph | Number of Vertices | Number of Spanning Trees |
|---|---:|---:|
| \(K_1\) | 1 | 1 |
| \(K_2\) | 2 | 1 |
| \(K_3\) | 3 | 3 |
| \(K_4\) | 4 | 16 |
| \(K_5\) | 5 | 125 |
| \(K_6\) | 6 | 1,296 |
| \(K_{10}\) | 10 | 100,000,000 |

## 5. Spanning Tree vs. Minimum Spanning Tree (MST)
| Feature | Spanning Tree | Minimum Spanning Tree |
|---|---|---|
| Includes all vertices | Yes | Yes |
| Connected | Yes | Yes |
| Contains cycles | No | No |
| Number of edges | \(V-1\) | \(V-1\) |
| Edge weights considered | Not necessarily | Yes |
| Objective | Connect all vertices without cycles | Minimize total edge weight |
| Algorithms | Can be constructed in different ways | Prim's and Kruskal's algorithms |

For a weighted connected, undirected graph:

\[
\text{MST Cost}=\min\sum_{e\in T}w(e)
\]

where \(T\) is a spanning tree and \(w(e)\) is the weight of edge \(e\).

## 6. Minimum Spanning Tree Algorithms
Two important greedy algorithms used to find an MST are:
- **Kruskal's Algorithm:** Sort edges by increasing weight and select an edge if it does not create a cycle.
- **Prim's Algorithm:** Start from a vertex and repeatedly add the minimum-weight edge connecting the current tree to a new vertex.
Both produce an MST for a connected, undirected weighted graph. If edge weights are distinct, the MST is unique.

## 7. Kirchhoff's Matrix-Tree Theorem
For a general graph, the number of spanning trees can be calculated using **Kirchhoff's Matrix-Tree Theorem**.
Basic procedure:
1. Construct the degree matrix \(D\).
2. Construct the adjacency matrix \(A\).
3. Calculate the graph Laplacian:
   \[
   L=D-A
   \]
4. Delete any one row and the corresponding column from \(L\).
5. Calculate the determinant of the resulting matrix.

\[
\boxed{\text{Number of spanning trees}=\det(L')}
\]

Here, \(L'\) is the reduced Laplacian matrix.

For a connected graph, the determinant gives the number of spanning trees.

# Kruskal’s Algorithm
- Kruskal’s Algorithm is a **Greedy Algorithm** used to find a **Minimum Spanning Tree (MST)** of a connected, weighted, undirected graph.
- It selects edges in **increasing order of weight**.
- An edge is selected only if adding it does **not create a cycle**.
- Stop when exactly \(V-1\) edges have been selected, where \(V\) is the number of vertices.

## 2. Important Properties
| Property | Kruskal’s Algorithm |
|---|---|
| Algorithm type | Greedy |
| Objective | Find Minimum Spanning Tree |
| Edge selection | Minimum weight first |
| Cycle allowed? | No |
| Number of MST edges | \(V-1\) |
| Intermediate forest connected? | Not necessarily |
| Common data structure | Min-Heap or sorted edge list |
| Efficient cycle detection | Disjoint Set Union (DSU) |
| Works on | Weighted, undirected graphs |

**Important:** Unlike Prim’s Algorithm, Kruskal’s Algorithm may create multiple disconnected components during execution. These components eventually form a spanning tree.

## 3. Steps of Kruskal’s Algorithm
1. Sort all edges in increasing order of weight.
2. Start with an empty MST.
3. Select the smallest-weight edge.
4. Check whether adding the edge creates a cycle.
5. If it does **not** create a cycle, include it in the MST.
6. If it creates a cycle, reject it.
7. Continue until the MST contains \(V-1\) edges.

### Pseudocode
```yml
Kruskal(G):
    MST = empty set
    sort all edges in increasing order of weight

    for each edge (u, v) in sorted edges:
        if u and v belong to different components:
            add (u, v) to MST
            union(u, v)

        if size(MST) == V - 1:
            break

    return MST
```

The `find` and `union` operations are typically implemented using a Disjoint Set Union (DSU) structure.

## 5. How to Detect a Cycle Quickly
An edge \((u,v)\) creates a cycle if \(u\) and \(v\) are **already connected through the selected edges**.
- If both vertices belong to the same component, reject the edge.
- If they belong to different components, select the edge and merge their components.

## 6. Time Complexity
Let:
- \(V\) = number of vertices
- \(E\) = number of edges

| Operation | Time Complexity |
|---|---|
| Sort all edges | \(O(E\log E)\) |
| Build a heap using heapify | \(O(E)\) |
| Extract the minimum from a heap | \(O(\log E)\) |
| Cycle detection with DSU | Nearly \(O(1)\) amortized per operation |
| Standard Kruskal with sorting and DSU | \(O(E\log E)\) |
> | Auxiliary space | \(O(V+E)\) |

The standard implementation sorts the edges and uses DSU for cycle detection:
O(E\log E)

Since \(E\leq V^2\) in a simple graph, \(\log E=O(\log V)\), so the complexity is also commonly expressed as:
O(E\log V)

> The standard overall time complexity is (O(E * log E)). 
 
## 7. Kruskal vs. Prim
| Feature | Kruskal’s Algorithm | Prim’s Algorithm |
|---|---|---|
| Strategy | Select the minimum available edge globally | Grow one tree from a starting vertex |
| Starts from | No specific starting vertex required | A starting vertex |
| Intermediate structure | Forest; may be disconnected | One connected tree |
| Selection | Smallest edge that does not create a cycle | Minimum edge connecting the tree to a new vertex |
| Common implementation | Sorting + DSU | Priority queue + adjacency list |
| Typical complexity | \(O(E\log E)\) | \(O(E\log V)\) with a binary heap and adjacency list |
| Output | MST | MST |

For a connected, weighted, undirected graph, both algorithms find a minimum spanning tree. If multiple MSTs exist, their selected edges may differ while their minimum total cost remains the same.

# Prim’s Algorithm 
- Prim’s Algorithm is a **Greedy Algorithm** used to find a **Minimum Spanning Tree (MST)** of a connected, weighted, undirected graph.
- It starts from any vertex and grows a single connected tree.
- At each step, select the **minimum-weight edge connecting a vertex inside the tree to a vertex outside the tree**.
- Continue until all vertices are included.

## 2. Important Properties
| Property | Prim’s Algorithm |
|---|---|
| Algorithm type | Greedy |
| Objective | Find Minimum Spanning Tree |
| Starting point | Any vertex, unless specified |
| Edge selection | Minimum edge connecting the tree to a new vertex |
| Cycle allowed? | No |
| Number of vertices in MST | \(V\) |
| Number of edges in MST | \(V-1\) |
| Intermediate tree connected? | Always |
| Graph type | Weighted, undirected, connected graph |
| Common data structure | Min-Heap / Priority Queue |

## 3. Steps of Prim’s Algorithm
1. Choose a starting vertex.
2. Mark it as part of the MST.
3. Find all edges connecting vertices inside the MST to vertices outside it.
4. Select the minimum-weight eligible edge.
5. Add that edge and its new vertex to the MST.
6. Repeat until all vertices are included.

**Important:** Do not select the minimum edge among all graph edges blindly. It must connect the current tree to a vertex not yet included in the tree.

## 4. Pseudocode
```yml
Prim(G, start):
    MST = empty set
    visited = {start}

    while not all vertices are visited:
        choose minimum-weight edge (u, v)
        where u is visited and v is not visited

        add (u, v) to MST
        add v to visited

    return MST
```

This is conceptual pseudocode. An efficient implementation uses a priority queue and stores the minimum edge cost needed to connect each unvisited vertex.

## 6. How Prim’s Algorithm Avoids Cycles
Prim’s Algorithm adds exactly one new vertex at each step.

- One endpoint of the selected edge must already belong to the tree.
- The other endpoint must be outside the tree.
- Therefore, the selected edge cannot connect two vertices already in the tree and create a cycle.

### Example
Suppose the current tree contains A, B and C, with edges A–B and B–C.

- Adding C–D is valid if D is outside the tree.
- Adding A–C is invalid because both A and C are already inside the tree, and it creates a cycle.

## 7. Time Complexity
Let \(V\) be the number of vertices and \(E\) the number of edges.

| Implementation | Time Complexity |
|---|---|
| Adjacency matrix | \(O(V^2)\) |
| Adjacency list + binary min-heap | \(O(E\log V)\) |
| Fibonacci heap implementation | \(O(E+V\log V)\) |

**GATE tip:** State the implementation when answering a time-complexity question. Prim’s Algorithm does not have just one time complexity for every implementation.

## 8. Prim’s vs. Kruskal’s Algorithm
| Feature | Prim’s Algorithm | Kruskal’s Algorithm |
|---|---|---|
| Strategy | Grows one connected tree | Builds a forest and merges components |
| Starting vertex | Required | Not required |
| Edge selection | Minimum edge from tree to outside vertex | Minimum edge globally that does not form a cycle |
| Intermediate structure | Always connected | May be disconnected |
| Cycle prevention | Add only a new vertex | Use cycle detection, commonly DSU |
| Common implementation | Priority queue | Sorting + DSU |
| Typical complexity | \(O(E\log V)\) | \(O(E\log E)\) |
| Output | MST | MST |

Both algorithms find an MST for a connected, weighted, undirected graph.