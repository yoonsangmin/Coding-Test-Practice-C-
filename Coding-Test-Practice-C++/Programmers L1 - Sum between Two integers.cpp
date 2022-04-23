//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(int a, int b) {
//    long long answer = 0;
//
//    //answer = a + b;
//    //answer *= (abs(a - b) + 1);
//    //answer /= 2;
//
//    answer = (long long)(a + b) * (abs(a - b) + 1) / 2;
//
//    return answer;
//}
//
//// 다른 사람 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(int a, int b) {
//    return (long long)(a + b) * (abs(a - b) + 1) / 2;
//}
//
//// 비트 연산
//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(int a, int b) {
//    long long answer = 0;
//    // XOR 배타적 논리합 exclusive or
//    // XOR 연산을 서로에게 교차로 3번 해주면 서로의 값이 바뀜 = 스왑 연산
//    if (a > b) a ^= b ^= a ^= b;
//    // a < b로 만듦
//    // ~ 비트 NOT 연산
//    // 곱하면 각각 양수 - 음수 * 음수면 다시 양수가 되기 때문
//    // 각각 0 부터 a, b 자신까지의 양의 합이 됨
//
//    // -~b = 1을 더함
//    // ~-a = 1을 뺌
//    // 따라서 양수인 경우 1부터 b까지의 합에서 1부터 a - 1까지의 합을 뺀 것
//    // 음수인 경우 -1부터 b + 1까지의 양의 합에서 -1부터 a까지의 양의 합을 뺀 것 - (큰 수로 빼기때문에 음수 - 반대로 a까지의 음의 합에서 반대를 뺀 것으로 봐도 될 듯)
//    // 큰수가 양수고 작은 수가 음수인 경우 1부터 b까지의 합에서  -1부터 a까지의 양의 합을 뺀 것 - (그냥 합을 더한 것으로 봐도 될 듯)
//
//    answer = (long long)b * -~b / 2 - (long long)a * ~- a / 2;
//    return answer;
//}
//
//// -~b가 +1인 이유?
//// 보수를 취해서 부호가 바뀌고 1이 작아짐(양수인 경우 절대값이 커짐, 음수인 경우 절대값이 작아짐), 부호를 되돌림 = 1이 더해짐
//// ~-a가 -1인 이유?
//// -연산으로 부호가 바뀌고 ~연산으로 부호가 다시 돌아오면 값이 1작아짐(음수에서 양수로 갈 때 절대값이 작아짐, 양수에서 음수로 갈 때 절대값이 커짐)
//
//// 현재 사용하는 음수 표기법은 1의 보수법 X 2의 보수법 O
//// 음수 연산을 하면 1의 보수를 취한 다음에 1을 더해줌
//// NOT 연산으로 1의 보수를 취하면 부호가 바뀌며 1이 작아짐