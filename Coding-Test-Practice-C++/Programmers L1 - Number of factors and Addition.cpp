//// 내 풀이
//// 제곱근이 정수인 경우에만 약수가 홀수개임 - 정수의 제곱으로 만들 수 있는수를 제곱수라고 함
//// 따라서 제곱근이 정수인지 판별해서 품
//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int solution(int left, int right) {
//    int answer = 0;
//
//	for (int i = left; i <= right; i++)
//	{
//		double root = sqrt(i);
//		if (root - (int)root == 0) answer -= i;
//		else answer += i;
//	}
//
//    return answer;
//}

// 다른 사람 풀이
// 결국 재귀 때문에 느리지만 홀수 판별하는 부분은 좋은 것 같음
//int sign(int n, int count = 1) {
//    for (int i = 1, last = n >> 1; i <= last; ++i) if (n % i == 0) ++count;
//    return count & 1 ? -1 : 1;
//}
//int solution(int a, int b) { return a > b ? 0 : sign(a) * a + solution(a + 1, b); }


//int sign(int n, int count = 1)
//{
//    // 짝수개인지
//    // n >> 1은 n / 2와 같음
//    for (int i = 1, last = n >> 1; i <= last; ++i)
//    {
//        if (n % i == 0)
//            ++count;
//    }
//    // 홀수인 경우 3 & 1로 참
//    // 짝수인 경우 4 & 1로 거짓
//    return count & 1 ? -1 : 1;
//}
//
//int solution(int a, int b)
//{
//    // 삼항 연산자 - 탈출 조건
//    // 재귀를 사용해 풀었음 - 그냥 반복문이나 마찬가지
//    // sign함수를 통해서 나오는 수는 그냥 1 또는 -1로 부호를 정해줌
//    return a > b ? 0 : sign(a) * a + solution(a + 1, b);
//}

//// 다른 사람 풀이
//// 범위의 모든 수를 더하고 거기에서 모든 제곱수를 두 번 빼줌
//// 제곱수는 left보다 큰 제곱근부터 시작해서 right보다 작은 제곱근을 구한다음 순회하면서 제곱해주면 됨
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int left, int right) {
//    int answer = 0;
//    int start = 0;
//    int end = 0;
//    int i = 0;
//    int sum = 0;
//    int square = 0;
//
//    // 약수의 개수가 짝수 : 제곱수가 아닌 수, 약수의 개수가 홀수 : 제곱수 
//
//    while (i * i < left) {
//        i++;
//    }
//    start = i;
//
//    while (i * i <= right) {
//        i++;
//    }
//    end = i - 1;
//
//    sum = (left + right) * (right - left + 1) / 2;
//
//    for (i = start; i <= end; i++) {
//        square += i * i;
//    }
//    //answer = start;
//    //answer = sum;
//    answer = sum - square * 2;
//    // answer = end;
//    // answer = square;
//
//    return answer;
//}