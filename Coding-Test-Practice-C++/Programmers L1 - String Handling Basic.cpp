//#include <string>
//#include <vector>
//
//using namespace std;
//
//bool solution(string s) {
//    bool answer = true;
//
//    if (s.length() != 4 && s.length() != 6)
//        answer = false;
//    else
//    {
//        for (int i = 0; i < s.length() && answer; i++)
//            if (s[i] < '0' || '9' < s[i])
//                answer = false;
//    }
//
//    return answer;
//}
//
//// �ٸ� ��� Ǯ��
//#include <string>
//#include <vector>
//using namespace std;
//
//bool solution(string s) {
//    bool answer = true;
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        // isdigit�̶� �Լ��� ����
//        if (!isdigit(s[i]))
//            answer = false;
//    }
//
//    // 3�� �������� �����ϰ� üũ��
//    return s.size() == 4 || s.size() == 6 ? answer : false;
//}