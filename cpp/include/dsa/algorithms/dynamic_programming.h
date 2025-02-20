#pragma once
/**
 * @file dynamic_programming.h
 * @author Carl Stahoviak
 * @brief Dynamic Programming algorithms.
 * @version 0.1
 * @date 2025-02-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <vector>

 namespace dsa::algorithms::dp
 {
  /**
   * @brief 70 Climbing Stairs (Easy)
   * https://leetcode.com/problems/climbing-stairs/
   * 
   * You are climbing a staircase. It takes n steps to reach the top. Each time
   * you can either climb 1 or 2 steps. In how many distinct ways can you climb
   * to the top?
   * 
   * @tparam T 
   * @param n The number of stairs
   * @return T The number of unique ways the stairs can be climbed.
   */
  template<typename T>
  T climb_stairs(T n) {
    return 0;
  }

  /**
   * @brief 746. Min Cost Climbing Stairs (Easy)
   * https://leetcode.com/problems/min-cost-climbing-stairs/
   * 
   * You are given an integer array cost where cost[i] is the cost of ith step
   * on a staircase. Once you pay the cost, you can either climb one or two
   * steps.
   * 
   * You can either start from the step with index 0, or the step with index 1.
   * 
   * Return the minimum cost to reach the top of the floor.
   * 
   * @tparam T 
   * @param cost An array representing the cost associated with each step.
   * @return T 
   */
  template<typename T>
  T min_cost_climbing_stairs(const std::vector<T>& cost) {
    return 0;     
  }

  /**
   * @brief Coin Change (Medium)
   * https://leetcode.com/problems/coin-change/
   * 
   * Return the fewest number of coins that you need to make up that amount. If
   * that amount of money cannot be made up by any combination of the coins,
   * return -1.
   * 
   * You may assume that you have an infinite number of each kind of coin.
   * 
   * @tparam T 
   * @param coins An integer array representing coins of different demoninations.
   * @param amount The total amount of money.
   * @return T 
   */
  template<typename T>
  T coin_change(const std::vector<T>& coins, T amount) {
    return 0;
  }

} // end namespace dsa::algorithms::dp