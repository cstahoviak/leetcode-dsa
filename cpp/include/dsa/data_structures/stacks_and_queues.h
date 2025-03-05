#pragma once
/**
 * @file stacks_and_queus.h
 * @author Carl Stahoviak
 * @brief Stack & Queues!
 * @version 0.1
 * @date 2025-01-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/utils.h"

#include <cstddef>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <string_view>

namespace dsa::data_structures::stacks_and_queues
{
  /**
   * @brief 71. Simplify Path (Medium)
   * https://leetcode.com/problems/simplify-path/
   * 
   * You are given an "absolute path" for a Unix-style file system, which
   * always begins with a slash '/'. Your task is to transform this absolute
   * path into its "simplified canonical path".
   * 
   * The rules of a Unix-style file system are as follows:
   * - The path must start with a single slash '/'.
   * - A single period '.' represents the current directory.
   * - A double period '..' represents the previous/parent directory.
   * - Multiple consecutive slashes such as '//' and '///' are treated as a
   * single slash '/'.
   * - Any sequence of periods that does not match the rules above should be
   * treated as a valid directory or file name. For example, '...' and '....'
   * are valid directory or file names.
   * 
   * The simplified canonical path should follow these rules:
   * - The path must start with a single slash '/'.
   * - The path must not end with a slash '/', unless it is the root directory.
   * - The path must not have any single or double periods ('.' and '..') used
   * to denote current or parent directories.
   * 
   * Interestingly, this is very similar to what the 'cd' command is doing
   * under the hood each time it parses a directory path.
   * 
   * @param path 
   * @return std::string 
   */
  inline std::string simplify_path(const std::string& path) {
    // TODO: Use dsa::utils::split_string to split the string on '/'.
    // std::vector<std::string> split = dsa::utils::split_string(path, "/");

    // This can't actually be solved correctly with a stack - using a stack will
    // result in building the final path in reverse order. So let's use a deque
    // instead. We'll choose to use a deque because we can build the string
    // component-wise by pushing to and popping from (when we encounter a "..")
    // the back of the deque. Finally, we can build the result string by
    // sequentially popping from the front of the deque.
    std::deque<std::string> deque;

    // Use a stringstream to process the input string by splitting on '/'.
    std::stringstream ss(path);
    std::string temp;

    while( getline(ss, temp, '/') ) {
      if ( temp.empty() ) {
        // The first component will always be an empty string. Also, "//" will
        // have an empty string between each "/".
        continue;
      }

      // Deal with ".." first.
      if ( temp == ".." ) {
        if ( !deque.empty() ) {
          // If we encounter a ".." AND the deque is not empty, pop the last element.
          LOG("Removing '" << deque.back() << "' from back of deque.");
          deque.pop_back();
        }
      }
      else if ( temp != "." ) {
        // For all other filename components, add it to the deque so long as
        // it's not a "." since the "." has no effect.
        LOG("Adding '" << temp << "' to back of deque.");
        deque.push_back(temp);
      }
    }

    // Build the result string by sequentially popping from the front of the deque.
    std::string result;
    while ( !deque.empty() ) {
      result += "/" + deque.front();
      LOG("Result string: " << result);
      deque.pop_front();
    }

    // If the result string is empty, return "/"
    return ( result.empty() ) ? "/" : result;
  }

  /**
   * @brief 1544. Make the String Great (Easy)
   * https://leetcode.com/problems/make-the-string-great/
   * 
   * A good string is a string which doesn't have two adjacent characters s[i] 
   * and s[i + 1] where s[i] is a lower-case letter and s[i + 1] is the same
   * letter but in upper-case or vice-versa.
   * 
   * To make the string good, you can choose two adjacent characters that make
   * the string bad and remove them. You can keep doing this until the string
   * becomes good.
   * 
   * Return the string after making it good. 
   * 
   * @param s An string containing only lower and upper case English letters.
   * @return std::string 
   */
  inline std::string make_great(const std::string& s) {
    // Again, we're gonna use a deque here because of the need to build the
    // result string from start to finish (and not in reverse order as a
    // stack would dictate).
    // std::deque<char> deque;

    // We an take advantage of the fact that std::string supports access,
    // insertion, and removal at the back (back, push_back and pop_back), and 
    // use a std::string to build the result without having to populate a deque
    // and then build the result string from the deque.
    std::string result;
    result.reserve(s.size());

    for ( const char& character : s ) {
      // Note: Upper and lower case characters of the same letter have an ASCII
      // offset of exactly 32.
      if ( !result.empty() && std::abs(character - result.back()) == 32 ) {
        // If the string is not empty, and we've encountered a sequential upper
        // and lowercase character of the same letter, remove the previously
        // added letter.
        result.pop_back();
      }
      else {
        result.push_back(character);
      }
    }

    // Build the output string
    // std::string result;
    // result.reserve(deque.size());
    // while ( !deque.empty() ) {
    //   result += deque.front();
    //   deque.pop_front();
    // }

    return result;
  }

  /**
   * @brief 346. Moving Average from Data Stream (Easy)
   * https://leetcode.com/problems/moving-average-from-data-stream/
   * 
   * Given a stream of integers and a window size, calculate the moving average
   * of all integers in the sliding window.
   * 
   */
  class MovingAverage
  {
    public:
      MovingAverage(size_t size) : size_(size) {}

      /**
       * @brief Returns the moving average of the last 'size' values of the
       * stream.
       * 
       * @param val The next value in the data stream.
       * @return double 
       */
      double next(int val) {
        // Add the new value onto the back of the queue
        queue_.push(val);
        sum_ += val;
        
        if ( queue_.size() > size_ ) {
          // If the queue has exceeded the size limit, remove a value from the front.
          sum_ -= queue_.front();
          queue_.pop();
        }

        return sum_ / queue_.size();
      }

    private:
      size_t size_;
      std::queue<int> queue_;
      double sum_{0};
  };

  /**
   * @brief 496. Next Greater Element I (Easy)
   * https://leetcode.com/problems/next-greater-element-i/
   * 
   * The "next greater element" of some element x in an array is the first 
   * greater element that is *to the right* of x in the same array.
   * 
   * You are given two distinct 0-indexed integer arrays 'nums1' and 'nums2', 
   * where 'nums1' is a subset of 'nums2'.
   * 
   * For each element nums1[i], find the index j such that nums1[i] == nums2[j]
   * and determine the next greater element of nums2[j] in nums2. If there is no
   * next greater element, then the answer for this query is -1.
   * 
   * Time complexity: Due to the nested for-loop approach, this solution
   * likely has O(n^2) time complexity - which is really bad. Can we do better?
   * 
   * @tparam T 
   * @param nums1 A subset of nums2 where nums1.size() <= nums2.size()
   * @param nums2 A *unique* set of integers.
   * @return std::vector<T> A vector of length nums1.size() such that each
   * element is the "next greater element" as described above.
   */
  template <typename T>
  std::vector<T> next_greater_element(
    const std::vector<T>& nums1,
    const std::vector<T>& nums2)
  {
    // // Create the result vector (same size as nums1).
    // std::vector<T> result(nums1.size(), -1);

    // // Time complexity: Due to the nested for-loop approach, this solution
    // // has O(m *n) time complexity where m and n are the sizes of nums1 and 
    // // nums2, respectively, i.e. effectively O(n^2). Can we do better?
    // size_t idx{0};
    // for ( size_t i = 0; i < nums1.size(); i++ ) {
    //   LOG("Searching for '" << nums1[i] << "' in nums2");
    //   for ( size_t j = 0; j < nums2.size(); j++ ) {
    //     if ( nums1[i] == nums2[j] ) {
    //       LOG("Found '" << nums2[j] << "' at index " << j);
    //       for ( size_t k = j+1; k < nums2.size(); k++ ) {
    //         if (nums2[k] > nums2[j] ) {
    //           LOG("Found next greatest element '" << nums2[k] << 
    //             "' at index " << k);
    //           result[idx] = nums2[k];
    //           break;
    //         }
    //         LOG("No next grrater element found.");
    //       }
    //     }
    //   }
    //   idx++;
    // }

    // The time complexity of the solution below is O(m + n), where m and n are
    // nums1.size() and nums2.size(), respectively. We iterate once over nums2
    // to create the 'next_largest' map - iteration over nums2 costs O(n), and
    // each insertion into the map costs O(1). Next, to create the result
    // vector, we iterate over nums1 exactly once and populate an element of the
    // result vector at each iteration with a single O(1) lookup into the map.

    // Store a map of (value, next largest value) for each value in nums2.
    std::unordered_map<T, T> next_largest;

    // Use a stack to pre-process nums2 and create the next_largest map.
    std::stack<T> stack;

    // Pre-process nums2 to create the next_largest map
    for ( const T& num : nums2 ) {
      // Begin by evaluating the current number against the top of the stack.
      while ( !stack.empty() && num > stack.top() ) {
        // We've found the next largest element. All current values in the stack
        // are guaranteed to be less than the current value 'num', so pop all
        // values from the stack and create an entry in the map for each value.
        LOG("next_largest[" << stack.top() << "] = " << num);
        next_largest[stack.top()] = num;
        stack.pop();
      }

      // Place the current value onto the stack.
      LOG("Placing '" << num << "' onto the stack.");
      stack.push(num);
    }

    // For any values remaining on the stack, there is no next largest element.
    while ( !stack.empty() ) {
      next_largest[stack.top()] = -1;
      stack.pop();
    }

    // Create the result vector
    std::vector<T> result(nums1.size());
    for (size_t idx = 0; idx < nums1.size(); idx++ ) {
      result[idx] = next_largest[nums1[idx]];
    }

    return result;
  }

  /**
   * @brief 901. Online Stock Span (Medium)
   * https://leetcode.com/problems/online-stock-span/
   * 
   * Design an algorithm that collects daily price quotes for some stock and
   * returns the "span" of that stock's price for the current day.
   * 
   * The span of the stock's price in one day is the maximum number of
   * consecutive days (starting from that day and going backward) for which the
   * stock price was less than or equal to the price of that day.
   * 
   * For example, if the prices of the stock in the last four days is [7,2,1,2]
   * and the price of the stock today is 2, then the span of today is 4 because
   * starting from today, the price of the stock was less than or equal 2 for 4
   * consecutive days.
   * 
   * @tparam T 
   */
  template<typename T>
  class StockPanner
  {
    public:
      // ISO standard forbids declaration of template class constructor with no type.
      // StockSpanner() = default;

      /**
       * @brief Returns the span of the stock's price given that today's price 
       * is 'price'.
       * 
       * @param price Today's price.
       * @return T The span of the stock's price.
       */
      inline T next(T price) {
        LOG("current price: " << price);

        // Initialize a current span of 1 day.
        T span{1};

        // We will update the current day's span until we encounter a day for
        // which the price exceeds the current price.
        while ( !stack_.empty() && stack_.top().first <= price ) {
          // A given stock price's span encodes the number of preceding days
          // for which the price was less than or equal to that day's price.
          // Thus for every value on the stack that we encounter that is less
          // than or equal to the current day's price, we will do two things:
          // 1. increment the current price's span by that day's span.
          span += stack_.top().second;
          LOG("current span: " << span);

          // 2. Remove the lesser-valued price from the stack since we have
          // just accounted for the information encoded in its span by updating
          // the current price's span (above). 
          LOG("Removing (" << stack_.top().first << ", " << 
            stack_.top().second << ")");
          stack_.pop();
        }

        // Push a new pair onto the stack representing today's price and span.
        LOG("Adding (" << price << ", " << span << ")");
        stack_.push(std::make_pair(price, span));
        return span;
      }

    private:
      // Our stack will store (price, span) pairs.
      std::stack<std::pair<T, T>> stack_;
  };
}