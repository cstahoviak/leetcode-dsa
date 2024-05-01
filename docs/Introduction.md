# Introduction

## Introduction to big-O
- _Big-O_ is a notation used to describe the computational complexity of an algorithm. The computational complexity of an algorithm is split into two parts: time complexity and space complexity.
  - The time complexity of an algorithm is the amount of time the algorithm needs to run relative to the input size. As the input size grows, how much longer does the algorithm take to complete?
  - The space complexity of an algorithm is the amount of memory allocated by the algorithm when run relative to the input size. As the input size grows, how much more memory does the algorithm use?
  - Typically, people care about the time complexity more than the space complexity, but both are important to know.

  Some example complexities include:
  - _O(1)_: A _constant time/space_ algorithm is the _best possible_ time/space complexity. Note that a complexity of _O(1)_ does __not__ necessarily mean that an algorithm is _fast_ (_O(5,000,000) = O(1)_), only that the runtime (or memory footprint) of the algorithm is independent of the input size.
  - _O(n)_
  - _O(n<sup>2</sup>)_
  - _O(2<sup>n</sup>)_
  - _O(log n)_: The _second best_ possible time/space complexity. A common time complexity is _O(n * log n)_ which is reasonably fast for most problems and also the time complexity of efficient sorting algorithms.
  - _O(n * m)_

  There are a few rules when it comes to calculating complexity.

  1. __We ignore constants__. It may be the case that algorithm A is 10x slower than algorithm B, i.e. we might be tempted to say that algo A is _O(10n)_ and algorithm B is _O(n)_. But in terms of time complexity, both A and B are _O(n)_ because complexity _only_ cares about how time to execute changes __as the input changes__, and for both A and B, if we 10x the size of the input, both algorithms will 10x in number of operations.
  2. We consider complexity as the input variables __tend to infinity__. For example, _O(2<sup>n</sup> + n<sup>2</sup> - 500n) = O(2<sup>n</sup>_ because as _n_ tends to infinity, _2<sup>n</sup>_ dominates.

  When talking about complexity, there are normally three cases:

  1. Best case scenario
  2. Average case
  3. Worst case scenario

  In most algorithms, all three of these will be equal, but some algorithms will have them differ. If you have to choose only one to represent the algorithm's time or space complexity, never choose the best case scenario. It is most correct to use the worst case scenario, but you should be able to talk about the difference between the cases.

### Analyzing Time Complexity: Logarithmic Time
_O(log n)_ means that somewhere in your algorithm, the input is being reduced by a percentage at every step. A good example of this is binary search, which is a searching algorithm that runs in _O(log n)_ time. With binary search, we initially consider the entire input (`n` elements). After the first step, we only consider `n/2` elements. After the second step, we only consider `n/4` elements, and so on. At each step, we are reducing our search space by 50%, which gives us a logarithmic time complexity.

### Analyzing Space Complexity


## Introduction to Recursion
Recursion is a problem solving method. While iterative algorithms use for loops and while loops to simulate repetition, recursive algorithms use function calls to simulate the same logic.

An important thing to understand about recursion is the order in which the code runs - the order in which the computer executes instructions. With an iterative program, it's easy - start at the top, and go line by line. With recursion, it can get confusing because calls can cascade on top of each other. Consider the following simple example:

```
function fn(i):
1.  if i > 3:
2.    return

3.  print(i)
4.  fn(i + 1)
5.  print(f"End of call where i = {i}")
6.  return

fn(1)
```

If you ran this code, you would see the following in the output that illustrates how recursives code _moves back up_ once the recursion has finished.

```
1
2
3
End of call where i = 3
End of call where i = 2
End of call where i = 1
```

A classic example of recursion can be used to get the _n<sup>th</sup>_ (zero-indexed) Fibonacci number, _F<sub>n</sub> = F<sub>n-1</sub> + F<sub>n-2</sub>_ :

```
function fibonacci(n):
    if n <= 1:
        return n

    oneBack = fibonacci(n - 1)
    twoBack = fibonacci(n - 2)
    return oneBack + twoBack
```

## Notes before starting