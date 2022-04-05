//// 내 풀이
//// 모든 엣지를 끊어가면서 차이를 모두 계산함
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int get_node_number(vector<vector<int>>& edges, int head)
//{
//	int number = 0;
//	vector<bool> visited(edges.size(), false);
//	queue<int> q;
//
//	q.push(head);
//	visited[head] = true;
//
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//		number++;
//
//		for (int i = 0; i < edges[cur].size(); i++)
//		{
//			if (visited[edges[cur][i]])
//				continue;
//			else
//			{
//				visited[edges[cur][i]] = true;
//				q.push(edges[cur][i]);
//			}
//		}
//	}
//
//	return number;
//}
//
//int solution(int n, vector<vector<int>> wires) {
//    int answer = n;
//	vector<vector<int>> edges(n + 1);
//
//	for (int i = 0; i < wires.size(); i++)
//	{
//		edges[wires[i][0]].push_back(wires[i][1]);
//		edges[wires[i][1]].push_back(wires[i][0]);
//	}
//
//	for (int i = 0; i < wires.size(); i++)
//	{
//		edges[wires[i][0]].erase(find(edges[wires[i][0]].begin(), edges[wires[i][0]].end(), wires[i][1]));
//		edges[wires[i][1]].erase(find(edges[wires[i][1]].begin(), edges[wires[i][1]].end(), wires[i][0]));
//
//		answer = min(answer, abs(get_node_number(edges, wires[i][0]) - get_node_number(edges, wires[i][1])));
//
//		edges[wires[i][0]].push_back(wires[i][1]);
//		edges[wires[i][1]].push_back(wires[i][0]);
//	}
//
//    return answer;
//}

//// 다른 사람 풀이
//// 높은 레벨의 코드 테크닉이 돋보임
//// 1에서 시작해서 1을 트리의 머리로 보고 dfs로 순회하면서 각 노드와 노드의 자식들의 합을 구함
//// 각 엣지를 끊었다고 가정하고 끊은 후 엣지의 반대편의 그래프의 사이즈와 n에서 그 값을 빼면 두 그래프의 사이즈를 모두 구할 수 있음
//// 1에서 2를 끊으면 값이 제대로 나오지만 반대로 끊으면 값이 제대로 나오지 않음
//// = 1에서 부터 순회한 순서로 끊으면 답은 제대로 나오고 반대로 끊으면 쓸모 없는 값임
//// 그래도 모든 경우를 하면 답은 나옴
//// #include <bits/stdc++.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <functional>
//
//using namespace std;
//
//int solution(int n, vector<vector<int>> wires) {
//    vector<vector<int>> graph(n + 1);
//    for (int i = 0; i < (int)wires.size(); i++) {
//        int u = wires[i][0];
//        int v = wires[i][1];
//        graph[u].push_back(v);
//        graph[v].push_back(u);
//    }
//    vector<int> siz(n + 1);
//    function<void(int, int)> dfs = [&](int cur, int prev)  -> void {
//        siz[cur] = 1;
//        for (int nxt : graph[cur]) {
//            if (nxt == prev) continue;
//            dfs(nxt, cur);
//            siz[cur] += siz[nxt];
//        }
//    };
//    dfs(1, -1);
//    int answer = INT_MAX;
//    for (int i = 1; i <= n; i++) {
//        for (int j : graph[i]) {
//            int l = siz[j];
//            int r = n - siz[j];
//            answer = min(answer, abs(l - r));
//        }
//    }
//    return answer;
//}

//// bfs와 비슷하게 첫 번째로 정한 노드로부터 너비를 넓혀가며 중복 없이 first에 넣음
//// 한 엣지에 대해서만 계산을 안 함 - 노드를 끊었다고 생각
//// n - 2 * (f_ind) = (n - f_ind) - f_ind = 다른 쪽 트리의 노드의 개수, 엣지를 끊고 한 노드로부터 찾은 트리의 노드의 개수
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(int n, vector<vector<int>> wires) {
//    int answer = n;
//    for (int i = 0; i < wires.size(); i++) {
//        vector<int> first;
//        first.push_back(wires[i][0]);
//        int f_ind = 0;
//
//        while (f_ind < first.size()) {
//            for (int j = 0; j < wires.size(); j++) {
//                if (i != j) {
//                    if (first[f_ind] == wires[j][0]) {
//                        if (find(first.begin(), first.end(), wires[j][1]) == first.end())
//                            first.push_back(wires[j][1]);
//                    }
//                    else if (first[f_ind] == wires[j][1]) {
//                        if (find(first.begin(), first.end(), wires[j][0]) == first.end())
//                            first.push_back(wires[j][0]);
//                    }
//                }
//            }
//            ++f_ind;
//        }
//
//        int result = abs(n - 2 * (f_ind));
//        if (result < answer) {
//            answer = result;
//        }
//        else if (result == 0) {
//            return 0;
//        }
//
//    }
//
//    return answer;
//}

//// 길어지는 변수명을 typedef로 줄여서 부를 수 있음
//// 전체적인 풀이는 비슷함
//#include <bits/stdc++.h>
//#define rep(i,a,b) for(int i=a;i<b;++i)
//#define forn(i,n) rep(i,0,n)
//#define eb emplace_back
//using namespace std;
//typedef vector<int> vi;
//typedef vector<vi> vvi;
//typedef vector<bool> vb;
//
//vvi g;
//vi cnt;
//vb visited;
//int dfs(int cur) {
//    int size = g[cur].size();
//    forn(i, size) {
//        int next = g[cur][i];
//        if (visited[next]) continue;
//        visited[next] = true;
//        cnt[cur] += dfs(next);
//    }
//    return cnt[cur];
//}
//int solution(int n, vector<vector<int>> wires) {
//    int size = wires.size();
//    cnt.resize(n + 1);
//    visited.resize(n + 1);
//    g.resize(n + 1);
//    forn(i, n + 1) {
//        cnt[i] = 1;
//        visited[i] = false;
//    }
//    forn(i, size) {
//        g[wires[i][0]].eb(wires[i][1]);
//        g[wires[i][1]].eb(wires[i][0]);
//    }
//    visited[1] = true;
//    dfs(1);
//    int ans = (int)1e9;
//    rep(i, 1, n + 1) {
//        int cur = cnt[i];
//        ans = min(ans, max(n - cur, cur) - min(n - cur, cur));
//    }
//    return ans;
//}