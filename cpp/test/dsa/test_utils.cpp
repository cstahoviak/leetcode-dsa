/**
 * @file test_utils.cpp
 * @author Carl Stahoviak
 * @brief Units test for the dsa::utils namespace.
 * @version 0.1
 * @date 2024-08-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "dsa/utils.h"

#include <gtest/gtest.h>


// Don't require a text fixture for this simple test
TEST(TestUtils, TestBoolToString) {
  EXPECT_EQ(dsa::utils::bool_to_string(false), "false");
  EXPECT_EQ(dsa::utils::bool_to_string(true), "true");
}
