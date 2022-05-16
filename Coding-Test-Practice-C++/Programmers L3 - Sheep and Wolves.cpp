//// 내 풀이
//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//void traversal(vector<int>& info, vector<vector<int>>& childs, vector<int>& visited, int& answer, int cur, vector<int> to_visit, int sheep, int wolves)
//{
//    if (sheep == wolves || to_visit.size() == info.size() - 1)
//    {
//        answer = max(answer, sheep);
//        return;
//    }
//
//    for (int i = 0; i < childs[cur].size(); i++)
//        to_visit.push_back(childs[cur][i]);
//
//    for (int i = 0; i < to_visit.size(); i++)
//        if (!visited[to_visit[i]])
//        {
//            visited[to_visit[i]] = true;
//            if (info[to_visit[i]] == 0)
//                traversal(info, childs, visited, answer, to_visit[i], to_visit, sheep + 1, wolves);
//            else
//                traversal(info, childs, visited, answer, to_visit[i], to_visit, sheep, wolves + 1);
//            visited[to_visit[i]] = false;
//        }
//}
//
//int solution(vector<int> info, vector<vector<int>> edges) {
//    int answer = 0;
//    vector<vector<int>> childs(info.size());
//    vector<int> visited(info.size(), false);
//
//    for (int i = 0; i < edges.size(); i++)
//        childs[edges[i][0]].push_back(edges[i][1]);
//
//    traversal(info, childs, visited, answer, 0, {}, 1, 0);
//
//    return answer;
//}

//// 다시 풀어봄
//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//void traversal(vector<int>& info, vector<int>& parent, vector<bool>& visited, int& answer)
//{
//    int wolves = 0, sheep = 0;
//    for (int i = 0; i < info.size(); i++)
//    {
//        if (visited[i])
//        {
//            if (info[i] == 0)
//                sheep++;
//            else
//                wolves++;
//        }
//    }
//
//    if (sheep <= wolves)
//        return;
//    answer = max(answer, sheep);
//
//    for (int i = 1; i < info.size(); i++)
//    {
//        if (visited[i] || !visited[parent[i]])
//            continue;
//
//        visited[i] = true;
//        traversal(info, parent, visited, answer);
//        visited[i] = false;
//    }
//}
//
//int solution(vector<int> info, vector<vector<int>> edges) {
//    int answer = 0;
//    const int n = info.size();
//    vector<int> parent(n, -1);
//
//    for (int i = 0; i < edges.size(); i++)
//        parent[edges[i][1]] = edges[i][0];
//
//    vector<bool> visited(n, false);
//    visited[0] = true;
//
//    traversal(info, parent, visited, answer);
//
//    return answer;
//}


//// 다른 사람 풀이
//// function 객체를 사용해서 함수 내에 선언했고 캡쳐를 사용해서 굳이 많은 매개 변수를 넘겨주지 않아도 됨
//// #include <bits/stdc++.h>
//#include <vector>
//// functional을 안 써도 auto로 람다식을 객체에 할당 가능한 듯
//// #include <functional>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//// constexpr은 컴파일 타임에 값을 꼭 알아야 함
//// https://modoocode.com/293
//constexpr int INF = 1e9 + 7;
//
//int solution(vector<int> info, vector<vector<int>> edge) {
//    //// 원본
//    //// 1.
//    //const int n = info.size();
//    //vector<vector<int>> adj(n);
//    //// 양면으로 인접 리스트를 초기화함
//    //for (const auto& i : edge) {
//    //    adj[i[0]].push_back(i[1]);
//    //    adj[i[1]].push_back(i[0]);
//    //}
//
//    //// 2.
//    //// par은 부모
//    //vector<int> par(n, -1);
//    //// 람다 함수를 재귀하려면 매개 변수로 자신을 넘겨줘야 가능한 듯
//    //auto DFS1 = [&](int cur, int prv, auto&& DFS1) -> void {
//    //    // 부모를 기록함 - 위에서 해줘도 될 것 같은데
//    //    par[cur] = prv;
//    //    for (const auto& nxt : adj[cur]) {
//    //        if (nxt == prv) continue;
//    //        // 자식인 경우에만 내려감
//    //        DFS1(nxt, cur, DFS1);
//    //    }
//    //};
//    //DFS1(0, -1, DFS1);
//    //// 동일함
//    ///*
//    //vector<int> par(n, -1);
//    //function<void(int cur, int prv)> DFS1 = [&](int cur, int prv){
//    //    par[cur] = prv;
//    //    for (const auto& nxt : adj[cur]) {
//    //        if (nxt == prv) continue;
//    //        DFS1(nxt, cur);
//    //    }
//    //};
//    //DFS1(0, -1);
//    //*/
//
//    // 수정
//    // 부모만 체크하는 거면 굳이 재귀하지 않아도 됨
//    // 1.
//    const int n = info.size();
//    vector<int> par(n, -1);
//    // 양면으로 인접 리스트를 초기화함
//    for (const auto& i : edge) {
//        par[i[1]] = i[0];
//    }
//
//    // 3.
//    auto GetCnt = [&](int state) -> pair<int, int> {
//        int sheep = 0, wolf = 0;
//        for (int i = 0; i < n; i++)
//            // 방문한 곳의 노드만
//            if (state & 1 << i) {
//                if (info[i]) wolf++;
//                else sheep++;
//            }
//        return { sheep, wolf };
//    };
//
//    // auto& DFS2로 써도 작동함
//    auto DFS2 = [&](int state, auto&& DFS2) -> int {
//        auto [sheep, wolf] = GetCnt(state);
//        if (sheep <= wolf) return -INF;
//        int ret = sheep;
//        for (int i = 1; i < n; i++) {
//            // 방문한 곳의 노드 또는 부모 노드가 1이 아닌 경우(부모 노드를 방문하지 않은 경우) - 모든 노드를 순회하기 때문에 아직 부모 노드도 방문하지 않은 노드들도 다 체크하기 때문에 예외가 필요함
//            if (state & 1 << i || ~state & 1 << par[i]) continue;
//            // state는 방문한 곳의 상태 - 오른쪽부터 0번 노드, 1인 경우 방문, 0인 경우 미방문
//            ret = max(ret, DFS2(state | 1 << i, DFS2));
//        }
//        return ret;
//    };
//    return DFS2(1, DFS2);
//}