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
#include "dsa/data_structures/linked_lists.h"
#include "dsa/utils.h"

namespace dsa::data_structures::linked_lists
{
  SinglyLinkedList::SinglyLinkedList(size_t size, int start_val) {
    if ( size ) {
      // Create a vector of increasing integer values.
      std::vector<int> values(size);
      std::iota(values.begin(), values.end(), start_val);

      // TODO: I can't seem to acheive the behavior (doing some work in one
      // ctor before passing some info onto another ctor) I'm after via
      // "delegating ctors", so how acceptable is this solution?
      // *this = SinglyLinkedList(values);

      // Create the singly linked list
      for ( const int& val : values ) {
        // Create a new node with the current value
        ListNode* new_node = new ListNode(val);
        LOG("Creating node " << val << " (" << new_node << ")");

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

  SinglyLinkedList::SinglyLinkedList(const std::vector<int>& nums) {
    if ( nums.size() ) {
      // Create the singly linked list
      for ( const int& val : nums ) {
        // Create a new node with the current value
        ListNode* new_node = new ListNode(val);
        LOG("Creating node " << val << " (" << new_node << ")");

        if ( head_ == nullptr ) {
          // On the first iteration, set the head and tail node's to be the same.
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
      LOG("Deleting node " << temp->val << " (" << temp << "), next node: " << 
        current_node);
      delete temp;
    }
  }

  std::vector<int> SinglyLinkedList::values() const {
    std::vector<int> values;
    ListNode* current = head_;
    while ( current != nullptr ) {
      values.push_back(current->val);
      current = current->next;
    }
    return values;
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
  ListNode* SinglyLinkedList::middle_node() const {
    const ListNode* slow = head_;
    const ListNode* fast = head_;

    while ( fast != nullptr && fast->next != nullptr ) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return const_cast<ListNode*>(slow);
  }

  /**
   * @brief Given the head of a sorted linked list, delete all duplicates such
   * that each element appears only once. The resulting list must remain sorted.
   * 
   * @param head 
   */
  void SinglyLinkedList::remove_duplicates() {
    ListNode* current = head_;

    while ( current != nullptr && current->next != nullptr ) {
      // Get the next value in the list
      ListNode* next = current->next;

      // While the current value and the next value are the same, continue
      // moving the "next" pointer.
      while ( next != nullptr && next->val == current->val ) {
        // Move the "next" pointer and delete the node via the temp pointer.
        ListNode* temp = next;
        next = next->next;
        delete temp;
      }

      if ( next != current->next ) {
        // Update the current node's next pointer
        LOG("Moving current's (" << current << ") next ptr from " <<
          current->next << " to " << next); 
        current->next = next;
      }

      // Update the current node
      current = current->next;
    }
  }

  /**
   * @brief 92. Reverse Linked List II (Medium)
   * https://leetcode.com/problems/reverse-linked-list-ii/
   * 
   * Given the head of a singly linked list and two integers 'left' and
   * 'right' where 'left' <= 'right', reverse the nodes of the list from
   * position 'left' to position 'right', and return the reversed list.
   * 
   * @param left The index of the left-most node is the reversed sub-list.
   * @param right The index of the right-most node is the reversed sub-list.
   */
  void SinglyLinkedList::reverse_sublist(int left, int right) {

  }
}