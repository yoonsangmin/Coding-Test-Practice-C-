// �� Ǯ��
// ��� ��츦 ���ؼ� �����ϰ� �ߺ� ������
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

//// �ٸ� Ǯ��
//// ��� ��츦 set�� ������ set�� �˾Ƽ� �����ϴϱ� set�� ���� �� set�� ��ȸ�ϸ鼭 answer�� ���� ����
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

//// �ٸ� ��� Ǯ��
//// assign���� iterator ���縦 �� �� �־���
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

//// �ߺ� �˻縦 �迭�� �ذ� ��
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