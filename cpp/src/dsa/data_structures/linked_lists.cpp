/**
 * @file linked_lists.cpp
 * @author Carl Stahoviak
 * @brief Linked Lists definitions.
 * @version 0.1
 * @date 2025-01-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

#include "dsa/data_structures/linked_lists.h"

namespace dsa::data_structures::linked_lists
{
  SinglyLinkedList::SinglyLinkedList(size_t size, int start_val) {
    if ( size ) {
      // Create a vector of increasing integer values.
      std::vector<int> values(size);
      std::iota(values.begin(), values.end(), start_val);

      // Create the singly linked list
      for ( const int& val : values ) {
        // Create a new node with the current value
        ListNode* new_node = new ListNode(val);
        std::cout << "Creating node " << val << " (" << new_node << ")"
          << std::endl;

        if ( head_ == nullptr ) {
          // O the first iteration, set the head and tail node's to be the same.
          head_ = new_node;
          tail_ = new_node;
        }
        else {
          // On all other iterations, assign the new node as the tail's next node.
          tail_->next = new_node;
          tail_ = tail_->next;
        }
      }

      // TODO: I can't seem to achieve the behavior (doing some work in one
      // ctor before passing some info onto another ctor) I'm after via
      // "delegating ctors", so how acceptable is this solution?
      // *this = SinglyLinkedList(values);
    }
  }

  SinglyLinkedList::SinglyLinkedList(const std::vector<int>& nums) {
    if ( nums.size() ) {
      // Create the singly linked list
      for ( const int& val : nums ) {
        // Create a new node with the current value
        ListNode* new_node = new ListNode(val);
        std::cout << "Creating node " << val << " (" << new_node << ")"
          << std::endl;

        if ( head_ == nullptr ) {
          // O the first iteration, set the head and tail node's to be the same.
          head_ = new_node;
          tail_ = new_node;
        }
        else {
          // On all other iterations, assign the new node as the tail's next node.
          tail_->next = new_node;
          tail_ = tail_->next;
        }
      }
    }

  }

  SinglyLinkedList::~SinglyLinkedList() {
    // Delete all nodes in the list.
    ListNode* current_node = head_;
    while ( current_node != nullptr ) {
      // Store the current node as a temporary
      ListNode* temp = current_node;

      // Move the current node pointer to the next node.
      current_node = current_node->next;

      // Delete the current node via the temp pointer.
      std::cout << "Deleting node " << temp->val << " (" << temp <<
        "), next node: " << current_node << std::endl; 
      delete temp;
    }
  }

  /**
   * @brief Given the head of a singly linked list, return the middle node of
   * the linked list. If there are two middle nodes, return the second middle
   * node.
   * 
   * We will use the "fast and slow pointers" method to solve this problem.
   * 
   * @param head 
   * @return ListNode* 
   */
  ListNode* middle_node(ListNode* head) {
    std::cout << "Finding middle node starting from " << head << std::endl;
    ListNode* slow = head;
    ListNode* fast = head;

    size_t steps{0};
    while ( fast != nullptr && fast->next != nullptr ) {
      std::cout << "slow: " << slow->val << ", fast: " << fast->val << std::endl;
      slow = slow->next;
      fast = fast->next->next;
      steps++;
    }

    return slow;

    // std::cout << "steps: " << steps << std::endl;
    // std::cout << "slow: " << slow->val << std::endl;
    // return ( steps % 2 ) ? slow->next : slow;
  }
}