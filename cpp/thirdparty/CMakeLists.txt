cmake_minimum_required(VERSION 3.10.2)

include(FetchContent)

# 1. Add pybind11
FetchContent_Declare(
  pybind11
  URL https://github.com/pybind/pybind11/archive/refs/tags/v2.13.6.tar.gz
)
FetchContent_MakeAvailable(pybind11)

# 2. Add googletest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
FetchContent_MakeAvailable(googletest)

# 3. Add Intel Threading Building Blocks (TBB).
# TBB is required by the <execution> header. I was experimenting with this
# header to enabale parallel execution of std::transform_reduce() within:
#   dsa::algorithms::binary_search::smallest_divisor()

# 3a. Abandoning the FetchContent approach because building TBB locally
# results in a VERY long build time.
# FetchContent_Declare(
#   TBB
#   URL https://github.com/uxlfoundation/oneTBB/archive/refs/tags/v2022.1.0-rc1.tar.gz
# )
# FetchContent_MakeAvailable(TBB)

# 3b. libtbb-dev is part of the Ubuntu distribution (see: sudo dpkg -l | grep tbb),
# but find_package(TBB) won't work without first setting 'TBB_DIR' - the
# directory in which 'TBBConfig.cmake' is located.
# NOTE: You may need to change this for your machine!

set(TBB_DIR "/lib/x86_64-linux-gnu/cmake/TBB")
find_package(TBB REQUIRED)

# 3c. Alternative solution: If find_package() isn't working, we can use
# find_path() and find_library() to point directly to 'tbb.h' and 'libtbb.so',
# respectively.

# Find TBB headers (on my machine: /usr/include/tbb/tbb.h)
# find_path(TBB_INCLUDE_DIR tbb/tbb.h
#   HINTS "/usr/local/include" "/opt/intel/tbb/include" "/usr/include"
# )

# Find TBB library (on my machine: usr/lib/x86_64-linux-gnu/libtbb.so)
# find_library(TBB_LIBRARY tbb
#   HINTS "/usr/local/lib" "/opt/intel/tbb/lib/intel64/gcc4.8" "/usr/lib/x86_64-linux-gnu"
# )

# Include directories
# include_directories(${TBB_INCLUDE_DIR})



