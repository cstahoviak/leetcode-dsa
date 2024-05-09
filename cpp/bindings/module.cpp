#include <pybind11/pybind11.h>

namespace py = pybind11;

// Forward-declare class-specific binding functions

void initTwoPointers(py::module_& m);

PYBIND11_MODULE(dsa_bindings, m) {
  m.doc() = "Python bindings for the Leetcode DSA library."

  initTwoPointers(m);
}