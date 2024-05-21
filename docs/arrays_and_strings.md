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
Two pointers is an extremely common technique used to solve array and string problems. It involves having two integer variables (or iterators) that both move along an iterable.

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
Sliding window is another common approach to solving problems related to arrays. A sliding window is actually implemented using two pointers! Before we start, we need to talk about the concept of a __subarray__.

### Subarrays
Given an array, a subarray is a contiguous section of the array. All the elements must be adjacent to each other in the original array and in their original order. For example, with the array `[1, 2, 3, 4]`, the subarrays (grouped by length) are:

- `[1]`, `[2]`, `[3]`, `[4]`
- `[1, 2]`, `[2, 3]`, `[3, 4]`
- `[1, 2, 3]`, `[2, 3, 4]`
- `[1, 2, 3, 4]`

A subarray can be defined by two indices, the start and end. Let's call the starting index the left bound and the ending index the right bound. Another name for subarray in this context is _window_.

### When Should We Use Sliding Window?
There is a very common group of problems involving subarrays that can be solved efficiently with sliding window. Let's talk about how to identify these problems.

__First__, the problem will either explicitly or implicitly define criteria that make a subarray _valid_. There are two components that define a _valid_ subarray:

1. __A constraint metric__. This is some attribute of a subarray. It could be the sum, the number of unique elements, the frequency of a specific element, or any other attribute.
2. __A numeric restriction__ on the constraint metric. This is what the constraint metric should be for a subarray to be considered _valid_.

__Second__, the problem will ask you to find valid subarrays in some way.

1. The most common task you will see is finding the _best_ valid subarray. The problem will define what makes a subarray better than another, e.g. a problem might ask you to find the longest valid subarray.
2. Another common task is finding the number of valid subarrays.

Whenever a problem description talks about subarrays, you should figure out if sliding window is a good option by analyzing the problem description. If you can find the things mentioned above, then it's a good bet.

### The Sliding Window Algorithm
In sliding window, we maintain two variables `left` and `right`, which at any given time represent the _current subarray_ under consideration.

Initially, we have `left = right = 0`, which means that the first subarray we look at is just the first element of the array on its own. We want to expand the size of our _window_, and we do that by incrementing `right`. When we increment `right`, this is like "adding" a new element to our window.

But what if after adding a new element, the subarray becomes invalid? We need to "remove" some elements from our window until it becomes valid again. To "remove" elements, we can increment `left`, which shrinks our window.

As we add and remove elements, we are "sliding" our window along the input from left to right. The window's size is constantly changing - it grows as large as it can until it's invalid, and then it shrinks. However, it always slides along to the right, until we reach the end of the input.

### Implementation
Below is pseudocode for a generalized implementation of the sliding window algorithm
```
def sliding_window(arr: Iterable):
    left = 0
    for (int right = 0; right < arr.length; right++):
        Do some logic to "add" element at arr[right] to window

        while WINDOW_IS_INVALID:
            Do some logic to "remove" element at arr[left] from window
            left++

        Do some logic to update the answer
```

### Why is Sliding Window Efficient?
For any array, how many subarrays are there? If the array has a length of `n`, there are `n` subarrays of length `1`. Then there are `n - 1` subarrays of length `2` (every index except the last one can be a starting index), `n - 2` subarrays of length `3` and so on until there is only `1` subarray of length `n`.

In terms of time complexity, any algorithm that looks at every subarray will be at least _O(n<sup>2</sup>)_, which is usually too slow. A sliding window guarantees a maximum of _2n_ window iterations - the right pointer can move _n_ times and the left pointer can move _n_ times. This means if the logic done for each window is _O(1)_, sliding window algorithms run in _O(n)_, which is __much faster__.

### Number of Subarrays
If a problem asks for the _number of subarrays_ that fit some constraint, we can still use the sliding window approach, but we need to use a neat math trick to calculate the number of subarrays.

### Fixed Window Size
In the examples above, our window size was dynamic. We tried to expand it to the right as much as we could while keeping the window within some constraint and removed elements from the left when the constraint was violated. Sometimes, a problem will specify a fixed window size.

```
function fixed_window_size(arr, k):
    curr = some data to track the window

    // build the first window
    for (int i = 0; i < k; i++)
        Do something with curr or other variables to build first window

    ans = answer variable, probably equal to curr here depending on the problem
    for (int i = k; i < arr.length; i++)
        Add arr[i] to window
        Remove arr[i - k] from window
        Update ans

    return ans
```

### Closing Notes
Sliding window is an extremely common and versatile pattern. We only scratched the surface here because many sliding window problems will also need to use a __hashmap__, which we will talk about in the hashing chapter. After learning about hashmaps, we'll look at some more sliding window problems.

## Prefix Sum

## More Common Patterns