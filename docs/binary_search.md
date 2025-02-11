# Binary Search
__Binary search is a search algorithm that runs in $O(\log n)$ in the worst case, where 
$n$ is the size of the search space__. For binary search to work, your search space usually needs to be __sorted__. Binary search trees, which we looked at in the trees and graphs chapter, are based on binary search.

Normally, binary search is done on an __array of sorted elements__. If you have a sorted array `arr` and an element `x`, then in $O(\log n)$ time and $O(1)$ space, binary search can:

- Find the index of `x` if it is in `arr`
- Find the first or last index at which `x` can be inserted such that `arr` remains sorted.

Here's the idea behind binary search:

Let's say that there is a sorted integer array `arr`, and you know that the number `x` is in it, but you don't know at what index. You want to find the position of `x`. Start by checking the element in the middle of `arr`. If this element is too small, then we know every element in the left half will also be too small, since the array is sorted. Similarly, if the element is too large, then every element in the right half will also be too large.

We can discard the half that can't contain `x`, and then repeat the process on the other half. We continue this process of cutting the array in half until we find `x`.

Because the search space is halved at every iteration, binary search's worst-case time complexity is $O(\log n)$. This makes it an extremely powerful algorithm as __logarithmic time is very fast compared to linear time__.

The C++ implementation of binary search looks like:

```
int binary_search(const vector<int>& arr, int target) {
  // left and right represent the inclusive bounds of the current search space.
  int left = 0;
  int right = int(arr.size()) - 1;

  while (left <= right) {
    // Calculate the middle of the current search space.
    // Equivalent to (left + right) / 2, but prevents overflow.
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      // The element has been found, return its index.
      return mid;
    }

    // Halve the search space by updating either left or right.
    if (arr[mid] > target) {
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }
  
  // Target is not in arr, but left is at the insertion point
  return left;
}
```
If your input has __duplicate elements__, you can modify the binary search template above to find either the __first or the last position__ of a given element, or the right-most __insertion point__.

__You should think about binary search anytime the problem provides anything sorted. $O(\log n)$ is extremely fast and binary search is usually a HUGE optimization__.

## On Arrays

## On Solution Spaces
