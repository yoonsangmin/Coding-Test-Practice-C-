//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//	int idx_count = 0;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ')
//			idx_count = 0;
//		else
//		{
//			if (idx_count & 1)
//				s[i] = tolower(s[i]);
//			else
//				s[i] = toupper(s[i]);
//
//
//			idx_count++;
//		}
//	}
//
//	answer = s;
//
//    return answer;
//}