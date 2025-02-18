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
    return {};
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
    return {};
  }
} // end namesapce dsa::algorithms::backtracking