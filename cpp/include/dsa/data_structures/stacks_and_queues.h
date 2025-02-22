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
  std::string simplify_path(std::string path) {
    // TODO: Use dsa::utils::split_string to split the string on '/'.
    // std::vector<std::string> split = dsa::utils::split_string(path, "/");

    // TODO: Create the output string as a stack by iterating over the split
    // vector and adding or removing from the stack based on the current string.

    return {};
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
}