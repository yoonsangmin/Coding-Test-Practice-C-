//// 1번 문제
//// 야간 아르바이트 동전 거슬러 주기
//// 다이나믹 프로그래밍 문제 - 공부 많이 하기
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void dfs(vector<int>& money, int idx, int n, int& answer)
//{
//    if (n == 0)
//    {
//        answer += 1;
//        answer %= 1000000007;
//        return;
//    }
//
//    if (idx == money.size())
//    {
//        return;
//    }
//
//    for (int i = 0; i * money[idx] <= n; i++)
//    {
//        dfs(money, idx + 1, n - i * money[idx], answer);
//    }
//}
//
//int solution(int n, vector<int> money) {
//    int answer = 0;
//
//    sort(money.begin(), money.end(), greater<>());
//
//    dfs(money, 0, n, answer);
//
//    return answer;
//}

//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n, vector<int> money) {
//    int answer = 0;
//    vector<int> dt(n + 1, 0);
//    // 중요 - 만약 5원에서 5원짜리 동전으로 계산할 때 dt[j - 5] = dt[0] 이 1이여야 1회가 증가함
//    dt[0] = 1;
//
//    // 1부터해서 아래와 같이 하면 0일 때 알아서 세팅됨
//	  // dt[i] = i % money[0] == 0 ? 1 : 0;
//    for (int i = 1; i <= n; i++)
//        if (i % money[0] == 0)
//            dt[i] = 1;
//
//    for (int i = 1; i < money.size(); i++)
//    {
//        for (int j = money[i]; j <= n; j++)
//        {
//            dt[j] = (dt[j] + dt[j - money[i]]) % 1000000007;
//        }
//    }
//
//    answer = dt[n];
//
//    return answer;
//}

//// 옛날 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n, vector<int> money) {
//    int answer = 0;
//    vector<int> dp(n + 1);
//
//    for (int i = 0; i <= n; i++)
//        dp[i] = ((i % money[0] == 0) ? 1 : 0);
//
//    for (int i = 1; i < money.size(); i++)
//        for (int j = money[i]; j <= n; j++)
//            dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
//
//    answer = dp[n];
//    return answer;
//}

// 2번 문제
// 가중치 트리 가중치 0 만들기
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void dfs(vector<vector<int>>& g, vector<bool>& visited, vector<long long>& n, long long& answer, int cur)
//{
//    for (int i = 0; i < g[cur].size(); i++)
//    {
//        if (visited[g[cur][i]])
//            continue;
//        visited[g[cur][i]] = true;
//        dfs(g, visited, n, answer, g[cur][i]);
//        long long temp = n[g[cur][i]];
//        n[cur] += temp;
//        answer += abs(temp);
//    }
//}
//
//long long solution(vector<int> a, vector<vector<int>> edges) {
//    long long answer = 0;
//    int sum = 0;
//    bool is_zero = true;
//
//    for (int i = 0; i < a.size(); i++)
//    {
//        if (a[i] != 0)
//        {
//            sum += a[i];
//            is_zero = false;
//        }
//    }
//
//    if (is_zero)
//        return 0;
//    if (sum != 0)
//        return -1;
//
//    vector<vector<int>> g(a.size());
//    vector<bool> visited(a.size(), false);
//    vector<long long> n(a.begin(), a.end());
//
//    for (int i = 0; i < edges.size(); i++)
//    {
//        g[edges[i][0]].push_back(edges[i][1]);
//        g[edges[i][1]].push_back(edges[i][0]);
//    }
//
//    visited[0] = true;
//    dfs(g, visited, n, answer, 0);
//
//    return answer;
//}
//
//int main()
//{
//    solution({ -5, 0, 2, 1, 2 }, { {0, 1},{3, 4},{2, 3},{0, 3} });
//
//    return 0;
//}