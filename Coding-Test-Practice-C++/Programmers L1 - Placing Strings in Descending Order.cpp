//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//string solution(string s) {
//    sort(s.begin(), s.end(), greater<>());
//    // sort(s.rbegin(), s.rend());
//
//    return s;
//}
//
//// 델리게이트
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//
//    sort(s.begin(), s.end(), [](const char& lhs, const char& rhs)
//        {
//            return lhs > rhs;
//        });
//    answer = s;
//    return answer;
//}


//// 선택 정렬
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s) {
//    
//    int selected;
//
//    for (int i = 0; i < s.length() - 1; i++)
//    {
//        selected = i;
//        for (int j = i + 1; j < s.length(); j++)
//        {
//            if (s[selected] < s[j])
//            {
//                selected = j;
//            }
//        }
//
//        swap(s[i], s[selected]);
//    }
//
//    return s;
//}
