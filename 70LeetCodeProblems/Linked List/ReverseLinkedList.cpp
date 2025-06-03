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
  ListNode *reverseList (ListNode *head) {
    ListNode *previous = nullptr;
    ListNode *curr = head;

    while (curr != nullptr) {
      ListNode *next = curr->next;
      curr->next = previous;

      previous = curr;
      curr = next;      
    }

    return previous;
  }
};

int main() {
  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  // Reverse the list
  Solution sol;
  ListNode *reversed = sol.reverseList(head);

  // Print the reversed list
  ListNode *curr = reversed;
  while (curr) {
    cout << curr->val;
    if (curr->next) cout << " -> ";
    curr = curr->next;
  }
  cout << endl;

  // Free memory
  curr = reversed;
  while (curr) {
    ListNode *tmp = curr;
    curr = curr->next;
    delete tmp;
  }

  return 0;
}