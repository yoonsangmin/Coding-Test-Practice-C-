//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//
//};
//
// 다른 사람 풀이
// 
//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode* current_node = l1;
//
//		if (l2 == nullptr)
//			return l1;
//		if (l1 == nullptr)
//			return l2;
//
//		while (current_node != nullptr)
//		{
//			if (current_node->val > l2->val)
//			{
//				// val swap
//				int temp_val = current_node->val;
//				current_node->val = l2->val;
//				l2->val = temp_val;
//
//				// next swap
//				ListNode* temp_node = l2->next;
//				l2->next = current_node->next;
//				current_node->next = temp_node;
//			}
//
//			if (current_node->next == nullptr)
//			{
//				current_node->next = l2;
//				break;
//			}
//
//			current_node = current_node->next;
//		}
//
//		return l1;
//	}
//};

// 내 풀이

//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode* answer = nullptr;
//		ListNode* temp_answer = nullptr;
//
//		ListNode* temp1 = l1, * temp2 = l2;
//
//		while (temp1 != nullptr && temp2 != nullptr)
//		{
//			if (temp1->val < temp2->val)
//			{
//				if (temp_answer == nullptr)
//				{
//					temp_answer = new ListNode(temp1->val);
//					answer = temp_answer;
//				}
//				else
//				{
//					temp_answer->next = new ListNode(temp1->val);
//					temp_answer = temp_answer->next;
//				}
//
//				temp1 = temp1->next;
//			}
//			else
//			{
//				if (temp_answer == nullptr)
//				{
//					temp_answer = new ListNode(temp2->val);
//					answer = temp_answer;
//				}
//				else
//				{
//					temp_answer->next = new ListNode(temp2->val);
//					temp_answer = temp_answer->next;
//				}
//
//				temp2 = temp2->next;
//			}
//		}
//		while (temp1 != nullptr)
//		{
//			if (temp_answer == nullptr)
//			{
//				temp_answer = new ListNode(temp1->val);
//				answer = temp_answer;
//			}
//			else
//			{
//				temp_answer->next = new ListNode(temp1->val);
//				temp_answer = temp_answer->next;
//			}
//
//			temp1 = temp1->next;
//		}
//
//		while (temp2 != nullptr)
//		{
//			if (temp_answer == nullptr)
//			{
//				temp_answer = new ListNode(temp2->val);
//				answer = temp_answer;
//			}
//			else
//			{
//				temp_answer->next = new ListNode(temp2->val);
//				temp_answer = temp_answer->next;
//			}
//
//			temp2 = temp2->next;
//		}
//
//		return answer;
//	}
//};