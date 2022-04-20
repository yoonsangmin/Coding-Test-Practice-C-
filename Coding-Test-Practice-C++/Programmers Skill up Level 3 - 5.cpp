//// 1번 문제 내 풀이
//// 입국 심사 - 이진 탐색
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//long long solution(int n, vector<int> times) {
//    long long answer = 0;
//
//    long long left = 0;
//    long long right = (long long)*max_element(times.begin(), times.end()) * n;
//    long long mid, pass;
//
//    while (left <= right)
//    {
//        mid = (left + right) / 2;
//        pass = 0;
//        
//        for (int i = 0; i < times.size(); i++)
//        {
//            pass += mid / times[i];
//        }
//
//        if (pass >= n)
//        {
//            answer = mid;
//            right = mid - 1;
//        }
//        else
//        {
//            left = mid + 1;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution(6, { 7, 10 });
//
//    return 0;
//}

//// 2번 문제
//// 제재된 사용자
//#include <string>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//void dfs(vector<vector<int>>& match, vector<int> v, int idx, set<set<int>>& answer_set)
//{
//    if (idx == match.size())
//    {
//        set<int> s;
//        for (int i = 0; i < v.size(); i++)
//        {
//            s.insert(v[i]);
//        }
//        
//        if (s.size() == match.size())
//            answer_set.insert(s);
//
//        return;
//    }
//
//    for (int i = 0; i < match[idx].size(); i++)
//    {
//        v.push_back(match[idx][i]);
//        dfs(match, v, idx + 1, answer_set);
//        v.pop_back();
//    }
//}
//
//int solution(vector<string> user_id, vector<string> banned_id) {
//    vector<vector<int>> match(banned_id.size());
//    set<set<int>> answer_set;
//
//    for (int i = 0; i < banned_id.size(); i++)
//    {
//        for (int j = 0; j < user_id.size(); j++)
//        {
//            if (banned_id[i].size() != user_id[j].size())
//                continue;
//
//            bool is_same = true;
//            for (int k = 0; k < banned_id[i].size(); k++)
//            {
//                if (banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k])
//                {
//                    is_same = false;
//                    break;
//                }
//            }
//
//            if (is_same)
//            {
//                match[i].push_back(j);
//            }
//        }
//    }
//
//    dfs(match, {}, 0, answer_set);
//
//    return answer_set.size();
//}