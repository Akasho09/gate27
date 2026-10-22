# 

## QUICK SORT 
- Divide and Conquer
    - Best case	O(n\log n)
    - Average case	O(n\log n)
    - Worst case	O(n^2)
- Auxiliary space (average)	O(log n)
- Stable. : No
    - A sorting algorithm is stable if equal elements maintain their original relative order after sorting.
- In-place	Yes, typically

![alt text](<Screenshot 2026-10-22 at 10.56.38 AM.png>)
- Choose pivot.
- choose 2 pinters and move both till < or >= pivot.
- if p and q havent crossed each other, swap p & q else swap q with pivot.
- after every pass pivot is at right position.
- TC : 
    - Best case : T(n) = T(n/2) + T(n/2) + n ~= O(nlogn)
> REMEMBER UNSTABLE

## Bubble sort
- bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order.
- Working principle: After each pass in ascending order, the largest unsorted element moves to the end, like a bubble rising to the surface.
- 4. Time and space complexity
    - Best case	O(n). Already sorted, with early stopping
    - Average case	O(n^2)	Randomly ordered array
    - Worst case O(n^2)	Reverse-sorted array
    - Auxiliary space	O(1)	Uses constant extra memory
> Important: Without the swapped optimization, even an already sorted array takes \(O(n^2)\) time.
- 
| Property | Answer |
|---|---|
| Stable | Yes |
| In-place | Yes |
| Recursive or iterative | Usually iterative |
| Requires extra array | No |
- n(n-1)/2 comparisons and max swaps.

### TOTAL NUMBER OF SWAPS :
- For each el sum the no of elements less than it to its right.

## Selection Sort
- Selection Sort is a sorting algorithm that repeatedly selects the smallest element from the unsorted part and places it at the beginning of that part.
- Divide the array conceptually into a sorted part and an unsorted part.
- Working principle: Find the minimum element, swap it with the first unsorted element, and repeat.
- 
| Case | Time Complexity | Reason |
|---|---|---|
| Best case | O(n^2) | Still searches the unsorted part |
| Average case | O(n^2) | Repeated minimum searches |
| Worst case | O(n^2) | Repeated minimum searches |
| Auxiliary space | O(1) | Uses constant extra memory |
- 
| Property | Answer |
|---|---|
| Stable | No, usually |
| In-place | Yes |
| Adaptive | No, usually |
| Comparison-based | Yes |
| Recursive or iterative | Usually iterative |
| Requires another array | No |
- Maximum passes = \(n-1\)
- Comparisons = \(\frac{n(n-1)}{2}\)
- Maximum swaps = \(n-1\) if self-swaps are avoided

## Insertion Sort
- Insertion Sort builds a sorted array one element at a time by inserting each element into its correct position.
- start from 2 and place it at correct poistion on left. 
- Approach: Divide the array into a sorted part and an unsorted part.
- Take the next element (key), shift larger elements to the right, and insert the key in the correct position.
- Stable: Yes.
- In-place: Yes.
- Adaptive: Yes.
- Usually implemented: Iteratively.
- 
| Case | Time Complexity | Reason |
|---|---|---|
| Best case | O(n) | Array is already sorted |
| Average case | O(n^2) | Elements require shifting |
| Worst case | O(n^2) | Array is reverse sorted |
| Auxiliary space | O(1) | Constant extra memory |

---
| Feature | Insertion Sort | Bubble Sort | Selection Sort | Quick Sort |
|---|---|---|---|---|
| Best case | O(n) | O(n), optimized | O(n^2) | O(n log n) |
| Average case | O(n^2) | O(n^2) | O(n^2) | O(n log n) |
| Worst case | O(n^2) | O(n^2) | O(n^2) | O(n^2) |
| Stable | Yes | Yes | Usually no | Usually no |
| In-place | Yes | Yes | Yes | Usually yes |
| Adaptive | Yes | Yes, optimized | No, usually | Depends on implementation |
| Main operation | Shifting | Adjacent swaps | Selecting minimum | Partitioning |

## Radix sort :


# Binary serach :
while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
>            low = mid + 1;
        else
>            high = mid - 1;
    }

