/**
 * @file two_pointers.cpp
 * @author Carl Stahoviak
 * @brief Pybind11 bindings for the dsa::algorithms::two_pointers namespace.
 * @date 2024-05-08
 */

#include "dsa/algorithms/two_pointers.h"

#include <pybind11/pybind11.h>

namespace py = pybind11;

void initTwoPointers(py::module_& m)
{
  m.def("two_sum", &dsa::algorithms::two_pointers::two_sum, py::arg("vec"), py::arg("target"));
}



