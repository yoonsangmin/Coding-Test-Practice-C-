//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = "";
//
//	for (int i = 0; i < phone_number.size() - 4; i++)
//	{
//		answer += '*';
//	}
//
//	for (int i = phone_number.size() - 4; i < phone_number.size(); i++)
//	{
//		answer += phone_number[i];
//	}
//
//    return answer;
//}
//
//// �ٸ� ��� Ǯ��
//// �׳� ��ü�ϴ� ���
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = "";
//
//    for (int i = 0; i < phone_number.size() - 4; i++)
//    {
//        phone_number[i] = '*';
//    }
//
//    answer = phone_number;
//
//    return answer;
//}
//
//// replace��� �޼ҵ尡 ����
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = phone_number;
//    for (int i = 0; i < answer.size() - 4; i++) {
//        answer.replace(i, 1, "*");
//    }
//    return answer;
//}
//
//// �ѹ��� �ٷ� ��ü�� ���� ����
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string phone_number) {
//    string answer = "";
//    string strStar = "";
//    int nLength = phone_number.length();
//
//    for (int i = 0; i < nLength - 4; i++)
//    {
//        strStar += "*";
//    }
//
//    phone_number.replace(0, nLength - 4, strStar);
//    answer = phone_number;
//
//    return answer;
//}