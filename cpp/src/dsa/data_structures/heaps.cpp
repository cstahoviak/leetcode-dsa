/**
 * @file heaps.cpp
 * @author Carl Stahoviak
 * @brief 
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/data_structures/heaps.h"

namespace dsa::data_structures::heaps
{
  template<typename T>
  KthLargest<T>::KthLargest(int k, const std::vector<T>& nums) {
    // Add all elements in nums to the min heap.
    for ( const T& num : nums ) {
      scores_.push(num);
      
      // Ensure the heap does not grow beyond a size of k.
      if ( scores_.size() > k ) {
        scores_.pop();
      }
    }
    
    // Guarantee a heap size of k.
    while ( scores_.size() < k ) {
      scores_.push(std::numeric_limits<T>::min());
    }
  }

  template<typename T>
  T KthLargest<T>::add(T val) {
    // Add the new value to the pq (increasing its size to k+1)
    scores_.push(val);

    // Remove the (k+1)th highest value.
    scores_.pop();

    // Return the kth highest value.
    return scores_.top();
  }

  // Explicit template instantiation for types 'int'
  template class KthLargest<int>;

  template <typename T>
  MyTemplateClass<T>::MyTemplateClass(T value) : data(value) {}

  template <typename T>
  T MyTemplateClass<T>::getData() const {
    return data;
  }

  template <typename T>
  void MyTemplateClass<T>::setData(T value) {
    data = value;
  }

  // Explicit template instantiation for types 'int' and 'double'
  template class MyTemplateClass<int>;
  template class MyTemplateClass<double>;

} // end namespace dsa::data_structures::heaps