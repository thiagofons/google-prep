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

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0, carry = 0;

    ListNode *result = new ListNode();
    ListNode *first = result;

    while (l1 || l2 || carry) {
      sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      carry = sum / 10;
      result->val = sum % 10;

      // Só cria novo nó se ainda houver valores a processar
      if (l1 || l2 || carry) {
        result->next = new ListNode();
        result = result->next;
      } else {
        result->next = nullptr;
      }
    }
    return first;
  }

  // Versão recursiva
  ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int carry = 0) {
    if (!l1 && !l2 && carry == 0) return nullptr;
    int sum = carry;
    if (l1) sum += l1->val;
    if (l2) sum += l2->val;
    ListNode* node = new ListNode(sum % 10);
    node->next = addTwoNumbersRecursive(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum / 10);
    return node;
  }
};

ListNode* createList(const vector<int>& nums) {
  ListNode dummy;
  ListNode* curr = &dummy;
  for (int n : nums) {
    curr->next = new ListNode(n);
    curr = curr->next;
  }
  return dummy.next;
}

void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  vector<int> v1 = {9,9,9,9,9,9,9};
  vector<int> v2 = {9,9,9,9};
  ListNode* l1 = createList(v1);
  ListNode* l2 = createList(v2);

  Solution sol;
  ListNode* result = sol.addTwoNumbersRecursive(l1, l2);

  printList(result);

  // Free memory
  while (l1) { ListNode* tmp = l1; l1 = l1->next; delete tmp; }
  while (l2) { ListNode* tmp = l2; l2 = l2->next; delete tmp; }
  while (result) { ListNode* tmp = result; result = result->next; delete tmp; }

  return 0;
}



