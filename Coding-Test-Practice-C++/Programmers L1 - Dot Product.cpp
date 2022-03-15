//// 내 풀이
//// 기본적인 내적 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> a, vector<int> b) {
//    int answer = 0;
//
//	for (int i = 0; i < a.size(); i++)
//	{
//		answer += a[i] * b[i];
//	}
//
//    return answer;
//}

//// 다른 사람 풀이
//// numeric 헤더에 inner_product가 있다는 걸 알게 됨
//#include <vector>
//#include <numeric>
//using namespace std;
//
//int solution(vector<int> a, vector<int> b) {
//	return inner_product(a.begin(), a.end(), b.begin(), 0);
//}