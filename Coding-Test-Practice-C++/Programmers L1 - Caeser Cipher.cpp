//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s, int n) {
//    string answer = "";
//
//	for (char c : s)
//	{
//		if ('a' <= c && c <= 'z')
//			answer += (c + n) > 'z' ? c + n - 26 : c + n;
//		else if ('A' <= c && c <= 'Z')
//			answer += (c + n) > 'Z' ? c + n - 26 : c + n;
//		else
//			answer += c;
//	}
//
//    return answer;
//}

//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s, int n) {
//	string answer = "";
//
//	for (char c : s)
//	{
//		if (islower(c))
//			answer += (c + n) > 'z' ? c + n - 26 : c + n;
//		else if (isupper(c))
//			answer += (c + n) > 'Z' ? c + n - 26 : c + n;
//		else
//			answer += c;
//	}
//
//	return answer;
//}