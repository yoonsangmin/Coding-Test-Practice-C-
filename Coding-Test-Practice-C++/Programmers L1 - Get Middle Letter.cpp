//// 내 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//
//    int size = s.size();
//
//    // 홀수면 true, 짝수면 false;
//    // 비트 비교 연산은 모두 1일 때만 참
//    // 1은 참, 0은 거짓
//    answer = size & 1 ? s.substr(size / 2, 1) : s.substr(size / 2 - 1, 2);
//
//    return answer;
//}

//// 다른 사람 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s) {
//    int size = s.size();
//    // 짝수일 때 1, 홀수일 때 2로 길이를 정함
//    string answer = s.substr((size - 1) / 2, (size - 1) % 2 + 1);
//    return answer;
//}