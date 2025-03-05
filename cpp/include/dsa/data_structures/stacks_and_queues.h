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

#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <string_view>

namespace dsa::data_structures::stacks_and_queues {

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
          // If we encounter a ".." AND the stack is not empty, pop the last element.
          LOG("Removing '" << deque.back() << "' from back of deque.");
          deque.pop_back();
        }
      }
      else if ( temp != "." ) {
        // For all other filename components, add it to the stack so long as
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

    for ( const char& character : s ) {
      // Note: Upper and lower case characters of the same letter have an ASCII
      // offset of exactly 32.
      if ( !result.empty() && std::abs(character - result.back()) == 32 ) {
        // If the deque is not empty, and we've encountered a sequential upper
        // and lowercase character of the same leter, remove the previously
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
   * 
   * 
   * @tparam T 
   * @param nums1 
   * @param nums2 
   * @return std::vector<T> 
   */
  template <typename T>
  std::vector<T> next_greater_element(
    const std::vector<T>& nums1,
    const std::vector<T>& nums2)
  {
    return {};
  }
}