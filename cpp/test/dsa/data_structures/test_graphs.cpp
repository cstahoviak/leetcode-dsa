/**
 * @file test_graphs.cpp
 * @author Carl Stahoviak
 * @brief Unit tests for algorithms related to the Graph data structure.
 * @version 0.1
 * @date 2025-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "dsa/data_structures/graphs.h"

#include <gtest/gtest.h>

using namespace dsa::data_structures;

TEST(TestGraphs, TestValidPath) {
  // Define the inputs
  std::vector<std::vector<int>> edges1 = { {0,1}, {1,2}, {2,0} };
  std::vector<std::vector<int>> edges2 = { {0,1}, {0,2}, {3,5}, {5,4}, {4,3} };

  EXPECT_TRUE(graphs::valid_path(3, edges1, 0, 2));
  EXPECT_FALSE(graphs::valid_path(6, edges2, 0, 5));
}

TEST(TestGraphs, TestNumConnectedComponents) {
  // Define the inputs
  std::vector<std::vector<int>> edges1 = { {0,1}, {1,2}, {3,4} };
  std::vector<std::vector<int>> edges2 = { {0,1}, {1,2}, {2,3}, {3,4} };
  std::vector<std::vector<int>> edges3 = { {0,1}, {2,3} };
  std::vector<std::vector<int>> edges4 = { {2,3}, {1,2}, {1,3} };

  EXPECT_EQ(graphs::num_conn_com(5, edges1), 2);
  EXPECT_EQ(graphs::num_conn_com(5, edges2), 1);
  EXPECT_EQ(graphs::num_conn_com(4, edges3), 2);
  EXPECT_EQ(graphs::num_conn_com(4, edges4), 2);
}

TEST(TestGraphs, TestMaxIslandArea) {
  // Define the input
  std::vector<std::vector<int>> grid = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0},
  };

  // Validate that I copied the input to the test correctly.
  EXPECT_EQ(grid.size(), 8);
  EXPECT_EQ(grid.at(0).size(), 13);

  // Validate the algorithm
  EXPECT_EQ(graphs::max_island_area(grid), 6);
}

TEST(TestGraphs, TestNearestExit) {
  // Define the inputs
  std::vector<std::vector<char>> maze1 = {
    {'+','+','.','+'},
    {'.','.','.','+'},
    {'+','+','+','.'},
  };

  std::vector<std::vector<char>> maze2 = {
    {'+','+','+'},
    {'.','.','.'},
    {'+','+','+'},
  };

  std::vector<std::vector<char>> maze3 = { {0, 1} };
  
  // Validate the algorithm
  EXPECT_EQ(graphs::nearest_exit(maze1, {1,2}), 1);
  EXPECT_EQ(graphs::nearest_exit(maze2, {1,0}), 2);
  EXPECT_EQ(graphs::nearest_exit(maze3, {0,0}), -1);
}

TEST(TestGraphs, TestMinMutations) {
  // Define the inputs
  const std::string start1 = "AACCGGTT";
  const std::string end1 = "AACCGGTA";
  const std::vector<std::string> bank1 = { "AACCGGTA" };

  const std::string start2 = "AACCGGTT";
  const std::string end2 = "AAACGGTA";
  const std::vector<std::string> bank2 = { "AACCGGTA","AACCGCTA","AAACGGTA" };

  EXPECT_EQ(graphs::min_mutation(start1, end1, bank1), 1);
  EXPECT_EQ(graphs::min_mutation(start2, end2, bank2), 2);
}