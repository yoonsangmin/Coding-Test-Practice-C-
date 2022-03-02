#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

// kruskal 알고리즘 연습해보기
int find(vector<int>& root, int x)
{
    if (root[x] == x)
        return x;
    return find(root, root[x]);
}

bool union_set(vector<int>& root, int x, int y)
{
    int x_root = find(root, x);
    int y_root = find(root, y);

    if (x_root == y_root)
    {
        return false;
    }
    else
    {
        root[y_root] = x_root;
        return true;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int edge = 0;
    vector<int> root(n, 0);

    for (int i = 0; i < n; i++)
    {
        root[i] = i;
    }

    sort(costs.begin(), costs.end(), cmp);

    for (vector<int> cost : costs)
    {
        if (union_set(root, cost[0], cost[1]))
        {
            edge++;
            answer += cost[2];
        }

        if (edge == n - 1)
            break;
    }

    return answer;
}