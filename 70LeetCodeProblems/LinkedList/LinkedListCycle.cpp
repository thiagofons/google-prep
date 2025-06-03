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
  bool hasCycle (ListNode *head) {
    ListNode *slow = head, *fast = head->next;

    while (fast && fast->next) {
      if (slow->val == fast->val)
        return true;

      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
};

int main () {
  // Create nodes
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(0);
  ListNode* node4 = new ListNode(-4);

  // Link nodes to form a cycle: 3 -> 2 -> 0 -> -4 -> 2 ...
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node2; // cycle here

  Solution sol;
  if (sol.hasCycle(node1)) {
    cout << "Cycle detected." << endl;
  } else {
    cout << "No cycle detected." << endl;
  }

  // Break the cycle for cleanup
  node4->next = nullptr;
  delete node1;
  delete node2;
  delete node3;
  delete node4;

  // Test with no cycle
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);

  if (sol.hasCycle(head)) {
    cout << "Cycle detected." << endl;
  } else {
    cout << "No cycle detected." << endl;
  }

  delete head->next;
  delete head;

  return 0;
}