# leetcode-dsa
Repository for working through Leetcode's Data Structures &amp; Algorithms course. See [docs/README.md](/docs/README.md) for a comprehensive overview of all topics covered by this course.

## What does this course contain?
The course is split up into 13 chapters. The bulk of the content is within chapters 2-11, each of which focuses on a specific data structure or algorithm:

- Arrays and strings
- Hashmaps and sets
- Linked lists
- Stacks and queues
- Trees and graphs
- Heaps
- Greedy algorithms
- Binary search
- Backtracking
- Dynamic programming

__These are the most important and most common data structures and algorithms for coding interviews.__

In each of these chapters, you can expect to find:

1. Explanation of the data structure/algorithm, what it's good at doing, how it can be used to solve problems, and details behind implementation & time/space complexity. If it's a data structure, we will also talk about the interface and how to use it.
2. Common patterns and tricks related to the data structure or algorithm.
3. Several example walkthroughs of relevant problems to help illustrate the concepts supplemented with visual aids, concise explanations, and time/space complexity analysis.
4. Precisely curated practice problems to help you build muscle memory with what you've learned.
5. We also provide a list of bonus problems at the end of each chapter. These problems are optional but can be used to reinforce the ideas learned in each chapter.

The 12th chapter contains several useful tools that can be used moving forward. There are code templates for all common patterns, cheatsheets regarding time and space complexities, and a flowchart that can be used as a general guideline when trying to figure out what data structure or algorithm should be used. We will also break down the stages of a coding interview and what you should do at each stage. To demonstrate this advice, there are example FAANG mock interview videos.

The final chapter is a bonus chapter where we will look into a few more techniques that aren't common/broad enough to warrant their own chapter.

## Building
To enable parallel execution of `std::transform_reduce` in `dsa::algorithms::binary_search::smallest_divisor`, we need to make sure that [Intel Threading Building Blocks (TBB)](https://github.com/uxlfoundation/oneTBB/tree/master) is installed. We can install `tbb` via `apt`.

```
sudo apt install libtbb-dev
```

Build the __apps__, __unit tests__ and __python bindings__ via the standard CMake build process.

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j8
```

### Running the Unit Tests
Once the tests have been built, they can be run by doing:

```
cd build
./cpp/test/dsa_tests
```

## Typos & Corrections
1. (Introduction, Analyzing time complexity) "This for loop iterates 500,000 times, which means each __inner__ for loop iteration costs..."
2. 
