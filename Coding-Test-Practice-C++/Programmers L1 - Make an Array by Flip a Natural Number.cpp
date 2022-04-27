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

//// �ٸ� ��� Ǯ��
//// �� ���ϰ� ������ ����ϸ� ������ �� ���� �� ���Ҵµ� �̷��� �ϸ� ������ ���� ��
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

//// ���ڿ��� ����� ������ ������ �ʿ� ����
//// ���ڿ��� ��ȯ�� �� �ӵ��� �� ����
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