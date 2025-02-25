# Greedy Algorithms
A __greedy algorithm__ is any algorithm that makes the __locally optimal decision__ at every step.

- What does it mean to be __optimal__? That will be context-dependent. For example, if we are choosing some elements and the problem wants us to find the maximum sum of elements we take, then given a choice between two numbers, __it is optimal to take the larger one__.
- What makes a decision __local__?  A decision is local when it considers only the available options at the current step. It is based on the information it has at the time, without knowledge of future information or regard for future consequences.

__Most greedy problems will be asking for the maximum or minimum of something__, but not always.

__A lot of algorithms involving heaps can also be considered greedy__. A heap gives us a maximum or minimum element, and generally greedy approaches will be choosing max/min elements at each "step". Most of the algorithms we looked at in the __heaps__ module can be cosidered __greedy__.

Another thing to note is that __in many greedy problems, you will be sorting the input at the start__.

Typically, implementing a greedy algorithm is very easy. The hard part is realizing/proving that a greedy strategy actually works. In many problems, a greedy approach may lead to an answer that is very close to the correct answer, but still wrong.

 good example of this is the [traveling salesman problem (TSP)](https://en.wikipedia.org/wiki/Travelling_salesman_problem). A greedy approach to TSP yields an answer that is usually only wrong by about 25%, with a time complexity of $O(n^2)$. For an exact solution, we haven't found a classical algorithm faster than $O(2^n)$, and many people doubt such an algorithm exists.

 __"Greedy" isn't a data structure and it isn't any single algorithm either__, but more of a way to approach a problem. As such, it's hard to become "good" at greedy algorithms, and there isn't much to "learn" about it. __Greedy algorithms are usually very efficient__, so if you are given a problem that can be solved greedily, it's important to recognize it.