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
  ListNode *mergeTwoListsAux(ListNode *list1, ListNode *list2, ListNode *newList) {
    if (!list1) return list1;
    if (!list2) return list2;

    if (list1->val < list2->val) {
      newList->next = mergeTwoListsAux(list1->next, list2, newList->next);
    } else {
      newList->next = mergeTwoListsAux(list1, list2->next, newList->next);
    }
    
    return nullptr;
  }

  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *newList;

    mergeTwoListsAux(list1, list2, newList);

    return newList;
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

