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

//// �ٸ� ��� Ǯ��
//// �ڿ��� ���� K ��ŭ ������ ���� ��ŭ ���� ���� K ��ŭ�� �� �κ��� �� �ڿ��� ���� ���ϸ鼭 ��ü�� ���� ã�� ��ü�� ���� ������ K ���� �� ĭ �� ������ �ű�鼭 �Ȱ��� ���� ��
//// j�� ���� ���� ó���� �� �� �־ ������ - j < answer.size()
//// ����� ������ ��� �׷��� �ð��� �ξ� ���� �ɸ�
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