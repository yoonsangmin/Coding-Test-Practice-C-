//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int n) {
//    string answer = "";
//
//	for (int i = 0; i < n; i++)
//		if ((i & 1) == 0)
//			answer += "수";
//		else
//			answer += "박";
//
//    return answer;
//}
//
//// 다른 사람 풀이
//// 더 짧은 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int n) {
//    string answer = "";
//
//    for (int i = 0; i < n; i++)
//        i & 1 ? answer += "박" : answer += "수";
//
//    return answer;
//}
//
//
//// 나누어 떨어지는 만큼 수박을 붙인 다음 홀수이면 수를 더 붙임
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int n) {
//    string answer = "";
//    for (int i = 0; i < n / 2; i++) {
//        answer.append("수박");
//    }
//    if (n % 2 == 1)
//        answer.append("수");
//    return answer;
//}