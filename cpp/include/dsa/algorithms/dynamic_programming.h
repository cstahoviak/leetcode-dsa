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
#include "dsa/math.h"
#include "dsa/utils.h"

#include <execution>
#include <functional>     // std::function
#include <numeric>        // std::transform_reduce
#include <queue>          // std::priority_queue
#include <unordered_map>
#include <unordered_set>
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
   * This solution implements the "backtracking" approach (which works) on the
   * smaller test cases, but throws a "Time Limit Exceeded" error on Leetcode
   * meaning that this approach is too slow for larger starciase sizes, e.g. 
   * n >= 38.
   * 
   * Remember that backtracking is really only suitable for n <= 15(ish).
   * 
   * @param n The number of steps on the staircase.
   * @return int The number of unique ways the stairs can be climbed.
   */
  int climb_stairs_backtracking(int n) {
    // Store all possible solution combinations
    std::vector<std::vector<int>> combinations;
    int count{0};

    // Define the backtracking function
    std::function<void(std::vector<int>&, int)> backtrack = 
      [&n, &count, &backtrack]
      (std::vector<int>& combination, int sum)
    {
        LOG("current sum: " << sum << ", " << combination);

        // Base case: We've climbed all n stairs
        if ( sum == n ) {
          LOG("Adding " << combination << " to the solution vector.");
          count++;
          // combinations.push_back(combination);
          return;
        }

        // Base case: We've exceeded the number of steps - this is no longer
        // a valid combination of steps.
        if ( sum > n ) {
          return;
        }

        // Explore both possibilites - taking 1 step forward and 2 steps forward
        for (int idx = 1; idx <= 2; idx++ ) {
          combination.push_back(idx);
          backtrack(combination, sum + idx);
        }
      };

    // We can take either 1 or 2 steps at the beginning.
    std::vector<int> combination;
    for (int idx = 1; idx <= 2; idx++ ) {
      combination.push_back(idx);
      backtrack(combination, idx);
    }

    // return combinations.size();
    return count;
  }

  /**
   * @brief 70 Climbing Stairs (Easy)
   * https://leetcode.com/problems/climbing-stairs/
   * 
   * You are climbing a staircase. It takes n steps to reach the top. Each time
   * you can either climb 1 or 2 steps. In how many distinct ways can you climb
   * to the top?
   * 
   * This solution implements the "dynamic programming" approach.
   * 
   * TODO: This approach is WRONG, and I haven't been able to understand the
   * solutions provided in the "editorial" section.
   * 
   * @param n The number of steps on the staircase.
   * @return int The number of unique ways the stairs can be climbed.
   */
  int climb_stairs_dp(int n) {
    // Memoize (cache) the results in a local static variable - memo[i] stores
    // the number of ways to reach the ith step.
    static std::vector<int> memo(n, 0);

    // Define our dp function: it will return the number of ways to reach the
    // currrent step.
    std::function<int(int)> dp = [&dp](int step) {
      // Base case: there is only one way to reach the first step.
      if ( step == 1 ) {
        return 1;
      }

      // Base case: There are 2 distinct ways to reach the second step.
      if ( step == 2 ) {
        return 2;
      }

      // Return a cached result if it's available
      if ( !memo[step] ) {
        return memo[step];
      }

      // Define the recurrence relation: the number of ways to reach the nth
      // step is one greater than the number of ways to reach the preceeding
      // step.
      LOG("computing memo[" << step << "]");
      memo[step] = dp(step - 1) + 1;
      return memo[step];
    };

    dp(n);
    LOG("memo: " << memo);
    return memo[n];
  }

  /**
   * @brief 70 Climbing Stairs (Easy)
   * https://leetcode.com/problems/climbing-stairs/
   * 
   * You are climbing a staircase. It takes n steps to reach the top. Each time
   * you can either climb 1 or 2 steps. In how many distinct ways can you climb
   * to the top?
   * 
   * This solutionis taken from the comments section on the editorial page.
   * 
   * @param n The number of steps on the staircase.
   * @return int The number of unique ways the stairs can be climbed.
   */
  int climb_stairs_dp2(int n) {
    int k{0}, ways{0};
    while ( k <= n ) {
      int c = dsa::math::combinations(n, k);
      LOG("adding C(" << n << ", " << k << ") = " << c);
      ways += dsa::math::combinations(n, k);
      k++;
      n--;
    }

    return ways;
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
   * TODO: The solution provided in the "Framework for DP" section is wrong.
   * 
   * @tparam T 
   * @param cost An array representing the cost associated with each step.
   * @return T 
   */
  template<typename T>
  T min_cost_climbing_stairs(const std::vector<T>& cost) {
    // Memoize (cache) the results in a local static variable.
    static std::vector<int> memo(cost.size() + 1, -1);

    // Define the recurrence relation as a function.
    std::function<int(int)> dp = [&cost, &dp](int idx) {
      if (idx <= 1) {
        return 0;
      }

      if ( memo[idx] != -1) {
        return memo[idx];
      }

      memo[idx] = 
        std::min(dp(idx - 1) + cost[idx - 1], dp(idx - 2) + cost[idx - 2]);
      return memo[idx];
    };

    // Find the minimum cost to climb the stairs.  
    return dp(cost.size());   
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
   * This solution implements a heap-based approach that will fail for certain
   * coin and amount combinations (see test case 4).
   * 
   * @tparam T 
   * @param coins An integer array representing coins of varying demoninations.
   * @param amount The total amount of money.
   * @return T 
   */
  template<typename T>
  T coin_change_heap(const std::vector<T>& coins, T amount) {
    LOG("amount: " << amount << ", coins: " << coins);

    // Default case: it takes zero coins to get to $0.
    if ( amount == 0 ) {
      return 0;
    }

    // Use a max heap to store the coins values
    std::priority_queue<T> max_heap(coins.cbegin(), coins.cend());

    T count{0};
    while ( !max_heap.empty() && amount > 0 ) {
      // Compute the number of coins of this value that we can use.
      // NOTE: integer division in C++ truncates
      T n_coins = amount / max_heap.top();
      LOG("value: " << max_heap.top() << ", n_coins: " << n_coins);
      if ( n_coins ) {
        // Deduct from the remianing amount.
        amount -= max_heap.top() * n_coins;
        count += n_coins;
        LOG("added " << n_coins << " coins of value " << max_heap.top() << 
          ", remaining: " << amount);
      }
      max_heap.pop();
    }

    // If we exactly reached 0, we can return the count, otherwise no
    // of available coins could exactly produce the amount.
    LOG("amount remaining: " << amount);
    return ( amount == 0 ) ? count : -1;
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
   * Let's try taking a different heap-based approach. This heap-based solution
   * is an improvement on the previous one because we now keep track of
   * previously seen (n_coins, amount remaining) pairs, but it still fails due
   * to a "Time Limit Exceeded" error on Leetcode.
   * 
   * @param coins An integer array representing coins of varying demoninations.
   * @param amount The total amount of money.
   */
  inline int coin_change_heap2(const std::vector<int>& coins, int amount) {
    LOG("amount: " << amount << ", coins: " << coins);

    // Default case: it takes zero coins to get to $0.
    if ( amount == 0 ) {
      return 0;
    }

    // Base case (infeasible): the amount is less than the minimum value coin.
    if ( amount < *std::min_element(coins.cbegin(), coins.cend()) ) {
      LOG(amount << " is less than " << 
        *std::min_element(coins.cbegin(), coins.cend()) <<
        ". No solution is possible.");
      return -1;
    }

    // Create a set to keep track of unique (coin count, amount remaining) pairs
    // that have been added to the queue.
    using Pair = std::pair<int, int>;
    std::unordered_set<Pair, dsa::utils::PairHash> set;

    // Use a min heap to store the coins values. Each pair will represent the
    // amount remaining and the number of coins used thus far.
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> min_heap;

    // Place one of each coin onto the heap.
    for ( const int& coin : coins ) {
      LOG("Pushing (1, " << amount - coin << ") onto the heap.");
      min_heap.push(std::make_pair(1, amount - coin));
      set.emplace(1, amount - coin);
    }

    auto in_set = [&set](const int& n_coins, const int& remaining) -> bool {
      return set.find(std::make_pair(n_coins, remaining)) != set.end();
    };

    while ( !min_heap.empty() ) {
      const Pair current = min_heap.top();
      // LOG("top: (" << current.first << ", " << current.second << ")");
      min_heap.pop();
      
      if ( current.second == 0 ) {
        // If the remaining amount is 0, return the number of coins.
        LOG("n coins: " << current.first);
        return current.first;
      }

      for ( const int& coin : coins ) {
        int remaining = current.second - coin;
        if ( remaining >= 0 && !in_set(current.first + 1, remaining)) {
          // LOG("coin: " << coin << ",\tpushing (" << current.first + 1 << ", " 
          //   << remaining << ") onto the heap.");
          // If the amount remaining is geq to zero, and we haven't already
          // arrived at this particular (n_coins, remaining) pair via some other
          // path, push the pair onto the queue and add it to the set.
          min_heap.push(std::make_pair(current.first + 1, remaining));
          set.emplace(current.first + 1, remaining);
        } 
      }
    }

    LOG("Cannot get to a sum of " << amount << " with the available coins.");
    return -1;
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
   * We again take a heap-based approach, but this time, we use a hash map to
   * be even mroe restrictive about which (n_coin, amount remaining) pairs that
   * we place onto the heap. This still was not sufficient to deal with test
   * case 6, but it did reduce the average algorithm runtime by ~6.5x from
   * 2100ms down to 300ms. So that's a small win!
   * 
   * @param coins An integer array representing coins of varying demoninations.
   * @param amount The total amount of money.
   */
  template<typename T>
  T coin_change_heap3(const std::vector<T>& coins, T amount) {
    LOG("amount: " << amount << ", coins: " << coins);

    // Default case: it takes zero coins to get to $0.
    if ( amount == 0 ) {
      return 0;
    }

    // Base case (infeasible): the amount is less than the minimum value coin.
    if ( amount < *std::min_element(coins.cbegin(), coins.cend()) ) {
      LOG(amount << " is less than " << 
        *std::min_element(coins.cbegin(), coins.cend()) <<
        ". No solution is possible.");
      return -1;
    }

    auto is_even = [](const T& val) -> bool { return val % 2 == 0; };

    // Returns true if all elements in the vector are even.
    auto all_even = [&is_even](const std::vector<T>& vec) -> bool {
      return std::transform_reduce(
        std::execution::seq,        // execution policy: sequential
        vec.cbegin(), vec.cend(),   // input range
        true,                       // initial value of reduction operation
        std::logical_and<bool>(),   // reduction operation: &&
        is_even                     // transformation operation
      );
    };
    
    // Base case (infeasible): all coin values are even, and the amount is odd.
    if ( all_even(coins) && !is_even(amount) ) {
      LOG("Infeasible - all coin values are even, and the amount is odd.");
      return -1;
    }

    // Create a map whose key is the amount remaining and the value is the
    // minimum number of coins required to reach that amount.
    std::unordered_map<T, T> map;

    // Use a min heap to store the coins values. Each pair will represent the
    // number of coins used and the amount remianing.
    using Pair = std::pair<T, T>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> min_heap;

    // Place one of each coin onto the heap.
    for ( const T& coin : coins ) {
      LOG("Pushing (1, " << amount - coin << ") onto the heap.");
      min_heap.push(std::make_pair(1, amount - coin));
      map[amount - coin] = 1;
    }

    auto add_to_heap = [&map](const T& n_coins, const T& remaining) -> bool
    {
      if ( remaining >= 0 ) {
        if ( map.find(remaining) != map.end() ) {
          if ( n_coins < map.at(remaining) ) {
            // If the amount remaining is geq to zero and the number of coins
            // required to reach this amount is less than we've previously seen,
            // update the heap.
            return true;
          }
        }
        else {
          // If the remaining amount is geq to zero and doesn't exist in the
          // map, add it to the heap.
          return true;
        }
      }

      // If the remaining amount is negative, do not update the heap.
      return false;
    };

    size_t max_heap_size{0};
    while ( !min_heap.empty() ) {
      max_heap_size = std::max(max_heap_size, min_heap.size());
      const Pair current = min_heap.top();
      // LOG("top: (" << current.first << ", " << current.second << ")");
      min_heap.pop();
      
      if ( current.second == 0 ) {
        // If the remaining amount is 0, return the number of coins.
        LOG("n coins: " << current.first);
        LOG("max heap size: " << max_heap_size);
        return current.first;
      }

      for ( const T& coin : coins ) {
        int remaining = current.second - coin;
        if ( add_to_heap(current.first + 1, remaining) ) {
          // LOG("coin: " << coin << ",\tpushing (" << current.first + 1 << ", " 
          //   << remaining << ") onto the heap.");
          min_heap.push(std::make_pair(current.first + 1, remaining));
          map[remaining] = current.first + 1;
        }
      }
    }

    LOG("Cannot get to a sum of " << amount << " with the available coins.");
    return -1;
  }
} // end namespace dsa::algorithms::dp