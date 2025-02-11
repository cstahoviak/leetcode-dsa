# Data Structures and Algorithms Overview
The following is an overview of the Data Structures and Algorithms covered by this course. The following tables details the data structure or algorithm, the relevent C++ implementations, and the applciable problem types that should be solved using that particular data structure or algorithm.

## Data Structures
Data Structures overview.

| Data Structure | C++ Implementation | Features | Applicable Problem Types |
|:---------------|:-------------------|:---------|:-------------------------|
| Hash Map/<br> Hash Table            | `std::map`<br> `std::unordered_map`<br> `std::set`<br> `std::unordered_set` | Adding, updating, removing and checking the existence of an element can __ALL__ be done in $O(1)$. | - Checking if an element/item exists.<br> - Counting/Frequency.| 


## Algorithms
Algorithms overview.

| Algorithm | Assoc. Data Structures | C++ Implementation    | Use Cases |
|:----------|:-----------------------|:----------------------|:----------|
| Greedy    | Heaps                  | `std::priority_queue` | Chose a __greedy__ algorithm when the problem calls for _greedily_ choosing the max/min element at each step.|