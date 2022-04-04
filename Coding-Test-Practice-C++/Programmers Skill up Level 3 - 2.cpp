//// 1번 문제
//// 다른 사람 풀이 보고 풀어봄
//// 트리 만드는 방법을 좀 배운 것 같음
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//struct node
//{
//	int x, y, num;
//};
//
//struct tree
//{
//	node n;
//	tree* left, * right;
//
//	tree(node n)
//	{
//		this->n = n;
//		left = nullptr;
//		right = nullptr;
//	}
//};
//
//void add_node(tree* root, tree* temp)
//{
//	if (temp->n.x < root->n.x)
//	{
//		if (root->left == nullptr)
//		{
//			root->left = temp;
//		}
//		else
//		{
//			add_node(root->left, temp);
//		}
//	}
//	else
//	{
//		if (root->right == nullptr)
//		{
//			root->right = temp;
//		}
//		else
//		{
//			add_node(root->right, temp);
//		}
//	}
//}
//
//bool cmp(node n1, node n2)
//{
//	if (n1.y == n2.y)
//	{
//		return n1.x < n2.x;
//	}
//
//	return n1.y > n2.y;
//}
//
//void preorder(tree* cur, vector<int>& answer)
//{
//	if (cur == nullptr)
//		return;
//	answer.push_back(cur->n.num);
//	preorder(cur->left, answer);
//	preorder(cur->right, answer);
//}
//
//void postorder(tree* cur, vector<int>& answer)
//{
//	if (cur == nullptr)
//		return;
//	postorder(cur->left, answer);
//	postorder(cur->right, answer);
//	answer.push_back(cur->n.num);
//}
//
//vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
//    vector<vector<int>> answer(2);
//	vector<node> nodes;
//
//	for (int i = 0; i < nodeinfo.size(); i++)
//	{
//		node temp = { nodeinfo[i][0], nodeinfo[i][1], i + 1 };
//		nodes.push_back(temp);
//	}
//
//	sort(nodes.begin(), nodes.end(), cmp);
//
//	tree* root = new tree(nodes[0]);
//
//	for (int i = 1; i < nodes.size(); i++)
//	{
//		tree* temp = new tree(nodes[i]);
//		add_node(root, temp);
//	}
//
//	// 전위
//	preorder(root, answer[0]);
//	postorder(root, answer[1]);
//		
//    return answer;
//}
//
//int main()
//{
//	solution({{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}} );
//
//	return 0;
//}

//// 2번 문제
//// 다단계 칫솔 판매
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
//{
//    vector<int> answer(enroll.size(), 0);
//    map<string, int> enroll_map;
//
//    for (int i = 0; i < enroll.size(); i++)
//    {
//        enroll_map[enroll[i]] = i;
//    }
//
//    for (int i = 0; i < seller.size(); i++)
//    {
//        int price = amount[i] * 100;
//        int seller_idx = enroll_map[seller[i]];
//        int share = 0;
//
//        do
//        {
//            share = price / 10;
//
//            answer[seller_idx] += (price - share);
//
//            price = share;
//
//            if (referral[seller_idx] == "-")
//                break;
//            seller_idx = enroll_map[referral[seller_idx]];
//        } while (share > 0);
//    }
//
//    return answer;
//}