//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = "";
//
//	for (int i = 0; i < phone_number.size() - 4; i++)
//	{
//		answer += '*';
//	}
//
//	for (int i = phone_number.size() - 4; i < phone_number.size(); i++)
//	{
//		answer += phone_number[i];
//	}
//
//    return answer;
//}
//
//// 다른 사람 풀이
//// 그냥 대체하는 방법
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = "";
//
//    for (int i = 0; i < phone_number.size() - 4; i++)
//    {
//        phone_number[i] = '*';
//    }
//
//    answer = phone_number;
//
//    return answer;
//}
//
//// replace라는 메소드가 있음
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = phone_number;
//    for (int i = 0; i < answer.size() - 4; i++) {
//        answer.replace(i, 1, "*");
//    }
//    return answer;
//}
//
//// 한번에 바로 대체할 수도 있음
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = "";
//    string strStar = "";
//    int nLength = phone_number.length();
//
//    for (int i = 0; i < nLength - 4; i++)
//    {
//        strStar += "*";
//    }
//
//    phone_number.replace(0, nLength - 4, strStar);
//    answer = phone_number;
//
//    return answer;
//}