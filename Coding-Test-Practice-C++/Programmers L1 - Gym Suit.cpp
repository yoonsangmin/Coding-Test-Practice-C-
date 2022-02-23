//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(int n, vector<int> lost, vector<int> reserve) {
//
//	sort(lost.begin(), lost.end());
//	sort(reserve.begin(), reserve.end());
//
//	for (int i = 0; i < reserve.size(); i++)
//	{
//		for (int j = 0; j < lost.size(); j++)
//		{
//			if (reserve[i] < lost[j])
//			{
//				break;
//			}
//			if (reserve[i] == lost[j])
//			{
//				lost.erase(lost.begin() + j);
//				reserve.erase(reserve.begin() + i);
//				i--;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i < reserve.size(); i++)
//	{
//		for (int j = 0; j < lost.size(); j++)
//		{
//			if (reserve[i] == lost[j] - 1)
//			{
//				lost.erase(lost.begin() + j);
// 
//				break;
//			}
//			else if (reserve[i] == lost[j] + 1)
//			{
//				lost.erase(lost.begin() + j);
//				
//				break;
//			}
//		}
//	}
//
//	return n - lost.size();
//}

//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int solution(int n, vector<int> lost, vector<int> reserve) {
//    int answer = 0;
//    map<int, int> suit;
//
//    for (int i = 0; i < lost.size(); i++)
//    {
//        suit[lost[i] - 1] = -1;
//    }
//
//    for (int i = 0; i < reserve.size(); i++)
//    {
//        suit[reserve[i] - 1]++;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (suit[i] == -1)
//        {
//            if (i - 1 >= 0 && suit[i - 1] == 1)
//            {
//                suit[i]++;
//                suit[i - 1]--;
//            }
//            else if (i + 1 < n && suit[i + 1] == 1)
//            {
//                suit[i]++;
//                suit[i + 1]--;
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (suit[i] >= 0) answer++;
//    }
//
//    return answer;
//}