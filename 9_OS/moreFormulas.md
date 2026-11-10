# The key formula for ensuring deadlock freedom under all possible execution orders is:
> R <= n(k-1)+1 
- Where:
    - \(R\) = total instances of a resource type
    - \(n\) = number of processes
    - \(k\) = maximum demand per process for that resource

> The idea is to give every process k-1 resources and leave at least one resiurce free and disturibute rest all.


## Simple Average Method 
> T_(n+1)= Sum of actual burst times / Number of processes

## Exponential Averaging Method 
> T_(n+1)= (alpha * t_n) + (1-alpha)T_n
- T_n = Previous predicted burst time
- t_n  = Actual burst time
- alpha = Smoothing factor
----
- Given T1 and t1 we can calculate T2.
- using T2 and if again given t2 we can calculate T3... so on

## Bounded Waiting 
is a property of the Critical Section Problem that ensures a process does not have to wait indefinitely to enter its critical section after requesting entry.
- Deadlock means processes are permanently blocked.
- Bounded Waiting concerns whether a waiting process can be postponed indefinitely while other processes continue entering.

## A Process switch generally takes more time than switch between user and kernel mode as it invloves both.

## 26. Semaphore is used for:
(a) Synchronization  ✅
(b) Deadlock Avoidance
(c) Bounded Waiting 

## Resource allocation graph
1. In a single instance Resource allocation graph (Wait for graph) cycle is a:
(b) Sufficient condition for deadlock

2. In a Multiple instance Resource allocation graph, cycle is a:
(a) Necessary condition for deadlock 

## The depth of a node in a tree data structure is the number of edges along the unique path from the root node to that specific node.

## Catlan number :
> (2*n) C n / (n+1)

## 

