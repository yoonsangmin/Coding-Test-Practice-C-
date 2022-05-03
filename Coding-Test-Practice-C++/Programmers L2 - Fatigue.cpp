//// 내 풀이
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////bool cmp(vector<int> v1, vector<int> v2)
////{
////    return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
////}
//
//void dfs(int k, const vector<vector<int>>& dungeons, vector<bool>& visited, int& answer, int clear)
//{
//    answer = max(answer, clear);
//
//    for (int i = 0; i < dungeons.size(); i++)
//    {
//        if (visited[i] || k < dungeons[i][0])
//            continue;
//        
//        visited[i] = true;
//        // k를 깊은 복사로 넘겨주면 뺐다가 다시 더하는 작업을 없애도 됨 - 어차피 int 변수라 주솟값 넘겨주는 거랑 변수 복사하는 거랑 용량 차이가 없을 것 같음
//        // k -= dungeons[i][1];
//        dfs(k - dungeons[i][1], dungeons, visited, answer, clear + 1);
//        visited[i] = false;
//        // k += dungeons[i][1];
//    }
//}
//
//// brutal force이기 때문에 정렬이 의미가 없음
//int solution(int k, vector<vector<int>> dungeons) {
//    int answer = -1;
//    vector<bool> visited(dungeons.size(), false);
//
//    // sort(dungeons.begin(), dungeons.end(), cmp);
//    dfs(k, dungeons, visited, answer, 0);
//
//    return answer;
//}
//
//int main()
//{
//    solution(80, {{80, 20}, { 50, 40}, { 30, 10}});
//}

//// 다른 사람 풀이
//// 재귀 로직이 멋있긴 한데 다른 풀이에 비해 조금 느림 - visited를 사용하지 않고 새로 배열을 만들어서 그런 것 같음
//#include <vector>
//using namespace std;
//
//// 솔루션 자체를 재귀로 만들었음
//int solution(int k, vector<vector<int>> d) {
//    int ans = 0;
//    for (auto it = d.begin(); it != d.end(); it++) {
//        if (k >= (*it)[0]) {
//            // it 이터레이터의 위치를 제외한 새로운 배열을 만듦
//            auto d2 = vector(d.begin(), it);
//            d2.insert(d2.end(), it + 1, d.end());
//
//            // 새로운 배열을 d로 다시 넘겨줌
//            // s는 현재까지 탐험한 던전의 개수로 재귀 후 나온 결과에서 1을 더해줌
//            int s = solution(k - (*it)[1], d2) + 1;
//            ans = s > ans ? s : ans;
//        }
//    }
//    return ans;
//}