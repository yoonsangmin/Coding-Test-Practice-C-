//// �� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int n, long long left, long long right) {
//    vector<int> answer(right - left + 1, 0);
//
//	int start_i = left / n, start_j = left % n;
//
//	for (int i = 0; i < answer.size(); i++)
//	{
//		answer[i] = start_i > start_j ? start_i + 1 : start_j + 1;
//
//		start_j++; 
//		if (start_j == n)
//		{
//			start_i++;
//			start_j -= n;
//		}
//	}
//
//	return answer;
//}
//
//// �ٸ� ��� Ǯ��
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(int n, long long left, long long right) {
//	vector<int> answer;
//
//	// i, j ���� ��� ������ ���� �ʰ� left���� right���� ��� �ݺ��ϸ鼭 ���� i, �������� j�� ����ϸ� ��
//	// push_back ������ ���̱� ���ؼ� �̸� ũ�⸦ ������ ���� i - left�� �ϸ� �˸��� �ε����� ������ �� ����
//	for (long long i = left; i <= right; i++) {
//		answer.push_back(max(i / n, i % n) + 1);
//	}
//
//	return answer;
//}
//
//// ���ĺ� Ǯ��
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(int n, long long left, long long right) {
//	vector<int> answer(right - left + 1);
//
//	for (long long i = left; i <= right; i++) {
//		answer[i - left] = max(i / n, i % n) + 1;
//	}
//
//	return answer;
//}