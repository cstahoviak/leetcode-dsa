cmake_minimum_required(VERSION 3.10.2)

set(TEST_NAME ${PROJECT_NAME}_test)

# Get the test source files
set(TEST_SOURCES
  "dsa/test_utils.cpp"
  "dsa/algorithms/test_two_pointers.cpp"
  "dsa/algorithms/test_sliding_window.cpp"
  "dsa/algorithms/test_prefix_sum.cpp"
)

# Create the test executable
add_executable(${TEST_NAME} ${TEST_SOURCES})

# Linking
target_link_libraries(${TEST_NAME} PUBLIC
# link our tests against both the googletest library and our library
  gtest_main
  dsalib
)

# Add the tests
add_test(
  NAME ${TEST_NAME}
  COMMAND ${TEST_NAME}
)