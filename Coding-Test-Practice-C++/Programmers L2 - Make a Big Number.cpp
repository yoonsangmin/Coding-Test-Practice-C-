//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string number, int k) {
//    
//	for (int i = 0; i < k; i++)
//	{
//		bool is_deleted = false;
//		for (int j = 0; j < number.size() - 1; j++)
//		{
//			if (number[j] < number[j + 1])
//			{
//				number.erase(number.begin() + j);
//
//				is_deleted = true;
//
//				break;
//			}
//		}
//
//		if (!is_deleted)
//			number.pop_back();
//	}
//
//    return number;
//}

//// 다른 사람 풀이
//// 뒤에서 부터 K 만큼 제외한 길이 만큼 따로 떼서 K 만큼의 앞 부분의 맨 뒤에서 부터 비교하면서 교체할 것을 찾고 교체할 것이 없으면 K 부터 한 칸 씩 앞으로 옮기면서 똑같이 진행 함
//// j의 범위 예외 처리가 안 돼 있어서 수정함 - j < answer.size()
//// 지우기 연산이 없어서 그런지 시간이 훨씬 적게 걸림
//
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//string solution(string number, int k) {
//    string answer = "";
//    answer = number.substr(k);
//    for (int i = k - 1; i >= 0; i--) {
//        int j = 0;
//        do {
//            if (number[i] >= answer[j]) {
//                char temp = answer[j];
//                answer[j] = number[i];
//                number[i] = temp;
//                j++;
//            }
//            else {
//                break;
//            }
//        } while (j < answer.size());
//    }
//
//
//
//    return answer;
//}
//
//int main()
//{
//    solution("54321", 3);
//}