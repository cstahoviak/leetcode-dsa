cmake_minimum_required(VERSION 3.10.2)

set(TEST_NAME ${PROJECT_NAME}_tests)

# Get the test source files
set(TEST_SOURCES
  "dsa/algorithms/test_backtracking.cpp"
  "dsa/algorithms/test_binary_search.cpp"
  "dsa/algorithms/test_dynamic_programming.cpp"
  "dsa/algorithms/test_greedy.cpp"
  "dsa/algorithms/test_prefix_sum.cpp"
  "dsa/algorithms/test_sliding_window.cpp"
  "dsa/algorithms/test_two_pointers.cpp"

  "dsa/data_structures/test_binary_trees.cpp"
  "dsa/data_structures/test_graphs.cpp"
  "dsa/data_structures/test_hash_maps.cpp"
  "dsa/data_structures/test_heaps.cpp"
  "dsa/data_structures/test_linked_lists.cpp"
  "dsa/data_structures/test_stacks_and_queues.cpp"

  "dsa/test_utils.cpp"
)

# Create the test executable
add_executable(${TEST_NAME} ${TEST_SOURCES})

# Linking
target_link_libraries(${TEST_NAME} PUBLIC
  # link tests against gtest, dsalib, and tbb (Intel Threading Building Blocks)
  gtest_main
  dsalib
  tbb
  # ${TBB_LIBRARY}
)

# Add debug info for each target
if( DEBUG_INFO )
  message(STATUS "Test DEBUG_INFO: ${DEBUG_INFO}")
  target_compile_definitions(${TEST_NAME} PRIVATE DEBUG_INFO)
endif()

# Add the tests
add_test(
  NAME ${TEST_NAME}
  COMMAND ${TEST_NAME}
)