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
  ListNode* mergeTwoLists (ListNode *list1, ListNode *list2) {
    ListNode dummy(0);
    ListNode *merged = &dummy;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        merged->next = list1;
        list1 = list1->next;
      } else {
        merged->next = list2;
        list2 = list2->next;
      }
      merged = merged->next;
    }

    if (list1) {
      merged->next = list1;
    } else {
      merged->next = list2;
    }

    return dummy.next;
  }
};

int main () {
  // Create first sorted linked list: 1 -> 2 -> 4
  ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));

  // Create second sorted linked list: 1 -> 3 -> 4
  ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  Solution solution;
  // Call mergeTwoLists (make it public for testing)
  ListNode* merged = solution.mergeTwoLists(list1, list2);

  // Print merged list
  while (merged) {
    cout << merged->val;
    if (merged->next) cout << " -> ";
    merged = merged->next;
  }
  cout << endl;

  return 0;
}