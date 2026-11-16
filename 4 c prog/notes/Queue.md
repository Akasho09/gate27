# A Queue 
- is a linear data structure that follows the FIFO (First In, First Out) principle.
- The element inserted first is removed first.

1. Enqueue	: Insert an element	O(1)
2. Dequeue	: Remove an element	O(1)
3. Front / Peek	: Access first element	O(1)
4. Rear : 	Access last element	O(1)
5. isEmpty :	Check whether queue is empty	O(1)


1. Queue using Stack	
- 2 stacks	
Insertion operation : Enqueue	
Deletion operation : Dequeue	
- FIFO using LIFO

2. Queue using Stack with REVERSE	
1 stack	PUSH	
REVERSE + POP	
FIFO using reversal

2. Stack using Queue	
2 queues	
PUSH	
POP	
LIFO using FIFO

4. Stack using Queue (costly PUSH)	
- 1 queue	
Rotate existing elements + Enqueue	
Dequeue	
LIFO using rotation

5. Stack using Queue (costly POP)	
- 1 queue	
Enqueue	
Rotate elements + Dequeue	
- LIFO using rotation

6. Stack using Array	
1 array	
PUSH	
POP	
- LIFO

7. Queue using Array	
1 array	
Enqueue	
Dequeue	
- FIFO

8. Stack using Linked List	
1 linked list	
Insert at head	
Delete at head	
- LIFO

9. Queue using Linked List	
- 1 linked list	
Insert at tail	
Delete at head	
- FIFO


## A Priority Queue 
- is a linear data structure in which each element is associated with a priority, and elements are served based on their priority rather than their insertion order.
- Key point: Higher-priority elements are removed before lower-priority elements.



