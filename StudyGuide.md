# Data Structures: Final Exam Study Guide
- Dijkstra's algorithm os O(|V^2|)
- Topological sort: Think prereques, in order for you to print a node, all of its predacessors must have already been reached. 
- Hand code question on either list, stacks, or queues
- There WILL be a simulate sort on a quadratic sort
- There WILL be a huffman tree question
## Lists
- O(1): Insert at end(append/pushback), access
- O(n): Insert in middle/Remove from middle (Average: O(n/2), worst: O(n))
- Possible Questions: Merge two linked lists' overlap, Delete an element in a linked list (on a seperate powerpoint)
- Array Implementaiton Vs. Reference Implementation
    - Array implemnetation needs a size estimate, and requires storage of only item. Allows for constant time access to any index, and for adding/removing requires elements to be moved
    - Reference implementatoin can grow as needed, requireds storage of pointer and item. Requires stepping through the list to access an item, insertion or removal is constant time if an iterator is where you want it to be.
## Stacks
- remember how to do the prefix/postfix stuff
- look at palindrome, balanced parenthesis algorithms for potential problems on exam
- Push/Pop is O(1)
## Queues
- Array based queue: use a circular array
- O(1) for everything like a stack
## Binary Trees
- Searching a binary tree is O(log n), worst case: O(n)
- Full: When all binary tree nodes have either 2 or 0 children
- Perfect: when a binary tree is both full and complete, height is O(log n)
- when a binary tree is "completed left to right", height is O(log n)
- Know: preorder, inorder and postorder traversal
- Know: binary search tree insertion and removal
    - insertion: go to leaf, and put in either < or >
    - deletion: 3 cases:
        - no children: just remove it
        - 1 child: remove it and make its child the child of the removed's parent
        - 2 children
            - replace it with in order predacessor
## Splay Tree
- O(m log n) guarentee
- Average: O(log n)
- worse: O(n)
- After access, or insertion, the node becomes the root of the splay tree
    - Zig Zig
    - Zig Zag
    - Zag Zag
- Practice Tree rotation questions
## Red-Black Trees
- Rules: 
    - A node is either red or black
    - The root is always black
    - A red node always has black children
    - The number of black nodes in any path from the root to a leaf is the same
- Difference between R-B and AVL
    - Storage:
        - AVL trees need a balance factor (int) at each node
        - R-B trees only need a color (bool)
        - R-B ++
    - Searching:
        - AVL trees are strictly balanced
        - R-B trees are not
        - AVL ++
    - Insert/Delete:
        - AVL have to calculate and rotate 
        - R-B does no calculations and does fewer rotations
        - R-B ++
## B+ trees
- M-ary tree, represents blocks of data
- each node can have up to m-children
- Make sure you know how to do an example
- Non leaf nodes store up to m-1 keys
- the root has between 2 and m children
- data is stored in leaves only
- all leaves are at same depth and have between L/2 and L values
-  Know how to draw out an example
-  Know how to do a memory block question
## Hash Tables
- Average time retrieval: O(n)
- Hash functions should be easy to compute and should evenly distribute data
- Collision resolution:
    - Open Adressing: use linear probing to access items. When deleting something, you can't just "remove" it, you set a dummy value in its place since its the only way to still get proper values for items that collided before
    - chaining: each index is a linked list (a bucket) that has every item that had the same table value. Simply adding or removing a new value corresponds to inserting or deleting from a linked list
    - Ideal load factor: .75
    - Cannot be traversed
## Heaps
- @p, left child is at 2p+1 and right child is at 2p+2
- insert/Deletion are O(log n) due to heapifying
- Building a heap is O(n)
- heap sort is O(n log n), idea is to make a heap, remove the front, and put it in the back of an array, then repeat the process till the heap is empty
## Sorting
- Selection sort:
    - Makes several passes and puts the smallest element in the next location