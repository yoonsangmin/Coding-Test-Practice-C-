//#include <string>
//#include <vector>
//
//using namespace std;
//
//// 유클리드 호제법 - 최대 공약수
//int GCD(int a, int b)
//{
//    //if (a % b == 0)
//    //    return b;
//    //return GCD(b, a % b);
//
//    // 삼항 연산자를 사용하면 더 간단하게 나타낼 수 있음
//    return a % b ? GCD(b, a % b) : b;
//    //// 또는
//    //return a % b == 0 ? b : GCD(b, a % b);
//
//    //// 다른 사람 풀이, 함수가 한 번 더 불린 후 b가 0인 것을 체크, 대신 모듈러 연산 횟수가 적음
//    //return b ? GCD(b, a % b) : a;
//
//    //// 대신 변수에 저장하면 모듈러 연산을 중복으로 안 해도 됨, 속도는 비슷함
//    //int res = a % b;
//    //return res ? GCD(b, res) : b;
//}
//
//vector<int> solution(int n, int m) {
//    vector<int> answer(2);
//
//    // 스왑
//    if (n < m) n ^= m ^= n ^= m;
//    answer[0] = GCD(n, m);
//
//    // 최소 공배수는 각각의 서로소의 곱 * 최대 공약수
//    answer[1] = n * m / answer[0];
//
//    return answer;
//}
//
//int main()
//{
//    solution(3, 12);
//
//    return 0;
//}
//
//// 다른 사람 풀이
//// 간단하게 유클리드 호제법을 구현 - a와 b의 크기가 역전되는 시점이 나머지가 나온 것, 둘 중 하나가 0이 되면 나누어 떨어진 것 - 최대 공약수
//while (b) {
//    if (a > b) a -= b;
//    else b -= a;
//}