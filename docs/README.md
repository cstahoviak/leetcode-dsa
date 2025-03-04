# Data Structures and Algorithms Overview
The following is an overview of the Data Structures and Algorithms covered by this course. The following tables detail the data structure or algorithm, the relevent C++ implementations, and the applciable problem types that should be solved using that particular data structure or algorithm.

## Data Structures
Data Structures overview.

| Data Structure                 | C++ Implementation | Features | Applicable Problem Types |
|:-------------------------------|:-------------------|:---------|:-------------------------|
| Ordered Associative Containers | `std::map`<br> `std::set`<br> `std::multimap`<br> `std::multiset` | - Efficient $O(\log n)$ __access__, __insertion__, __removal__ and __search__.<br> - Only `multimaps` and `multisets` allow duplicate keys. | ... |  
| Unordered Associative Containers/ Hash Maps | `std::unordered_map`<br> `std::unordered_set`<br> `std::unordered_multimap`<br> `std::unordered_multiset` | - __Very__ efficient (constant time $O(1)$ on average, linear $O(n)$ worst case) __access__, __insertion__, __removal__ and __search__. | - Checking if an element/item exists.<br> - Counting/frequency of items in a collection.|
| Linked List                    | - `std::forward_list` (singly-linked list).<br> - `std::list` (doubly-linked list) | - Linked lists are traversed __iteratively__ (sequentially).<br> - In a __single-linked list__, each node contains a pointer to the next node, but __not__ the previous node.<br> - In a __doubly-linked list__, each node contains pointers to both the next __and__ the previous nodes.<br> &ensp; - A doubly-linked list that additionally maintains both __head__ and __tail__ pointers can be used to efficiently implement a __queue__. | -_Fast and slow pointers_: ...<br> - Know how to reverse a linked list! |
| Stack*                         | `std::stack` | - A __LIFO__ data structure.<br> - Supports the following constant time $O(1)$ operations:<br> &ensp; - `push` (insertion)<br> &ensp; - `top` (access the top element)<br> &ensp; - `pop` (remove the top element) | - Suitable for any problem where you recognize the __LIFO pattern__.<br> - These problems will involve the elements of the input interacting with each other in some way, e.g.<br> &ensp; - matching elements together.<br> &ensp; - querying some property, e.g. _distance to next largest element_. |
| Queue*                         | `std::queue` | - A __FIFO__ data structure.<br> - Supports the following constant time $O(1)$ operations:<br> &ensp; - `push` (insert element at end)<br> &ensp; - `pop` (remove first element)<br> &ensp; - `front` (access the first element)<br> &ensp; - `back` (access the last element) | - Suitable for any problem where you recognize the __FIFO pattern__, e.g.<br> &ensp; - moving average of a data stream.<br> - Queues are primarily uased to implement __Breadth First Search (BFS)__. |
| Deque* (double-ended queue)    | `std::deque` | Constant time $O(1)$ __access__, __insertion__ and __removal__ at both ends.<br> &ensp; - `push_front`, `push_back` (insertion at front or back)<br> &ensp; - `front`, `back` (access first or last element)<br> &ensp; - `pop_front`, `pop_back` (remove first or last element) | - A deque is a good option for maintaing queue of __ordered__ elements because we can apply __binary search__ to `std::deque` to efficiently, $O(\log n)$, find an element or determine its insertion point in the deque.<br> &ensp; - For example, we can maintain a time window of recent data points (adding new data points to the front, and removing old data points from the end), and use __binary search__ to efficiently query our queue or find the insertion point of a new element. |
| Binary Tree                    | N/A | - The __root__ node has no parent and is positioned at the _top_ of the tree.<br> - A __leaf__ node has no children.<br> - The __depth__ of a node is how far it is from the root.<br> - A __subtree__ is a given node and all its descendants.<br> - All nodes have a maximum of __two children__.<br> - Binary trees are traversed __recursively__. | - The idea of __subtrees__ is fundamental to solving binary tree problems.<br> - Treating a given node as its own subtree allows these problems to be solved __recursively__ via either __DFS__ or __BFS__. |
| Binary Search Tree (BST)       | N/A | A __binary search tree__ is a binary tree that has the following additional properties:<br> &ensp; - All values in a node's left subtree are __less than__ the node's value.<br> &ensp; - All values in a node's right subtree are __greater than__ the node's value.<br> &ensp; - All values in a BST are __unique__. | - __In-order__ DFS traversal (prioritizing left over right) will handle nodes in __sorted__ order. |
| Graph                          | N/A | - Graphs have the following properties:<br> &ensp; - __Edges__ can be __directed__ or __undirected__.<br> &ensp; - A __connected componment__ is a group of connected nodes (__vertices__).<br> &ensp; - A graph can be either __cyclic__ (containing one or more cycles) or __acyclic__.<br> &ensp; - Binary trees are __directed, acyclic__ graphs.<br> - Traversal is done via iteration over the neighbors of the current node. | - Graph problems can be either explicit or implicit:<br> &ensp; - explicit: __array of edges__, __adjacency list__, __adjacency matrix__, __matrix__.<br> &ensp; - implicit graphs will involve modeling a transition between two states as two or more connected nodes whose connecting edges represent the range of possible state transitions, e.g. [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/).  |
| Heap                           | `std::priority_queue`<br> `std::make_heap` | - Constant time $O(1)$ access of the __top__ element via `top`.<br> - Logarithmic time $O(\log n)$ insertion (`push`) and removal of the __top__ element (`pop`). | - Use a heap to repeatedly find the min/max element.<br> - Any type of problem that asks for the __top `k` elements__. |

*It's worth noting that stacks and queues are higher level containers than `std::deque`, `std::vector` or `std::list`, i.e. both a stack and queue can be constructed from the lower level containers. In other words, __stack and queue are simply restrictions on a deque__.

### C++ Container Types
C++ provides the following types of [containers](https://en.cppreference.com/w/cpp/container) (including some mentioned above).

#### Sequence containers
Sequence containers implement data structures which can be accessed sequentially.

| Container           | Description                                         |
|:--------------------|:----------------------------------------------------|
| `std::array`        | fixed-size (fixed at compile time) contiguous array |
| `std::vector`       | dynamic/resizeable contiguous array                 |
| `std::deque`        | double-ended queue                                  |
| `std::forward_list` | single-linked list                                  |
| `std::list`         | doubly-linked list                                  |

#### Associative Containers
Associative containers implement sorted data structures that can be quickly searched, $O(\log n)$ complexity.

| Container       | Description                                                        |
|:----------------|:-------------------------------------------------------------------|
| `std::set`      | collection of __unique__ keys, sorted by keys                      |
| `std::map`      | collection of key-value pairs, sorted by keys, keys are __unique__ |
| `std::multiset` | collection of keys, hashed by keys                                 |
| `std::multimap` | collection of key-value pairs, sorted by keys                      |

#### Unordered Associative Containers
Unordered associative containers implement unsorted (__hashed__) data structures that can be quickly searched, $O(1)$ average and $O(n)$ worst-case complexity.

| Container                 | Description                                                        |
|:--------------------------|:-------------------------------------------------------------------|
| `std::unordered_set`      | collection of unique keys, __hashed__ by keys                      |
| `std::unordered_map`      | collection of key-value pairs, __hashed__ by keys, keys are unique |
| `std::unordered_multiset` | collection of keys, hashed by keys                                 |
| `std::unordered_multimap` | collection of key-value pairs, hashed by keys                      |
 
#### Container Adaptors
Container adaptors provide a unique interface for __sequential containers__.

| Container             | Description                                                        |
|:----------------------|:-------------------------------------------------------------------|
| `std::stack`          | adapts a container to provide a stack (__LIFO__ data structure)
| `std::queue`          | adapts a container to provide a queue (__FIFO__ data structure)
| `std::priority_queue` | provides constant time $O(1)$ lookup of the largest (by default) element, at the expense of logarithmic $O(\log n)$ insertion and extraction.


## Algorithms
Algorithms overview.

| Algorithm                  | Assoc. Data Structures | C++ Implementation    | Use Cases / Notes |
|:---------------------------|:-----------------------|:----------------------|:----------|
| Recursion                  | Trees, Graphs          | N/A                   | - Depth First Search (DFS) of binary search trees (BSTs) and graphs.<br> - __Top-down__ dynamic programming. |
| Prefix Sum                 | N/A                    | `std::partial_sum`<br> `std::inclusive_scan` | `inclusive_scan` is a parallelized version of `partial_sum` that requires its `BinaryOp` to be associative, e.g. addition and mutliplication, but __not__ division. |
| Hash Function              | Hash Maps, Hash Tables | `std::hash`           | |
| Depth First Search (DFS)   | Binary Trees, Binary Search Trees | N/A | - The first major __tree/graph traversal algorithm__.<br> - 3 types of DFS: __pre-order__, __in-order__ and __post-order__.<br> &ensp; - __pre-order__ traversal processes nodes in a top-down, left-to-right order with the root node being handled first.<br> &ensp; - __in-order__ traversal processes nodes in a bottom-up, left-to-right order with the root node being processed only after the entire left subtree is processed. <br> &ensp; - __post-order__ traversal processes nodes in a bottom-up order that prioritizes processing __leaf nodes__ first. The root node is processed __last__. |
| Depth First Search (DFS) | Graphs | N/A | - DFS for graphs allows us to visit each node of a single connected component before exploring the next node from an unvisited component. |
| Breadth First Search (BFS) | Binary Trees, Binary Search Trees | N/A | - The second major __tree/graph traversal algorithm__.<br> - In BFS, we traverse __all nodes at a given depth__ before moving on to the next depth. |
| Breadth First Search (BFS) | Graphs | N/A | - BFS for graphs visits all nodes according to their distance from the starting node.<br> &ensp; - Every time a node is visited, BFS guarantees that it has been reached in the __minimum possible number of steps__.<br> - BFS is implemented via a __queue__. |
| Greedy                     | Heaps                  | N/A | Chose a __greedy__ algorithm when the problem calls for _greedily_ choosing the max/min element at each step.|
| Binary Search | - Binary Search Trees<br> - Any sorted range of elements, including a `std::deque` of __ordered__ elements. | `std::binary_search`<br> `std::upper_bound`<br> `std::lower_bound` | - __Searching__, __insertion__ and __removal__ can be done in $O(\log n)$.<br> - Consider using binary search when the problem provides a __sorted input__ and asks about the __insertion point__ of a new element.<br> - Anytime a problem asks us to find a __threshold__ where a task transitions from feasible to infeasible.<br> &ensp; - We can use binary search to efficiently halve the feasible space at each step. |
| Backtracking               | Trees, Graphs          | N/A | - Any problem that asks you to find __all__ of something, e.g.<br> &ensp; - __Permutations__, __subsets__ and __combinations__ (these can all be represented as trees).<br> &ensp; - Finding all possible paths between two nodes in a graph (DAG).<br> - These problem will constrain the input size to be __very small__ (`n <= ~15`).<br> - These problems will have a "tree" structure even if that's not immediately obvious.<br> &ensp; - solving the problem will require __pruning__ paths (subtrees) that cannot lead to a solution. |
| Dynamic Programming (DP)   | - Recursion for __top-down__ DP.<br> - Arrays for __bottom-up__ DP. | N/A | ... |  
