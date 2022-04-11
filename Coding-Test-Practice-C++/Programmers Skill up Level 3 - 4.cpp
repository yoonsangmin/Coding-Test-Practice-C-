//// 1번 문제
//// 플로이드 워셜 문제
//// 합승 택시 요금
//#include <string>
//#include <vector>
//#include <algorithm>
//#define INF 20000000
//
//using namespace std;
//
//int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//    int answer = INF;
//    vector<vector<int>> graph(n, vector<int>(n, INF));
//
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            if (i == j)
//                graph[i][j] = 0;
//
//    for (vector<int> fare : fares)
//    {
//        graph[fare[0] - 1][fare[1] - 1] = fare[2];
//        graph[fare[1] - 1][fare[0] - 1] = fare[2];
//    }
//    
//    for (int k = 0; k < n; k++)
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j < n; j++)
//            {
//                int temp = min(graph[i][j], graph[i][k] + graph[k][j]);
//                graph[i][j] = temp;
//                graph[j][i] = temp;
//            }       
//     
//    for (int i = 0; i < n; i++)
//        answer = min(answer, graph[s - 1][i] + graph[i][a - 1] + graph[i][b - 1]);
//
//    return answer;
//}
//
//int main()
//{
//    solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}} );
//
//    return 0;
//}
//// 다른 사람 풀이
//// 도착 점에서 출발한다고 생각하면 다익스트라를 사용할 수 있음
//// 오히려 더 빠름
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//#define inf 1987654321
//int res[3][201];
//struct Node {
//    vector<pair<int, int>> next;
//};
//Node node[201];
//void dij(int idx, int n, int start) {
//    res[idx][start] = 0;
//    priority_queue<pair<int, int>> pq;
//    pq.push({ -0, start });
//    for (int i = 1; i <= n; i++) res[idx][i] = inf;
//    while (!pq.empty()) {
//        auto cur = pq.top();
//        pq.pop();
//        if (res[idx][cur.second] != inf) continue;
//        int cost = -cur.first;
//        res[idx][cur.second] = cost;
//        for (int i = 0; i < node[cur.second].next.size(); i++) {
//            auto next = node[cur.second].next[i];
//            if (res[idx][next.second] != inf) continue;
//            pq.push({ -(cost + next.first), next.second });
//        }
//    }
//}
//int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
//    int answer = 0;
//    for (int i = 0; i < fares.size(); i++) {
//        node[fares[i][0]].next.push_back({ fares[i][2] ,fares[i][1] });
//        node[fares[i][1]].next.push_back({ fares[i][2] ,fares[i][0] });
//    }
//    dij(0, n, s);
//    dij(1, n, a);
//    dij(2, n, b);
//    answer = inf;
//    for (int i = 1; i <= n; i++) {
//        answer = min(answer, res[0][i] + res[1][i] + res[2][i]);
//    }
//    return answer;
//}

// 2번 문제
// 아이템 줍기
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> mix;

    for (vector<int> elem : rectangle)
    {

    }

    return answer;
}