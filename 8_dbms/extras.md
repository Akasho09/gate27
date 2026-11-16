# 

1. Suppose a relation R has 9 attributes, then the maximum possible number of candidate keys are?
> Max(9.C.i) , i=0 to 9.


2. Equivalence of Functional Dependency Sets. :
- Two functional dependency sets F and G are equivalent if:
> F^+=G^+
Where:
- F+ = Closure of F.
- G+ = Closure of G.
- Closure represents all functional dependencies logically implied by the given set.
- This means:
    1. Every FD in G must be derivable from F.
    2. Every FD in F must be derivable from G.

3. Simple functional
A Simple Functional Dependency is a functional dependency in which the left-hand side (LHS) contains only one attribute.
> A --> B
- Here:
    - A = Single attribute (determinant).
    - B = Attribute or set of attributes being determined.


4. Minimal cover :
- A Minimal Cover is the smallest equivalent set of functional dependencies that represents the same constraints as the original FD set.
- In simple words, it is a simplified version of a functional dependency set without losing any information.
- A Minimal Cover must satisfy three conditions.
    1. Condition 1: Single attribute on RHS
    - Every functional dependency must have exactly one attribute on the RHS.
    2. Condition 2: No extraneous attribute on LHS
    - Every attribute on the LHS must be necessary.
    3. Condition 3: No redundant FD
    - No functional dependency should be removable without changing the closure of the FD set.
```yml
Consider a relation R = {P, Q, R, S, T, U, V, W} with
the functional dependency sets S = {PR→V, S→TV,
QR→S, RV→QS, PRS→Q, RT→PV}
The minimum numbers of simple functional
dependency in the minimal cover of F is

Finals :  S->T , S->V , R->Q , R->S , R->P , R->V
```

## Dependency Preserving Decomposition
- Dependency Preserving Decomposition means decomposing a relation into smaller relations in such a way that all the original functional dependencies can still be checked without performing a JOIN operation.
- When we divide a table into smaller tables, we should be able to verify all functional dependencies using the smaller tables independently.

### 1.1 What is Lossless Join?
A decomposition is called lossless if we can reconstruct the original relation exactly by joining the decomposed relations.
In simple words:
- No original information should be lost.
- No extra (spurious) tuples should be generated.
- Joining the decomposed tables must give exactly the original table.

