# Hashing

## Introduction to Hash Maps
First, let's talk about __data structures__. A data structure can be thought of as consisting of two components: the __interface__ and the __implementation__. 

The __interface__ is like a contract that specifies how we can interact with the data structure - what operations we can perform on it, what inputs it expects, and what outputs we can expect. For example, consider a dynamic array. The interface would include operations like _appending_, _insertion_, _removal_, _updating_, and more. These operations are well-defined and have specific rules that we must follow when we use them.

The __implementation__ is the code that actually makes the data structure work. This is where the details of how the data is stored and how the operations are performed come into play. For example, the implementation of a dynamic array might involve allocating memory for the list, tracking the size, and rearranging or copying the elements when an operation like `push` is called. For many data structures, the implementation can be quite complex, involving intricate algorithms and data manipulation.

In this chapter, we are going to talk about __hash maps__ and __sets__, which are implemented using __hashing__.

__A hash function is a function that takes an input and deterministically converts it to an integer that is less than a fixed size set by the programmer__. Inputs are called __keys__ and the same input will always be converted to the same integer.

### What is the Point of a Hash Function?
We know that arrays have $O(n)$ random access. Given an arbitrary index, we can access and update its value in the array in __constant time__. The main constraint with arrays is that they are a __fixed size__, and the indices have to be integers. Because hash functions can convert any input into an integer, we can effectively remove the constraint of indices needing to be integers. __When a hash function is combined with an array, it creates a hash map, also known as a hash table or dictionary__.

A hash map is probably the most important concept in all of algorithm interviewing. It is extremely powerful and allows you to reduce the time complexity of an algorithm by a factor of $O(n)$ for a huge amount of problems. To summarize:

- A hash map is an __unordered data structure__ that stores __key-value pairs__.
- A hash map can perform the following operations in $O(1)$:
  - Add, update or remove elements.
  - Check to see if a given __key__ exists in the map.
- You can iterate over both the keys and values of a hash map, but the iteration won't necessarily follow any order.

__Note__: An __ordered data structure__ is one where the insertion order is _remembered_. An __unordered data structure__ is one where the insertion order is not relevant.

### Comparison with Arrays
In terms of time complexity, hash maps blow arrays out of the water. The following operations are all $O(1)$ for a hash map:

- Add an element and associate it with a value
- Delete an element if it exists
- Check if an element exists

A hash map also has many of the same useful properties as an array with the same time complexity:

- Get length/number of elements
- Updating values
- Iterate over elements

### Collisions
__When different keys convert to the same integer, it is called a collision__. Without handling collisions, older keys will get overridden and data will be lost. There are multiple ways to handle collisions, but here we'll talk about a common one called __chaining__.

When using chaining, we store linked lists inside the hash map's array instead of the elements themselves. The linked list nodes store both the key and the value. If there are collisions, the collided key-value pairs are linked together in a linked list. Then, when trying to access one of these key-value pairs, we traverse through the linked list until the key matches.

## Checking for Existence
One of the most common applications of a hash table or set is determining if an element exists in $O(1)$. Since an array needs $O(n)$ to do this, using a hash map or set can improve the time complexity of an algorithm greatly, usually from $O(n^2)$ to $O(n)$.

Anytime you find your algorithm running `if ... in ...`, then consider using a hash map or set to store elements to have these operations run in $O(1)$.

## Counting
Counting is a very common pattern with hash maps. By "counting", we are referring to tracking the frequency of things. This means our hash map will be mapping keys to integers. Anytime you need to count anything, think about using a hash map to do it.

Using a hash map to store the frequency of any key we want allows us to __solve sliding window problems that put constraints on multiple elements__. We know from earlier that the time complexity of sliding window problems are $O(n)$ if the work done inside each for loop iteration is amortized constant, which is the case here due to a hash map having $O(1)$ operations. The hash map occupies $O(k)$ space, as the algorithm will delete elements from the hash map once it grows beyond $k$.

