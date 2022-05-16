//// �� Ǯ��
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

//// �ٽ� Ǯ�
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


//// �ٸ� ��� Ǯ��
//// function ��ü�� ����ؼ� �Լ� ���� �����߰� ĸ�ĸ� ����ؼ� ���� ���� �Ű� ������ �Ѱ����� �ʾƵ� ��
//// #include <bits/stdc++.h>
//#include <vector>
//// functional�� �� �ᵵ auto�� ���ٽ��� ��ü�� �Ҵ� ������ ��
//// #include <functional>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//// constexpr�� ������ Ÿ�ӿ� ���� �� �˾ƾ� ��
//// https://modoocode.com/293
//constexpr int INF = 1e9 + 7;
//
//int solution(vector<int> info, vector<vector<int>> edge) {
//    //// ����
//    //// 1.
//    //const int n = info.size();
//    //vector<vector<int>> adj(n);
//    //// ������� ���� ����Ʈ�� �ʱ�ȭ��
//    //for (const auto& i : edge) {
//    //    adj[i[0]].push_back(i[1]);
//    //    adj[i[1]].push_back(i[0]);
//    //}
//
//    //// 2.
//    //// par�� �θ�
//    //vector<int> par(n, -1);
//    //// ���� �Լ��� ����Ϸ��� �Ű� ������ �ڽ��� �Ѱ���� ������ ��
//    //auto DFS1 = [&](int cur, int prv, auto&& DFS1) -> void {
//    //    // �θ� ����� - ������ ���൵ �� �� ������
//    //    par[cur] = prv;
//    //    for (const auto& nxt : adj[cur]) {
//    //        if (nxt == prv) continue;
//    //        // �ڽ��� ��쿡�� ������
//    //        DFS1(nxt, cur, DFS1);
//    //    }
//    //};
//    //DFS1(0, -1, DFS1);
//    //// ������
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
//    // ����
//    // �θ� üũ�ϴ� �Ÿ� ���� ������� �ʾƵ� ��
//    // 1.
//    const int n = info.size();
//    vector<int> par(n, -1);
//    // ������� ���� ����Ʈ�� �ʱ�ȭ��
//    for (const auto& i : edge) {
//        par[i[1]] = i[0];
//    }
//
//    // 3.
//    auto GetCnt = [&](int state) -> pair<int, int> {
//        int sheep = 0, wolf = 0;
//        for (int i = 0; i < n; i++)
//            // �湮�� ���� ��常
//            if (state & 1 << i) {
//                if (info[i]) wolf++;
//                else sheep++;
//            }
//        return { sheep, wolf };
//    };
//
//    // auto& DFS2�� �ᵵ �۵���
//    auto DFS2 = [&](int state, auto&& DFS2) -> int {
//        auto [sheep, wolf] = GetCnt(state);
//        if (sheep <= wolf) return -INF;
//        int ret = sheep;
//        for (int i = 1; i < n; i++) {
//            // �湮�� ���� ��� �Ǵ� �θ� ��尡 1�� �ƴ� ���(�θ� ��带 �湮���� ���� ���) - ��� ��带 ��ȸ�ϱ� ������ ���� �θ� ��嵵 �湮���� ���� ���鵵 �� üũ�ϱ� ������ ���ܰ� �ʿ���
//            if (state & 1 << i || ~state & 1 << par[i]) continue;
//            // state�� �湮�� ���� ���� - �����ʺ��� 0�� ���, 1�� ��� �湮, 0�� ��� �̹湮
//            ret = max(ret, DFS2(state | 1 << i, DFS2));
//        }
//        return ret;
//    };
//    return DFS2(1, DFS2);
//}