//// 내 풀이
//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//// 메모리 용량 문제로 에라토스테네스의 체를 사용할 수 없었음
//bool is_prime(long long n)
//{
//    if (n < 2) return false;
//    for (long long i = 2; i <= sqrt(n); i++)
//        if (n % i == 0)
//            return false;
//    return true;
//}
//
//int solution(int n, int k) {
//    int answer = 0;
//    long long converted = 0;
//    long long decimal = 1;
//
//    while (n > 0)
//    {
//        if (n % k != 0)
//        {
//            converted += n % k * decimal;
//            decimal *= 10;
//        }
//        else if (converted != 0)
//        {
//            if (is_prime(converted))
//                answer++;
//            converted = 0;
//            decimal = 1;
//        }
//        n /= k;
//    }
//    if (converted != 0)
//        if (is_prime(converted))
//            answer++;
//
//    return answer;
//}
//
//// 에라토스테네스의 체 사용 시
//// 미리 계산해야 할 양이 너무 많음
//// 가장 큰 값까지만 계산한다고 해도 그 값들을 저장할 벡터의 크기가 long long을 사용하면 너무 커져서 메모리 초과가 뜸
//// 제곱근까지 직접 나누어 보면서 소수인지 판별하는 것이 이 경우에는 오히려 더 효율적임
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(int n, int k) {
//    int answer = 0;
//    long long converted = 0;
//    long long decimal = 1;
//
//    vector<bool> prime(1000000000001, true);
//
//    prime[0] = false;
//    prime[1] = false;
//
//    for (int i = 2; i < prime.size(); i++)
//        if (prime[i])
//            // i * k 에서 (k < i) i이전 값 까지는 이미 검사했으니 j시작 값은 i * 2가 아니라 i * i 부터 시작해도 됨
//            for (int j = i * i; j < prime.size(); j += i)
//                prime[j] = false;
//
//    while (n > 0)
//    {
//        if (n % k != 0)
//        {
//            converted += n % k * decimal;
//            decimal *= 10;
//        }
//        else if (converted != 0)
//        {
//            if (prime[converted]) answer++;
//            converted = 0;
//            decimal = 1;
//        }
//        n /= k;
//    }
//    if (converted != 0)
//        if (prime[converted]) answer++;
//
//    return answer;
//}

//int main()
//{
//    solution(110011, 10);
//
//    return 0;
//}