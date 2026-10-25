# The key formula for ensuring deadlock freedom under all possible execution orders is:
> R <= n(k-1)+1 
- Where:
    - \(R\) = total instances of a resource type
    - \(n\) = number of processes
    - \(k\) = maximum demand per process for that resource

> The idea is to give every process k-1 resources and leave at least one resiurce free and disturibute rest all.


# PAGING
![alt text](<Screenshot 2026-10-25 at 1.10.03 PM.png>)

- Logical addres space = process size. 
example 4GB => 2^32 Bytes => 32 bytes is size of Log address by CPU .

