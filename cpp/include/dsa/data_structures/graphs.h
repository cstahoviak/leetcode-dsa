/**
 * @file graphs.h
 * @author Carl Stahoviak
 * @brief Types and algorithms related to the binary tree data structure.
 * @version 0.1
 * @date 2025-01-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dsa/utils.h"

#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <vector>

namespace dsa::data_structures::graphs
{
  /**
   * @brief Builds a graph from a vector of edges where edges[i] = [ai, bi]
   * indicates that there is an edge between ai and bi in the graph.
   * 
   * @tparam T 
   * @param n The number of nodes in the graph, always starting from node 0.
   * @param edges The vector of graph edges. Each vector element is represents a
   * single edge and is guaranteed to have a size of 2.
   * @param undirected True if the edges are undirected (default is true).
   * @return std::unordered_map<T, std::vector<T>> 
   */
  template<typename T>
  std::unordered_map<T, std::vector<T>> from_edges_(
    size_t n,
    const std::vector<std::vector<T>> edges,
    bool undirected = true)
  {
    std::unordered_map<T, std::vector<T>> graph;

    for ( const std::vector<T>& edge: edges ) {
      T x = edge.at(0), y = edge.at(1);
      graph[x].push_back(y);
      if ( undirected ) graph[y].push_back(x);
    }

    // Ensure that unconnected nodes are represented in the graph.
    for ( size_t idx = 0; idx < n; idx++ ) {
      if ( graph.find(static_cast<T>(idx)) != graph.end() ) {
        // The key for this node already exists in the graph.
        continue;
      }

      // Creates a default element (size 0 vector) for the disconnected node.
      graph[idx] = {};
    }
    
    return graph;
  }

  template<typename T>
  std::unordered_map<T, std::vector<T>> from_adjacency_mtx_(
    const std::vector<std::vector<T>> adjacencyMtx,
    bool undirected = true)
  {
    std::unordered_map<int, std::vector<int>> graph;

    for ( size_t i = 0; i < adjacencyMtx.size(); i++ ) {
      for ( size_t j = 0; j < adjacencyMtx.size(); j++ ) {
        if ( adjacencyMtx.at(i).at(j) ) {
          graph[i].push_back(j);
          if ( undirected ) graph[j].push_back(i);
        }
      }
    }

    return graph;
  }

  /**
   * @brief Creates a hash table that represents a graph. Each key is a node
   * in the graph and the associated value is a vector of nodes to which that
   * node is connected.
   * 
   * @tparam T
   * @param n The number of nodes in the graph, always starting from node 0.
   * @param input 
   * @param undirected 
   * @return std::unordered_map<T, std::vector<T>> 
   */
  template<typename T>
  std::unordered_map<T, std::vector<T>> build_graph(
    size_t n,
    const std::vector<std::vector<T>> input,
    bool undirected = true)
  {
    if ( input.size() == input.at(0).size() ) {
      // Assume that if the row dimension matches the first column dimension
      // that the input is an nxn matrix.
      return from_adjacency_mtx_(input, undirected);
    }
    else {
      return from_edges_(n, input, undirected);
    }
  }

  /**
   * @brief Performs a depth first search (DFS) on 'graph' starting at 'node'
   * and marks all nodes in the same connected component as 'node' as 'visited'.
   * 
   * @tparam T 
   * @param node 
   * @param graph 
   * @param visited 
   */
  template<typename T>
  void dfs_graph(
    int node,
    const std::unordered_map<T, std::vector<T>>& graph,
    std::vector<bool>& visited)
  {
    for ( const int& neighbor : graph.at(node) ) {
      if ( !visited.at(neighbor) ) {
        // Mark the neighbor as visited to prevent cycles.
        visited.at(neighbor) = true;

        // Begin a new DFS from the current neighbor.
        dfs_graph(neighbor, graph, visited);
      }
    }
  }

  /**
   * @brief Perform a depth first search on a binary grid where valid
   * connections between cells exist vertically and horizantally, but not
   * diagonally.
   * 
   * @tparam T 
   * @param row 
   * @param col 
   * @param grid 
   * @param visited
   * @param area
   */
  template<typename T>
  void dfs_binary_grid(
    size_t row,
    size_t col,
    const std::vector<std::vector<T>>& grid,
    std::vector<std::vector<bool>>& visited,
    size_t& area)
  {
    // Statically store the up, down, left right direction vectors.
    static const std::vector<std::vector<int>> directions = 
      { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    const size_t m = grid.size();
    const size_t n = grid.at(0).size();

    // Define the valid cell function as a lambda
    auto valid = [m, n, &grid](int row, int col) {
      return 0 <= row && row < m && 0 <= col && col < n && grid.at(row).at(col); 
    };

    for ( const std::vector<int>& direction : directions ) {
      const int next_row = row + direction.at(0);
      const int next_col = col + direction.at(1);

      if ( valid(next_row, next_col) && !visited.at(next_row).at(next_col) ) {
        // Increment the area count and mark the "next" cell as visited.
        area++;
        visited.at(next_row).at(next_col) = true;

        // Perform DFS on the "next" cell.
        dfs_binary_grid(next_row, next_col, grid, visited, area);
      }
    }
  }

  /**
   * @brief Returns true if there exists a valid path between the source vertex
   * and the destination vertex.
   * 
   * To solve this, we need to determine if source and destination are in the
   * same "connected component".
   * 
   * @param n The number of nodes/vertices.
   * @param edges A 2D integer array edges, where each edges[i] = [u_i, v_i]
   *  denotes an undirected edge between vertex u_i and vertex v_i.
   * @param source The source vertex (guaranteed to be in the graph). 
   * @param destination The destination vertex (guaranteed to be in the graph).
   * @return true if there is a valid path from source to destination.
   */
  template<typename T>
  bool valid_path(
    T n,
    const std::vector<std::vector<T>>& edges,
    T source,
    T destination)
  {
    // Base case: The source and the destination node are the same.
    if ( source == destination ) {
      return true;
    }

    // Create the graph and an indicator vector to mark each node as visited
    std::unordered_map<T, std::vector<T>> graph = build_graph(n, edges);
    std::vector<bool> visited(n, false);

    // Peform a DFS search starting at the source node. If source and
    // destination are in the same connected component, then the destination
    // node will be marked visited after the search completes.
    dfs_graph(source, graph, visited);

    return visited.at(destination);
  }

  /**
   * @brief Finds the number of connected components in an undirected graph.
   * 
   * @tparam T 
   * @param n The number of nodes in the graph.
   * @param edges An array of edges where edges[i] = [ai, bi] indicates that
   *  there is an edge between ai and bi in the graph.
   * @return size_t The number of connected components in the graph.
   */
  template<typename T>
  size_t num_conn_com(int n, std::vector<std::vector<T>> edges) {
    // Create the graph and an indicator vector to mark each node as visited
    std::unordered_map<T, std::vector<T>> graph = from_edges_(n, edges);
    std::vector<bool> visited(n, false);

    size_t n_conn_com{0};
    for ( const auto& [node, neighhbors] : graph ) {
      if ( visited.at(node) ) {
        // If the node has already been visited, the component it belongs to
        // has already been counted.
        LOG("Skipping node " << node);
        continue;
      }

      // Increment the component count and perform DFS starting from node.
      n_conn_com++;
      LOG("Starting DFS from node " << node);
      dfs_graph(node, graph, visited);
    }
    
    return n_conn_com;
  }

  /**
   * @brief An island is a group of 1's (representing land) connected
   * 4-directionally (horizontally or vertically). The area of an island is the
   * number of grid cells associated with that island.
   * 
   * Given an m x n island, return the maximum area of an island in the grid.
   * If there are no islands, return 0; 
   * 
   * @tparam T 
   * @param grid 
   * @return size_t 
   */
  template<typename T>
  size_t max_island_area(std::vector<std::vector<T>> grid) {
    // Base case: an empty grid.
    if ( !grid.size() ) {
      return 0;
    }

    // Unpack the grid dimensions
    size_t m = grid.size();
    size_t n = grid.at(0).size();

    // Create the visited vector
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

    // Create a vector representing the area of each connected component (island)
    std::vector<size_t> area;

    for ( size_t row = 0; row < m; row++ ) {
      for ( size_t col = 0; col < n; col++ ) {
        if ( grid.at(row).at(col) && !visited.at(row).at(col) ) {
          // Add a new element to the connected component area vector
          area.push_back(1);

          // Mark the current grid local as visited and perform DFS
          visited.at(row).at(col) = true;
          dfs_binary_grid(row, col, grid, visited, area.back());
        }
      }
    }

    return ( area.size() ) ? *std::max_element(area.begin(), area.end()) : 0;
  }
} // end namespace dsa::data_structures::graphs