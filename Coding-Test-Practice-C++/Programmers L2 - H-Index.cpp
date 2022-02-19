//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> citations) {
//    sort(citations.begin(), citations.end());
//
//    for (int h = citations.size() - 1; h >= 0; h--)
//    {
//        if (citations[h] < citations.size() - h)
//        {
//            return citations.size() - h - 1;
//        }
//    }
//    return citations.size();
//}
//
//// 다른 사람의 풀이
////#include <string>
////#include <vector>
////#include <algorithm>
////
////using namespace std;
////
////int solution(vector<int> citations) {
////    sort(citations.begin(), citations.end(), greater<int>());
////
////    for (int i = 0; i < citations.size(); ++i) {
////        if (citations[i] < i + 1) {
////            return i;
////        }
////    }
////
////    return citations.size();
////}