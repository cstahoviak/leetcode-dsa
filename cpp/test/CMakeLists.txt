cmake_minimum_required(VERSION 3.10.2)

set(TEST_NAME ${PROJECT_NAME}_test)

# Get the test source files
set(TEST_SOURCES
  "dsa/utils/test_utils.cpp"
)

# Create the test executable
add_executable(${TEST_NAME} ${TEST_SOURCES})

# Linking
target_link_libraries(${TEST_NAME} 
# link our tests against both the googletest library and our library
  gtest_main
  dsalib
)

# Add the tests
add_test(
  NAME ${TEST_NAME}
  COMMAND ${TEST_NAME}
)