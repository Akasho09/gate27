## Dijkstra’s Algorithm 

- Dijkstra’s Algorithm is a `**Greedy Algorithm**` used to find the **Single Source Shortest Paths (SSSP)** from one source vertex to all other reachable vertices.
- It repeatedly selects the unvisited vertex with the smallest tentative distance.
- It relaxes the outgoing edges to improve the shortest-distance estimates.
- It works on directed and undirected weighted graphs **provided all edge weights are non-negative**.

### Applications

- GPS and route planning
- Network routing
- Finding minimum-cost paths in graphs
- Transportation and communication networks

## 2. Important Terms
| Term | Meaning |
|---|---|
| Source | Vertex from which shortest paths are calculated |
| Distance array `dist[]` | Stores the best-known distance from the source |
| Relaxation | Attempts to reduce the distance to a neighboring vertex |
| Visited / settled vertex | Vertex whose shortest distance has been finalized |
| Infinity (\(\infty\)) | Represents an initially unknown or unreachable distance |
| Parent / predecessor | Previous vertex on the shortest path |

## 3. Initialization

Suppose the source vertex is \(s\).

- Set `dist[s] = 0`.
- Set the distance of every other vertex to infinity.
- Initially, no vertex is settled.

| Vertex | Initial Distance |
|---|---:|
| Source \(s\) | 0 |
| Every other vertex | \(\infty\) |

## 4. Relaxation — The Most Important Concept
Relaxation checks whether reaching a vertex through another vertex produces a shorter path.
- For an edge \(u \rightarrow v\) with weight \(w(u,v)\):
dist[v]=min ( dist[v],
              dist[u]+w(u,v) )

### Rule
1. Calculate `dist[u] + weight(u, v)`.
2. Compare it with the current `dist[v]`.
3. If the new distance is smaller, update `dist[v]`.
4. Otherwise, leave `dist[v]` unchanged.

## 5. Algorithm Steps

1. Initialize distances: source = 0, all others = infinity.
2. Select the unvisited vertex with the minimum tentative distance.
3. Mark that vertex as settled.
4. Relax all its outgoing edges to unvisited neighbors.
5. Repeat until all reachable vertices are settled or the minimum tentative distance is infinity.

**Important:** Once a vertex is settled, its shortest distance is final only because Dijkstra’s algorithm assumes non-negative edge weights.

## 6. Pseudocode — Min-Heap Implementation

```yml
Dijkstra(G, source):
    for each vertex v:
        dist[v] = infinity
        parent[v] = NIL

    dist[source] = 0
    priorityQueue = {(0, source)}

    while priorityQueue is not empty:
        (d, u) = extractMin(priorityQueue)

        if d > dist[u]:
            continue

        for each edge (u, v) with weight w:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
                insert (dist[v], v) into priorityQueue

    return dist, parent
```

This version uses a priority queue with lazy updates. Stale entries are ignored when their stored distance exceeds the current best distance.

## 8. Time Complexity
- Let \(V\) be the number of vertices and \(E\) the number of edges.

| Implementation | Time Complexity |
|---|---|
| Adjacency matrix, simple implementation | \(O(V^2)\) |
| Adjacency list + binary min-heap | \(O((V+E)log V)\) |
| Binary heap, commonly simplified for connected graphs | \(O(E\log V)\) |
| Fibonacci heap | \(O(E+V\log V)\) |

> O(E . log V)

## 9. Advantages and Limitations

| Advantages | Limitations |
|---|---|
| Finds shortest paths from one source | Does not work correctly in general with negative-weight edges |
| Works with directed and undirected graphs | Cannot handle negative-weight cycles |
| Efficient with a priority queue | Not designed to find shortest paths between every pair of vertices in one run |
| Can reconstruct paths using parent pointers | A different algorithm may be needed when negative weights exist |

### Which algorithm should you use?

| Requirement | Suitable Algorithm |
|---|---|
| Single-source shortest paths, non-negative weights | Dijkstra |
| Single-source shortest paths, negative edges allowed | Bellman–Ford |
| All-pairs shortest paths | Floyd–Warshall |

## 3. Edge Relaxation

For an edge from \(u\) to \(v\) with weight \(w(u,v)\):

```yml
if dist[u] + w(u, v) < dist[v]:
    dist[v] = dist[u] + w(u, v)
    update v's priority in the min-heap
```

**Key idea:** Update a vertex's distance only when a shorter path is found.

## 5. Time Complexity Analysis

| Operation | Time complexity | Number of times |
|---|---:|---:|
| Initialize distances | \(O(V)\) | Once per vertex |
| Build an initial heap | \(O(V)\) | Once, using heapify |
| Extract minimum | \(O(\log V)\) | Up to \(O(E)\) with duplicate entries |
| Relax an edge | \(O(1)\) excluding heap operations | \(O(E)\) |
| Insert updated distance | \(O(\log V)\) | Up to \(O(E)\) |

### Overall complexity

For a binary min-heap with lazy insertion:

\[
\boxed{O((V+E)\log V)}
\]

For a connected simple graph, \(E \geq V-1\), so this is commonly written as:

\[boxed{O(E\log V)}]

For an implementation using a binary heap with decrease-key, the standard bound is \(O((V+E)\log V)\), also commonly simplified to \(O(E\log V)\) for connected graphs.

## 6. Complexity by Implementation

| Implementation | Time complexity |
|---|---:|
| Adjacency matrix + linear minimum search | \(O(V^2)\) |
| Adjacency list + binary min-heap | \(O((V+E)\log V)\) |
| Adjacency list + binary min-heap, connected graph | \(O(E\log V)\) |
| Adjacency list + Fibonacci heap | \(O(E+V\log V)\) |

