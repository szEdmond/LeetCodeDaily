#include<iostream>
#include<vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void deleteNode(ListNode* node) {
	ListNode* temp = node->next; // storing next node (for deleting at the end)
	node->val = node->next->val;
	node->next = node->next->next;
	delete temp;
}

int main() 
{
	std::vector<int> fill{ 4,5,1,9 };

	// ---------- Fill LinkedList ------------
	ListNode* head = new ListNode(fill[0]);
	ListNode* temp = head;
	for (int i = 1; i < fill.size(); i++) {
		temp->next = new ListNode(fill[i]);
		temp = temp->next;
	}
	temp = head;
	// ---------------------------------------

	int n = 1;
	while (temp) {
		if (temp->val == n)
			deleteNode(temp);
		std::cout << temp->val << std::endl;
		temp = temp->next;
	}
}