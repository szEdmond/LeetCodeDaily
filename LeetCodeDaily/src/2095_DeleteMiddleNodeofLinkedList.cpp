#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (!head)
        return NULL;
    if (!head->next)
        return NULL;
	
	// Tortoise and Hare algo
    ListNode* slow = head;
    ListNode* prev = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        if (slow != head) prev = prev->next;
        fast = fast->next->next;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

int main()
{
	std::vector<int> fill{ 4,5,1,9 };

	// Fill LinkedList
	ListNode* head = new ListNode(fill[0]);
	ListNode* temp = head;
	for (int i = 1; i < fill.size(); i++) {
		temp->next = new ListNode(fill[i]);
		temp = temp->next;
	}
	temp = head;
	// ---------------------------------------

	ListNode* result = deleteMiddle(temp);
	while (result) {
		std::cout << result->val << std::endl;
		result = result->next;
	}
}