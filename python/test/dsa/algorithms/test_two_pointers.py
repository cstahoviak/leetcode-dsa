"""
Unit tests for the two-pointers algorithms.
"""
import numpy as np

import dsa.bindings.dsa_cpp as dsa
from dsa.algorithms.two_pointers import sorted_squares


def test_sorted_squares():
  """
  Unit test for the python and C++ implementations of the "sorted squares"
  algorithm.
  """
  # Create an array of values
  values = np.random.randint(-10, 10, 100)

  # Sort the array using the python implementation
  result_py = sorted_squares(values)

  # Sort the array using the cpp implementation
  result_cpp = dsa.sorted_squares(list(values))

  # Verify that the python and cpp algortihms give the same result
  np.testing.assert_array_equal(result_cpp, result_py)
