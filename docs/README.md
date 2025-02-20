# Data Structures and Algorithms Overview
The following is an overview of the Data Structures and Algorithms covered by this course. The following tables detail the data structure or algorithm, the relevent C++ implementations, and the applciable problem types that should be solved using that particular data structure or algorithm.

## Data Structures
Data Structures overview.

| Data Structure       | C++ Implementation | Features | Applicable Problem Types |
|:---------------------|:-------------------|:---------|:-------------------------|
| Hash Map/ Hash Table | `std::map`<br> `std::unordered_map`<br> `std::set`<br> `std::unordered_set`<br> `std::multimap`<br> `std::unordered_multimap` | - Adding, updating, removing and checking the existence of an element can __ALL__ be done in $O(1)$.<br> - Only `multimaps` allow duplicate keys. | - Checking if an element/item exists.<br> - Counting/Frequency.|
| Linked List          | N/A |  |  |
| Stack                | `std:stack` | |
| Queue                | `std::queue` | |
| Deque                | `std::deque` | Constant time $O(1)$ insertion and removal at both ends. |
| Binary Tree          | N/A
| Graph                | N/A
| Heap                 | `std::priority_queue`<br> `std::make_heap` | - Accessing the "top" (min/max) element in $O(1)$.<br> - Adding a new element or removing the "top" element in $O(\log n)$.| - Use a heap to repeatedly find the min/max element.<br> - Any type of problem that asks for the __top `k` elements__. |


## Algorithms
Algorithms overview.

| Algorithm                  | Assoc. Data Structures | C++ Implementation    | Use Cases / Notes |
|:---------------------------|:-----------------------|:----------------------|:----------|
| Recursion                  | Trees, Graphs          | N/A                   | |
| Prefix Sum                 | N/A                    | `std::partial_sum`<br> `std::inclusive_scan` | `inclusive_scan` is a parallelized version of `partial_sum` that requires its `BinaryOp` to be associative, e.g. addition and mutliplication, but __not__ division. |
| Hash Function              | Hash Maps, Hash Tables | `std::hash`           | |
| Depth First Search (DFS)   | Trees, Graphs          | N/A                   | |
| Breadth First Search (BFS) | Trees, Graphs          | N/A                   | |
| Greedy                     | Heaps                  | N/A | Chose a __greedy__ algorithm when the problem calls for _greedily_ choosing the max/min element at each step.|
| Binary Search | Sorted range of elements | `std::binary_search`<br> `std::upper_bound`<br> `std::lower_bound` | - Consider using binary search when the problem provides a __sorted input__ and asks about the __insertion point__ of a new element.<br> - Anytime a problem asks us to find a __threshold__ where a task transitions from feasible to infeasible.<br> &ensp; - We can use binary search to efficiently halve the feasible space at each step.|
| Backtracking               | Trees, Graphs          | N/A | Any problem that asks you to find __all__ of something, e.g.<br> &ensp; - __Permutations__, __subsets__ and __combinations__ (these can all be represented as trees).<br> &ensp; - Finding all possible paths between two nodes in a graph (DAG). |
