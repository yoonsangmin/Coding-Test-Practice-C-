//#include <string>
//#include <vector>
//
//using namespace std;
//
//// ��Ŭ���� ȣ���� - �ִ� �����
//int GCD(int a, int b)
//{
//    //if (a % b == 0)
//    //    return b;
//    //return GCD(b, a % b);
//
//    // ���� �����ڸ� ����ϸ� �� �����ϰ� ��Ÿ�� �� ����
//    return a % b ? GCD(b, a % b) : b;
//    //// �Ǵ�
//    //return a % b == 0 ? b : GCD(b, a % b);
//
//    //// �ٸ� ��� Ǯ��, �Լ��� �� �� �� �Ҹ� �� b�� 0�� ���� üũ, ��� ��ⷯ ���� Ƚ���� ����
//    //return b ? GCD(b, a % b) : a;
//
//    //// ��� ������ �����ϸ� ��ⷯ ������ �ߺ����� �� �ص� ��, �ӵ��� �����
//    //int res = a % b;
//    //return res ? GCD(b, res) : b;
//}
//
//vector<int> solution(int n, int m) {
//    vector<int> answer(2);
//
//    // ����
//    if (n < m) n ^= m ^= n ^= m;
//    answer[0] = GCD(n, m);
//
//    // �ּ� ������� ������ ���μ��� �� * �ִ� �����
//    answer[1] = n * m / answer[0];
//
//    return answer;
//}
//
//int main()
//{
//    solution(3, 12);
//
//    return 0;
//}
//
//// �ٸ� ��� Ǯ��
//// �����ϰ� ��Ŭ���� ȣ������ ���� - a�� b�� ũ�Ⱑ �����Ǵ� ������ �������� ���� ��, �� �� �ϳ��� 0�� �Ǹ� ������ ������ �� - �ִ� �����
//while (b) {
//    if (a > b) a -= b;
//    else b -= a;
//}