//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int n) {
//    string answer = "";
//
//	for (int i = 0; i < n; i++)
//		if ((i & 1) == 0)
//			answer += "��";
//		else
//			answer += "��";
//
//    return answer;
//}
//
//// �ٸ� ��� Ǯ��
//// �� ª�� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int n) {
//    string answer = "";
//
//    for (int i = 0; i < n; i++)
//        i & 1 ? answer += "��" : answer += "��";
//
//    return answer;
//}
//
//
//// ������ �������� ��ŭ ������ ���� ���� Ȧ���̸� ���� �� ����
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int n) {
//    string answer = "";
//    for (int i = 0; i < n / 2; i++) {
//        answer.append("����");
//    }
//    if (n % 2 == 1)
//        answer.append("��");
//    return answer;
//}