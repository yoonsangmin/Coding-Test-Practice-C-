#include <string>
#include <vector>
#include <stack>

using namespace std;
// 내 풀이 뒤에서부터 보면서 앞에 자기보다 작거나 같은 게 나올 때까지 (큰 게 연속으로 나오면) answer 값을 수정함
// 자기보다 작거나 같은 애 앞에 있는 큰 값들은 신경 쓸 필요가 없기 때문
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


// 참고한 풀이 스택을 사용해서 해당 현재 보고 있는 것 보다 큰 것이 앞에 있는지 체크

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