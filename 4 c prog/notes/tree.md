# 

## Tree Traversal
- Tree Traversal is the process of visiting every node of a tree exactly once in a specific order.

### - There are two main categories:
1. Depth First Search (DFS)
DFS explores a subtree completely before moving to another subtree.
There are three types:
- Inorder
- Preorder
- Postorder

    1. Inorder Traversal (LNR)
    > Left -> Node -> Right
    - Steps:
        1. Traverse left subtree.
        2. Visit root.
        3. Traverse right subtree.

    2. Preorder Traversal (NLR)
    > Node -> Left -> Right
    - Steps:
        1. Visit root.
        2. Traverse left subtree.
        3. Traverse right subtree.

    3. Postorder Traversal (LRN)
    >  Left -> Right -> Node

    - Steps:
        1. Traverse left subtree.
        2. Traverse right subtree.
        3. Visit root.

2. Breadth First Search (BFS)
- BFS visits nodes level by level, from left to right.

It uses a Queue (FIFO) data structure.

