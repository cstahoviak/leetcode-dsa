# Arrays and Strings
In terms of algorithm problems, arrays (1D) and strings are very similar: they both represent an ordered group of elements. Most algorithm problems will include either an array or string as part of the input, so it's important to be comfortable with the basic operations and to learn the most common patterns.

Technically, an array can't be resized. A dynamic array, or list, can be. In the context of algorithm problems, usually when people talk about arrays, they are referring to dynamic arrays.

Similarly, strings are implemented differently between languages. In Python and Java, they are __immutable__. In C++, they are __mutable__. It's important to know the details behind arrays and strings for the language you plan on using in interviews.

- __Mutable__: A type of data that can be changed.
- __Immutable__: A type of data that cannot be changed. If you want to change something immutable, you will need to recreate the entire thing.

A quick look at the complexity of array and string operations:

| Operation                | Array/List (mutable) | String (immutable) |
| :----------------------- | :------------------: | :----------------: |
| Append to end            | *_O(1)_              | _O(n)_             |
| Pop from end             | _O(1)_               | _O(n)_             |
| Insertion (not from end) | _O(n)_               | _O(n)_             |
| Deletion (not from end)  | _O(n)_               | _O(n)_             |
| Modify element           | _O(1)_               | _O(n)_             |
| Random access            | _O(1)_               | _O(1)_             |
| Does element exist?      | _O(n)_               | _O(n)_             |

## Two Pointers
TODO: left off here.

## Sliding Window

## Prefix Sum

## More Common Patterns