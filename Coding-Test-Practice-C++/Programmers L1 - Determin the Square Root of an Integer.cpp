//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(long long n) {
//    long long i = 1;
//    long long pow = 1;
//    
//    do
//    {
//        pow = i * i;
//        i++;
//    } while (pow < n);
//
//    if (pow == n)
//        return i * i;
//
//    return -1;
//}

//// sqrt 함수 사용
//// 더 빠름
//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//long long solution(long long n) {
//    
//    double root = sqrt(n);
//
//    if (root - (long long)root == 0)
//		  // long long 형 변환 필수는 아님 - return 형에서 암묵적으로 변환이 일어나는 것 같음
//        return (long long)(root + 1) * (root + 1);
//
//    return -1;
//}

// 다른 사람 풀이
// for문이 깔끔한 듯
//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(long long n) {
//    long long answer = 0;
//
//    long long i;
//    for (i = 1; i * i <= n; i++);
//    if ((i - 1) * (i - 1) == n)
//    {
//        answer = i * i;
//    }
//
//    else {
//        answer = -1;
//    }
//
//
//
//    return answer;
//}

//// 매우 간단히 품
//#include <string>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//long long solution(long long n) {
//    long long answer = sqrt(n);
//
//    // powl은 반환형이 long double - double과 마찬가지로 8바이트이나 64비트 운영체계에선 16바이트 - 4배정도 부동소수점 자료형
//    // answer은 long long 자료형이므로 소수 부분이 누락됨, 그 상태에서 제곱을 취하면 제곱근이 아닌 경우엔 n과 같지 않음
//    return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
//}