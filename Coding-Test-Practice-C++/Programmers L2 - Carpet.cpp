////#include <string>
////#include <vector>
////#include <cmath>
////
////using namespace std;
////
////
////vector<int> solution(int brown, int yellow) {
////    vector<int> answer;
////    
////    for (int x = yellow; x >= sqrt(yellow); x--)
////    {
////        int y = 1;
////
////        while (x * y < yellow)
////        {
////            y++;
////        }
////
////        if (x * y == yellow)
////        {
////            // check
////            if ((x + y) * 2 + 4 == brown)
////            {
////                answer.push_back(x + 2);
////                answer.push_back(y + 2);
////                break;
////            }
////        }
////    }
////
////    return answer;
////}
//
//// �ٸ� ��� Ǯ�� ������ Ǯ��
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//
//	// brown�� yellow �� ���ο� ���θ� �� �� ���� �Ϳ� ������ 4���� ���� ����
//	// brown�� 2�� ������ ���ο� ���θ� ���� ������ 2�� �� ���� - ��ġ�� �������� �� ����
//	// brown / 2 + 2�� �ᱹ ���ο� ������ ��
//	int len = brown / 2 + 2;
//
//	// ������ �ּڰ� 3
//	int h = 3;
//	int w = len - 3;
//
//	while (w >= h)
//	{
//		if (w * h == (brown + yellow))
//		{
//			answer.push_back(w);
//			answer.push_back(h);
//		}
//
//		w--;
//		h++;
//	}
//
//    return answer;
//}