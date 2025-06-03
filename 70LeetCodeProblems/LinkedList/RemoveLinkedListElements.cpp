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
  ListNode* removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *curr = dummy;

    while (curr->next) {
      if (curr->next->val == val) {
        curr->next = curr->next->next;
      }
      else {
        curr = curr->next;
      }
    }

    return dummy->next;
  }
};

int main () {
  Solution solution;

  // Create a linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));

  head = solution.removeElements(head, 1);

  ListNode *curr = head;
  while (curr) {
    cout << curr->val;
    if (curr->next) cout << " -> ";
    curr = curr->next;
  }
  cout << endl;

  return 0;
}