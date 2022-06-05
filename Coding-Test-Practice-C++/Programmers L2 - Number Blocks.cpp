//// ≥ª «Æ¿Ã
//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//vector<int> solution(long long begin, long long end) {
//	long long size = end - begin + 1;
//	vector<int> answer(size, 1);
//
//	if (begin == 1)
//		answer[0] = 0;
//
//	for (long long i = 0; i < size; i++)
//	{
//		long long num = begin + i;
//
//		for (long long j = 2; j <= sqrt(num); j++)
//		{
//			long long quotient = num / j;
//			if (num % j == 0 && quotient < 10000001)
//			{
//				answer[i] = quotient;
//				break;
//			}
//		}
//	}
//
//    return answer;
//}
//
//int main()
//{
//	solution(999999999, 1000000000);
//
//	return 0;
//}