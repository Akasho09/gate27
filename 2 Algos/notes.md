# GATE CS --- Section 5: Algorithms (Revision Notes)

## 1. Asymptotic Analysis

-   **Time complexity:** Growth in operations with input size `n`;
    **space complexity:** memory required.
-   **Best / average / worst case:** minimum / expected / maximum work
    for inputs of size `n`.
-   **Auxiliary space:** extra working memory, excluding input storage.
-   **Asymptotic notation:** 
`O` upper bound, 
`Ω` lower bound, 
`Θ` tight bound, 
`o` strict upper bound, 
`ω` strict lower bound. 
- Big-O does **not** inherently mean worst case.
-   **Growth order:**
    `O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)`.


## 2. Searching

  ------------------------------------------------------------------------------------
  Algorithm       Requirement             Best       Average        Worst    Auxiliary
                                                                                 space
  --------------- --------------- ------------ ------------- ------------ ------------
  Linear search   None                    O(1)          O(n)         O(n)         O(1)

  Binary search   Sorted,                 O(1)      O(log n)     O(log n)         O(1)
  (iterative)     random-access                                           
                  data                                                    

  Binary search   Sorted,                 O(1)      O(log n)     O(log n)     O(log n)
  (recursive)     random-access                                           
                  data                                                    

  Interpolation   Sorted; works           O(1)  O(log log n)         O(n)         O(1)
  search          best for                             under              
                  uniform keys                   assumptions              

  Exponential     Sorted                  O(1)      O(log n)     O(log n)         O(1)
  search                                                                     iterative
  ------------------------------------------------------------------------------------

**Binary-search trick:** after `k` halvings, remaining size is about
`n/2ᵏ`; therefore `k = Θ(log₂ n)`. Lower bound = first element `>= key`;
upper bound = first element `> key`.

## 3. Sorting

  ----------------------------------------------------------------------------
  Algorithm             Best      Average        Worst    Auxiliary Stable?
                                                              space 
  ------------- ------------ ------------ ------------ ------------ ----------
  Bubble                O(n)        O(n²)        O(n²)         O(1) Yes
  (optimized)                                                       

  Selection            O(n²)        O(n²)        O(n²)         O(1) No,
                                                                    standard
                                                                    version

  Insertion             O(n)        O(n²)        O(n²)         O(1) Yes

  Merge sort      O(n log n)   O(n log n)   O(n log n)         O(n) Yes
  (array)                                                           

  Quick sort      O(n log n) Expected O(n        O(n²)     O(log n) Usually no
                                   log n)                   average 
                                                        stack; O(n) 
                                                              worst 

  Heap sort       O(n log n)   O(n log n)   O(n log n)         O(1) No

  Counting sort       O(n+k)       O(n+k)       O(n+k)      Usually Can be
                                                             O(n+k) 

  Radix sort       O(d(n+k))    O(d(n+k))    O(d(n+k))      Usually Yes, with
                                                             O(n+k) stable
                                                                    passes
  ----------------------------------------------------------------------------

`n` = number of elements; `k` = key range/base parameter; `d` = number
of digits/passes.

-   **Bubble:** adjacent swaps; optimized best case `O(n)` with swap
    flag; maximum inversions/swaps for reverse-sorted distinct input =
    `n(n−1)/2`.
-   **Selection:** selects minimum of unsorted part; exactly `n(n−1)/2`
    comparisons and at most `n−1` swaps; standard version is unstable.
-   **Insertion:** inserts each next item into sorted prefix; adaptive
    and good for nearly sorted data; reverse-sorted distinct input
    causes `n(n−1)/2` shifts.
-   **Merge sort:** divide, recursively sort, merge.
    `T(n)=2T(n/2)+Θ(n) = Θ(n log n)`. Stable; array version uses `Θ(n)`
    extra memory.
-   **Quick sort:** partition around pivot. Balanced partitions give
    `Θ(n log n)`; repeatedly unbalanced partitions give `Θ(n²)`.
    Randomized pivot gives expected `Θ(n log n)`, not a better
    worst-case bound.
-   **Heap sort:** build max-heap in `O(n)`; repeatedly extract maximum
    in `O(log n)`; total `O(n log n)`.
-   **Counting sort:** frequency counts for bounded integer keys; not
    comparison-based.
-   **Radix sort:** sort digit by digit; each pass must be stable for
    standard LSD radix sort.
-   **Comparison-sorting lower bound:** `Ω(n log n)` worst-case in the
    general comparison model.
-   **Terms:** stable = equal-key records retain relative order;
    in-place conventionally uses `O(1)` auxiliary space; adaptive
    benefits from nearly sorted input.

## 4. Hashing

-   Hash function maps key to slot: `h(k)`. A **collision** occurs when
    different keys map to the same slot.
-   **Load factor:** `α = n/m` (`n` keys, `m` slots).
-   **Separate chaining:** each slot holds a list/bucket; load factor
    may exceed 1. Expected search `O(1+α)` under suitable hashing; worst
    `O(n)`.
-   **Open addressing:** keys stay in table; load factor must be `< 1`.
    -   Linear probing: `h(k,i) = (h(k)+i) mod m`; suffers primary
        clustering.
    -   Quadratic probing: `h(k,i) = (h(k)+c₁i+c₂i²) mod m`; reduces
        primary clustering but may have secondary clustering.
    -   Double hashing: `h(k,i) = (h₁(k)+i·h₂(k)) mod m`; choose step
        relatively prime to `m` so all slots can be reached.
-   Search/insert/delete: expected `O(1)` under suitable assumptions;
    worst `O(n)`.
-   Open-address deletion often uses tombstones. Hash tables do not
    inherently keep keys sorted.

## 5. Algorithm Design Techniques

### Greedy

Make the best local choice at each step. Correctness requires suitable
structure (e.g., greedy-choice property and optimal substructure);
greedy is not always optimal. - **Fractional knapsack:** sort by
value/weight, take whole items then a fraction. Greedy is optimal. -
**0/1 knapsack:** items cannot be split; greedy by ratio is not
generally optimal. DP commonly takes `O(nW)` time and `O(nW)` space,
reducible to `O(W)`; this is pseudo-polynomial. - Other examples:
Kruskal, Prim, Huffman coding.

### Dynamic programming (DP)

Reuse solutions to **overlapping subproblems** with **optimal
substructure**. - **Memoization:** top-down, usually recursive; caches
states. - **Tabulation:** bottom-up; fills states in order. - Fibonacci:
naive recursion exponential; DP `O(n)` time; iterative two-value version
`O(1)` auxiliary space. - **0/1 knapsack:** `DP[i][w] = DP[i−1][w]` if
`wtᵢ>w`; otherwise `max(DP[i−1][w], vᵢ + DP[i−1][w−wtᵢ])`. Time `O(nW)`,
space `O(nW)` or `O(W)`. For 1-D optimization, iterate capacity
**downward**. - **LCS:** if characters match, `DP[i][j]=1+DP[i−1][j−1]`;
else `max(DP[i−1][j], DP[i][j−1])`. Time `O(mn)`, space `O(mn)` or
`O(min(m,n))` for length only. - **Matrix-chain multiplication:**
`DP[i][j]=minₖ(DP[i][k]+DP[k+1][j]+pᵢ₋₁pₖpⱼ)`. Time `O(n³)`, space
`O(n²)`.

### Divide and conquer

Divide into subproblems, solve recursively, combine. Examples: binary
search, merge sort, quick sort, Strassen multiplication. - **Master
theorem:** `T(n)=aT(n/b)+f(n)`; compare `f(n)` with `n^(log_b a)`. 1. If
`f(n)=O(n^(log_b a−ε))`, then `T(n)=Θ(n^(log_b a))`. 2. If
`f(n)=Θ(n^(log_b a) log^k n)`, then `T(n)=Θ(n^(log_b a) log^(k+1)n)`. 3.
If `f(n)=Ω(n^(log_b a+ε))` and regularity holds, then `T(n)=Θ(f(n))`. -
Examples: merge sort `2T(n/2)+n = Θ(n log n)`; binary search
`T(n/2)+1 = Θ(log n)`; Strassen `7T(n/2)+Θ(n²)=Θ(n^log₂7)`. Master
theorem does not directly handle every recurrence
(e.g. `T(n)=T(n−1)+n`).

## 6. Graph Fundamentals

A graph `G=(V,E)` has vertices `V` and edges `E`. - Undirected simple
graph maximum edges: `V(V−1)/2`. - Directed simple graph without
self-loops maximum edges: `V(V−1)`. - Tree: connected, undirected,
acyclic; has exactly `V−1` edges. - Handshaking lemma: undirected
`Σ deg(v)=2E`; directed `Σ indegree=Σ outdegree=E`. - **Adjacency
matrix:** `O(V²)` space; edge test `O(1)`; iterate neighbors `O(V)`. -
**Adjacency list:** `O(V+E)` space; iterate neighbors `O(deg(v))`; edge
test typically `O(deg(v))`.

## 7. BFS, DFS, Topological Sorting

  -----------------------------------------------------------------------------------------
  Algorithm     Main                Time (adjacency  Auxiliary space Key uses
                structure/idea                list)                  
  ------------- ------------------ ---------------- ---------------- ----------------------
  BFS           Queue; level by              O(V+E)             O(V) Unweighted shortest
                level                                                paths, components,
                                                                     bipartite testing

  DFS           Recursion/stack;             O(V+E)             O(V) Cycles, components,
                explore deeply                                       topological sort,
                                                                     bridges/articulation
                                                                     points, SCCs

  Topological   Kahn queue or                O(V+E)             O(V) Ordering tasks in a
  sort          reverse DFS finish                                   DAG
                order                                                
  -----------------------------------------------------------------------------------------

-   BFS/DFS order may vary with neighbor ordering.
-   One traversal from one start vertex may miss other components;
    restart at unvisited vertices to cover a disconnected graph.
-   **Topological order** exists only for a DAG. Kahn's algorithm
    processing fewer than `V` vertices indicates a directed cycle.
-   Cycle detection: undirected DFS with parent tracking or DSU;
    directed DFS with gray/recursion-stack states or Kahn's algorithm.
-   DFS colors: white = unvisited, gray = active, black = finished; edge
    to gray indicates a directed cycle.

## 8. Minimum Spanning Trees (MST)

An MST is a minimum-total-weight spanning tree of a connected,
undirected, weighted graph. - Contains every vertex and exactly `V−1`
edges; has no cycles. - Negative weights are allowed. Distinct edge
weights guarantee a unique MST; equal weights may allow multiple MSTs. -
A disconnected graph has a minimum spanning **forest**.

**Kruskal (greedy):** 1. Sort edges by weight. 2. Add the next lightest
edge if it joins different components. 3. Use Disjoint Set Union
(Union-Find), ideally path compression + union by rank/size. 4. Stop
after `V−1` edges for a connected graph. - Time `O(E log E)`; DSU
operations are nearly linear, `O(E α(V))`.

**Prim (greedy):** 1. Start at a vertex. 2. Repeatedly add the lightest
edge from the current tree to an outside vertex. - Binary heap +
adjacency list: `O((V+E) log V)`; adjacency matrix: `O(V²)`. - Kruskal
chooses globally lightest eligible edge; Prim grows one tree.

**Properties:** - Cut property: a lightest edge crossing a cut is safe
for an MST; a uniquely lightest crossing edge belongs to every MST. -
Cycle property: an edge strictly heavier than every other edge in a
cycle cannot belong to an MST. - **MST ≠ shortest-path tree:** MST
minimizes total connection weight; shortest-path tree minimizes
distances from a source.

## 9. Shortest Paths

  ---------------------------------------------------------------------------------
  Algorithm         Problem          Negative                 Time Space (auxiliary
                                     edges?                           unless noted)
  ----------------- ---------------- ------------ ---------------- ----------------
  BFS               Single-source,   N/A                    O(V+E)             O(V)
                    unweighted                                     

  Dijkstra + binary Single-source    No             O((V+E) log V)      O(V) state;
  heap                                                                   graph adds
                                                                             O(V+E)

  Bellman--Ford     Single-source    Yes                     O(VE)             O(V)

  Floyd--Warshall   All-pairs        Yes                     O(V³)            O(V²)

  DAG relaxation    Single-source on Yes                    O(V+E)             O(V)
                    DAG                                            
  ---------------------------------------------------------------------------------

-   **Relaxation:** if `d[u]+w(u,v)<d[v]`, update `d[v] = d[u]+w(u,v)`.
-   **Dijkstra:** repeatedly settle the smallest tentative distance and
    relax outgoing edges; standard version fails with arbitrary negative
    edges.
-   **Bellman--Ford:** relax all edges `V−1` times, then do another
    pass; a further improvement means a reachable negative cycle.
-   **Floyd--Warshall:** `D[i][j] = min(D[i][j], D[i][k]+D[k][j])` for
    each intermediate `k`; negative diagonal after completion indicates
    a negative cycle.
-   **DAG shortest paths:** topological order + relaxation; negative
    weights are fine because there are no directed cycles.
-   Selection guide: unweighted → BFS; nonnegative weighted → Dijkstra;
    negative edges → Bellman--Ford (or DAG method if DAG); all pairs →
    Floyd--Warshall is a standard option.

## 10. High-Yield Exam Traps

1.  Binary search requires sorted, random-access data.
2.  Standard array merge sort uses `O(n)` auxiliary space.
3.  Quick sort worst case is `O(n²)` despite expected `O(n log n)`.
4.  Bottom-up heap construction is `O(n)`.
5.  Selection sort makes `n(n−1)/2` comparisons even on sorted input.
6.  Stability preserves relative order of equal-key records.
7.  Hashing average `O(1)` is not a worst-case guarantee.
8.  Greedy is optimal for fractional knapsack, not generally for 0/1
    knapsack.
9.  Dijkstra requires nonnegative edge weights.
10. An MST has `V−1` edges but is not necessarily a shortest-path tree.
11. BFS gives shortest paths in unweighted graphs; DFS does not
    guarantee them.
12. Topological sorting is possible only for DAGs.
13. Bellman--Ford uses `V−1` full edge-relaxation passes plus a
    negative-cycle check.
14. Big-O means upper bound, not automatically worst case.
15. For disconnected graphs, a single BFS/DFS start does not visit every
    vertex.

## 11. Final Quick-Choice Table

  If asked to...                                  Use / remember
  ----------------------------------------------- --------------------------------
  Search unsorted data                            Linear search
  Search sorted array                             Binary search
  Sort nearly sorted data                         Insertion sort
  Need stable `O(n log n)` sorting                Merge sort
  Need `O(n log n)` worst-case in-place sorting   Heap sort
  Find MST                                        Prim or Kruskal
  Shortest path in unweighted graph               BFS
  Shortest path with nonnegative weights          Dijkstra
  Handle negative edge weights                    Bellman--Ford
  Find all-pairs shortest paths                   Floyd--Warshall
  Find shortest path in a DAG                     Topological-order relaxation
  Order dependencies/tasks                        Topological sort
  Find components                                 BFS or DFS
  Detect undirected cycle                         DFS with parent or DSU
  Detect directed cycle                           DFS colors or Kahn's algorithm
