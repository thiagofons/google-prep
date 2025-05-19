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
  bool hasCycle(ListNode *head) {
    ListNode *one = head, *two = head->next;

    while (two && two->next) {
      if (one->val == two->val)
        return true;
      
      one = one->next;
      two = two->next->next;
    }
    return false;
  }
};

int main () {
  Solution s;

  // Create nodes
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);

  // Link nodes to form the list 1 -> 2 -> 3 -> 4
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  // Test for cycle
  bool result = s.hasCycle(node1);
  cout << "Does the linked list have a cycle? " << (result ? "Yes" : "No") << std::endl;

  // Clean up memory
  delete node1;
  delete node2;
  delete node3;
  delete node4;

}
