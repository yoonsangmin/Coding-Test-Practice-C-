//using namespace std;
//int solution(int n)
//{
//    int answer = 0;
//
//    while (n > 0)
//    {
//        answer += n % 10;
//        n /= 10;
//    }
//
//    return answer;
//}

//// �ٸ� ��� Ǯ��
//// ������ �ߴ� ����̳� ������ �õ����� �� to_string�� �ӵ��� �ſ� ������
//#include <iostream>
//#include <string>
//
//using namespace std;
//int solution(int n)
//{
//    int answer = 0;
//
//    string s = to_string(n);
//
//    for (int i = 0; i < s.size(); i++) answer += (s[i] - '0');
//
//    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
//    cout << "Hello Cpp" << endl;
//
//    return answer;
//}