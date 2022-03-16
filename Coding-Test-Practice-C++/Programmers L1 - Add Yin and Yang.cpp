//// 내 풀이
//// case 문으로 간단하게 품
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> absolutes, vector<bool> signs) {
//    int answer = 0;
//
//	for (int i = 0; i < absolutes.size(); i++)
//	{
//		switch (signs[i])
//		{
//		case true:
//			answer += absolutes[i];
//			break;
//		case false:
//			answer -= absolutes[i];
//			break;
//		}
//	}
//
//    return answer;
//}
//
//// 다른 사람 풀이
//// 이런식으로 반복을 피할 수 있음
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> absolutes, vector<bool> signs) {
//	int answer = 0;
//	for (int i = 0; i < signs.size(); i++) {
//		if (!signs[i]) absolutes[i] *= -1;
//		answer += absolutes[i];
//	}
//	return answer;
//}
