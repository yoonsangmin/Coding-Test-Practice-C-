//// �� Ǯ��
//// �������� ������ ��쿡�� ����� Ȧ������ - ������ �������� ���� �� �ִ¼��� ��������� ��
//// ���� �������� �������� �Ǻ��ؼ� ǰ
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

// �ٸ� ��� Ǯ��
// �ᱹ ��� ������ �������� Ȧ�� �Ǻ��ϴ� �κ��� ���� �� ����
//int sign(int n, int count = 1) {
//    for (int i = 1, last = n >> 1; i <= last; ++i) if (n % i == 0) ++count;
//    return count & 1 ? -1 : 1;
//}
//int solution(int a, int b) { return a > b ? 0 : sign(a) * a + solution(a + 1, b); }


//int sign(int n, int count = 1)
//{
//    // ¦��������
//    // n >> 1�� n / 2�� ����
//    for (int i = 1, last = n >> 1; i <= last; ++i)
//    {
//        if (n % i == 0)
//            ++count;
//    }
//    // Ȧ���� ��� 3 & 1�� ��
//    // ¦���� ��� 4 & 1�� ����
//    return count & 1 ? -1 : 1;
//}
//
//int solution(int a, int b)
//{
//    // ���� ������ - Ż�� ����
//    // ��͸� ����� Ǯ���� - �׳� �ݺ����̳� ��������
//    // sign�Լ��� ���ؼ� ������ ���� �׳� 1 �Ǵ� -1�� ��ȣ�� ������
//    return a > b ? 0 : sign(a) * a + solution(a + 1, b);
//}

//// �ٸ� ��� Ǯ��
//// ������ ��� ���� ���ϰ� �ű⿡�� ��� �������� �� �� ����
//// �������� left���� ū �����ٺ��� �����ؼ� right���� ���� �������� ���Ѵ��� ��ȸ�ϸ鼭 �������ָ� ��
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
//    // ����� ������ ¦�� : �������� �ƴ� ��, ����� ������ Ȧ�� : ������ 
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