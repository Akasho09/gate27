# Travelling Salesman Problem (TSP) 
The **Travelling Salesman Problem (TSP)** is an optimization problem in which a salesman must:

1. Start from a particular city.
2. Visit every other city exactly once.
3. Return to the starting city.
4. Minimize the total travelling cost.

The cost of travelling between cities is represented using a **cost matrix** or a weighted graph.

## 2. Graph Representation

- Each city represents a vertex.
- Each route between cities represents an edge.
- The edge weight represents the travelling cost.
- The goal is to find a minimum-cost tour that visits every vertex once and returns to the starting vertex.

**Important:** A complete tour must include the return journey to the starting city.

## 3. Greedy Approach

A greedy approach chooses the locally cheapest available option at each step.

### How it works

1. Start from a selected city.
2. Choose the cheapest eligible next city.
3. Repeat until all cities have been visited.
4. Return to the starting city.
5. Calculate the total cost of the tour.

### Limitation of Greedy

- Greedy makes decisions based on immediate cost.
- It does not necessarily consider the cost of the entire remaining journey.
- Therefore, a locally optimal choice may lead to a globally suboptimal tour.
- Greedy does **not guarantee the optimal solution** for TSP.

**GATE point:** Finding a low-cost next edge does not guarantee finding the minimum-cost complete tour.

## 4. Brute-Force Approach
Brute force considers all possible orders in which the cities can be visited.

### Steps
1. Fix the starting city.
2. Generate every possible ordering of the remaining cities.
3. Calculate the total cost of each tour, including the return to the start.
4. Select the tour with the minimum total cost.

### Number of possible tours
- For \(n\) cities, with the starting city fixed, the remaining \(n-1\) cities can be arranged in:
> (n-1)! different orders.
For a symmetric graph, a tour and its reverse have the same cost. If reverse tours are counted as equivalent, the number of distinct tours is:

\[
\frac{(n-1)!}{2}
\]

for \(n>2\).

### Complexity

- Brute-force time complexity: factorial growth, commonly expressed as \(O(n!)\).
- It becomes computationally expensive as the number of cities increases.

## 5. Dynamic Programming (DP) Approach
Dynamic programming attempts to solve a problem by storing results of smaller subproblems and reusing them.

### Why consider DP for TSP?

- Brute force examines an enormous number of tours.
- DP can avoid recomputing the same subproblems.
- However, DP does not make TSP polynomial-time in general; its standard exact solution still has exponential complexity.

**Note:** The provided transcript introduces the DP idea but does not clearly present the complete TSP recurrence or DP table.

## 6. Complexity Comparison
| Approach | Main idea | Time complexity |
|---|---|---|
| Greedy heuristic | Choose a locally cheap next city | Depends on implementation; does not guarantee optimality |
| Brute force | Enumerate all tours | \(O(n!)\) |
| Dynamic programming | Store and reuse subproblem results | \(O(n^2 2^n)\) for the standard subset-DP algorithm |


# Sum of Subsets Problem 
The **Sum of Subsets Problem** asks whether a subset of a given set of numbers has a sum equal to a specified target \(M\).

**Input:**
- A set of \(n\) elements.
- A target sum \(M\).

**Output:** `TRUE` if a subset with sum \(M\) exists; otherwise, `FALSE`.

## 2. Brute-Force Approach
For each element, there are two choices:

1. Include the element in the subset.
2. Exclude the element from the subset.

For \(n\) elements, the total number of possible subsets is:
> 2^n

- We check the sum of each subset and determine whether any sum equals \(M\).

**Complexity:**

- Time: \(O(2^n)\) recursive calls; straightforward subset enumeration with summation can take 
> O(n2^n).
- Space: \(O(n)\) for a recursive implementation, excluding the storage of all subsets.

**Limitation:** The number of subsets grows exponentially as \(n\) increases.

## 3. Recursive Equation
Let:

- \(SOS(n,M)\) = whether a subset of the first \(n\) elements can produce sum \(M\).
- \(n\) = number of available elements.
- \(M\) = target sum.
- \(w_n\) = value of the \(n\)-th element.

For each element, consider two possibilities.

### Case 1: Exclude the \(n\)-th element
- The target remains unchanged, and only \(n-1\) elements remain.
> SOS(n-1,M)

### Case 2: Include the \(n\)-th element
- Subtract its value from the target, and consider the remaining \(n-1\) elements.
> SOS(n-1,M-w_n)

### Complete recurrence
```yml
SOS(n,M)=      { SOS(n-1,M)  }
               { or   }
               { SOS(n-1,M-w_n)}
--- base cases
                SOS(n-1,M), if  w_n>M 
                true if n=0 , m=0 
                false n=0 , m!=0
                true n!-0 , m=0
```

## 8. Time and Space Complexity
- The DP table contains \((n+1)(M+1)\) states.

| Approach | Time Complexity | Auxiliary Space |
|---|---|---|
| Brute force | \(O(2^n)\) recursive calls | \(O(n)\) recursion stack |
| DP with memoization | \(O(nM)\) | \(O(nM)\) |
| DP with tabulation | \(O(nM)\) | \(O(nM)\) |

The DP complexity is **pseudo-polynomial**, not polynomial in the total input length, because \(M\) is a numeric target and may require only \(O(\log M)\) bits to represent.

DP is particularly useful when \(M\) is reasonably small.


# Multistage Graph 
- A **Multistage Graph** is a directed, weighted graph whose vertices are divided into multiple stages.
- The objective is to find the **minimum-cost path from a source vertex to a destination vertex**.

### Important properties
- The graph is directed and weighted.
- Vertices are divided into ordered stages.
- The source is in the first stage.
- The destination is in the last stage.
- Edges generally connect vertices in successive stages.
- Vertices within the same stage are not connected to each other in the standard multistage graph model.
- Dynamic programming can solve the minimum-cost path problem efficiently.

## 4. Dynamic Programming Approach
```yml
fn(si,vj)=  min {  fn (S ( i+1 , k ) + C(vj + k))
                     c(vj,d) if si = sf-1 }
```

## 9. Time and Space Complexity
Let:
    - \(V\) = number of vertices.
    - \(E\) = number of edges.
- With dynamic programming, each vertex's minimum remaining cost is calculated once, and each edge is examined at most once.

| Method | Time complexity |
|---|---|
| Brute force, exploring all paths | Can be exponential |
| Dynamic programming on a multistage DAG | \(O(V+E)\) |

**Space complexity:** \(O(V)\) for the cost table and next-vertex information, excluding graph storage.

The \(O(V+E)\) bound assumes the graph is represented using adjacency lists and the DP processes each vertex and edge once.
