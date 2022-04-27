//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(long long n) {
//    vector<int> answer;
//
//    do
//    {
//        answer.push_back(n % 10);
//        n /= 10;
//    } while (n > 0);
//
//    return answer;
//}

//// 다른 사람 풀이
//// 몫 구하고 나누고 계속하면 성능이 안 좋을 것 같았는데 이렇게 하면 조금은 나을 듯
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(long long n) {
//    vector<int> answer;
//    long long num = n;
//    int i = 0;
//    long long multi = 10;
//    while (num != 0)
//    {
//        answer.push_back((num % multi) / (multi / 10));
//        num -= num % multi;
//        multi *= 10;
//    }
//    return answer;
//}

//// 문자열로 만들면 나눗셈 연산이 필요 없음
//// 문자열로 변환할 때 속도가 더 느림
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <sstream>
//using namespace std;
//
//vector<int> solution(long long n) {
//    vector<int> answer;
//    stringstream ss;
//    ss << n;
//    string str = ss.str();
//    int strLength = str.length();
//
//    for (int i = 0; i < strLength; i++)
//    {
//        answer.push_back(atoi(str.substr(i, 1).c_str()));
//    }
//
//    std::reverse(answer.begin(), answer.end());
//    return answer;
//}