// 내 풀이
// 모든 경우를 구해서 정렬하고 중복 제외함
// 
// #include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//
//	for (int i = 0; i < numbers.size() - 1; i++)
//	{
//		for (int j = i + 1; j < numbers.size(); j++)
//		{
//			answer.push_back(numbers[i] + numbers[j]);
//		}
//	}
//
//	sort(answer.begin(), answer.end());
//
//	answer.erase(unique(answer.begin(), answer.end()), answer.end());
//
//  return answer;
//}

//// 다른 풀이
//// 모든 경우를 set에 넣으면 set은 알아서 정렬하니까 set에 넣은 후 set을 순회하면서 answer에 값을 넣음
//
//#include <string>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//vector<int> solution(vector<int> numbers)
//{
//	vector<int> answer;
//	set<int> s;
//
//	for (int i = 0; i < numbers.size() - 1; i++)
//	{
//		for (int j = i + 1; j < numbers.size(); j++)
//		{
//			s.insert(numbers[i] + numbers[j]);
//		}
//	}
//
//	for (int number : s)
//	{
//		answer.push_back(number);
//	}
//
//	return answer;
//}

//// 다른 사람 풀이
//// assign으로 iterator 복사를 할 수 있었음
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//    set<int> st;
//    for (int i = 0; i < numbers.size(); ++i) {
//        for (int j = i + 1; j < numbers.size(); ++j) {
//            st.insert(numbers[i] + numbers[j]);
//        }
//    }
//    answer.assign(st.begin(), st.end());
//    return answer;
//}

//// 중복 검사를 배열로 해결 함
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//    vector<bool> visited(201, false);
//    for (int i = 0; i < numbers.size(); i++) {
//        for (int j = i + 1; j < numbers.size(); j++)
//            if (visited[numbers[i] + numbers[j]] == false) {
//                answer.push_back(numbers[i] + numbers[j]);
//                visited[numbers[i] + numbers[j]] = true;
//            }
//    }
//
//    sort(answer.begin(), answer.end());
//    return answer;
//}