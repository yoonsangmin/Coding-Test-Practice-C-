//// �� Ǯ��
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
//        // k�� ���� ����� �Ѱ��ָ� ���ٰ� �ٽ� ���ϴ� �۾��� ���ֵ� �� - ������ int ������ �ּڰ� �Ѱ��ִ� �Ŷ� ���� �����ϴ� �Ŷ� �뷮 ���̰� ���� �� ����
//        // k -= dungeons[i][1];
//        dfs(k - dungeons[i][1], dungeons, visited, answer, clear + 1);
//        visited[i] = false;
//        // k += dungeons[i][1];
//    }
//}
//
//// brutal force�̱� ������ ������ �ǹ̰� ����
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

//// �ٸ� ��� Ǯ��
//// ��� ������ ���ֱ� �ѵ� �ٸ� Ǯ�̿� ���� ���� ���� - visited�� ������� �ʰ� ���� �迭�� ���� �׷� �� ����
//#include <vector>
//using namespace std;
//
//// �ַ�� ��ü�� ��ͷ� �������
//int solution(int k, vector<vector<int>> d) {
//    int ans = 0;
//    for (auto it = d.begin(); it != d.end(); it++) {
//        if (k >= (*it)[0]) {
//            // it ���ͷ������� ��ġ�� ������ ���ο� �迭�� ����
//            auto d2 = vector(d.begin(), it);
//            d2.insert(d2.end(), it + 1, d.end());
//
//            // ���ο� �迭�� d�� �ٽ� �Ѱ���
//            // s�� ������� Ž���� ������ ������ ��� �� ���� ������� 1�� ������
//            int s = solution(k - (*it)[1], d2) + 1;
//            ans = s > ans ? s : ans;
//        }
//    }
//    return ans;
//}