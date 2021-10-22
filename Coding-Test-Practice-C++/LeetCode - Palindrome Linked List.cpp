//#include<deque>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        deque<int> d;
//
//        ListNode* temp = head;
//
//        while (temp != NULL)
//        {
//            d.push_back(temp->val);
//            temp = temp->next;
//        }
//
//        while (!d.empty())
//        {
//            if (d.front() != d.back())
//                return false;
//            d.pop_back();
//            if(!d.empty())
//                d.pop_front();
//        }
//
//        return true;
//    }
//};
//
//int main()
//{
//    ListNode* d = new ListNode(1);
//    ListNode* c = new ListNode(2, d);
//    ListNode* b = new ListNode(2, c);
//    ListNode* a = new ListNode(1, b);
//
//    Solution s;
//    s.isPalindrome(a);
//}