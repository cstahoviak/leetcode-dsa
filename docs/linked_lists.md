# Linked Lists
Let's start by introducing the concept of a node. A node can be thought of as an element, but with more information than just one piece of data like an integer or string. For example, an element of an array could be though of as a node containing two pieces of information: the index and the value.

Arrays are implemented under the hood in a way that the elements are stored contiguously in memory. A linked list is a data structure that is similar to an array. It also stores data in an ordered manner, but it is implemented using __node objects__. Each node will have a _next_ pointer, which points to the node representing the next element in the sequence. Traversal of the node graph is possible only on one direction, i.e. backtracking is not possible.

## Advantages and Disadvantages Compared to Arrays
To be honest, the advantages and disadvantages are not super relevant in terms of algorithm problems. This is because almost all the problems that involve linked lists will have the linked list as part of the input, so there isn't a decision on if you should use it, you're forced to.

The main advantage of a linked list is that you can add and remove elements at any position in $O(1)$ The caveat is that you need to have a reference to a node at the position in which you want to perform the addition/removal, otherwise the operation is $O(n)$, because you will need to iterate starting from the head until you get to the desired position. However, this is still much better than a normal (dynamic) array, which requires $O(n)$ for adding and removing from an arbitrary position.

The main disadvantage of a linked list is that there is no random access. If you have a large linked list and want to access the 150,000th element, then there usually isn't a better way than to start at the head and iterate 150,000 times. So while an array has $O(1)$ indexing, a linked list could require $O(n)$ to access an element at a given position.

## Types of Linked Lists

### Singly Linked Lists
A __singly linked list__ is the most common type of linked list. In a singly linked list, each node only has a pointer to the next node. This means you can __only__ move forward in the list when iterating. The pointer used to reference the next node is usually called `next`.

### Doubly Linked List
A doubly linked list is like a singly linked list, but __each node also contains a pointer to the previous node__. This pointer is usually called `prev`, and it allows iteration in __both directions__.
 
### Linked Lists with Sentinel Nodes
We call the start of a linked list the `head` and the end of a linked list the `tail`.

Sentinel nodes sit at the start and end of linked lists and are used to make operations and the code needed to execute those operations cleaner. The idea is that, even when there are no nodes in a linked list, you still keep pointers to a `head` and `tail`. The real head of the linked list is `head.next` and the real `tail` is `tail.prev`. The sentinel nodes themselves are __not__ part of our linked list.

Recall that addition and removal is only $O(1)$  if we have a reference to the node at the position we are performing the operation on. With the sentinel tail node, we can perform operations at the end of the list in $O(1)$.

## Fast and Slow Pointers
