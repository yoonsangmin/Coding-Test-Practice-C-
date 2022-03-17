//// 내 풀이
//// 모든 sizes를 돌면서 max 값을 저장해도 되지만 max_element를 한번 써보고 싶었음
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes) {
//    vector<int> x;
//    vector<int> y;
//
//    for (int i = 0; i < sizes.size(); i++)
//    {
//        if (sizes[i][0] < sizes[i][1])
//        {
//            x.push_back(sizes[i][1]);
//            y.push_back(sizes[i][0]);
//        }
//        else
//        {
//            x.push_back(sizes[i][0]);
//            y.push_back(sizes[i][1]);
//        }
//    }
//
//    return *max_element(x.begin(), x.end()) * *max_element(y.begin(), y.end());
//}

//// 모든 sizes 돌면서 max값 저장하기
//// 이게 반복문을 한 번만 돌아서 그런지 더 빠름
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes) {
//    int answer = 0;
//	int x_max = 0, y_max = 0;
//
//
//	for (int i = 0; i < sizes.size(); i++)
//	{
//		if (sizes[i][1] < sizes[i][0])
//		{
//			x_max = max(x_max, sizes[i][0]);
//			y_max = max(y_max, sizes[i][1]);
//		}
//		else
//		{
//			x_max = max(x_max, sizes[i][1]);
//			y_max = max(y_max, sizes[i][0]);
//		}
//	}
//
//    return x_max * y_max;
//}

//// 비교문을 삼항 연산자로 줄이고 if 내부의 반복을 최소한으로 줄여봄
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes) {
//	int answer = 0;
//	int x_max = 0, y_max = 0;
//
//	int bigger = 0, smaller = 1;
//
//	for (int i = 0; i < sizes.size(); i++)
//	{
//		bigger = sizes[i][0] > sizes[i][1] ? 0 : 1;
//		smaller = 1 - bigger;
//
//		x_max = max(x_max, sizes[i][bigger]);
//		y_max = max(y_max, sizes[i][smaller]);
//	}
//
//	return x_max * y_max;
//}

//// 다른 사람 풀이
//// 반복도 없고 깔끔함
//// 비교를 두 번 해도 속도가 오히려 빠르게 나옴
//// 비교가 큰 속도 차가 나진 않나 봄 - 아니면 max 연산이 비교 연산보다 빠른 듯
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes)
//{
//    int answer = 0;
//
//    int w = 0, h = 0;
//    for (int i = 0; i < sizes.size(); i++)
//    {
//        w = max(w, min(sizes[i][0], sizes[i][1]));
//        h = max(h, max(sizes[i][0], sizes[i][1]));
//    }
//    answer = w * h;
//
//    return answer;
//}

//// 내 코드랑 비슷한데 비교를 두 번 함
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes)
//{
//    int l = 0, u = 0;
//
//    for (const auto& i : sizes)
//    {
//        int lt = i[0] < i[1] ? i[0] : i[1];
//        int ut = i[1] >= i[0] ? i[1] : i[0];
//
//        l = lt > l ? lt : l;
//        u = ut > u ? ut : u;
//    }
//
//    return l * u;
//}