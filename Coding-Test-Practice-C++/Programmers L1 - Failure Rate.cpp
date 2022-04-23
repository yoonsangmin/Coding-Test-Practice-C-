//// 내 풀이
//// float 형변환하는 것 잊으면 안 됨
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool cmp(pair<int, float> p1, pair<int, float> p2)
//{
//	if (p1.second == p2.second)
//		return p1.first < p2.first;
//	return p1.second > p2.second;
//}
//
//vector<int> solution(int N, vector<int> stages) {
//    vector<int> answer(N);
//	vector<int> clears(N + 1, 0);
//	vector<pair<int, float>> stage_failure_rates;
//
//	for (int i = 0; i < stages.size(); i++)
//		clears[stages[i] - 1]++;
//
//	int sum = 0;
//
//	sum += clears.back();
//	for (int i = clears.size() - 2; i >= 0 ; i--)
//	{
//		sum += clears[i];
//		if (sum == 0)
//			stage_failure_rates.push_back({ i + 1, 0 });
//		else
//			stage_failure_rates.push_back({ i + 1, (float)clears[i] / sum });
//	}
//
//	sort(stage_failure_rates.begin(), stage_failure_rates.end(), cmp);
//	for (int i = 0; i < N; i++)
//		answer[i] = stage_failure_rates[i].first;
//
//    return answer;
//}