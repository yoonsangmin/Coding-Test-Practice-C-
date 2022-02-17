//#include <string>
//#include <vector>
//#include <map>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<int> priorities, int location) {
//    int answer = 0;
//    map<int, int> priority_count;
//    int max_priority = 0, cur_idx = 0;
//
//    for (int i = 0; i < priorities.size(); i++)
//    {
//        priority_count[priorities[i]]++;
//
//        if (max_priority < priorities[i])
//        {
//            max_priority = priorities[i];
//            cur_idx = i;
//        }
//    }
//
//    int order = 1;
//    while (true)
//    {
//        // cur_idx 구해야함
//        while (priorities[cur_idx] != max_priority)
//        {
//            cur_idx = (++cur_idx) % priorities.size();
//        }
//
//        // cur에 있는 애를 0으로 만듦
//        priorities[cur_idx] = 0;
//
//        if (cur_idx == location)
//        {
//            return order;
//        }
//
//        // priority_count 값을 줄임
//        priority_count[max_priority]--;
//
//        // priority_count 값이 0이면 다음 0이 아닌 max_priority를 구함
//        while (priority_count[max_priority] == 0)
//        {
//            max_priority--;
//        }
//
//
//        order++;
//    }
//
//
//
//
//    return answer;
//}
//
//
//// 다른 사람 풀이
////#include <algorithm>
////#include <string>
////#include <vector>
////
////using namespace std;
////
////int solution(vector<int> priorities, int location) {
////    int answer = 0;
////    int max = *max_element(priorities.begin(), priorities.end());
////    while (true)
////    {
////        for (int i = 0; i < priorities.size(); ++i)
////        {
////            if (priorities[i] == max)
////            {
////                ++answer;
////
////                if (i == location)
////                    return answer;
////
////                priorities[i] = 0;
////                max = *max_element(priorities.begin(), priorities.end());
////            }
////        }
////    }
////}
//
//void main()
//{
//    cout << solution({3, 4, 3}, 0);
//}