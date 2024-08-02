# pragma once
/**
 * @file utils.h
 * @author Carl Stahoviak 
 * @brief Header file for utility functions.
 * @date 2024-05-03
 * 
 * NOTE: This was another ~reasonably~ painful reminder that the definition and
 * declaration of a template function CANNOT be seaprated... I think(?!). See
 * the links below for more info:
 * 
 * https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 */

#include <array>
// Include to get 'size_t'
#include <cstddef>
#include <iostream>
#include <tuple>
#include <vector>

// Define a compiler varaible based macro that will effectively hide all of our
// logging code if that variable is not set.
#ifdef DEBUG_INFO
  # define LOG(x) std::cout << x << std::endl;
#else
  #define LOG(x)
#endif

namespace dsa::utils {
 
  /**
   * @brief Converts a boolean to a string.
   * 
   * @param b The boolean value.
   * @return const char* const - a const pointer to a const char instance.
   */
  const char* const bool_to_string(bool b) {
    return b ? "true" : "false";
  }

  /**
   * @brief Converts a vector to s fixe-size array.
   * 
   * TODO: This doesn't compile. Not sure how to get the templating to work
   * correctly yet.
   * 
   * @tparam T 
   * @tparam N 
   * @param vec 
   * @return std::array<T, N> 
   */
  template<typename T, size_t N>
  std::array<T, N> vector_to_array(std::vector<T>& vec) {
    std::array<T, N> arr;
    std::move(vec.begin(), vec.end(), arr.begin());
    return arr;
  }
} // end namespace dsa::utils

// template <class Iterator>
// std::ostream& iterable_to_string(std::ostream& stream, Iterator begin, Iterator end);

// template <typename T, size_t N>
// std::ostream& operator<<(std::ostream& stream, const std::array<T, N>& arr);

// template <typename T>
// std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec);

template <typename Iter>
std::ostream& _iterable_to_string(std::ostream& stream, Iter begin, Iter end) {
  // Only need this if I want to do something with the underlying "value type" 
  using T = typename std::iterator_traits<Iter>::value_type;

  // Deduce the size of the container. Note that this will only work for
  // container that store their elements contiguously (std::list does not 
  // guarantee this).
  size_t sz = (end - begin);

  stream << "[";
  size_t idx = 0;
  for ( Iter it = begin; it != end; it++ ) {
    stream << *it;
    idx++;
    if (idx < sz)
      stream << ", ";
  }
  stream << "]";
  return stream;
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& stream, const std::array<T, N>& arr) {
  return _iterable_to_string(stream, arr.begin(), arr.end());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec) {
  return _iterable_to_string(stream, vec.begin(), vec.end());
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::tuple<T1, T2>& t) {
  // Unpack tuple using structured bindings
  auto& [i, j] = t;
  return stream << "(" << i << ", " << j << ")";
}

