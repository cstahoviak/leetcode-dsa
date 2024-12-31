cmake_minimum_required(VERSION 3.10.2)

include(FetchContent)

# Add pybind11
FetchContent_Declare(
  pybind11
  URL https://github.com/pybind/pybind11/archive/refs/tags/v2.13.6.tar.gz
)
FetchContent_MakeAvailable(pybind11)

# Add googletest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
FetchContent_MakeAvailable(googletest)