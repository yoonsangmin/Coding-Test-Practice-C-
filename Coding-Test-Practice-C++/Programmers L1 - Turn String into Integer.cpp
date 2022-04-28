//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(string s) {
//    return stoi(s);
//}

//#include <string>
//#include <vector>
//#include <sstream>
//
//using namespace std;
//
//int solution(string s) {
//    stringstream ss(s);
//    int i;
//    ss >> i;
//    return i;
//}

//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(string s) {
//    int answer = 0;
//	int dec = 1;
//	for (int i = s.size() - 1; i >= 0; i--)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//		{
//			answer += (s[i] - '0') * dec;
//			dec *= 10;
//		}
//		else if (s[i] == '-')
//		{
//			answer = -answer;
//		}
//	}
//
//	return answer;
//}