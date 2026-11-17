#

## Terminology :
1. `External Sorting` is a sorting technique used when the data to be sorted is too large to fit entirely into the main memory (RAM).
2. 

## Inversions and Insertion sort:
For an array \(A\), a pair of indices (i,j) is called an inversion if:
> i<j and A[i]>A[j]

- Actual Time complexity of Insertion Sort is defined as 
> Θ(N+f(N))
- f(N) is the total number of Inversions 

## 3.  Merge Sort  vs	Quick Sort
1. Merge Sort is Stable	, Quick Sort is not stable.
2. In-place : 	No (standard array implementation)	 , Yes (typical implementation)
3. Extra memory	: O(n) , O(log n) average

## SUM OF SERIES :

### Harmonic Series
1. 1 + 1 + ... + 1 (n terms) = n                  → Θ(n)

2. 1 + 1/2 + 1/3 + ... + 1/n = H(n)              → Θ(log n)

3. 1 + 1/4 + 1/9 + ... + 1/n²                    → Θ(1)

4. log1 + log2 + .... logn = log(n!) = n.logn


## GCD Complexity :
> O(log(MAX(n,m)))
- GCD of 2 consecutive fibonacci numbers.

## Max and min in array : Pairwise comparison
> Even = 3/2*n - 2
> Odd : 3(n-1)/2
- If n is odd then initialize min and max as first element.
- If n is even then initialize min and max as minimum and maximum of the first two
elements respectively.
- For rest of the elements, pick them in pairs and compare their maximum and minimum
with max and min respectively.

##  Recurrence Relation and Time Complexity 
| Recurrence Relation | Time Complexity |

1. | T(n) = T(n-1) + O(1) | Θ(n) |
2. > | T(n) = T(n-1) + T(n-2) + O(1) | Θ(1.618^n) |
3. > | T(n) = 2T(n-1) + O(1) | Θ(2^n) |
4.  T(n) = 2T(n/2) + O(n) | Θ(n log n) |
5. T(n/3) + Cn.  ======> O(n)
- a=1, b=3,k=1 and p=0
or 
T(n)=Cn * (1+1/3+1/9+.....)
==> Geometric Progression (GP) with r<1. ====> shrinking.

## Complexities :

1. 2^n×2^n ie 2^2n CAN NOT be written as Θ(2^n)


## 
```c
for i = 1 to n do
for j = i to n do
for k = j + 1 to n do
```
> totat no of executions : n(n-1)(n+1)/6
This is one-sixth of the product of three consecutive integers.

## Hamiltonian cycle
- A Hamiltonian Cycle is a cycle in an undirected or directed graph that visits every vertex exactly once and returns to the starting vertex.

1. Hamiltonian Path	
- Visits every vertex exactly once	
- Does not need to return to starting vertex	
- Does not need to form a cycle	

2. Hamiltonian → Visits every vertex.
- Euler → Visits every edge.

3. Complexity
Determining whether a general graph contains a Hamiltonian cycle is an NP-Complete problem.
- Hamiltonian Cycle: NP-Complete.
- Finding a Hamiltonian Cycle: NP-Hard optimization/search problem.

## Maximum Subarray Sum Problem
1. Brute Force Approach
Time Complexity: \(O(n^3)\)
Space Complexity: \(O(1)\)

2. Improved Brute Force Approach
Time Complexity: \(O(n^2)\)
Space Complexity: \(O(1)\)

3. Divide and Conquer Approach
T(n)=O(n\log n)
Space Complexity: \(O(\log n)\) due to recursion stack.

4. Kadane's Algorithm (Dynamic Programming)
Time Complexity: \(O(n)\)
Space Complexity: \(O(1)\)

