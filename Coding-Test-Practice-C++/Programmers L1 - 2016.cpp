//// �� Ǯ��
//// �ε��� 0�� �Ͽ��Ϸ� ���� ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
//int days_in_month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//string solution(int a, int b) {
//    string answer = "";
//
//	int today = b - 1;
//
//	for (int i = 0; i < a - 1; i++)
//	{
//		today += days_in_month[i];
//	}
//
//	today += 5;
//
//	today %= 7;
//
//	answer = day[today];
//
//    return answer;
//}

// ù���� �ݿ����̴ϱ� �ε��� 0�� �ݿ��Ϸ� ���� ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string day[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
//int days_in_month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//string solution(int a, int b) {
//	string answer = "";
//
//	int today = b - 1;
//
//	for (int i = 0; i < a - 1; i++)
//	{
//		today += days_in_month[i];
//	}
//
//	today %= 7;
//
//	answer = day[today];
//
//	return answer;
//}