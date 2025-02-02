cmake_minimum_required(VERSION 3.10.2)

set(TEST_NAME ${PROJECT_NAME}_tests)

# Get the test source files
set(TEST_SOURCES
  "dsa/algorithms/test_two_pointers.cpp"
  "dsa/algorithms/test_sliding_window.cpp"
  "dsa/algorithms/test_prefix_sum.cpp"
  "dsa/data_structures/test_hash_maps.cpp"
  "dsa/data_structures/test_linked_lists.cpp"
  "dsa/data_structures/test_stacks_and_queues.cpp"
  "dsa/algorithms/test_dfs.cpp"
  "dsa/test_utils.cpp"
)

# Create the test executable
add_executable(${TEST_NAME} ${TEST_SOURCES})

# Linking
target_link_libraries(${TEST_NAME} PUBLIC
# link our tests against both the googletest library and our library
  gtest_main
  dsalib
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