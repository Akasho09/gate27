# Serializability
Serializability is a correctness criterion used to determine whether a non-serial schedule is equivalent to some serial schedule.

## Types of Serializability
1. Conflict Serializability
Based on conflicting operations

2. View Serializability
Based on read-from and final-write relationships

## Conflict Equivalent Schedules

## 1. Conflict Serializability | Precedence Graph
- A schedule is conflict serializable if it can be transformed into a serial schedule by swapping non-conflicting operations.

### Precedence Graph?
A Precedence Graph is a directed graph used to determine whether a schedule is conflict serializable.

It consists of:
- Vertices (Nodes): Transactions.
- Directed Edges: Conflict-based dependencies between transactions.

### Rules to construct a Precedence Graph
1. Step 1: Create one node for each transaction.
2. Step 2: Identify conflicting operations.
3. Step 3: Draw a directed edge from the transaction performing the earlier operation to the transaction performing the later operation.
T_i -> T_j
> This means transaction \(T_i\) must execute before transaction \(T_j\) in an equivalent serial schedule
4. Step 4: Check whether the graph contains a cycle.
- No cycle → Conflict Serializable.
- Cycle present → Not Conflict Serializable.
![alt text](image-6.png)

### Sequebce of Non confliction :
1. Start with Indegree = 0.
> Indegree of a vertex = Number of edges coming INTO that vertex.
2. Remove edges.
3. Keep adding Indegree = 0 node.

## 2. View Serializability
- View serializability is a concept used to determine whether a given schedule is equivalent to some serial schedule based on the values read and the final values written.
A schedule is view serializable if it is view equivalent to at least one serial schedule.

### 1. View Equivalence
Two schedules \(S_1\) and \(S_2\) are view equivalent if all three conditions hold:
1. Condition 1: Initial Read
If a transaction reads the initial value of a data item in one schedule, it must also read the initial value in the other schedule.

2. Condition 2: Read-From Relationship
If transaction \(T_i\) reads a value of data item \(X\) written by transaction \(T_j\) in one schedule, then it must read the value written by the same transaction \(T_j\) in the other schedule.

3. Condition 3: Final Write
The transaction that performs the final write on a data item must be the same in both schedules.
- Remember: These conditions compare the source of read values and the final writer, not necessarily the order of all operations.

---
Initial Read: Same initial read values.
Updated Read: Same updated read values.
Final Update/Write: Same final write values.
---

> A blind write occurs when a transaction writes a data item without reading it first.

