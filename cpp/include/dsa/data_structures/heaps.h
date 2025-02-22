#pragma once
/**
 * @file heaps.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/utils.h"

#include <cmath>
#include <cstddef>
#include <queue>

namespace dsa::data_structures::heaps
{
  /**
   * @brief 1962. Remove Stones to Minimize Total (Medium)
   * https://leetcode.com/problems/remove-stones-to-minimize-the-total/
   * 
   * You are given a 0-indexed integer array piles, where piles[i] represents
   * the number of stones in the ith pile, and an integer k. You should apply
   * the following operation exactly k times:
   * 
   * Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
   * 
   * Notice that you can apply the operation on the same pile more than once.
   * 
   * @tparam T 
   * @param piles A vector where each element represents a pile of stones.
   * @param k The number of reduction operations to perform.
   * @return int The minimum possible total number of stones remaining after
   * applying the k operations.
   */
  template<typename T>
  int min_stone_sum(const std::vector<T>& piles, int k) {
    // Create a max heap to store store the piles
    std::priority_queue<T> max_heap(piles.cbegin(), piles.cend());

    // Pre-sum the total number of stones across all piles
    T total{0};
    for ( const T& pile : piles) {
      total += pile;
      // max_heap.push(pile);
    }

    // Perform k pile-shrinking operations
    for ( size_t idx = 0; idx < k; idx++ ) {
      // Base case: if there are no more stones left in the largest pile, there
      // are no more stones left in any of the piles.
      if ( max_heap.top() == 0 ) {
        return 0;
      }

      // Remove the largest pile
      const T max_pile = max_heap.top();
      max_heap.pop();

      // Compute the number of stones to be removed and update the pile size.
      const T n_remove = std::floor(max_pile / 2);
      total -= n_remove;
      max_heap.push(max_pile - n_remove);
    }

    return total;
  }

  /**
   * @brief 1167. Minimum Cost to Connect Sticks (Medium)
   * https://leetcode.com/problems/minimum-cost-to-connect-sticks/
   * 
   * You have some number of sticks with positive integer lengths. These lengths
   * are given as an array 'sticks', where sticks[i] is the length of the ith
   * stick.
   * 
   * You can connect any two sticks of lengths x and y into one stick by paying
   * a cost of x + y. You must connect all the sticks until there is only one
   * stick remaining.
   * 
   * @tparam T 
   * @param sticks 
   * @return int The minimum cost of connecting all sticks into one stick.
   */
  template<typename T>
  int connect_sticks(const std::vector<T>& sticks) {
    // Use a min heap to store the stick lengths.
    std::priority_queue<T, std::vector<T>, std::greater<T>> min_heap(
      sticks.cbegin(), sticks.cend());
    
    // Store the total "cost"
    T cost{0};

    while ( min_heap.size() > 1 ) {
      // Remove the smallest two sticks and sum them to get the new stick's length
      T new_length = min_heap.top();
      min_heap.pop();
      new_length += min_heap.top();
      min_heap.pop();

      // Update the cost and push the new stick onto the queue.
      cost += new_length;
      min_heap.push(new_length);
    }

    return cost;
  }

  /**
   * @brief 215. Kth Largest Element in an Array (Medium)
   * https://leetcode.com/problems/kth-largest-element-in-an-array/
   * 
   * Given an integer array nums and an integer k, return the kth largest
   * element in the array. Solve without sorting.
   * 
   * @tparam T 
   * @param nums 
   * @param k 
   * @return T The kth largest element in the array.
   */
  template<typename T>
  T kth_largest(const std::vector<T>& nums, int k) {
    // Create a min heap to retrieve the kth largest element. The top element
    // in the (min) heap will be the smallest value in the heap.
    std::priority_queue<T, std::vector<T>, std::greater<T>> min_heap;

    // Copy the vector of nums into the min heap
    for ( const T& val : nums ) {
      min_heap.push(val);

      // Ensure that the heap does not grow beyond k elements
      if ( min_heap.size() > k ) {
        min_heap.pop();
      }
    }

    // The top element of the heap will be the kth largest value in nums.
    return min_heap.top();
  }

  /**
   * @brief 973. K Closest Points (Medium)
   * https://leetcode.com/problems/k-closest-points-to-origin/
   * 
   * Given an array of points where points[i] = [xi, yi] represents a point on
   * the X-Y plane and an integer k, return the k closest points to the origin
   * (0, 0).
   * 
   * @tparam T 
   * @param points A vector of 2D points.
   * @param k The size of the return vector.
   * @return std::vector<std::vector<T>> The k-closest points to the origin.
   */
  template<typename T>
  std::vector<std::vector<T>> k_closest(
    const std::vector<std::vector<T>>& points,
    int k)
  {
    LOG("point.size() = " << points.size() << ",\tk = " << k); 
    // Base case: points.size() == k
    if ( points.size() == k ) {
      return points;
    }

    // Create the euclidean distance function. We can use the squared euclidean
    // distance instead of taking a sqrt to save some computation time.
    auto distance = [](const std::vector<T>& point) {
      // return std::sqrt(std::pow(point[0], 2) + std::pow(point[1], 2));
      return std::pow(point[0], 2) + std::pow(point[1], 2);
    };

    // Create the comparison function.
    // TODO: Can we be more efficient than using sqrt and pow?
    auto compare = [&distance](const std::vector<T>& p1, const std::vector<T>& p2) {
      return distance(p1) < distance(p2);
    };

    // Create a max heap to store the k smallest distances. The top element in
    // the (max) heap will be the kth farthest point from the origin.
    // Start by pushing the first k points onto the queue.
    std::priority_queue<std::vector<T>, std::vector<std::vector<T>>, decltype(compare)> 
      max_heap(points.cbegin(), points.cbegin() + k, compare);
    LOG("max_heap.size() = " << max_heap.size());

    for (size_t idx = k; idx < points.size(); idx++) {
      // Push the next element on to the queue (growing its size to k+1), and
      // then pop the top (max) element.
      LOG("Pushing points[" << idx << "] (" << points[idx][0] << ", " << 
        points[idx][1] << ") onto the queue.");
      max_heap.push(points[idx]);
      max_heap.pop();
    }

    // Create the return vector
    std::vector<std::vector<T>> result(k);
    size_t idx{0};
    while ( !max_heap.empty() ) {
      const std::vector<T>& top = max_heap.top();
      LOG("Adding (" << top[0] << ", " << top[1] << "), dist = " << distance(top));
      result[idx] = max_heap.top();
      max_heap.pop();
      idx++;
    }

    return result;
  }

  /**
   * @brief 973. K Closest Points (Medium)
   * https://leetcode.com/problems/k-closest-points-to-origin/
   * 
   * An attempt to speed-up the k_closest algorithm by reducing the
   * number of copies of individual elements of 'points' and the number of
   * evaluations of the 'distance' function.
   * 
   * Success! This implementation resulted in a ~3x runtime speed-up as compared
   * to heaps::k_closest (from ~95ms down to ~35ms). There is also a memory
   * savings of ~10MB.
   * 
   * @tparam T 
   * @param points 
   * @param k 
   * @return std::vector<std::vector<T>> 
   */
  template<typename T>
  std::vector<std::vector<T>> k_closest_fast(
    const std::vector<std::vector<T>>& points,
    int k)
  {
    // Base case: points.size() == k
    if ( points.size() == k ) {
      return points;
    }

    // Create the euclidean distance function. We can use the squared euclidean
    // distance instead of taking a sqrt to save some computation time.
    auto distance = [](const std::vector<T>& point) -> float {
      // return std::sqrt(std::pow(point[0], 2) + std::pow(point[1], 2));
      return std::pow(point[0], 2) + std::pow(point[1], 2);
    };

    // Create a max heap to store the k smallest distances. The top element in
    // the (max) heap will be the kth farthest point from the origin. Each pair
    // represents the points distance from the origin and its index in the
    // 'points' vector. Note that we can choose to use float here (rather than
    // double) and uint16_t (rather than size_t) for an additional space savings.
    using Pair = std::pair<float, uint16_t>;
    std::priority_queue<Pair> max_heap;

    // Start by pushing the first k points onto the queue.
    for ( uint16_t idx = 0; idx < k; idx++ ) {
      max_heap.push(std::make_pair(distance(points[idx]), idx));
    }
    LOG("max_heap.size() = " << max_heap.size());

    for (uint16_t idx = k; idx < points.size(); idx++) {
      // Push the next element on to the queue (growing its size to k+1), and
      // then pop the top (max) element.
      LOG("Pushing points[" << idx << "] (" << points[idx][0] << ", " << 
        points[idx][1] << ") onto the queue.");
      max_heap.push(std::make_pair(distance(points[idx]), idx));
      max_heap.pop();
    }

    // Create the return vector
    std::vector<std::vector<T>> result(k);
    uint16_t idx{0};
    while ( !max_heap.empty() ) {
      result[idx] = points[max_heap.top().second];
      max_heap.pop();
      idx++;
    }

    return result;
  }

  /**
   * @brief 703. Kth Largest Element in a Stream (Easy)
   * https://leetcode.com/problems/kth-largest-element-in-a-stream/
   * 
   * Implement a class which, for a given integer k, maintains a stream of test
   * scores and continuously returns the kth highest test score after a new
   * score has been submitted. More specifically, we are looking for the kth
   * highest score in the sorted list of all scores.
   * 
   * @tparam T 
   */
  template<typename T>
  class KthLargest
  {
    public:
      /**
       * @brief Initializes the object with the integer 'k' and the stream of
       * test scores 'nums'.
       */
      KthLargest(int k, const std::vector<T>& nums);

      /**
       * @brief Adds a new test score 'val' to the stream and returns the
       * element representing the kth largest element in the pool of test scores
       * so far.
       * 
       * @param val 
       * @return T 
       */
      T add(T val);
    
    private:
      // Use a min-heap to store the scores.
      std::priority_queue<T, std::vector<T>, std::greater<T>> scores_;
  };

  /**
   * @brief This is a dummy class to explore separating a template class'
   * declaration (.h) from its definition (.cpp). The key piece to making it
   * work comes down adding "explicit template instantiation" to the cpp file.
   * 
   * @tparam T 
   */
  template <typename T>
  class MyTemplateClass
  {
    public:
      MyTemplateClass(T value);
      T getData() const;
      void setData(T value);

    private:
      T data;
  };

} // end namespace dsa::data_structures::heaps