//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int solution(int n) {
//    int answer = 0;
//
//	// ������ ������ üũ�ص� �� - �������� �������� ����� ¦�� �̷�
//	for (int i = 1; i <= sqrt(n); i++)
//	{
//		// ���� ������ ������ ����ȯ�� �ʿ���
//		float quotient = (float)n / i;
//
//		// ������ ���������� üũ
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
//// �ٸ� ��� Ǯ��
//// �̿Ͱ��� Ǯ� �������� ������ ������ �ߺ����� ���� �ʱ� ���� ���� ������ int�� ����ȯ�� ���� ���� 0���� == �Ҽ� �ڸ��� �ִ��� üũ�� ���� ����
//// for (int i = 1; i <= sqrt(n); i++) if (n % i == 0) { sum += i; if (n != i * i) sum += n / i; }
//
//int main()
//{
//	solution(5);
//	return 0;
//}

//// accumulate�� ��� ����
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

//// accumulate �� �ʿ䰡 ������
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