//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int solution(int n) {
//    int answer = 0;
//
//	// 제곱근 까지만 체크해도 됨 - 제곱근을 기준으로 약수가 짝을 이룸
//	for (int i = 1; i <= sqrt(n); i++)
//	{
//		// 정수 나누기 정수는 형변환이 필요함
//		float quotient = (float)n / i;
//
//		// 나누어 떨어졌는지 체크
//		if (quotient - int(quotient) == 0)
//		{
//			answer += i;
//			if (quotient != i)
//				answer += quotient;
//		}
//	}
//
//    return answer;
//}
//
//// 다른 사람 풀이
//// 이와같이 풀어도 괜찮지만 나누기 연산을 중복으로 하지 않기 위해 나눈 값에서 int로 형변환한 값을 빼서 0인지 == 소수 자리가 있는지 체크할 수도 있음
//// for (int i = 1; i <= sqrt(n); i++) if (n % i == 0) { sum += i; if (n != i * i) sum += n / i; }
//
//int main()
//{
//	solution(5);
//	return 0;
//}

//// accumulate로 모두 합함
//#include <string>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//int solution(int n) {
//	int answer = 0;
//	vector<int> divisors;
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (n % i == 0)
//		{
//			divisors.push_back(i);
//		}
//	}
//
//	answer = accumulate(divisors.begin(), divisors.end(), 0);
//
//	return answer;
//}

//// accumulate 쓸 필요가 없었네
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//	int answer = 0;
//	vector<int> divisors;
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (n % i == 0)
//		{
//			answer += i;
//		}
//	}
//
//	return answer;
//}