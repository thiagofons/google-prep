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
  bool isPalindrome (ListNode *list) {
    // Find the middle of the linked list
    ListNode *fast = list, *slow = list;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Revert the second linked list
    ListNode *previous = nullptr;

    while (slow) {
      ListNode *aux = slow->next;

      slow->next = previous;

      previous = slow;
      slow = aux;
    }

    // Walk through the lists checking if they are equal
    ListNode *left = list, *right = previous;

    while (right) {
      if (left->val != right->val) 
        return false;
      
      left = left->next;
      right = right->next;
    }

    return true;
    
  }
};

int main () {
  // Create a palindrome linked list: 1 -> 2 -> 2 -> 1
  ListNode* n4 = new ListNode(1);
  ListNode* n3 = new ListNode(2, n4);
  ListNode* n2 = new ListNode(2, n3);
  ListNode* n1 = new ListNode(1, n2);

  Solution sol;
  if (sol.isPalindrome(n1)) {
    cout << "The linked list is a palindrome." << endl;
  } else {
    cout << "The linked list is not a palindrome." << endl;
  }

  // Clean up memory
  delete n1;
  delete n2;
  delete n3;
  delete n4;

  return 0;
}