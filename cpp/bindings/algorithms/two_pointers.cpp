/**
 * @file two_pointers.cpp
 * @author Carl Stahoviak
 * @brief Pybind11 bindings for the dsa::algorithms::two_pointers namespace.
 * @date 2024-05-08
 */

#include "dsa/algorithms/two_pointers.h"

#include <pybind11/pybind11.h>
// Required for automatic type conversions between np.ndarray and std::vector
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace dsa::algorithms::two_pointers;

void initTwoPointers(py::module_& m)
{
  /*
   * NOTE: C++ templates cannot be instantiated at runtime, so you cannot bind
   * the non-instantiated function, &two_sum. You must bind each instantiated
   * function template separately. You may bind each instantiation with the
   * same name, which will be treated the same as an overloaded function.
   */
  m.def("two_sum", &two_sum<int>, py::arg("vec"), py::arg("target"));
  m.def("two_sum", &two_sum<float>, py::arg("vec"), py::arg("target"));

  m.def("sorted_squares", &sorted_squares<int>, py::arg("values"));
}