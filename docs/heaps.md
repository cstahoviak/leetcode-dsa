# Heaps

A heap is a data structure that is an implementation of the [priority queue](https://en.wikipedia.org/wiki/Priority_queue).

Note that __a priority queue is an abstract data structure__. A __heap__ is one of many ways to _implement_ a priority queue. However, people often use the two terms interchangeably. In this course, we will use the term __heap__.

A heap is a container that stores elements, and supports the following operations:

| Modifier | Operation                    | Time Complexity |
|:---------|:-----------------------------|:---------------:|
| `push`   | Add an element               | $O(\log n)$     |
| `pop`    | Remove the "minimum" element | $O(\log n)$     |
| `top`    | Access the "minimum" element | $O(1)$          |

A heap can also find the `max` element instead of the `min` element. If a heap is configured to find/remove the `min` element, it's called a __min heap__. If it's configured to find/remove the `max` element, it's called a __max heap__.

__The ability to find the min/max element in constant time, while only needing logarithmic time to maintain this ability through changes makes a heap an extremely powerful data structure.__

## How is a Heap Implemented?
The most popular heap implemenation is a __binary heap__ that uses an __array__ as the underlying data structure. The idea is that each element in the array is a node in the tree. The __smallest element in the tree is the root__, and the following property is maintained at every node: if `A` is the parent of `B`, then `A.val <= B.val`.

### A note on how array indexing for a heap is maintained
The parent-child relationships are done using math with the indices. The first element at index `0` is the root, then the elements at indices `1` and `2` are the root's children, the elements at indices `3` and `4` are the children of the element at index `1` and the elements at indices `5` and `6` are the children of the element at index `2`, and so on. __If a node is at index `i`, then its children are at indices `2i + 1` and `2i + 2`__. When elements are added or removed, operations are done to maintain the aforementioned property of `parent.val <= child.val`. __The number of operations needed scales logarithmically with the number of elements in the heap, and the process is known as "bubbling up"__.

An existing array of elements can also be converted into a heap in linear time, although the process is complicated. Luckily, some major programming languages have built-in methods to do this, e.g. `std::make_heap`.

## Heap Examples
A heap is an amazing tool whenever you need to repeatedly find the maximum or minimum element. It can handle insertions and removals all while maintaining the max/min property, all in logarithmic time.

### Example 1: (1046) [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)
You are given an array of integers stones where stones[i] is the weight of the $i^{th}$ stone. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights `x` and `y` with `x <= y`. If `x == y`, then both stones are destroyed. If `x != y`, then `x` is destroyed and `y` loses `x` weight. Return the weight of the last remaining stone, or 0 if there are no stones left. We can use `std::priority_queue` to implement the solution:

```
int last_stone_weight(const std::vector<int>& stones) {
  // std::priority_queue implements a max heap by default
  priority_queue<int> heap(stones.begin(), stones.end());
  
  while (heap.size() > 1) {
    int first = heap.top();
    heap.pop();
    int second = heap.top();
    heap.pop();
    if (first != second) {
      heap.push(first - second);
    }
  }
  
  return heap.empty() ? 0: heap.top();
}
```

### Two Heaps
Using multiple heaps is uncommon and the problems that require it are generally on the harder side. __If a problem involves finding a median, it's a good thing to consider__.

## Top K Elements
__One common type of interview problem is one that asks you to find the `k` best elements__, with "best" being defined by the problem. The easiest way to solve these problems is to sort the input according to the criteria defined in the problem, and then return the top `k` elements. This has a time complexity of $O(n \log n)$ if n is the length of the input.

Using a heap, we can instead find the top k elements in $O(n \log k)$. Logically, `k < n`, so this is an improvement.

Where exactly does the time complexity improvement come from? Create a max heap at the start, iterate over the input while pushing every element on the heap (according to the problem's criteria), and pop from the heap once the size exceeds `k`. Because the heap's size is bounded by `k`, then all heap operations are at worst $O(\log k)$. Multiply this by n iterations to get $O(n \log k)$. Because we are using a max heap and we are popping from the heap according to the problem criteria, pops remove the "worst" elements, so at the end, the `k` "best" elements will remain in the heap.
