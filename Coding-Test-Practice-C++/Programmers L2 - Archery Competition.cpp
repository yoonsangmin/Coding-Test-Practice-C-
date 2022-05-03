//#include <string>
//#include <vector>
//
//using namespace std;
//
//int get_score_diff(const vector<int>& peach, const vector<int>& lion)
//{
//    int peach_score = 0;
//    int lion_score = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (peach[i] == 0 && lion[i] == 0)
//            continue;
//
//        if (peach[i] < lion[i])
//            lion_score += (10 - i);
//        else
//            peach_score += (10 - i);
//    }
//
//    return lion_score > peach_score ? lion_score - peach_score : 0;
//}
//
//void dfs(int n, const vector<int>& info, int aim, vector<int> target, vector<int>& answer, int& score)
//{
//    if (n == 0)
//    {
//        // 점수 차이 비교
//        int temp_score = get_score_diff(info, target);
//
//        if (temp_score > score)
//        {
//            score = temp_score;
//
//            answer = target;
//        }
//
//        return;
//    }
//
//    for (int i = aim; i >= 0; i--)
//    {
//        if (n > info[i])
//        {
//            target[i] = info[i] + 1;
//            dfs(n - info[i] - 1, info, i - 1, target, answer, score);
//            target[i] = 0;
//        }
//    }
//
//    target[10] = n;
//    dfs(0, info, 11, target, answer, score);
//}
//
//vector<int> solution(int n, vector<int> info) {
//    vector<int> answer(11, 0);
//    int score = 0;
//    vector<int> target(11, 0);
//	
//    dfs(n, info, 9, target, answer, score);
//
//    return score ? answer : vector<int>(1, -1);
//}
//
//int main()
//{
//    solution(10, { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 });
//
//    return 0;
//}