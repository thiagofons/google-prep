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
private:
  ListNode *revert (ListNode *list) {
    ListNode *prev = nullptr;
    ListNode *curr = list;


    while (curr != nullptr) {
      ListNode *aux = curr->next;
      curr->next = prev;
      prev = curr;
      curr = aux;
    }

    return prev;
  }

public:
  void reorderList(ListNode* head) {
    // Dummy pointer pointing to the head
    ListNode *dummy = head;

    // Get the slow to the middle of the list
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // Revert the second list
    ListNode *reverted = revert(slow->next);

    // Split the list into two halves
    slow->next = nullptr;
    ListNode *first = head;
    ListNode *second = reverted;

    // Merge the two halves
    while (second) {
      ListNode *tmp1 = first->next;
      ListNode *tmp2 = second->next;

      first->next = second;
      second->next = tmp1;

      first = tmp1;
      second = tmp2;
    }
  }
};

int main () {
  Solution solution;

  ListNode* head = new ListNode(2);
  ListNode* curr = head;
  for (int i = 2; i <= 4; ++i) {
    curr->next = new ListNode(i*2);
    curr = curr->next;
  }

  solution.reorderList(head);

  curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  return 0;
}
