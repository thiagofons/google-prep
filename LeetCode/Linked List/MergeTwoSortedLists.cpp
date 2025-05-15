#include <vector>
#include <iostream>
#include <string>

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;

    while (list1 && list2) {
      if (list1->val > list2->val) {
        current->next = list2;
        list2 = list2->next;
      } else {
        current->next = list1;
        list1 = list1->next;
      }

      current = current->next;
    }

    if (list1) {
      current->next = list1;
    } else {
      current->next = list2;
    }

    return dummy->next;
  }
};


int main()
{
  Solution solution;

  // Create two sorted linked lists
  ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  // Merge the two lists
  ListNode *mergedList = solution.mergeTwoLists(list1, list2);

  // Print the merged list
  while (mergedList != nullptr)
  {
    cout << mergedList->val << " ";
    mergedList = mergedList->next;
  }
  cout << endl;

  return 0;
}

