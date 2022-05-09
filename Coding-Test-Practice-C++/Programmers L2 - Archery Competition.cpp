//// �� Ǯ��
//// ���� ������ ���ߴ� ��� ���� �����
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int get_score_diff(const vector<int>& peach, const vector<int>& lion)
//{
//    int peach_score = 0;
//    int lion_score = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (peach[i] == 0 && lion[i] == 0)
//            continue;
//
//        if (peach[i] < lion[i])
//            lion_score += (10 - i);
//        else
//            peach_score += (10 - i);
//    }
//
//    return lion_score > peach_score ? lion_score - peach_score : 0;
//}
//
//void dfs(int n, const vector<int>& info, int aim, vector<int> target, vector<int>& answer, int& score)
//{
//    if (n == 0)
//    {
//        // ���� ���� ��
//        int temp_score = get_score_diff(info, target);
//
//        if (temp_score > score)
//        {
//            score = temp_score;
//
//            answer = target;
//        }
//
//        return;
//    }
//
//    for (int i = aim; i >= 0; i--)
//    {
//        if (n > info[i])
//        {
//            target[i] = info[i] + 1;
//            dfs(n - info[i] - 1, info, i - 1, target, answer, score);
//            target[i] = 0;
//        }
//    }
//
//    target[10] = n;
//    dfs(0, info, 11, target, answer, score);
//}
//
//vector<int> solution(int n, vector<int> info) {
//    vector<int> answer(11, 0);
//    int score = 0;
//    vector<int> target(11, 0);
//	  
//    // 10���� �����ص� ��
//    dfs(n, info, 10, target, answer, score);
//
//    return score ? answer : vector<int>(1, -1);
//}

//// �ٸ� Ǯ��
//// ���� ���̰� ���� ��� ���� ������ �� ���� ���� ���� �������� �ٲ� ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int get_score_diff(const vector<int>& peach, const vector<int>& lion)
//{
//    int peach_score = 0;
//    int lion_score = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (peach[i] == 0 && lion[i] == 0)
//            continue;
//
//        if (peach[i] < lion[i])
//            lion_score += (10 - i);
//        else
//            peach_score += (10 - i);
//    }
//
//    return lion_score > peach_score ? lion_score - peach_score : 0;
//}
//
//void dfs(int n, const vector<int>& info, int aim, vector<int> target, vector<int>& answer, int& score)
//{
//    if (n == 0)
//    {
//        // ���� ���� ��
//        int temp_score = get_score_diff(info, target);
//
//        if (temp_score > score)
//        {
//            score = temp_score;
//
//            answer = target;
//        }
//        else if (temp_score == score)
//        {
//            bool flag = true;
//			  // i = 9���� �����ص� �ǰ� 10���� �����ص� ��
//			  // ���� 4�� ���� �������� �Ϳ� ���� ���ߴ� ���� ������ - ������ ���� �ʴ� ���� ���ߴ� ���� �ǹ̰� ���� - �׷� �ٿ� �������� �ϴ� �� ����
//            for (int i = 10; i >= 0; i--)
//            {
//                if (answer[i] == target[i])
//                    continue;
//                if (answer[i] > target[i])
//                    flag = false;
//                break;
//            }
//
//            if (flag)
//            {
//                score = temp_score;
//
//                answer = target;
//            }
//            
//        }
//
//        return;
//    }
//
//    for (int i = aim; i <= 10; i++)
//    {
//        if (i == 10)
//        {
//            target[i] = n;
//            dfs(0, info, i + 1, target, answer, score);
//        }
//        else if (n > info[i])
//        {
//            target[i] = info[i] + 1;
//            dfs(n - info[i] - 1, info, i + 1, target, answer, score);
//            target[i] = 0;
//        }
//    }
//}
//
//vector<int> solution(int n, vector<int> info) {
//    vector<int> answer(11, 0);
//    int score = 0;
//    vector<int> target(11, 0);
//
//    dfs(n, info, 0, target, answer, score);
//
//    return score ? answer : vector<int>(1, -1);
//}
//
//int main()
//{
//    solution(10, { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 });
//
//    return 0;
//}

//// �ٸ� ��� Ǯ��
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//int N, ans;
//vector<int> answer;
//int a[11];
//int r[11];
//void solve(int cnt, int idx) {
//    // ȭ���� ��� ���� ���
//    if (cnt == N) {
//        int asum = 0;
//        int rsum = 0;
//        // ���� ���
//        for (int i = 0; i <= 10; i++) {
//            if (a[i] == r[i] && a[i] == 0) continue;
//            if (r[i] > a[i]) rsum += i;
//            else asum += i;
//        }
//		  // ó�� ã�� ���� �ٲ��� ����
//        if (ans < rsum - asum) {
//            ans = rsum - asum;
//            answer.clear();
//            for (int i = 10; i >= 0; i--) {
//                answer.push_back(r[i]);
//            }
//        }
//    }
//    // ȭ���� �ϳ����� ��鼭 ������ - ȭ���� ��� ������ ���� �ʴ� ��쵵 ��� ����� �� ����
//    // ȭ���� ���� ������ ��� ��� �� ���� �� �߾� ���� ������ ��鼭 ��� ����� ���� ����� �� ����
//	  // ó�� ã�� ���� ��ȿ�� ���ΰ�? - ���� ������ ������� ���߱� ������ ��ȿ��
//    for (int i = idx; i <= 10; i++) {
//        if (a[i] >= r[i]) {
//            r[i]++;
//            solve(cnt + 1, i);
//            r[i]--;
//        }
//    }
//}
//
//vector<int> solution(int n, vector<int> info) {
//    N = n;
//    // info�� ����� a�� ����
//    for (int i = 10; i >= 0; i--) a[10 - i] = info[i];
//    solve(0, 0);
//    if (answer.empty()) answer.push_back(-1);
//    return answer;
//}
//
//int main()
//{
//    solution(10, { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 });
//}

//#include<vector>
//using namespace std;
//
//// ���, dfs�� ������� ����, ��� ��츦 �� �� �� ����, ���� �ٸ� ����� Ǯ�̺��ٴ� ���� - ���� �����ϰ� ���� ����(������ ��� ��츸 ����ϱ� ����, �ݸ鿡 ���� Ǯ�̴� ������ ���� �ʴ� ��쵵 ��� ��츦 �� �˻���)
//vector<int> solution(int n, vector<int> info) {
//    vector<int> ans(11);
//    int mx = 0;
//    // ��Ʈ�� ��������
//    // 2�� 11�� = 2048
//    // 2�� 0�º��� 2�� 10�±���
//    for (int i = 0; i < 2048; ++i) {
//        vector<int> cdd(11);
//        int sum = 0, score = 0;
//        // ȭ���� ���� �� üũ
//        for (int j = 0; j < 11; ++j) if (i & 1 << j) {
//            // ȭ���� ���� ���(������ ��� ���) ��ġ�� ȭ���� �������� 1��ŭ ȭ���� �� ����
//            // sum�� ȭ�� ������ ��
//            sum += cdd[10 - j] = info[10 - j] + 1;
//            // ȭ�� ���� ���� ���� ������
//            score += j;
//        }
//        // ȭ���� ���� ���� ���, ��ġ�� �ش� ������ ȭ���� ������ �ʾ����� �ƹ��ϵ� ����, �ش� ������ ȭ���� ���� ��� ��ġ�� �����̱� ������ score���� ���� - score�� ���� ��
//        else score -= info[10 - j] ? j : 0;
//
//        // ȭ�� ������ �ѱ� ���, ���� ���� 0���� ���� ��� = ��ġ�� ��, ���� ���� ������ ���� �亸�� ���� ��� - ��� x
//        if (sum > n || score <= 0 || mx > score) continue;
//        // ���� ȭ���� ������ ���� ������
//        cdd[10] += n - sum;
//
//        // ���� ���� ������ ���� �亸�� �� ũ��
//        if (mx < score) ans = cdd;
//        // ���� ���� ���� ���
//        else {
//            // ������ ���� ��� ���ؼ� ���� ������ �� ���� ���� ��츦 ������ ������
//            bool f = 1;
//            for (int j = 11; j--; ) {
//                if (ans[j] < cdd[j]) break;
//                if (ans[j] > cdd[j]) {
//                    f = 0;
//                    break;
//                }
//            }
//
//            if (f) ans = cdd;
//        }
//        // ���� ���� ū ������ ����
//        mx = score;
//    }
//
//    if (mx) return ans;
//
//    return { -1 };
//}
