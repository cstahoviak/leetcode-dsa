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

#include <functional>
#include <map>
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
   * 
   * Given a string containing digits from 2-9 inclusive, return all possible
   * letter combinations that the number could represent. Return the answer in
   * any order. Digits 1 and 0 do not map to any letters.
   * 
   * @param digits The input string of digits, [2,9].
   * @return std::vector<std::string> All possible letter combinations.
   */
  std::vector<std::string> letter_combinations(const std::string& digits) {
    // Define the mapping of digits to characters.
    static const std::map<char, std::vector<char>> map = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},      
    };

    // Create the result vector storing all possible string combinations.
    std::vector<std::string> combinations;

    // Define the backtracking function -
    std::function<void(std::string&, size_t)> backtrack = 
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
} // end namesapce dsa::algorithms::backtracking