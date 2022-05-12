//// 내 풀이
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
//// 다른 사람 풀이
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
//	// i, j 값을 계속 가지고 있지 않고 left에서 right까지 계속 반복하면서 몫은 i, 나머지는 j로 계산하면 됨
//	// push_back 연산을 줄이기 위해서 미리 크기를 지정해 놓고 i - left를 하면 알맞은 인덱스에 접근할 수 있음
//	for (long long i = left; i <= right; i++) {
//		answer.push_back(max(i / n, i % n) + 1);
//	}
//
//	return answer;
//}
//
//// 고쳐본 풀이
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