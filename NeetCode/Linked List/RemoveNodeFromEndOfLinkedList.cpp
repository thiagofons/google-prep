#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  /*
  int getListSize(ListNode *head) {
    ListNode *p = head;
    int size = 0;

    while (p != nullptr) {
      p = p->next;
      size++;
    }

    return size;
  }

  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Get the size of the list
    int size = getListSize(head);
    cout << "size = " << size << endl;

    if (size == 1) return nullptr;
    
    // Remove the size - n element
    ListNode *p = head;
    int i = 0;

    while (i < size - n - 1) {
      p = p->next;
      i++;
    }

    ListNode *previous = p;
    ListNode *node = p->next;

    previous->next = node->next;
    free(node);

    return head;
  }
  */

  ListNode* removeNthFromEnd(ListNode* head, int n) { 
    ListNode *dummy = new ListNode(0, head);

    // Create both of our pointers
    ListNode *left = dummy;
    ListNode *right = head;

    // Set the right pointer position in n
    while (n > 0 && right) {
      right = right->next;
      n--;
    }

    // Walk with both pointers through the list
    while (right) {
      left = left->next;
      right = right->next;
    }

    // Delete the node
    left->next = left->next->next;

    return dummy->next;
  }
};

int main () {
  ListNode* head = new ListNode(1, new ListNode(2));
  int n = 2;

  Solution sol;
  head = sol.removeNthFromEnd(head, n);

  // Print the resulting list
  ListNode* curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  // Free memory
  curr = head;
  while (curr != nullptr) {
    ListNode* temp = curr;
    curr = curr->next;
    delete temp;
  }
}
 