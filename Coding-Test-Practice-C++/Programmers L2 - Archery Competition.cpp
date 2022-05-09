//// 내 풀이
//// 낮은 점수를 맞추는 경우 부터 계산함
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
//        // 점수 차이 비교
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
//    // 10부터 시작해도 됨
//    dfs(n, info, 10, target, answer, score);
//
//    return score ? answer : vector<int>(1, -1);
//}

//// 다른 풀이
//// 점수 차이가 같을 경우 낮은 점수를 더 많이 맞춘 것을 정답으로 바꿔 줌
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
//        // 점수 차이 비교
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
//			  // i = 9부터 시작해도 되고 10부터 시작해도 됨
//			  // 예제 4번 보면 빗나가는 것에 많이 맞추는 것이 정답임 - 점수를 내지 않는 곳에 맞추는 것은 의미가 없음 - 그럴 바엔 빗나가게 하는 게 정답
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

//// 다른 사람 풀이
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//int N, ans;
//vector<int> answer;
//int a[11];
//int r[11];
//void solve(int cnt, int idx) {
//    // 화살을 모두 썼을 경우
//    if (cnt == N) {
//        int asum = 0;
//        int rsum = 0;
//        // 점수 계산
//        for (int i = 0; i <= 10; i++) {
//            if (a[i] == r[i] && a[i] == 0) continue;
//            if (r[i] > a[i]) rsum += i;
//            else asum += i;
//        }
//		  // 처음 찾은 답을 바꾸지 않음
//        if (ans < rsum - asum) {
//            ans = rsum - asum;
//            answer.clear();
//            for (int i = 10; i >= 0; i--) {
//                answer.push_back(r[i]);
//            }
//        }
//    }
//    // 화살을 하나씩만 쏘면서 진행함 - 화살을 쏘고도 점수를 얻지 않는 경우도 모두 고려할 수 있음
//    // 화살을 낮은 점수에 모두 쏘고 그 다음 한 발씩 다음 점수에 쏘면서 모든 경우의 수를 고려할 수 있음
//	  // 처음 찾은 답이 유효한 답인가? - 낮은 점수의 과녁부터 맞추기 때문에 유효함
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
//    // info를 뒤집어서 a에 넣음
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
//// 재귀, dfs를 사용하지 않음, 모든 경우를 다 볼 수 있음, 위의 다른 사람의 풀이보다는 빠름 - 거의 일정하게 답이 나옴(점수를 얻는 경우만 계산하기 때문, 반면에 위의 풀이는 점수를 얻지 않는 경우도 모든 경우를 다 검사함)
//vector<int> solution(int n, vector<int> info) {
//    vector<int> ans(11);
//    int mx = 0;
//    // 비트로 만들어버림
//    // 2의 11승 = 2048
//    // 2의 0승부터 2의 10승까지
//    for (int i = 0; i < 2048; ++i) {
//        vector<int> cdd(11);
//        int sum = 0, score = 0;
//        // 화살이 맞은 곳 체크
//        for (int j = 0; j < 11; ++j) if (i & 1 << j) {
//            // 화살이 맞은 경우(점수를 얻는 경우) 피치의 화살의 개수보다 1만큼 화살을 더 맞춤
//            // sum에 화살 개수의 합
//            sum += cdd[10 - j] = info[10 - j] + 1;
//            // 화살 맞은 곳의 점수 더해줌
//            score += j;
//        }
//        // 화살이 맞지 않은 경우, 피치도 해당 점수에 화살을 맞히지 않았으면 아무일도 없고, 해당 점수에 화살을 맞춘 경우 피치의 득점이기 때문에 score에서 빼줌 - score는 점수 차
//        else score -= info[10 - j] ? j : 0;
//
//        // 화살 개수를 넘긴 경우, 점수 차가 0보다 작은 경우 = 피치의 승, 점수 차가 이전에 구한 답보다 작은 경우 - 계산 x
//        if (sum > n || score <= 0 || mx > score) continue;
//        // 남은 화살을 빗나간 경우로 더해줌
//        cdd[10] += n - sum;
//
//        // 점수 차가 이전에 구한 답보다 더 크면
//        if (mx < score) ans = cdd;
//        // 점수 차가 같은 경우
//        else {
//            // 이전에 구한 답과 비교해서 작은 점수를 더 많이 맞춘 경우를 답으로 설정함
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
//        // 점수 차를 큰 값으로 변경
//        mx = score;
//    }
//
//    if (mx) return ans;
//
//    return { -1 };
//}
