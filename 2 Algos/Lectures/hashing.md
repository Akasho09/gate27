# Hashing in Data Structures 
- **Hashing** is a technique used to store and retrieve data efficiently.
- It maps a large key value to a smaller index in a hash table.
- It uses a **hash function** to calculate the storage location.
- It supports insertion, searching and deletion.
- Average-case time complexity for these operations can be \(O(1)\), assuming a suitable hash function and effective collision handling.

## 2. Important Terminology

| Term | Meaning |
|---|---|
| Search key | A value used to identify and retrieve a record |
| Hash table | An array-like data structure used to store keys or records |
| Hash function | A function that maps a key to a table index |
| Hash value | The index produced by the hash function |
| Collision | When two different keys map to the same index |
| Bucket | A table location that stores one or more keys, depending on the collision method |

### Example of a search key
- A student database may contain a student's name, father's name, mother's name and other details. A roll number or registration number can be used as the search key to locate the corresponding record.

## 3. Hash Function: Division Method
- The most common example in the lecture is:
> h(K)= K mod N
- Where:
    - \(K\) = key
    - \(N\) = size of the hash table
    - \(h(K)\) = calculated hash index
- The modulo operation returns the remainder after division.

## 4. Operations in Hashing

### A. Insertion
1. Take the key.
2. Apply the hash function.
3. Calculate the index.
4. Store the key at that location, resolving any collision if necessary.

### B. Searching
1. Take the key to be searched.
2. Apply the same hash function.
3. Go to the calculated index.
4. Check the key and follow the collision-resolution method if required.

### C. Deletion

1. Calculate the key's hash index.
2. Locate the key using the appropriate collision-resolution method.
3. Delete it while preserving the rules of that method.

## 5. Other Hashing Methods
The lecture introduces three methods.

### A. Division Method
Calculate the remainder:
h(K)=K\bmod N

### B. Mid-Square Method
1. Square the key.
2. Select the required middle digit or digits.
3. Use the selected digits as the hash index.
- Example:
K=123
K^2=123^2=15129
- The middle digits are selected according to the required table size and the convention specified in the question.

### C. Folding Method
1. Divide the key into groups of digits.
2. Add the groups together.
3. Use the resulting value, applying any required table-size adjustment.
- Example from the lecture:
    - Key: 123456
    - Groups: 123, 45, 6
    - Sum: \(123+45+6=174\)

For a table with indexes 0–999, the resulting index is 174.

## 6. Collision in Hashing
A **collision** occurs when two different keys produce the same hash index.
- Example:
- h(K)=K\bmod10
    - For key 52:
    52\bmod10=2
    - For key 62:
    62\bmod10=2
- Both keys map to index 2. If key 52 already occupies that location, inserting key 62 causes a collision.

**Important:** Collision-resolution techniques are the next topic in the lecture series; this video introduces the problem but does not explain those methods.

## 7. Time Complexity

| Operation | Average-case complexity | Worst-case complexity |
|---|---|---|
| Search | \(O(1)\) | \(O(n)\) |
| Insertion | \(O(1)\) | \(O(n)\) |
| Deletion | \(O(1)\) | \(O(n)\) |

These are general hash-table complexities, not guarantees that every operation takes constant time. Performance depends on the hash function, load factor and collision-resolution method.

# Collision Resolution Techniques in Hashing 
A **collision** occurs when two or more different keys map to the same hash table index.
- Example:
    h(K)=K\bmod 6
- The hash table has indexes from \(0\) to \(5\).

| Key | Calculation | Hash index |
|---:|---|---:|
| 24 | \(24\bmod 6\) | 0 |
| 19 | \(19\bmod 6\) | 1 |
| 32 | \(32\bmod 6\) | 2 |
| 44 | \(44\bmod 6\) | 2 |

Both 32 and 44 map to index 2. Since index 2 is already occupied by 32, inserting 44 causes a **collision**.

## 2. Types of Collision Resolution Techniques

There are two main categories discussed in the lecture.

1. **Chaining (Open Hashing)**
2. **Open Addressing (Closed Hashing)**
   - Linear Probing
   - Quadratic Probing
   - Double Hashing

## 3. Chaining (Open Hashing)
- In chaining, each hash table index can maintain a linked list of keys that map to that index.
- When a collision occurs, the new key is added to the chain at that index.
- It uses additional memory to store the linked-list nodes.

**Advantages**
- Multiple keys can be stored at the same index through a chain.
- The table can accommodate more keys than the number of table slots.

**Disadvantages**
- Requires extra memory for linked-list nodes.
- Searching can become slower when chains grow long. O(n)

- Load factor. : no of keys / no of slots

## 4. Open Addressing (Closed Hashing)
 
- All keys are stored within the hash table itself.
- If the calculated index is occupied, another slot is searched using a probing method.
- The three methods covered are linear probing, quadratic probing and double hashing.

## 5. Linear Probing
- In linear probing, if the original position is occupied, check the next position sequentially until an empty slot is found.

### Formula
> h_i(K)= (h(K)+i) \ mod N
- Where:
    - \(h(K)\) = original hash index
    - \(i=0,1,2,\ldots\) = probe number
    - \(N\) = table size

**Main point:** Linear probing checks consecutive slots.

**Disadvantage:** It can cause primary clustering, where long groups of occupied slots form.

## 6. Quadratic Probing
- In quadratic probing, the next positions are calculated using the square of the probe number.

### Formula used in the lecture
> h_i(K)=(h(K)+i^2)\bmod N

**Main point:** Quadratic probing uses squared offsets instead of checking consecutive slots.

- Not every table size guarantees that every slot will be visited.

## 7. Double Hashing

- Double hashing uses **two hash functions**.
- The first function determines the initial index.
- The second function determines the step size used to probe for another slot when a collision occurs.

### General formula
> h_i(K) = K mod 11
> h_2(K) = 8 - (K mod 8)
then 
> h_i + i*h_2 mod 11
- Where:
    - \(h_1(K)\) = first hash function
    - \(h_2(K)\) = second hash function
    - \(i\) = probe number
    - \(N\) = table size

### Working
1. Calculate the initial index using \(h_1(K)\).
2. If the slot is occupied, calculate the next position using \(h_2(K)\).
3. Continue probing until an available slot is found.

**Main point:** Double hashing uses a key-dependent step size, which helps reduce clustering.

For reliable probing, the step size should be relatively prime to the table size so that all slots can be visited.

---
---
---
---
---
---
---
---
---
---
---
---
---
---
---









# L-6.3: Chaining in Hashing

- Chaining is a **collision resolution technique** in hashing.
- It is also called **Open Hashing** or **Separate Chaining**.
- Each hash table index stores a pointer to a chain of keys that map to that index.
- A chain is commonly implemented using a linked list.
- Multiple keys can be stored at the same index.

## 2. Example of Chaining

Given keys: `42, 19, 10, 12`

Hash function:

\[
h(K)=K\bmod5
\]

Since the table size is 5, valid indexes are `0, 1, 2, 3, 4`.

### Step 1: Calculate hash values

| Key | Calculation | Hash index |
|---:|---|---:|
| 42 | \(42\bmod5\) | 2 |
| 19 | \(19\bmod5\) | 4 |
| 10 | \(10\bmod5\) | 0 |
| 12 | \(12\bmod5\) | 2 |

### Step 2: Construct the hash table

Keys 42 and 12 both map to index 2, so they form a chain.

| Index | Stored keys |
|---:|---|
| 0 | 10 → NULL |
| 1 | NULL |
| 2 | 12 → 42 → NULL |
| 3 | NULL |
| 4 | 19 → NULL |

**Important:** The lecture inserts new nodes at the beginning of the linked list. Therefore, 12 is placed before 42.

## 3. How Does Chaining Work Internally?

Each linked-list node generally contains two parts:

1. **Data field:** stores the key.
2. **Next pointer:** stores the address of the next node.

When inserting 12 at index 2:

1. Calculate \(12\bmod5=2\).
2. The bucket at index 2 already points to node 42.
3. Create a new node containing 12.
4. Set `12.next = 42`.
5. Update the bucket pointer to point to node 12.

Result:

`Bucket[2] → 12 → 42 → NULL`

## 4. Advantages of Chaining

### A. Easy deletion

- First, search for the key in its chain.
- Update the appropriate pointer to bypass the node.
- Free the deleted node's memory.

Example:

Before deletion:

`Bucket[2] → 12 → 42 → NULL`

Delete 12:

`Bucket[2] → 42 → NULL`

Deletion is relatively easy compared with open addressing because there is no need to preserve a probing sequence.

### B. Constant-time insertion

- The lecture inserts each new node at the beginning of the chain.
- If the hash index is known, inserting at the head takes \(O(1)\) time.
- This assumes no additional search is needed, such as checking for duplicate keys.

## 5. Disadvantages of Chaining

### A. Searching can take \(O(n)\)

- If many keys map to the same index, the linked list becomes long.
- Searching may require traversing the entire chain.
- Deletion may also take \(O(n)\), because the key must first be found.

**Worst-case time complexity:**

\[
\boxed{O(n)}
\]

### Example of the worst case

Consider the keys:

`2, 12, 32, 42, 52, 62`

Using \(h(K)=K\bmod10\):

Every key maps to index 2.

`Bucket[2] → 2 → 12 → 32 → 42 → 52 → 62 → NULL`

The chain contains all \(n=6\) keys. Searching for a key at the end requires traversing the entire chain.

### B. Extra memory requirement

- Chaining uses additional memory for linked-list nodes and pointers.
- Some hash table buckets may remain empty while chains occupy additional memory outside the main table.
- This additional memory is one reason for the term **Open Hashing** in the lecture.

## 6. Load Factor

The **load factor** is the ratio of the total number of stored keys to the total number of hash table slots.

It is denoted by \(\alpha\) (alpha).

\[
\boxed{\alpha=\frac{n}{m}}
\]

Where:

- \(n\) = total number of keys
- \(m\) = total number of slots or buckets

### Example from the lecture

- Total keys = 4
- Total slots = 5

\[
\alpha=\frac45=0.8
\]

Therefore, the load factor is **0.8**.

### Important points

- In chaining, the load factor can be greater than 1.
- A higher load factor generally means longer chains.
- A lower load factor generally means shorter chains, assuming a reasonably distributed hash function.

## 7. Time Complexity of Chaining

| Operation | Best case | Average/expected case* | Worst case |
|---|---|---|---|
| Insertion at head | \(O(1)\) | \(O(1)\) | \(O(1)\) |
| Searching | \(O(1)\) | \(O(1+\alpha)\) | \(O(n)\) |
| Deletion | \(O(1)\) | \(O(1+\alpha)\) | \(O(n)\) |

*Expected search and deletion complexity assumes a suitable hash function and a reasonably distributed set of keys. The worst-case insertion bound assumes head insertion without duplicate checking.*

## 8. GATE Exam Quick Revision

| Question | Answer |
|---|---|
| What is chaining? | A collision resolution technique using linked lists or other chains |
| Another name for chaining? | Open hashing / separate chaining |
| Which data structure is commonly used? | Linked list |
| How is insertion performed in this lecture? | At the beginning of the linked list |
| What is the main advantage? | Easy deletion and simple insertion |
| Worst-case search complexity? | \(O(n)\) |
| Worst-case deletion complexity? | \(O(n)\) |
| Load-factor formula? | \(\alpha=n/m\) |
| Load factor for 4 keys and 5 slots? | \(0.8\) |
| Can load factor exceed 1? | Yes |
| Why can searching become slow? | Many keys may map to the same bucket |
| Why is it called open hashing here? | It uses additional memory for chain nodes |

## 9. Most Important Exam Takeaways

1. **Insertion at the head of a chain:** \(O(1)\), assuming the bucket is known.
2. **Worst-case searching:** \(O(n)\), when all keys map to the same bucket.
3. **Worst-case deletion:** \(O(n)\), because searching for the key may take linear time.
4. **Load factor:** \(\alpha=n/m\).
5. **Chaining allows \(\alpha>1\)** because multiple keys can share a bucket.
6. In the lecture's example, \(42\) and \(12\) both map to index 2 under \(h(K)=K\bmod5\).


# Linear Probing in Hashing 
- **Linear probing** is a collision-resolution technique used in hashing.
- It is a type of **open addressing (closed hashing)**.
- When a collision occurs, the next consecutive slot is checked until an empty slot is found.
- If the next slot is occupied, move to the next one, and continue sequentially.
- If the end of the table is reached, wrap around to index `0`.

**Example:** If the hash function gives index `3` and index `3` is occupied, check `4`, then `5`, then `6`, and so on.

## 2. Hash Function and Hash Table Size

For a hash function:

\[
h(K)=K \bmod N
\]

- \(K\) = key
- \(N\) = hash table size
- Possible indices = `0` to `N − 1`

For example, if \(h(K)=K\bmod 10\), the hash table indices are `0` to `9`.

## 3. Linear Probing Formula

\[
h_i(K)=(h(K)+i)\bmod N
\]

Where:

- \(h(K)\) = original hash value
- \(i\) = probe number, starting from `0`
- \(N\) = hash table size
- \(h_i(K)\) = index checked during the \(i\)-th probe

**Remember:** If the original slot is occupied, check the next slot. Keep moving forward until an empty slot is found.

## 4. Example: Inserting Keys Using Linear Probing

Given:

- Hash function: \(h(K)=K\bmod 10\)
- Keys, in insertion order: `43, 135, 72, 23, 99, 19, 82`

### Step-by-step insertion

| Key | Original hash value | Probe sequence | Final index | Probe number |
|---:|---:|---|---:|---:|
| 43 | 3 | 3 | 3 | 0 |
| 135 | 5 | 5 | 5 | 0 |
| 72 | 2 | 2 | 2 | 0 |
| 23 | 3 | 3 → 4 | 4 | 1 |
| 99 | 9 | 9 | 9 | 0 |
| 19 | 9 | 9 → 0 | 0 | 1 |
| 82 | 2 | 2 → 3 → 4 → 5 → 6 | 6 | 4 |

The probe number above uses the formula's convention: the original slot is probe `0`. The video sometimes counts the first checked slot as attempt `1`.

### Final hash table

| Index | Stored key |
|---:|---:|
| 0 | 19 |
| 1 | Empty |
| 2 | 72 |
| 3 | 43 |
| 4 | 23 |
| 5 | 135 |
| 6 | 82 |
| 7 | Empty |
| 8 | Empty |
| 9 | 99 |

**Important:** `19` demonstrates wrap-around. Its original index is `9`, but because index `9` is occupied, it is inserted at index `0`.

## 5. Probe Number — Important for GATE

The probe number indicates how many positions are checked before finding the key's slot.

Be careful: two counting conventions are common.

- **Formula convention:** original slot has \(i=0\).
- **Attempt convention:** first checked slot is attempt `1`.

| Key | Positions checked | Formula probe \(i\) | Attempt count |
|---:|---|---:|---:|
| 43 | 3 | 0 | 1 |
| 135 | 5 | 0 | 1 |
| 72 | 2 | 0 | 1 |
| 23 | 3, 4 | 1 | 2 |
| 99 | 9 | 0 | 1 |
| 19 | 9, 0 | 1 | 2 |
| 82 | 2, 3, 4, 5, 6 | 4 | 5 |

### Exam tip

If a question asks for the probe number of an element, determine whether it counts the initial hash position as probe `0` or attempt `1`. Follow the convention used in the question.

## 6. Advantages of Linear Probing

1. **No extra linked-list space:** All keys are stored directly in the hash table.
2. **Simple implementation:** Only consecutive positions need to be checked.
3. **Cache-friendly:** Consecutive memory locations can improve locality.
4. **Expected constant-time operations:** Insertion and searching can be \(O(1)\) under suitable conditions, especially at a low load factor.

## 7. Disadvantages of Linear Probing

### A. Searching can take \(O(n)\)

- In the best case, the required key is at its original hash position: \(O(1)\).
- In the worst case, many or all table positions may need to be examined: \(O(n)\).

### B. Deletion is difficult

Suppose key `82` is stored after probing through indices `2`, `3`, `4`, `5`, and `6`.

If key `43` is deleted from index `3` by simply marking the slot empty, a search for `82` may stop at index `3` and incorrectly conclude that `82` is absent.

**Solution: Lazy deletion (tombstones)**

- Mark the deleted slot using a special `DELETED` marker.
- During searching, continue past `DELETED` slots.
- During insertion, deleted slots may be reused carefully.
- A truly empty slot can terminate an unsuccessful search; a tombstone cannot.

### C. Primary clustering

- A **cluster** is a contiguous group of occupied slots.
- Linear probing tends to create long contiguous groups of occupied slots.
- New keys may join an existing cluster even if their original hash positions differ.
- As clusters grow, insertion and searching require more probes.

### D. Performance degrades as the table fills

As the number of occupied slots increases, finding an empty slot becomes more difficult. Consequently, the number of probes can increase significantly.

## 8. Primary Clustering

**Definition:** Primary clustering occurs when consecutive occupied slots form a cluster that tends to grow as more keys are inserted.

Example:

```text
Index:  0  1  2  3  4  5  6  7  8  9
Table:  -  -  A  B  C  D  E  -  -  -
```

Here, indices `2` through `6` form a cluster.

Why is this a problem?

1. A key may hash to any position within the cluster.
2. If that position is occupied, linear probing moves forward.
3. The key may join the same cluster.
4. The cluster becomes longer.
5. Searching and insertion may require more probes.

**GATE fact:** Linear probing suffers from primary clustering.

## 9. Secondary Clustering

**Definition:** Secondary clustering occurs when keys with the same initial hash value follow the same probe sequence.

In linear probing, if two keys have the same initial hash index, they follow the same sequence of consecutive positions until an empty slot is found.

For example, if two keys both hash to index `3`, both initially check:

```text
3 → 4 → 5 → 6 → ...
```

The sequence can differ in how far each key travels before insertion, but their initial probe sequences are the same.

**GATE distinction:**

- **Primary clustering:** Long contiguous groups of occupied slots develop.
- **Secondary clustering:** Keys with the same initial hash value follow the same probe sequence.

Quadratic probing reduces primary clustering but can still suffer from secondary clustering when keys have the same initial hash value.

## 10. Time Complexity

| Operation | Best case | Worst case |
|---|---:|---:|
| Search | \(O(1)\) | \(O(n)\) |
| Insertion | \(O(1)\) | \(O(n)\) |
| Deletion | \(O(1)\) to locate the key | \(O(n)\) to locate the key |

These are worst-case bounds. Under suitable hashing assumptions and a reasonably low load factor, operations can have expected constant-time performance.

## 11. Linear Probing vs Chaining

| Feature | Linear Probing | Chaining |
|---|---|---|
| Technique | Open addressing | Separate chaining |
| Storage | Keys stored inside the table | Each bucket maintains a chain |
| Extra memory | No linked-list pointers required | Extra memory for nodes and pointers |
| Collision handling | Check consecutive slots | Add key to the bucket's chain |
| Deletion | More complicated; tombstones may be needed | Generally straightforward |
| Clustering | Primary clustering occurs | Linear-probing-style primary clustering does not occur |
| Worst-case search | \(O(n)\) | \(O(n)\) |

## 12. GATE Quick Revision Facts

1. Linear probing is a collision-resolution technique based on **open addressing**.
2. Formula: \(h_i(K)=(h(K)+i)\bmod N\).
3. If a slot is occupied, check the next consecutive slot.
4. After the final index, wrap around to index `0`.
5. Linear probing uses the existing hash table slots; it does not require linked-list storage.
6. Worst-case searching and insertion can take \(O(n)\).
7. Deletion requires care because an empty slot can terminate an unsuccessful search.
8. **Primary clustering** means the formation and growth of contiguous occupied groups.
9. **Secondary clustering** means keys with the same initial hash value follow the same probe sequence.
10. Performance generally worsens as the load factor increases.

## 13. Quick Self-Test

| Question | Answer |
|---|---|
| What is the formula for linear probing? | \(h_i(K)=(h(K)+i)\bmod N\) |
| What are the valid indices for a table of size \(N\)? | \(0\) to \(N-1\) |
| What happens when a collision occurs? | Check the next consecutive slot |
| What happens after the last index? | Wrap around to index `0` |
| Which clustering is associated with linear probing? | Primary clustering |
| What is secondary clustering? | Keys with the same initial hash value follow the same probe sequence |
| Why is deletion difficult? | An empty slot can cause a search to stop before reaching a key |
| What is a tombstone? | A marker indicating a deleted slot that must not terminate a search |
| What is the worst-case search complexity? | \(O(n)\) |
| Does linear probing need linked-list pointers? | No |

