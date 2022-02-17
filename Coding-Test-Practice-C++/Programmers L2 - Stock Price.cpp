#include <string>
#include <vector>
#include <stack>

using namespace std;
// �� Ǯ�� �ڿ������� ���鼭 �տ� �ڱ⺸�� �۰ų� ���� �� ���� ������ (ū �� �������� ������) answer ���� ������
// �ڱ⺸�� �۰ų� ���� �� �տ� �ִ� ū ������ �Ű� �� �ʿ䰡 ���� ����
// 
//vector<int> solution(vector<int> prices) {
//    vector<int> answer;
//
//	for (int i = 0; i < prices.size(); i++)
//	{
//		answer.push_back(prices.size() - 1 - i);
//	}
//
//	for (int i = prices.size() - 2; i >= 1; i--)
//	{
//		int cur = 1;
//
//		while (i - cur >= 0 && prices[i - cur] > prices[i])
//		{
//			answer[i - cur] = cur;
//
//			cur++;
//		}
//	}
//
//    return answer;
//}


// ������ Ǯ�� ������ ����ؼ� �ش� ���� ���� �ִ� �� ���� ū ���� �տ� �ִ��� üũ

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;

	for (int i = 0; i < prices.size(); i++)
	{
		while (!s.empty() && prices[s.top()] > prices[i] || !s.empty() && i == prices.size() - 1)
		{
			answer[s.top()] = i - s.top();
			s.pop();
		}

		s.push(i);
	}


    return answer;
}