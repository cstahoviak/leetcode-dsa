"""
The "two-pointers" algorithm module.
"""
from typing import List

def sorted_squares(values: List[float]) -> List[float]:
  """
  Given an integer array nums sorted in non-decreasing order, return an array of
  the squares of each number sorted in non-decreasing order.

  Args:
    values:

  Returns:

  """
  left = 0
  right = len(values) - 1
  
  result = [None] * len(values)
  idx = len(values) - 1
  while left <= right:
    if abs(values[right]) > abs(values[left]):
      result[idx] = values[right]**2
      right -= 1
    else:
      result[idx] = values[left]**2
      left += 1
    idx -= 1
    
  return result
