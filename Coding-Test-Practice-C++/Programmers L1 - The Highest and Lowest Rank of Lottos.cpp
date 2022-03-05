//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> lottos, vector<int> win_nums) {
//    vector<int> answer;
//    int blanks = 0;
//    int corrects = 0;
//
//    for (int i = 0; i < 6; i++)
//    {
//        if (lottos[i] == 0)
//        {
//            blanks++;
//        }
//
//        else if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
//        {
//            corrects++;
//        }
//    }
//
//    if (7 - (corrects + blanks) < 6)
//        answer.push_back(7 - (corrects + blanks));
//    else
//        answer.push_back(6);
//    if(7 - corrects < 6)
//        answer.push_back(7 - corrects);
//    else
//        answer.push_back(6);
//
//    return answer;
//}
//
////// 조건문 대신 이런식으로 간단하게 맞은 개수에 맞는 순위를 구할 수 있음
////int rank[7] = { 6, 6, 5, 4, 3, 2, 1 };
////answer.push_back(rank[max_count]);
////answer.push_back(rank[min_count]);