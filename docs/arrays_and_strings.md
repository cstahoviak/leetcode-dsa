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
Two pointers is an extremely common technique used to solve array and string problems. It involves having two integer variables that both move along an iterable.

```
def two_pointers(Iterable[arr]):
  left = 0
  right = len(arr) - 1

  while left < right:
    // Some problem-specific logic
    // Do one of the following:
      1. left++
      2. right--
      3. left++ AND right--
```
The strength of this technique is that we will never have more than 
_O(n)_ iterations for the while loop because the pointers start _n_ away from each other and move at least one step closer in every iteration. Therefore, if we can keep the work inside each iteration at 
_O(1)_, this technique will result in a linear runtime, which is usually the best possible runtime. A common example of this example is determining if a word is a palindrome, e.g. "racecar".

```
def two_pointers(arr: Iterable):
  left = 0
  right = len(arr) - 1

  while left < right:
    if arr[left] != arr[right]:
      return False
    left += 1
    right -= 1

  return True
```

### Closing Notes
Remember that the methods laid out here are just guidelines. For example, in the first method, we started the pointers at the first and last index, but sometimes you might find a problem that involves starting the pointers at different indices. Two pointers just refers to using two integer variables to move along some iterables. The strategies we looked at in this article are the most common patterns, but always be on the lookout for a different way to approach a problem. There are even problems that make use of "three pointers".


## Sliding Window

## Prefix Sum

## More Common Patterns