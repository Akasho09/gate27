# Dynamic Programming 
- Dynamic Programming (DP) is an algorithmic technique used to solve problems by breaking them into smaller subproblems.
- It is commonly used for **optimization problems**, where we need to find:
  - Maximum value (e.g., maximum profit).
  - Minimum value (e.g., minimum cost).
- DP stores the results of solved subproblems to avoid solving the same subproblems repeatedly.

## 2. Greedy vs Dynamic Programming

| Feature | Greedy Method | Dynamic Programming |
|---|---|---|
| Decision-making | Chooses the locally best option at each step | Considers alternative subproblem solutions |
| Main idea | Make the best immediate choice | Solve and combine subproblems |
| Revisiting decisions | Generally does not reconsider earlier choices | Compares alternatives through stored subproblem results |
| Optimal answer | Not guaranteed for every problem | Finds an optimal answer when the problem has the required DP properties and recurrence is correct |
| Subproblems | Depends on the problem | Often has overlapping subproblems |
| Storage | Usually does not require a DP table | Stores intermediate results |
| Example | Dijkstra's algorithm for non-negative edge weights | 0/1 Knapsack, LCS, Matrix Chain Multiplication |

## 3. Properties of Dynamic Programming

### A. Optimal Substructure
A problem has optimal substructure when an optimal solution can be constructed from optimal solutions to its subproblems.

**Example:** A larger problem is divided into smaller problems, their solutions are found, and those solutions are combined to obtain the final answer.

### B. Overlapping Subproblems
A problem has overlapping subproblems when the same smaller problems occur repeatedly during recursive computation.

- Without storing results, the same subproblem may be solved multiple times.
- DP stores previously computed results.
- When the same subproblem appears again, its stored answer is reused.

**Key difference:**

- Divide and conquer commonly solves separate, non-overlapping subproblems.
> Dynamic programming is especially useful when subproblems overlap.

## 4. Fibonacci Series — DP Example
The Fibonacci sequence is:

`0, 1, 1, 2, 3, 5, 8, 13, 21, ...`

### Recurrence relation
- F(n)=F(n-1)+F(n-2)

### Recursive approach without memoization

```yml
Fibonacci(n):
    if n == 0:
        return 0

    if n == 1:
        return 1

    return Fibonacci(n-1) + Fibonacci(n-2)
```

- The same subproblems are computed repeatedly.
- The time complexity is exponential: \(O(2^n)\) as a standard upper bound.

### Dynamic programming with memoization

```yml
Fibonacci(n):
    if n == 0:
        return 0

    if n == 1:
        return 1

    if memo[n] is already computed:
        return memo[n]

    memo[n] = Fibonacci(n-1) + Fibonacci(n-2)
    return memo[n]
```

- Each Fibonacci value is computed once and stored.
- Time complexity: \(O(n)\).
- Auxiliary space: \(O(n)\), including the memo table and recursion stack.

## 6. Memoization vs Tabulation

| Feature | Memoization | Tabulation |
|---|---|---|
| Approach | Top-down | Bottom-up |
| Technique | Recursion with caching | Iterative computation |
| Calculation order | Computes needed subproblems on demand | Computes subproblems in a planned order |
| Storage | Cache / memo table | DP table |
| Recursion | Usually used | Usually avoided |
| Fibonacci complexity | \(O(n)\) time | \(O(n)\) time |

### Fibonacci using tabulation

```yml
Fibonacci(n):
    if n <= 1:
        return n

    dp[0] = 0
    dp[1] = 1

    for i = 2 to n:
        dp[i] = dp[i-1] + dp[i-2]

    return dp[n]
```

## 7. Applications of Dynamic Programming

The video mentions the following applications:

- Matrix Chain Multiplication
- Multistage Graph
- Travelling Salesman Problem
- Longest Common Subsequence (LCS)
- Sum of Subsets
- All-Pairs Shortest Paths
- 0/1 Knapsack Problem

## 8. Dynamic Programming vs Divide and Conquer

| Feature | Divide and Conquer | Dynamic Programming |
|---|---|---|
| Subproblem structure | Commonly non-overlapping | Commonly overlapping |
| Repeated computation | Often limited | Avoided by storing results |
| Main process | Divide, solve, combine | Solve, store, reuse, combine |
| Example | Merge Sort | Fibonacci with memoization |

# Bellman–Ford Algorithm 
- **Technique:** Dynamic programming / repeated edge relaxation
- **Problem:** Single-Source Shortest Path (SSSP)
- **Works with:** Positive, zero, and negative edge weights
- **Special feature:** Detects negative-weight cycles reachable from the source.

## 2. Initialization
For a graph with \(V\) vertices and \(E\) edges:
1. Set the source vertex distance to `0`.
2. Set every other vertex distance to `∞`.
3. > Relax every edge repeatedly for \(V-1\) iterations.

## 3. Edge Relaxation
For every edge \(u \rightarrow v\) with weight \(w\):
```yml
if dist[u] != infinity:
    if dist[u] + w < dist[v]:
        dist[v] = dist[u] + w
```

## 4. Bellman–Ford Pseudocode

```yml
BellmanFord(G, source):

    for each vertex v:
        dist[v] = infinity

    dist[source] = 0

    repeat V - 1 times:
        for each edge (u, v) with weight w:
            if dist[u] != infinity:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

    for each edge (u, v) with weight w:
        if dist[u] != infinity and dist[u] + w < dist[v]:
            return "Negative-weight cycle detected"

    return dist
```

## 5. Why Do We Relax Edges \(V-1\) Times?
- A shortest simple path can contain at most \(V-1\) edges.
- Each iteration allows shortest-path information to propagate across additional edges.
- Therefore, after \(V-1\) iterations, shortest distances are guaranteed to be found if no reachable negative-weight cycle exists.

| Number of vertices | Maximum edges in a simple path | Required relaxation rounds |
|---:|---:|---:|
| 3 | 2 | 2 |
| 4 | 3 | 3 |
| 5 | 4 | 4 |
| \(V\) | \(V-1\) | \(V-1\) |

## 6. Negative-Weight Cycle Detection
After the \(V-1\) iterations, perform **one additional pass** over all edges.

- If any distance can still be reduced, a negative-weight cycle is reachable from the source.
- If no distance can be reduced, no reachable negative-weight cycle has been detected.
- An unreachable negative cycle will not be detected by this source-specific check unless the algorithm is adapted.

### Why does this work?
Without a reachable negative-weight cycle, shortest distances stabilize after at most \(V-1\) edge-relaxation rounds.

If a reachable negative cycle exists, repeatedly traversing it reduces the path cost, allowing a distance to decrease even after \(V-1\) rounds.

## 7. Time and Space Complexity

| Operation | Complexity |
|---|---:|
| Initialize distances | \(O(V)\) |
| Relax all edges \(V-1\) times | \(O(VE)\) |
| Check for a negative cycle | \(O(E)\) |
| **Overall time complexity** | **\(O(VE)\)** |
| Auxiliary space for distances | \(O(V)\) |

> O(VE)

## 8. Bellman–Ford vs Dijkstra

| Feature | Bellman–Ford | Dijkstra |
|---|---|---|
| Algorithmic approach | Repeated edge relaxation | Greedy |
| Negative edge weights | Supported | Not generally supported |
| Negative-cycle detection | Yes, reachable from source | No |
| Time complexity | \(O(VE)\) | \(O((V+E)\log V)\) with a binary heap |
| Main use | SSSP with possible negative edges | SSSP with non-negative edges |


# 0/1 Knapsack Problem
The **0/1 Knapsack Problem** is an optimization problem in which we select items to maximize total profit without exceeding the capacity of a knapsack.

- `0` means the item is not selected.
- `1` means the item is selected completely.
- Items cannot be divided into fractions.
- Each item has a weight and a profit.
- Total selected weight must be less than or equal to the knapsack capacity.

## 4. Brute-Force Approach
For every item, there are two choices:

1. Include the item.
2. Exclude the item.

- Therefore, for \(n\) items, the number of possible subsets is:
> 2^n

### Complexity of brute force

- Number of subsets: \(2^n\).
- Evaluating each subset takes up to \(O(n)\) time using a straightforward approach.
- Time complexity: \(O(n2^n)\).
- Recursive include/exclude implementations are commonly described as \(O(2^n)\) when counting recursive calls, excluding additional per-call work.

### Final recurrence relation
```yml
- K(n,W)= max { K(n-1,W)  , 
                p_n + K(n-1,W-w_n) }
```

## 6. Recursive Pseudocode

```yml
Knapsack(n, W):
    if n == 0 OR W == 0:
        return 0

    if weight[n] > W:
        return Knapsack(n-1, W)

    include = profit[n] + Knapsack(n-1, W-weight[n])
    exclude = Knapsack(n-1, W)

    return max(include, exclude)
```

### How it works

- If the item is too heavy, exclude it.
- Otherwise, calculate the profit from including it.
- Calculate the profit from excluding it.
- Return whichever result is larger.

## 7. Recursion Tree
- Each recursive call can branch into two possibilities:
    - Include the current item.
    - Exclude the current item.
- For example:

```yml
                  K(n, W)
                 /       \
            Include     Exclude
               /           \
       K(n-1, W-w[n])    K(n-1, W)
```

- Each branch reduces the number of remaining items by one.

The recursion continues until either:
> n=0  or  W=0.

### Number of recursive calls
- The recursion tree can have up to \(2^n\) leaves and \(O(2^n)\) total nodes.

> O(2^n) 

- The recursion stack uses 
> \(O(n)\) auxiliary space
because the depth is at most \(n\).

## 9. Dynamic Programming — Tabulation
- Create a table: dp[i][c]

where `dp[i][c]` is the maximum profit achievable using the first \(i\) items with capacity \(c\).

### Initialization
- dp[0][c]=0 , dp[i][0]=0

### Transition
- If item \(i\) is too heavy:
    - dp[i][c]=dp[i-1][c]
- Otherwise:
    - dp[i][c]= max ( dp[i-1][c] , p_i+dp[i-1][c-w_i] ) .

### Pseudocode

```yml
KnapsackDP(n, W):
    create dp[0...n][0...W], initialized to 0

    for i = 1 to n:
        for c = 0 to W:
            if weight[i] > c:
                dp[i][c] = dp[i-1][c]
            else:
                include = profit[i] + dp[i-1][c-weight[i]]
                exclude = dp[i-1][c]
                dp[i][c] = max(include, exclude)

    return dp[n][W]
```

## 11. Time and Space Complexity
- Let \(n\) be the number of items and \(W\) the knapsack capacity.

| Approach | Time complexity | Auxiliary space |
|---|---:|---:|
| Brute-force recursion | \(O(2^n)\) recursive calls | \(O(n)\) stack |
| DP with memoization | \(O(nW)\) | \(O(nW)\) plus recursion stack |
| DP with tabulation | \(O(nW)\) | \(O(nW)\) |
| Space-optimized DP | \(O(nW)\) | \(O(W)\) |

### Why is DP \(O(nW)\)?
- The DP table has: (n+1)(W+1) entries.
- Each entry takes constant time to calculate, so .

**Important:** \(O(nW)\) is pseudo-polynomial time, not polynomial in the input's bit length, because \(W\) is a numerical capacity.

## 12. Space-Optimized DP
- The two-dimensional table can be reduced to one dimension by processing capacities in descending order.

```yml
KnapsackDP1D(n, W):
    dp[0...W] = 0

    for i = 1 to n:
        for c = W down to weight[i]:
            dp[c] = max(
                dp[c],
                profit[i] + dp[c-weight[i]]
            )

    return dp[W]
```

> Time: \(O(nW)\)
> Auxiliary space: \(O(W)\)

- **Why descending order?** It prevents the current item from being reused multiple times in the same iteration.

If capacities were processed in ascending order, the update could reuse the same item repeatedly, producing behavior closer to the unbounded knapsack problem.