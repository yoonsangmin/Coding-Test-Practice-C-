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
//// 다른 사람 풀이 참고한 풀이
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//
//	// brown은 yellow 의 가로와 세로를 두 번 더한 것에 꼭지점 4개를 더한 값임
//	// brown을 2로 나누면 가로와 세로를 더한 값에서 2를 뺀 값임 - 겹치는 꼭지점이 두 군데
//	// brown / 2 + 2는 결국 가로와 세로의 합
//	int len = brown / 2 + 2;
//
//	// 높이의 최솟값 3
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