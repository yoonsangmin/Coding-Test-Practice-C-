//
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
// 
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* temp_l1 = l1;
//		ListNode* temp_l2 = l2;
//		int round_up = 0;
//
//		while (temp_l1 != nullptr && temp_l2 != nullptr)
//		{
//			temp_l1->val += temp_l2->val;
//
//			if (temp_l1->next == nullptr)
//			{
//				temp_l1->next = temp_l2->next;
//				temp_l2->next = nullptr;
//			}
//
//			temp_l1 = temp_l1->next;
//			temp_l2 = temp_l2->next;
//		}
//
//		temp_l1 = l1;
//
//		while (temp_l1 != nullptr)
//		{
//			if (temp_l1->next == nullptr)
//			{
//				temp_l1->val += round_up;
//
//				round_up = temp_l1->val / 10;
//				temp_l1->val %= 10;
//
//				if (round_up != 0)
//					temp_l1->next = new ListNode(round_up);
//				break;
//			}
//			else
//			{
//				temp_l1->val += round_up;
//
//				round_up = temp_l1->val / 10;
//				temp_l1->val %= 10;
//
//				temp_l1 = temp_l1->next;
//			}
//		}
//
//		return l1;
//	}
//};