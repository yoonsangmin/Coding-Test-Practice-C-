//#include <string>
//#include <vector>
//
//using namespace std;
//
//int shortest;
//
//// 내 풀이
//// bfs로 모든 경로 다 찾음
//void bfs(string& name, vector<bool> visited, vector<int> q, int num)
//{
//    int cur = q.front();
//    q.erase(q.begin());
//
//    visited[cur] = true;
//    bool is_last = true;
//
//    for (int i = 1; i < name.size(); i++)
//    {
//        int temp = cur + i;
//
//        if (temp >= name.size()) temp -= name.size();
//
//        if (!visited[temp])
//        {
//            q.push_back(temp);
//            bfs(name, visited, q, num + i);
//
//            q.pop_back();
//            is_last = false;
//            break;
//        }
//    }
//
//    if (is_last)
//    {
//        if (shortest > num)  shortest = num;
//
//        return;
//    }
//
//    for (int i = 1; i < name.size(); i++)
//    {
//        int temp = cur - i;
//
//        if (temp < 0) temp += name.size();
//
//        if (!visited[temp])
//        {
//            q.push_back(temp);
//            bfs(name, visited, q, num + i);
//
//            q.pop_back();
//            break;
//        }
//    }
//}
//
//int solution(string name) {
//    int answer = 0;
//
//    for (char letter : name)
//    {
//        int up = letter - 'A', down = 26 - up;
//        
//        if (up < down) answer += up;
//        else answer += down;
//    }
//
//    shortest = name.size();
//    vector<bool> visited(name.size(), true);
//
//    for (int i = 1; i < name.size(); i++)
//    {
//        if (name[i] != 'A') visited[i] = false;
//    }
//
//    bfs(name, visited, {0}, 0);
//
//    answer += shortest;
//
//    return answer;
//}
//
//int main()
//{
//    solution("JEROEN");
//
//    return 0;
//}

//// 다른 사람 풀이, 식으로 된 부분 이해하는데 오래 걸림
//// 연속된 A를 만날 때까지 왼쪽 또는 오른쪽으로 간 다음 다시 반대로 가서 연속된 A의 반대 부분까지 갈 때 왼쪽으로 가는 게 좋은 지 오른쪽으로 가는 게 좋은 지 체크
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
//
//int solution(string name) {
//    int answer = 0;
//    for (auto ch : name)
//        answer += LUT[ch - 'A'];
//    int len = name.length();
//    int left_right = len - 1;
//    for (int i = 0; i < len; ++i) {
//        int next_i = i + 1;
//        while (next_i < len && name[next_i] == 'A')
//            next_i++;
//        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
//    }
//    answer += left_right;
//    return answer;
//}