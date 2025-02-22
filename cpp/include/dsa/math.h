/**
 * @file math.h
 * @author Carl Stahoviak
 * @brief Math functions.
 * @version 0.1
 * @date 2025-02-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 namespace dsa::math
 {
  /**
   * @brief Computes the factorial of n, n!.
   * 
   * @param n 
   * @return uint32_t 
   */
  inline int factorial(int n) {
    if ( n == 0 ) {
      return 1;
    }
    int result = 1;
    for ( int idx = 1; idx <= n; ++idx ) {
      result *= idx;
    }
    return result;
  }

  /**
   * @brief Computes the number of combinations, n choose k.
   * 
   * @param n 
   * @param k 
   * @return uint32_t 
   */
  inline int combinations(int n, int k) {
    if ( k < 0 || k > n ) {
      return 0; // Invalid input
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
  }
 } // end namespace dsa::math