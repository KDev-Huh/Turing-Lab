#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x)
{
	ListNode* smallPtr = nullptr;
	ListNode* current = head;
	ListNode* start = nullptr;
	ListNode* before = nullptr;
	
	while (current != nullptr) {
		bool isRemove = false;
		/*cout << current->val << endl;*/
		if (current->val < x && smallPtr == nullptr) {
			if (before != nullptr) {
				before->next = current->next;
				isRemove = true;
			}
			head = new ListNode(current->val);
			smallPtr = head;
		}
		else if (current->val < x) {
			smallPtr->next = new ListNode(current->val);
			/*cout << "change : " << before->val << ", " << current->val << endl;*/
			before->next = current->next;
			isRemove = true;
			smallPtr = smallPtr->next;
		}
		else if(start == nullptr){
			start = current;
		}
		if(!isRemove)
			before = current;
		current = current->next;
	}
	if(smallPtr != nullptr)
		smallPtr->next = start;

	/*current = head;
	while (current != nullptr) {
		cout << current->val << endl;
		current = current->next;
	}*/

	return head;
}

ListNode* insertListNode(vector<int>& nums)
{
	ListNode* head = new ListNode(nums[0]);
	ListNode* current = head;

	for (int i = 1; i < nums.size(); ++i)
	{
		current->next = new ListNode(nums[i]);
		current = current->next;
	}

	return head;
}

int main() {
	vector<int> nums1{ 1, 4, 3, 2, 5, 2 };
	vector<int> nums2{ 2, 1 };
	vector<int> nums3{ 1, 4, 3, 0, 2, 5, 2 };
	vector<int> nums4{ 7, 9, 3, 0, 1, 7, 6, 8, 2 };

	ListNode* head1 = insertListNode(nums1);
	ListNode* head2 = insertListNode(nums2);
	ListNode* head3 = insertListNode(nums3);
	ListNode* head4 = insertListNode(nums4);

	vector<pair<ListNode*, int>> testCases = {
		{head1, 3},
		{head2, 2},
		{head3, 3},
		{head4, 3}
	};

	for (auto [head, x] : testCases)
	{
		head = partition(head, x);
		while (head) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << "\n";
	}


	return 0;
}