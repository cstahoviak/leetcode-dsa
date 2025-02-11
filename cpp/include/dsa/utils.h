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

#include <algorithm>
#include <array>
// Include to get 'size_t'
#include <cstddef>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

// Define a compiler varaible based macro that will effectively hide all of our
// logging code if that variable is not set.
#ifdef DEBUG_INFO
  # define LOG(x) std::cout << "[LOG] " <<  x << std::endl
#else
  #define LOG(x)
#endif

namespace dsa::utils
{
  /**
   * @brief Converts a boolean to a string.
   * 
   * NOTE: If the definition of a non-template function exists in a header, that
   * function must be marked "inline" to prevent "multiple definition" errors.
   * If the function is not marked "inline", the compiler will generate machine
   * code for that function in ~each~ translation unit that includes the header
   * where the function is defined, thus creating "multiple definition" errors.
   * 
   * @param b The boolean value.
   * @return const char* const - a const pointer to a const char instance.
   */
  inline const char* const bool_to_string(bool b) {
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

  /**
   * @brief Splits a string similar to Pythons "split" function. 
   * 
   * Source: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
   * 
   * TODO: This function is not yet implemented such that it does not modify
   * the input string s.
   * 
   * @param s 
   * @param delimiter 
   * @return std::vector<std::string> 
   */
  // std::vector<std::string> split_string(
  // const std::string& s,
  // const std::string& delimiter)
  // {
  //   std::vector<std::string> tokens;
  //   size_t pos = 0;
  //   std::string token;
  //   while ((pos = s.find(delimiter)) != std::string::npos) {
  //     token = s.substr(0, pos);
  //     tokens.push_back(token);
  //     // TODO: Cannot modify the inout string
  //     s.erase(0, pos + delimiter.length());
  //   }
  //   tokens.push_back(s);

  //   return tokens;
  // }


  template<typename A, typename B>
  std::pair<B,A> flip_pair(const std::pair<A, B>& p)
  {
    return std::pair<B, A>(p.second, p.first);
  }

  /**
   * @brief Template function for swapping the keys and values of a std::map.
   * 
   * Source: https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value
   * 
   * TODO: This seems to work with the default comparator, std::less<A>, but
   * I don't know how to get it to work with std::greater<A> or a custom
   * comparator.
   * 
   * I wanted to use this to experiment with the implementation of
   * dsa::algorithms::greedy::min_set_size_2, but it's not working yet.
   * 
   * @tparam A 
   * @tparam B 
   * @param src 
   * @return std::multimap<B, A> 
   */
  template<typename A, typename B>
  std::multimap<B, A> flip_map(const std::map<A, B>& src)
  {
    // TODO: How do I "inherit" the comparator function from 'src'?
    std::multimap<B, A> dst;
    std::transform(
      src.begin(), src.end(),
      std::inserter(dst, dst.begin()),
      flip_pair<A, B>);
    return dst;
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
  // containers that store their elements contiguously (std::list does not 
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

