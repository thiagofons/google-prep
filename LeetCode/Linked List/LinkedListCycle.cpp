#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow) {
				return true;
			}
		}
		return false;
    }
};

int main() {
	// Create a linked list with a cycle
	ListNode* node1 = new ListNode(1);
	
	node1->next = nullptr;
	
	Solution solution;
	if (solution.hasCycle(node1)) {
		cout << "The linked list has a cycle." << endl;
	} else {
		cout << "The linked list does not have a cycle." << endl;
	}

	node1->next = nullptr; // Break the cycle to safely delete nodes
	delete node1;
	

	return 0;
}