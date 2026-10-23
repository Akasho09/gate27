# Greedy Algorithm?

## 1. What is a Greedy Algorithm?
- **Definition:** A Greedy Algorithm is an algorithmic technique that makes the **locally optimal choice at each step**, with the aim of obtaining a **globally optimal solution**.

- Makes the best choice at the current stage.
- Builds the solution step by step.
- Generally does not reconsider previous choices.
- Does not guarantee a globally optimal solution for every problem.

**Example:** If the available costs are 10, 20 and 5, a greedy algorithm chooses the minimum cost, i.e., 5.

## 2. Important Terminologies

| Term | Meaning |
|---|---|
| Solution Space | Set of all possible solutions to a problem |
| Feasible Solution | A solution that satisfies all problem constraints |
| Optimal Solution | The best feasible solution according to the objective |
| Local Optimum | Best choice at the current stage |
| Global Optimum | Best solution among all feasible solutions |
| Objective Function | Function to minimize or maximize |
| Greedy Choice | The locally best choice selected at a step |

## 3. How Does a Greedy Algorithm Work?

1. Start with an empty solution.
2. Identify the available choices.
3. Select the locally best choice using a greedy criterion.
4. Check whether the choice satisfies the constraints.
5. Include the choice if it is feasible.
6. Repeat until the solution is complete.

**Flow:**

`Start → Identify Choices → Select Locally Best Choice → Check Feasibility → Accept Choice → Repeat → Complete Solution`

## 4. Types of Greedy Objectives

| Objective | Greedy Goal | Example |
|---|---|---|
| Cost | Minimize cost | Minimum Spanning Tree |
| Profit | Maximize profit | Job Sequencing |
| Risk | Minimize risk | Risk-based selection problems |
| Length | Minimize total length | Optimal Merge Pattern |
| Distance | Minimize distance | Dijkstra's Algorithm (non-negative edges) |
| Code Length | Minimize weighted code length | Huffman Coding |

**Important:** Greedy does not always find the global optimum. The result depends on whether the problem has the required properties.

## 5. Local Optimum vs Global Optimum

| Local Optimum | Global Optimum |
|---|---|
| Best choice at the current step | Best complete solution |
| Considers the immediate decision | Considers the overall result |
| Selected using a greedy rule | May require considering future consequences |
| May lead to a suboptimal result | Is the best feasible result |


## 6. Properties Required for Greedy Algorithms

| Property | Meaning |
|---|---|
| Greedy-Choice Property | An optimal solution can be obtained by making an appropriate locally optimal choice |
| Optimal Substructure | An optimal solution contains optimal solutions to its relevant subproblems |

These properties help establish when a greedy strategy is correct.

## 7. Important Greedy Algorithms for GATE

| Algorithm | Main Greedy Choice | Objective |
|---|---|---|
| Fractional Knapsack | Select the highest profit-to-weight ratio | Maximize profit |
| Job Sequencing with Deadlines | Select profitable jobs that fit deadlines | Maximize profit |
| Prim's Algorithm | Select the minimum-weight edge connecting the tree to a new vertex | Minimum Spanning Tree |
| Kruskal's Algorithm | Select the minimum-weight edge that does not form a cycle | Minimum Spanning Tree |
| Dijkstra's Algorithm | Select the unprocessed vertex with the smallest tentative distance | Single-source shortest paths |
| Huffman Coding | Merge the two minimum-frequency nodes | Optimal prefix code |
| Optimal Merge Pattern | Merge the two smallest files repeatedly | Minimize total merge cost |
| Activity Selection | Select the compatible activity with the earliest finishing time | Maximize number of activities |

## 8. Greedy vs Dynamic Programming

| Greedy Algorithm | Dynamic Programming |
|---|---|
| Makes a locally optimal choice | Solves and combines subproblems |
| Usually does not reconsider choices | Stores and reuses subproblem results |
| Often simpler and uses less memory | May require more memory |
| Can fail to find the global optimum | Can find the global optimum when correctly formulated |
| Example: Fractional Knapsack | Example: 0/1 Knapsack |

# Knapsack Problem?
- The **Knapsack Problem** is an optimization problem in which we have a bag of limited capacity and a set of objects, each having a weight and a profit.
- **Objective:** Maximize the total profit without exceeding the capacity of the bag.

### Given
- `n` objects
- Each object has a profit `P[i]`
- Each object has a weight `W[i]`
- Knapsack capacity = `M`


## 3. Three Greedy Approaches

### Approach 1: Greedy by Maximum Profit
**Rule:** Select the object with the highest profit first.

### Approach 2: Greedy by Minimum Weight
**Rule:** Select the lightest object first.

### Approach 3: Greedy by Profit-to-Weight Ratio
**This is the correct greedy strategy for Fractional Knapsack.**
**Rule:** Select the object with the highest profit per unit of weight.

## 4. Fractional Knapsack Algorithm
### Steps
1. Calculate the profit-to-weight ratio for every object.
2. Sort all objects in descending order of their ratios.
3. Initialize the remaining capacity to `M`.
4. Select each object in sorted order:
   - If the entire object fits, take it completely.
   - Otherwise, take the fraction that fits and stop.
5. Return the total profit.

## 5. Time Complexity

| Operation | Time Complexity |
|---|---|
| Calculate profit/weight ratios | O(n) |
| Sort objects by ratio | O(n log n) |
| Select objects | O(n) |
| Total time complexity | **O(n log n)** |

## 6. Fractional Knapsack vs 0/1 Knapsack

| Fractional Knapsack | 0/1 Knapsack |
|---|---|
| Objects can be divided into fractions | Objects cannot be divided |
| An object can be partially selected | An object is either selected or rejected |
| Greedy by profit/weight ratio is optimal | Greedy by ratio is not always optimal |
| Commonly solved using a greedy algorithm | Commonly solved using dynamic programming |
| Time complexity with sorting: O(n log n) | Standard DP time complexity: O(nM) |

**Important GATE point:** The greedy profit-to-weight ratio strategy guarantees an optimal solution for Fractional Knapsack, but not for the general 0/1 Knapsack problem.

# Huffman Coding 
- **Definition:** Huffman Coding is a `greedy algorithm` used for **lossless data compression** by assigning variable-length binary codes to characters based on their frequencies.

- Frequently occurring characters get shorter codes.
- Rarely occurring characters get longer codes.
- Reduces the total number of bits required to represent data.
- Uses a binary tree called a **Huffman Tree**.
- Produces an optimal prefix-free code for the given character frequencies.

## 2. Why Do We Use Huffman Coding?
Huffman Coding helps to:
- Reduce data storage requirements.
- Reduce message size.
- Improve transmission efficiency.
- Compress data without losing information.

### Comparison of Encoding Methods
For a message containing 100 characters with frequencies:

| Character | Frequency |
|---|---:|
| A | 50 |
| B | 10 |
| C | 30 |
| D | 5 |
| E | 3 |
| F | 2 |
| **Total** | **100** |

- 
| Encoding Method | Bits per Character | Total Bits |
|---|---:|---:|
| 7-bit encoding | 7 | 700 |
| Fixed-length encoding for 6 symbols | 3 | 300 |
| Huffman Coding | Variable | 185 |

**Note:** The Huffman total of 185 bits corresponds to the particular tree constructed in the example below.

## 3. Important Terminologies

| Term | Meaning |
|---|---|
| Encoding | Converting symbols into binary codes |
| Frequency | Number of occurrences of a character |
| Huffman Tree | Binary tree used to generate Huffman codes |
| Prefix-Free Code | No character's code is a prefix of another character's code |
| Lossless Compression | Compression that allows exact reconstruction of the original data |
| Variable-Length Coding | Different characters can have different code lengths |
| Greedy Technique | Repeatedly choosing the two minimum-frequency nodes |

## 4. Huffman Coding Algorithm
### Steps
1. Calculate the frequency of every character.
2. Create a leaf node for each character.
3. Select the two nodes with the minimum frequencies.
4. Combine them into a new internal node whose frequency is their sum.
5. Insert the new node back into the set of available nodes.
6. Repeat until only one node remains.
7. The remaining node becomes the root of the Huffman Tree.
8. Assign `0` to left edges and `1` to right edges.
9. The binary code for each character is the path from the root to its leaf.

**Important:** If frequencies are equal, either node may be placed on the left or right. 
The resulting codes may differ, but their optimal total cost remains the same.

## 6. Huffman Tree and Codes
- Using the tie-breaking and left/right placement 
    - Left edge = `0`
    - Right edge = `1`
- The resulting codes are:
| Character | Frequency | Huffman Code | Code Length |
|---|---:|---|---:|
| A | 50 | `0` | 1 |
| B | 10 | `100` | 3 |
| C | 30 | `11` | 2 |
| D | 5 | `1010` | 4 |
| E | 3 | `10111` | 5 |
| F | 2 | `10110` | 5 |

**Note:** Huffman codes can differ depending on how equal-frequency nodes are merged and placed. Follow the tree given in the question.

> while building huffman tree , take 2 min elements and keep rmeoving these 2 els and add the sum to array and then see the new 2 min elements.

## 9. Important Properties of Huffman Coding
- It is a greedy algorithm.
- It is used for lossless compression.
- It creates a binary tree.
- The two minimum-frequency nodes are merged at every step.
- The frequency of each internal node equals the sum of its children's frequencies.
- Characters are stored at leaf nodes.
- Higher-frequency characters generally receive shorter codes.
- Lower-frequency characters generally receive longer codes.
- Huffman codes are prefix-free.
- The code for a character is obtained by tracing its path from the root to the leaf.
- The optimality is measured by minimizing the weighted sum of code lengths.

## why not 0 , 1 , 01 , 10 , 11 , 001 , ......so on
1. Fixed-length encoding: Every character gets the same number of bits.

2. Prefix-free encoding: No codeword is the prefix of another codeword, so decoding is `unambiguous`.

3. Huffman encoding: Produces an optimal prefix-free code for known symbol frequencies, minimizing the weighted average code length.

## 10. Prefix-Free Property
A code is **prefix-free** if no codeword is the prefix of another codeword.
- Example:
| Character | Code |
|---|---|
| A | `0` |
| B | `10` |
| C | `110` |
| D | `111` |
- This is prefix-free because no complete code is the starting portion of another complete code.
- **Why is it important?**
    - Allows unambiguous decoding.
    - The receiver can identify character boundaries without separators between codes.

## 11. Time Complexity
Using a min-heap (priority queue):
| Operation | Time Complexity |
|---|---|
| Build min-heap | O(n) |
| Repeatedly extract two minimum nodes and insert their parent | O(n log n) |
| Overall time complexity | **O(n log n)** |
- Here, `n` is the number of distinct characters or symbols.
    - **Space complexity:** O(n) for the Huffman tree and associated data structures.

## 12. Huffman Coding vs Fixed-Length Coding
| Huffman Coding | Fixed-Length Coding |
|---|---|
| Uses variable-length codes | Uses equal-length codes |
| Depends on character frequencies | Depends on the number of symbols |
| Frequently occurring symbols get shorter codes | Every symbol uses the same number of bits |
| Can reduce the total number of bits | May use more bits for skewed frequencies |
| Requires a code tree or equivalent code table | Uses a fixed symbol-to-code mapping |

# Job Sequencing with Deadlines 
Job Sequencing with Deadlines is a greedy algorithm problem in which each job has a profit and a deadline, and the objective is to **maximize total profit** by scheduling jobs within their deadlines.
Each job has two parameters:
- **Profit (P):** Profit earned by completing the job on time.
- **Deadline (D):** Latest time slot by which the job must be completed.

## 2. Assumptions
1. There is only one processor (uniprocessor system).
2. Preemption is not allowed.
3. Each job takes exactly one unit of time.
4. A job earns its profit only if completed by its deadline.
5. Only one job can execute in a time slot.

## 4. Greedy Strategy
**Rule:** Sort all jobs in decreasing order of profit and schedule each job in the **latest available slot on or before its deadline**.

### Algorithm Steps
1. Sort jobs by profit in descending order.
2. Find the maximum deadline.
3. Create time slots from `1` to the maximum deadline.
4. Consider jobs in decreasing order of profit.
5. For each job, search backward from its deadline for an empty slot.
6. If an empty slot exists, schedule the job there.
7. If no slot is available, reject the job.
8. Calculate the total profit of the scheduled jobs.

**Why schedule as late as possible?**
It leaves earlier slots available for jobs with tighter deadlines.

## 6. Pseudocode

```yml
JobSequencing(jobs, n):

    Sort jobs by decreasing profit

    maxDeadline = maximum deadline among jobs
    Create maxDeadline empty slots

    totalProfit = 0

    for each job in sorted jobs:
        for slot = min(job.deadline, maxDeadline) down to 1:
            if slot is empty:
                schedule job in slot
                totalProfit += job.profit
                break

    return totalProfit
```

## 7. Time Complexity

Let:
- `n` = number of jobs.
- `D` = maximum deadline.

| Operation | Time Complexity |
|---|---|
| Sort jobs by profit | O(n log n) |
| Initialize slots | O(D) |
| Search for a slot for each job | O(nD) |
| Overall time complexity | **O(n log n + nD)** |

> If the maximum deadline is at most `n`, then `D ≤ n`, giving the worst-case time complexity: O(n^2)

## 8. Important Properties
- Job Sequencing is a greedy technique.
- The objective is to maximize total profit.
- Jobs are sorted by decreasing profit.
- Each job takes one unit of time.
- Preemption is not allowed.
- A job must finish by its deadline to earn profit.
- Schedule each selected job as late as possible without missing its deadline.
- If no valid slot exists, reject the job.
- The maximum number of jobs that can be scheduled is limited by the available time slots.

## 9. Common Mistakes in GATE Questions

| Mistake | Correct Approach |
|---|---|
| Scheduling jobs in increasing profit order | Sort by decreasing profit |
| Placing every job in the earliest available slot | Prefer the latest available slot before its deadline |
| Treating deadline as job duration | Every job takes one unit of time |
| Scheduling a job after its deadline | Never schedule beyond the deadline |
| Assuming all jobs must be selected | Reject jobs when no valid slot exists |
| Adding profit for rejected jobs | Count profit only for scheduled jobs |

# Optimal Merge Pattern 
- is a **Greedy Algorithm** used to merge multiple files into one file with the **minimum total number of record movements**.
- Only **two files can be merged at a time**.
- The size of the merged file is the sum of the sizes of the two files being merged.
- The key strategy is to **always merge the two smallest files first**.
 
## 2. Greedy Approach
**Algorithm:** Repeatedly select the two minimum-sized files, merge them, and insert the newly created file back into the collection.
- Steps:
1. Select the two smallest files.
2. Merge them.
3. Add their sizes to the total merging cost.
4. Insert the merged file back into the collection.
5. Repeat until only one file remains.

**Important:** Always insert the merged file back before choosing the next two minimum files.

## 4. Why Do We Merge the Two Smallest Files First?

- Smaller files incur less cost when merged early.
- A file merged early may be included in multiple later merges.
- Therefore, larger files should ideally participate in fewer merges.
- Selecting the two smallest files greedily minimizes the overall merging cost.

## 6. Algorithm Using a Min-Heap
A **Min-Heap** efficiently provides the smallest file size.

1. Build a min-heap containing all \(n\) file sizes.
2. Initialize `totalCost = 0`.
3. While the heap contains more than one element:
   - Extract the minimum element \(a\).
   - Extract the next minimum element \(b\).
   - Calculate `merged = a + b`.
   - Add `merged` to `totalCost`.
   - Insert `merged` back into the min-heap.
4. Return `totalCost`.

### Pseudocode

```yml
OptimalMerge(files):
    Build a min-heap from files
    totalCost = 0

    while heap size > 1:
        a = extractMin()
        b = extractMin()

        merged = a + b
        totalCost = totalCost + merged

        insert(merged)

    return totalCost
```

## 7. Time Complexity

Let \(n\) be the number of files.

| Operation | Time Complexity |
|---|---|
| Build min-heap using heapify | \(O(n)\) |
| Extract minimum | \(O(\log n)\) |
| Extract two minimums | \(O(\log n)\) |
| Insert merged file | \(O(\log n)\) |
| Number of merges | \(n-1\) |
| Total time complexity | **\(O(n\log n)\)** |

Each merge performs two extractions and one insertion, taking \(O(\log n)\) time per merge.

Therefore:

\[
O(n)+O((n-1)\log n)=\boxed{O(n\log n)}
\]

**GATE point:** Building the initial heap using bottom-up heapify takes \(O(n)\), not \(O(n\log n)\).

## 8. Connection with Huffman Coding
- Optimal Merge Pattern and Huffman Coding use the same greedy idea.
- Both repeatedly combine the two smallest weights or frequencies.
- Both commonly use a min-heap.
- Their applications differ:
  - **Optimal Merge Pattern:** Minimizes the cost of merging files.
  - **Huffman Coding:** Constructs an optimal prefix code to minimize weighted encoding length.
