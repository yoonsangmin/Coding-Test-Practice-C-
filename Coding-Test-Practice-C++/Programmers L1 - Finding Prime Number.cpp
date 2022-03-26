//// 내 풀이
//// 소수의 개수 구하는 문제
//// n의 크기가 충분히 크기 때문에 일일이 검사할 순 없고 에라토스테네스의 체를 이용하는 게 좋아 보임
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//    int answer = 0;
//    vector<bool> is_prime(n + 1, true);
//
//    //// 굳이 필요하진 않음
//    //is_prime[0] = false;
//    //is_prime[1] = false;
//
//    for (int i = 2; i <= n; i++)
//    {
//        if (is_prime[i])
//        {
//            answer++;
//            // i 또는 i + i 또는 i * 2
//            // 이미 정답 개수에 포함했기 때문에 자신도 false로 만들어도 상관 없음
//            for (int j = i + i; j <= n; j += i)
//                is_prime[j] = false;
//        }
//    }
//
//    return answer;
//}