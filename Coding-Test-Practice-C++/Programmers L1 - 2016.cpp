//// 내 풀이
//// 인덱스 0을 일요일로 했을 때
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

// 첫날이 금요일이니까 인덱스 0을 금요일로 했을 때
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