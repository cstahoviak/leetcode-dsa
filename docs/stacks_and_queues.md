## Stacks & Queues
A stack is an ordered collection of elements where elements are only added and removed from the same end. In the physical world, an example of a stack would be a stack of plates in a kitchen - you add plates or remove plates from the top of the pile. In the software world, a good example of a stack is the history of your current browser's tab.

Another term used to describe stacks is __LIFO__, which stands for __last in, first out__. The last (most recent) element placed inside is the first element to come out.

Aany dynamic array can implement a stack. Typically, inserting into a stack is called `pushing` and removing from a stack is called `popping`. Stacks will usually also come with operations like `top`, which allow for inspection/retrieval of the element at the top of the stack.

The time complexity of stack operations is dependent on the implementation. If you use a dynamic array, which is the most common and easiest way, then the time complexity of your operations is the same as that of a dynamic array. $O(1)$ `push`, `pop`, and random access `[]`, and $O(n)$ search. Sometimes, a stack may be implemented with a linked list with a tail pointer.

The characteristic that makes something a "stack" is that you can only add and remove elements from the same end. It doesn't matter how you implement it, a "stack" is just an abstract interface.

__Stacks and recursion are very similar__. This is because recursion is actually done using a stack. Function calls are pushed on a stack. The call at the top of the stack at any given moment is the "active" call. On a return statement or the end of the function being reached, the current call is popped off the stack.

## String Problems

## Queues
While a stack followed a __LIFO__ pattern, a queue follows __FIFO (first in first out)__. In a stack, elements are added and removed from the same side. __In a queue, elements are added and removed from opposite sides__. Like with a stack, there are multiple ways to implement a queue, but the important thing that defines it is the abstract interface of adding and removing from opposite sides.

Queues are trickier to implement than stacks if you want to maintain good performance. Like a stack, you could just use a dynamic array, but operations on the front of the array (adding or removal) are $O(n)$, where $n$ is the size of the array. Adding to a queue is called __enqueue__ and deletions are called __dequeue__. If you want these operations to be $O(1)$, you'll need a more sophisticated implementation.

One way to implement an efficient queue is by using a doubly linked list__. Recall that with a doubly linked list, if you have the pointer to a node, y__ou can add or delete at that location in $O(1)$__. A doubly linked list that maintains pointers to the head and tail (both ends, usually with sentinel nodes) can implement an efficient queue.

There is also a data structure called a __deque__, short for __double-ended queue__, and pronounced "deck". In a deque, you can add or delete elements from both ends. A normal queue designates adding to one end and deleting to another end.

For algorithm problems, queues are less common than stacks, and the problems are generally more difficult. __The most common use of a queue is to implement an algorithm called breadth-first search (BFS)__, which we will learn about in a future chapter. Outside of BFS, unlike stack, there aren't many problems whose main focus is a queue - we'll still look at a few examples, but __keep in mind that a queue is mostly used to implement BFS__.

## Monotonic

_Note: if you're a beginner and struggle to grasp this article, don't be discouraged! This is one of the most difficult concepts taught in this course. Good news is, the concept is not super common in interviews, but still a good one to know. If you find yourself stuck, don't worry about moving on and coming back later._

__Monotonic__: (of a function or quantity) varying in such a way that it either never decreases or never increases.

A monotonic stack or queue is one whose elements are always sorted. It can be sorted either ascending or descending, depending on the algorithm. Monotonic stacks and queues maintain their sorted property by removing elements that would violate the property before adding new elements.

