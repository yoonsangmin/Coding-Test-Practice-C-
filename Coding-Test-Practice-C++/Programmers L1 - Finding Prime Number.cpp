//// �� Ǯ��
//// �Ҽ��� ���� ���ϴ� ����
//// n�� ũ�Ⱑ ����� ũ�� ������ ������ �˻��� �� ���� �����佺�׳׽��� ü�� �̿��ϴ� �� ���� ����
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//    int answer = 0;
//    vector<bool> is_prime(n + 1, true);
//
//    //// ���� �ʿ����� ����
//    //is_prime[0] = false;
//    //is_prime[1] = false;
//
//    for (int i = 2; i <= n; i++)
//    {
//        if (is_prime[i])
//        {
//            answer++;
//            // i �Ǵ� i + i �Ǵ� i * 2
//            // �̹� ���� ������ �����߱� ������ �ڽŵ� false�� ���� ��� ����
//            for (int j = i + i; j <= n; j += i)
//                is_prime[j] = false;
//        }
//    }
//
//    return answer;
//}