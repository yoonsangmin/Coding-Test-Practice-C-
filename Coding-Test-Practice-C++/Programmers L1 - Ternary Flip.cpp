//// �� Ǯ��
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
//        // ���������� ����鼭 �ٷ� ���������
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
//// �ٸ� ��� Ǯ��
//// �� ������ ���
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