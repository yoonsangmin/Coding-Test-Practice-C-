//// �� Ǯ��
//// ��� ���Ŀ� ������
//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(long long n) {
//    long long answer = 0;
//    vector<int> counts(10, 0);
//
//    while (n > 0)
//    {
//        counts[n % 10]++;
//        n /= 10;
//    }
//
//    for (int i = 9; i >= 0; i--)
//    {
//        for (int j = 0; j < counts[i]; j++)
//        {
//            answer *= 10;
//            answer += i;
//        }
//    }
//
//    return answer;
//}
//
//// �ٸ� ��� Ǯ��
//// vector ����
//#include <vector>
//#include <algorithm>
//#include <functional>
//using namespace std;
//
//long long solution(long long n) {
//    long long answer = 0;
//    vector<int> vec;
//    while (n > 0) {
//        vec.push_back(n % 10);
//        n /= 10;
//    }
//    sort(vec.begin(), vec.end(), greater<int>());
//    for (int i = 0; i < vec.size(); i++) {
//        answer = answer * 10 + vec[i];
//    }
//    return answer;
//}
//
//// string ����
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <functional>
//using namespace std;
//
//long long solution(long long n) {
//    long long answer = 0;
//
//    string str = to_string(n);
//    sort(str.begin(), str.end(), greater<char>());
//    answer = stoll(str);
//
//    return answer;
//}