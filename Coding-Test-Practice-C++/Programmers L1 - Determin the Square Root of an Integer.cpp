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

//// sqrt �Լ� ���
//// �� ����
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
//		  // long long �� ��ȯ �ʼ��� �ƴ� - return ������ �Ϲ������� ��ȯ�� �Ͼ�� �� ����
//        return (long long)(root + 1) * (root + 1);
//
//    return -1;
//}

// �ٸ� ��� Ǯ��
// for���� ����� ��
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

//// �ſ� ������ ǰ
//#include <string>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//long long solution(long long n) {
//    long long answer = sqrt(n);
//
//    // powl�� ��ȯ���� long double - double�� ���������� 8����Ʈ�̳� 64��Ʈ �ü�迡�� 16����Ʈ - 4������ �ε��Ҽ��� �ڷ���
//    // answer�� long long �ڷ����̹Ƿ� �Ҽ� �κ��� ������, �� ���¿��� ������ ���ϸ� �������� �ƴ� ��쿣 n�� ���� ����
//    return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
//}