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


## GCD Complexity :
> O(log(MAX(n,m)))
- GCD of 2 consecutive fibonacci numbers.

## Max and min in array : Pairwise comparison
> Even = 3/2*n - 2
> Odd : 3(n-1)/2

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


## 


