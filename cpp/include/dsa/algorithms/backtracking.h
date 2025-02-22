#pragma once
/**
 * @file backtracking.h
 * @author Carl Stahoviak
 * @brief Bacvktracking algorithms.
 * @version 0.1
 * @date 2025-02-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/utils.h"

#include <cstdint>        // uint8_t
#include <functional>
#include <unordered_map>
#include <string>
#include <vector>

 namespace dsa::algorithms::backtracking
 {
  /**
   * @brief 797. All Paths from Source to Target (Medium)
   * https://leetcode.com/problems/all-paths-from-source-to-target/
   * 
   * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n-1, find
   * all possible paths from node 0 to node n - 1 and return them in any order.
   * 
   * @tparam T 
   * @param graph graph[i] is a list of all nodes you can visit from node i, 
   * i.e. there is a directed edge from node i to node graph[i][j]).
   * @return std::vector<std::vector<T>> All possible paths from node 0 to
   * node n-1
   */
  template<typename T>
  std::vector<std::vector<T>> all_paths(
    const std::vector<std::vector<T>>& graph)
  {
    // The target node is the final node in the graph
    T target = graph.size() - 1;

    // Create the result vector of all possible paths.
    std::vector<std::vector<T>> paths;

    // Define the backtracking function - a recursive function that will
    // continue exploration of the graph given the current node and the path
    // traversed so far.
    // NOTE: defining a recursive function as a lambda results in a "use of 
    // 'backtrack' before deduction of 'auto'" error. We need to use
    // std::function to define a "recursive" lambda.
    // auto backtrack = [&](T node, std::vector<std::vector<T>> path) -> void {
    std::function<void(T, std::vector<T>&)> backtrack = 
      [&graph, &target, &paths, &backtrack](T node, std::vector<T>& path)
    {
      // Define the base case: stop exploration when the target node is reached
      if ( node == target ) {
        // We've reached the target node - add this path to the result vector.
        paths.push_back(path);
        return;
      }

      for ( const T& neighbor : graph[node] ) {
        // Add the neighbor node to the path.
        path.push_back(neighbor);
        // Continue exploring the graph via the neighbor node.
        backtrack(neighbor, path);
        // Undo the current choice of neighbor by removing it from the path
        path.pop_back();
      }
    };

    // Add the origin node to the path and begin exploring via backtracking.
    std::vector<T> path { 0 };
    backtrack(0, path);
    return paths;
  }

  /**
   * @brief 17. Letter Combinations of a Phone Number (Medium)
   * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
   * 
   * Given a string containing digits from 2-9 inclusive, return all possible
   * letter combinations that the number could represent. Return the answer in
   * any order. Digits 1 and 0 do not map to any letters.
   * 
   * @param digits The input string of digits, digits[i] in [2,9].
   * @return std::vector<std::string> All possible letter combinations.
   */
  std::vector<std::string> letter_combinations(const std::string& digits) {
    // Define the mapping of digits to characters.
    static const std::unordered_map<char, std::vector<char>> map = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},      
    };

    // Create the result vector storing all possible string combinations.
    std::vector<std::string> combinations;

    // Define the backtracking function (idx is the index of the current
    // position in the digits string).
    std::function<void(std::string&, size_t)> backtrack = 
      // NOTE: local static variables can be accessed without explicit capture.
      [&digits, &combinations, &backtrack]
      (std::string& combination, size_t idx)
    {
      LOG("current string: '" << combination << "'");
      // Base base: end string when it's reached its maximum size.
      if ( combination.length() == digits.size() ) {
        // Add this combination to the answer and return
        LOG("Adding '" << combination << "' to the list of combinations.");
        combinations.push_back(combination);
        return;
      }

      // Iterate over each possible letter associated with the current digit
      for (const char& letter : map.at(digits[idx]) ) {
        // Add the digit to the current string.
        combination.push_back(letter);
        // Continue building the current string from the next character onwards
        backtrack(combination, idx + 1);
        // Undo the choice of letter before continuing on
        combination.pop_back();
      }
    };

    if ( digits.empty() ) {
      return {};
    }

    // Iterate over each starting character
    std::string combination{""};
    for ( const char& letter : map.at(digits[0]) ) {
      // Add the current letter to the combination
      combination.push_back(letter);
      // Continue building the string with the next digit
      backtrack(combination, 1);
      // Remove this start character and move onto the next one
      combination.pop_back();
    }

    return combinations;
  }

  /**
   * @brief 22. Generate Parenthesis (Medium)
   * https://leetcode.com/problems/generate-parentheses/
   * 
   * Given n pairs of parentheses, write a function to generate all combinations
   * of "well-formed" parentheses.
   * 
   * @param n 
   * @return std::vector<std::string> 
   */
  std::vector<std::string> generate_parenthesis(int n) {
    // Define the list of valid parenthesis strings
    std::vector<std::string> combinations;

    // Define the backtracking function
    std::function<void(uint8_t, uint8_t, std::string&)> backtrack = 
      [&n, &combinations, &backtrack]
      (uint8_t n_open, uint8_t n_closed, std::string& combination)
    {
      LOG("current string: '" << combination << "',\tn_open: " << n_open <<
        ", n_closed: " << n_closed);

      // Base base: the string has reached its maximum size
      if ( combination.length() == 2 * n ) {
        LOG("Adding '" << combination << "' to the list of combinations.");
        combinations.push_back(combination);
        return;
      }

      if ( n_open < n ) {
        // We can continue adding open parenthesis.
        combination.push_back('(');
        backtrack(n_open + 1, n_closed, combination);
        combination.pop_back();
      }

      if ( n_closed < n_open ) {
        // We need to close one or more of the parentheses that we've opened.
        combination.push_back(')');
        backtrack(n_open, n_closed + 1, combination);
        combination.pop_back();
      }
    };

    // Always begin with the an open parenthesis
    std::string combination{"("};
    backtrack(1, 0, combination);
    return combinations;
  }

  /**
   * @brief 967. Numbers with Same Consecutive Differences (Medium)
   * https://leetcode.com/problems/numbers-with-same-consecutive-differences/
   * 
   * Given two integers n and k, return an array of all the integers of length
   * n, where the difference between every two consecutive digits is k. You may
   * return the answer in any order.
   * 
   * Note that the integers should not have leading zeros. Integers as '02' and
   * '043' are not allowed.
   * 
   * @param n 
   * @param k 
   * @return std::vector<int> 
   */
  std::vector<int> consecutive_diff(int n, int k) {
    return {};
  }

  /**
   * @brief Combination Sum III (Medium)
   * https://leetcode.com/problems/combination-sum-iii/
   * 
   * Find all valid combinations of k numbers that sum up to n such that the
   * following conditions are true:
   *  - Only numbers 1 through 9 are used.
   *  - Each number is used at most once.
   * 
   * Return a list of all possible valid combinations in any order.
   * 
   * @param k Each valid combination consists of k numbers.
   * @param n Each valid combination must have a sum of n.
   * @return std::vector<std::vector<int>> 
   */
  std::vector<std::vector<int>> combination_sum_3(int k, int n) {
    // Create the result vector
    std::vector<std::vector<int>> combinations;

    // The maximum possible value in a given combination is k less than n, e.g.
    // if the sum is n=9, and there are k=3 numbers per combination, n-k=6 is
    // the largest possible value in the solution [1,2,6].
    int max_val = std::min(9, n - k + 1); 

    // Define the backtracking function
    std::function<void(std::vector<int>&, int)> backtrack = 
      [&k, &n, &max_val, &combinations, &backtrack]
      (std::vector<int>& combination, int sum)
    {
      LOG("current combination: " << combination);

      if ( combination.size() == k ) {
        if ( sum == n ) {
          LOG("Adding " << combination << " to the result vector.");
          combinations.push_back(combination);
          return;
        }
        else {
          LOG("Invalid combination " << combination << " discarded.");
          return;
        }
      }

      // Iterate over all possible successive numbers
      for ( int idx = combination.back() + 1; idx <= max_val; idx++ ) {
        if ( sum + idx <= n ) {
          combination.push_back(idx);
          backtrack(combination, sum + idx);
          combination.pop_back();
        }
      }
    };

    // Iterate over all possible starting values.
    std::vector<int> combination;
    for ( int idx = 1; idx <= max_val; idx++ ) {
      combination.push_back(idx);
      backtrack(combination, idx);
      combination.pop_back();
    }

    return combinations;
  }
} // end namesapce dsa::algorithms::backtracking