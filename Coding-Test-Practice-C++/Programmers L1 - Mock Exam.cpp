//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int p1[] = { 1, 2, 3, 4, 5 };
//int p2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
//int p3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
//
//bool cmp(pair<int, int> p1, pair<int, int> p2)
//{
//    if (p1.first == p2.first)
//        return p1.second < p2.second;
//
//    return p1.first > p2.first;
//}
//
//vector<int> solution(vector<int> answers) {
//    vector<int> answer;
//    vector<pair<int, int>> scores;
//
//    scores.push_back({ 0, 1 });
//    scores.push_back({ 0, 2 });
//    scores.push_back({ 0, 3 });
//
//    for (int i = 0; i < answers.size(); i++)
//    {
//        if (answers[i] == p1[i % 5])
//        {
//            scores[0].first++;
//        }
//        if (answers[i] == p2[i % 8])
//        {
//            scores[1].first++;
//        }
//        if (answers[i] == p3[i % 10])
//        {
//            scores[2].first++;
//        }
//    }
//
//    sort(scores.begin(), scores.end(), cmp);
//
//    answer.push_back(scores[0].second);
//
//    for (int i = 1; i < scores.size(); i++)
//    {
//        if (scores[i - 1].first == scores[i].first)
//        {
//            answer.push_back(scores[i].second);
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    return answer;
//}
//
//// 다른 사람 풀이
////#include <string>
////#include <vector>
////#include <algorithm>
////
////using namespace std;
////
////vector<int> one = { 1,2,3,4,5 };
////vector<int> two = { 2,1,2,3,2,4,2,5 };
////vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };
////
////vector<int> solution(vector<int> answers) {
////    vector<int> answer;
////    vector<int> they(3);
////    for (int i = 0; i < answers.size(); i++) {
////        if (answers[i] == one[i % one.size()]) they[0]++;
////        if (answers[i] == two[i % two.size()]) they[1]++;
////        if (answers[i] == thr[i % thr.size()]) they[2]++;
////    }
////    int they_max = *max_element(they.begin(), they.end());
////    for (int i = 0; i < 3; i++) {
////        if (they[i] == they_max) answer.push_back(i + 1);
////    }
////    return answer;
////}