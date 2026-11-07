# All-Pairs Shortest Path (APSP) — Floyd–Warshall Algorithm
The **All-Pairs Shortest Path (APSP)** problem finds the shortest-path distance between every pair of vertices in a graph.

For a graph with \(V\) vertices, we need the shortest distance from every vertex \(i\) to every vertex \(j\).

### Difference: SSSP vs APSP

| Feature | Single-Source Shortest Path (SSSP) | All-Pairs Shortest Path (APSP) |
|---|---|---|
| Starting vertex | One fixed source | Every vertex |
| Destination | All other vertices | Every other vertex, for every source |
| Output | One distance array | A \(V\times V\) distance matrix |
| Algorithms | Dijkstra, Bellman–Ford | Floyd–Warshall, or repeated SSSP algorithms |

## 2. Why Not Run SSSP Algorithms Repeatedly?

The lecture considers running Dijkstra or Bellman–Ford from every vertex.

### A. Dijkstra from every vertex
Using a binary heap, one SSSP run takes approximately:
> O((V+E) . log V)
- Running it from all \(V\) vertices gives:
> O(V(V+E)\log V)
- For a dense graph where \(E=O(V^2)\):
> {O(V^3\log V)}

**Limitation:** Dijkstra does not correctly handle graphs with negative-weight edges in general.

### B. Bellman–Ford from every vertex
- One Bellman–Ford run takes: O(VE)
- Running it from every vertex gives: O(V^2E)
- For a dense graph where \(E=O(V^2)\):
> {O(V^4)}

### Comparison

| Method | APSP time complexity in a dense graph |
|---|---:|
| Repeated Dijkstra with a binary heap | \(O(V^3\log V)\) |
| Repeated Bellman–Ford | \(O(V^4)\) |
| Floyd–Warshall | \(O(V^3)\) |

## 3. Floyd–Warshall Algorithm
**Floyd–Warshall** is a dynamic programming algorithm for finding the shortest-path distances between all pairs of vertices.

- The algorithm is especially useful when we need a complete distance matrix rather than shortest paths from just one source.

# Floyd–Warshall Algorithm 

- **Floyd–Warshall** is a Dynamic Programming (DP) algorithm.
- It solves the **All-Pairs Shortest Path (APSP)** problem.
- It finds the shortest distance between **every pair of vertices** in a weighted graph.
- Works with directed and undirected weighted graphs.
- Supports positive and negative edge weights, provided there is no negative-weight cycle.
- Uses a distance matrix to update shortest paths.

### SSSP vs APSP

| Feature | SSSP | APSP |
|---|---|---|
| Full form | Single-Source Shortest Path | All-Pairs Shortest Path |
| Purpose | One source to all vertices | Every vertex to every other vertex |
| Example algorithm | Dijkstra, Bellman–Ford | Floyd–Warshall |
| Floyd–Warshall applicable? | Can provide these distances too | Yes |

## 2. Distance Matrices

For a graph with \(n\) vertices, Floyd–Warshall uses an \(n \times n\) matrix.

### Initial matrix: \(D^{(0)}\)

Construct the initial matrix using only direct edges.

- \(D[i][i] = 0\): distance from a vertex to itself.
- \(D[i][j] = w(i,j)\): if a direct edge exists from \(i\) to \(j\).
- \(D[i][j] = \infty\): if no direct edge exists.
- **Direction matters:** an edge \(i \to j\) does not imply an edge \(j \to i\).

## 3. Meaning of \(D^{(k)}\)

\(D^{(k)}[i][j]\) represents the shortest distance from vertex \(i\) to vertex \(j\), allowing intermediate vertices only from the set \(\{1,2,\ldots,k\}\).

| Matrix | Meaning |
|---|---|
| \(D^{(0)}\) | Direct edges only; no intermediate vertices |
| \(D^{(1)}\) | Paths may use vertex 1 |
| \(D^{(2)}\) | Paths may use vertices 1 and 2 |
| \(D^{(3)}\) | Paths may use vertices 1, 2 and 3 |
| \(D^{(n)}\) | Final all-pairs shortest distances |

**Important:** When constructing \(D^{(k)}\), previously allowed intermediate vertices remain available. You are not restricted to using only vertex \(k\).

## 4. Floyd–Warshall Recurrence Formula

For every pair of vertices \(i,j\), compare:

1. The existing shortest distance from \(i\) to \(j\).
2. The distance obtained by travelling from \(i\) to \(k\), then from \(k\) to \(j\).

\[
D^{(k)}[i][j] =
\min\left(
D^{(k-1)}[i][j],
D^{(k-1)}[i][k]+D^{(k-1)}[k][j]
\right)
\]

In simple words:

**New distance = minimum of (old distance, distance via vertex \(k\)).**

If the path through \(k\) is shorter, update the matrix. Otherwise, keep the previous value.

## 5. Example from the Lecture

The transcript describes a directed, weighted graph with four vertices.

### Initial matrix \(D^{(0)}\)
> The direct-edge weights are:

- \(1 \to 2 = 8\)
- \(1 \to 4 = 1\)
- \(2 \to 3 = 1\)
- \(3 \to 1 = 4\)
- \(4 \to 2 = 2\)
- \(4 \to 3 = 9\)

All other off-diagonal entries are \(\infty\).

| From \ To | 1 | 2 | 3 | 4 |
|---|---:|---:|---:|---:|
| 1 | 0 | 8 | ∞ | 1 |
| 2 | ∞ | 0 | 1 | ∞ |
| 3 | 4 | ∞ | 0 | ∞ |
| 4 | ∞ | 2 | 9 | 0 |

### Matrix \(D^{(1)}\): Allow vertex 1
Compare the existing distances with paths through vertex 1.

**Example 1: Distance from 3 to 2**

- Existing distance: \(\infty\)
- Via vertex 1: \(3 \to 1 \to 2 = 4+8=12\)
- New distance: \(\min(\infty,12)=12\)

**Example 2: Distance from 3 to 4**

- Existing distance: \(\infty\)
- Via vertex 1: \(3 \to 1 \to 4=4+1=5\)
- New distance: \(\min(\infty,5)=5\)

Therefore:

| From \ To | 1 | 2 | 3 | 4 |
|---|---:|---:|---:|---:|
| 1 | 0 | 8 | ∞ | 1 |
| 2 | ∞ | 0 | 1 | ∞ |
| 3 | 4 | 12 | 0 | 5 |
| 4 | ∞ | 2 | 9 | 0 |

### Matrix \(D^{(2)}\): Allow vertices 1 and 2

Now compare distances through vertex 2.

**Example 1: Distance from 1 to 3**

- Existing distance: \(\infty\)
- Via vertex 2: \(1 \to 2 \to 3=8+1=9\)
- New distance: \(9\)

**Example 2: Distance from 4 to 3**

- Existing distance: \(9\)
- Via vertex 2: \(4 \to 2 \to 3=2+1=3\)
- New distance: \(\min(9,3)=3\)

| From \ To | 1 | 2 | 3 | 4 |
|---|---:|---:|---:|---:|
| 1 | 0 | 8 | 9 | 1 |
| 2 | ∞ | 0 | 1 | ∞ |
| 3 | 4 | 12 | 0 | 5 |
| 4 | ∞ | 2 | 3 | 0 |

### Matrix \(D^{(3)}\): Allow vertices 1, 2 and 3

Now compare distances through vertex 3.

**Example 1: Distance from 2 to 1**

- Existing distance: \(\infty\)
- Via vertex 3: \(2 \to 3 \to 1=1+4=5\)
- New distance: \(5\)

**Example 2: Distance from 2 to 4**

- Existing distance: \(\infty\)
- Via vertex 3: \(2 \to 3 \to 4=1+5=6\)
- New distance: \(6\)

**Example 3: Distance from 4 to 1**

- Existing distance: \(\infty\)
- Via vertex 3: \(4 \to 3 \to 1=3+4=7\)
- New distance: \(7\)

| From \ To | 1 | 2 | 3 | 4 |
|---|---:|---:|---:|---:|
| 1 | 0 | 8 | 9 | 1 |
| 2 | 5 | 0 | 1 | 6 |
| 3 | 4 | 12 | 0 | 5 |
| 4 | 7 | 2 | 3 | 0 |

### Matrix \(D^{(4)}\): Allow all four vertices

Finally, compare distances through vertex 4.

**Example 1: Distance from 1 to 2**

- Existing distance: \(8\)
- Via vertex 4: \(1 \to 4 \to 2=1+2=3\)
- New distance: \(3\)

**Example 2: Distance from 1 to 3**

- Existing distance: \(9\)
- Via vertex 4: \(1 \to 4 \to 3=1+3=4\)
- New distance: \(4\)

**Example 3: Distance from 3 to 2**

- Existing distance: \(12\)
- Via vertex 4: \(3 \to 4 \to 2=5+2=7\)
- New distance: \(7\)

### Final shortest-distance matrix

| From \ To | 1 | 2 | 3 | 4 |
|---|---:|---:|---:|---:|
| 1 | 0 | 3 | 4 | 1 |
| 2 | 5 | 0 | 1 | 6 |
| 3 | 4 | 7 | 0 | 5 |
| 4 | 7 | 2 | 3 | 0 |

This final matrix gives the shortest distance between every ordered pair of vertices.

## 6. Most Important Concept: Previously Allowed Vertices

When calculating \(D^{(k)}\), you can use paths that already contain vertices \(1,\ldots,k-1\).

For example, while considering vertex 3, the subpath from 3 to 4 may itself use vertex 1. Therefore, you must use the distances already computed in \(D^{(2)}\), not just direct edges.

- Always calculate the new matrix from the previous matrix.

## 7. Algorithm Pseudocode
```yml
FloydWarshall(D, n):
    for k = 1 to n:
        for i = 1 to n:
            for j = 1 to n:
                D[i][j] = min(
                    D[i][j],
                    D[i][k] + D[k][j]
                )
    return D
```

Implementation note: treat \(\infty\) carefully so that unreachable paths are not accidentally added as ordinary numbers.

## 8. Time and Space Complexity

| Complexity | Value |
|---|---|
| Time | \(O(V^3)\) |
| Space | \(O(V^2)\) |
| Vertices | \(V\) |
| Matrix size | \(V \times V\) |

There are three nested loops, each running up to \(V\), giving \(O(V^3)\) time. The distance matrix requires \(O(V^2)\) space.


# Floyd–Warshall Algorithm — Time and Space Complexity

## 1. Floyd–Warshall Recurrence

Floyd–Warshall calculates the shortest distance between every pair of vertices.

\[
D^{(k)}[i][j]=\min\left(
D^{(k-1)}[i][j],
D^{(k-1)}[i][k]+D^{(k-1)}[k][j]
\right)
\]

Where:
- \(i\) = source vertex
- \(j\) = destination vertex
- \(k\) = intermediate vertex
- \(D^{(k-1)}[i][j]\) = existing shortest distance
- \(D^{(k-1)}[i][k]+D^{(k-1)}[k][j]\) = distance via vertex \(k\)

Choose the minimum of the two distances.

## 2. Time Complexity — Derivation

Let \(n\) be the number of vertices.

### Step 1: Size of one matrix

The distance matrix has \(n\) rows and \(n\) columns.

\[
n\times n=n^2
\]

Therefore, each matrix contains \(n^2\) elements.

### Step 2: Work required for one matrix

For every element \(D[i][j]\), we calculate the minimum using the recurrence.

- Number of elements = \(n^2\)
- Work per element = \(O(1)\)

Therefore:

\[
T_{\text{one matrix}}=O(n^2)
\]

### Step 3: Number of matrices

We start with \(D^{(0)}\), the initial matrix. Then we perform updates for each of the \(n\) intermediate vertices.

There are \(n\) update rounds.

### Step 4: Total time complexity

\[
T(n)=n\times O(n^2)
\]

\[
\boxed{T(n)=O(n^3)}
\]

**Final time complexity: \(O(n^3)\)**

### Quick trick for GATE

Floyd–Warshall has three nested loops, each running \(n\) times.

\[
n\times n\times n=\boxed{O(n^3)}
\]

## 3. Space Complexity — Derivation

### Step 1: Size of the distance matrix

The matrix contains \(n^2\) entries.

\[
\boxed{O(n^2)}
\]

### Step 2: Do we need to store every matrix?

No. We can reuse matrix storage instead of storing every intermediate matrix \(D^{(0)},D^{(1)},\ldots,D^{(n)}\).

At each iteration, the current distance matrix can be updated in place. The standard Floyd–Warshall implementation needs one \(n\times n\) distance matrix.

\[
S(n)=O(n^2)
\]

**Final auxiliary space complexity: \(O(n^2)\)**

The result matrix itself also occupies \(O(n^2)\) space.

## 4. Complexity Summary Table
---
| Property | Complexity |
|---|---|
| Initial distance matrix | \(O(n^2)\) |
| Number of update rounds | \(n\) |
| Work per update round | \(O(n^2)\) |
| Total time complexity | **\(O(n^3)\)** |
| Space for distance matrix | **\(O(n^2)\)** |
| Number of matrices needed in an in-place implementation | 1 |

