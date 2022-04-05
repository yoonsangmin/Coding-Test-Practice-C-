//// �� Ǯ��
//// ��� ������ ����鼭 ���̸� ��� �����
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

//// �ٸ� ��� Ǯ��
//// ���� ������ �ڵ� ��ũ���� ������
//// 1���� �����ؼ� 1�� Ʈ���� �Ӹ��� ���� dfs�� ��ȸ�ϸ鼭 �� ���� ����� �ڽĵ��� ���� ����
//// �� ������ �����ٰ� �����ϰ� ���� �� ������ �ݴ����� �׷����� ������� n���� �� ���� ���� �� �׷����� ����� ��� ���� �� ����
//// 1���� 2�� ������ ���� ����� �������� �ݴ�� ������ ���� ����� ������ ����
//// = 1���� ���� ��ȸ�� ������ ������ ���� ����� ������ �ݴ�� ������ ���� ���� ����
//// �׷��� ��� ��츦 �ϸ� ���� ����
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

//// bfs�� ����ϰ� ù ��°�� ���� ���κ��� �ʺ� �������� �ߺ� ���� first�� ����
//// �� ������ ���ؼ��� ����� �� �� - ��带 �����ٰ� ����
//// n - 2 * (f_ind) = (n - f_ind) - f_ind = �ٸ� �� Ʈ���� ����� ����, ������ ���� �� ���κ��� ã�� Ʈ���� ����� ����
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

//// ������� �������� typedef�� �ٿ��� �θ� �� ����
//// ��ü���� Ǯ�̴� �����
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