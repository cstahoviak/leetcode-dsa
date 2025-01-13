/**
 * @file linked_lists.h
 * @author Carl Stahoviak
 * @brief Algorithms operating on a linked list data structure
 * @version 0.1
 * @date 2025-01-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <cstddef>
#include <numeric>
#include <vector>


namespace dsa::data_structures::linked_lists
{
  struct ListNode {
    int val{0};
    ListNode* next{nullptr};

    // Contructors
    // ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
  };

  class SinglyLinkedList
  {
    public:
      SinglyLinkedList(size_t, int = 1);
      SinglyLinkedList(const std::vector<int>&);
      ~SinglyLinkedList();

      ListNode* head() { return head_; }
    
    private:
      // The head and tail nodes.
      ListNode* head_{nullptr};
      ListNode* tail_{nullptr};
  };

  ListNode* middle_node(ListNode* head);
}