//// 내 풀이
// #include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//    int answer = 0;
//    
//    long long temp = 0;
//    while (n != 0)
//    {
//        // 삼진법으로 만들면서 바로 뒤집어버림
//        temp *= 10;
//        temp += n % 3;
//        n /= 3;
//    }
//
//    int ternary = 1;
//    while (temp != 0)
//    {
//        answer += (temp % 10) * ternary;
//        temp /= 10;
//        ternary *= 3;
//    }
//
//    return answer;
//}
//
//// 다른 사람 풀이
//// 꽤 괜찮은 방법
//#include <bits/stdc++.h>
//using namespace std;
//
//int solution(int n) {
//    vector<int> a;
//    while (n) {
//        a.push_back(n % 3);
//        n /= 3;
//    }
//
//    int ret = 0;
//    for (int i = 0; i < a.size(); ++i) ret = ret * 3 + a[i];
//    return ret;
//}