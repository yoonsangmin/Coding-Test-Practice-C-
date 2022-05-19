//// 내 풀이
//// 처음에는 모든 로그들의 시작점, 끝점, 플레이 시작 점 - 0, 플레이 끝 점에서 광고 길이만큼 시청한 사람의 시간을 합해서 체크했는데 틀림
//// 어려워서 힌트를 얻었는데 슬라이드 윈도우로 탐색해야 함
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int conv(string s)
//{
//    return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
//}
//
//string reconv(int i)
//{
//    char buff[8];
//    sprintf(buff, "%02d:%02d:%02d", i / 3600, (i % 3600) / 60, i % 60);
//
//    return buff;
//}
//
//string solution(string play_time, string adv_time, vector<string> logs) {
//    int answer = 0;
//    long long max_watch_time = 0;
//
//    int play_time_int = conv(play_time);
//    int adv_time_int = conv(adv_time);
//
//    vector<int> time_line(play_time_int + 1, 0);
//
//    // 누적합 마크
//    for (string log : logs)
//    {
//        time_line[conv(log.substr(0, 8))]++;
//        time_line[conv(log.substr(9, 8))]--;
//    }
//
//    long long sum = time_line[0];
//   
//    for (int i = 1; i < adv_time_int; i++)
//    {
//        // 누적합
//        time_line[i] += time_line[i - 1];
//        sum += time_line[i];
//    }
//
//    max_watch_time = sum;
//
//    for (int i = adv_time_int; i < play_time_int; i++)
//    {
//        // 누적합
//        time_line[i] += time_line[i - 1];
//
//        sum -= time_line[i - adv_time_int];
//        sum += time_line[i];
//
//        if (sum > max_watch_time)
//        {
//            max_watch_time = sum;
//            answer = i - adv_time_int + 1;
//        }
//    }
//
//    return reconv(answer);
//}

//// 기능에 따라서 누적합을 따로 함 - 반복을 한 회 더 해서 조금 느림
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int conv(string s)
//{
//    return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
//}
//
//string reconv(int i)
//{
//    char buff[8];
//    sprintf(buff, "%02d:%02d:%02d", i / 3600, (i % 3600) / 60, i % 60);
//
//    return buff;
//}
//
//string solution(string play_time, string adv_time, vector<string> logs) {
//    int answer = 0;
//    long long max_watch_time = 0;
//
//    int play_time_int = conv(play_time);
//    int adv_time_int = conv(adv_time);
//
//    vector<int> time_line(play_time_int + 1, 0);
//
//    // 누적합 마크
//    for (string log : logs)
//    {
//        time_line[conv(log.substr(0, 8))]++;
//        time_line[conv(log.substr(9, 8))]--;
//    }
//
//    for (int i = 1; i <= play_time_int; i++)
//        // 누적합
//        time_line[i] += time_line[i - 1];
//
//    long long sum = 0;
//
//    for (int i = 0; i < adv_time_int; i++)
//        sum += time_line[i];
//
//    max_watch_time = sum;
//
//    for (int i = adv_time_int; i < play_time_int; i++)
//    {
//        sum -= time_line[i - adv_time_int];
//        sum += time_line[i];
//
//        if (sum > max_watch_time)
//        {
//            max_watch_time = sum;
//            answer = i - adv_time_int + 1;
//        }
//    }
//
//    return reconv(answer);
//}

//
//int main()
//{
//    solution("02:03:55", "00:14:15", { "01:20:15-01:45:14", "00:25:50-00:48:29", "00:40:31-01:00:00", "01:37:44-02:02:30", "01:30:59-01:53:29" });
//
//    return 0;
//}

//// 다른 사람 풀이 보고 다시 품
//// 누적을 두 번 함
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int conv(const string& s)
//{
//    // substr 안 쓰고 레퍼런스로 받아와서 처리하니까 속도가 빨라짐
//        int ret = ((s[0] - 48) * 10 + s[1] - 48) * 3600 +
//            ((s[3] - 48) * 10 + s[4] - 48) * 60 +
//            (s[6] - 48) * 10 + s[7] - 48;
//        return ret;
//}
//
//string reconv(int& i)
//{
//    char buff[8];
//    sprintf(buff, "%02d:%02d:%02d", i / 3600, (i % 3600) / 60, i % 60);
//
//    return buff;
//}
//
//string solution(string play_time, string adv_time, vector<string> logs) {
//    int answer = 0;
//
//    int play_time_int = conv(play_time);
//    int adv_time_int = conv(adv_time);
//
//    vector<long long> time_line(play_time_int + 2, 0);
//    // 누적이기 때문에 0초는 본 시간이 0
//
//    // 누적합 마크
//    for (int i = 0; i < logs.size(); i++)
//    {
//        string& log = logs[i];
//        time_line[conv(log.substr(0, 8)) + 1]++;
//        time_line[conv(log.substr(9, 8)) + 1]--;
//    }
//
//    long long accumulated = 0;
//
//    for (int i = 1; i <= play_time_int + 1; i++)
//    {
//        // 누적합
//        accumulated += time_line[i];
//        time_line[i] = time_line[i - 1] + accumulated;
//    }
//
//    long long max_watch_time = 0;
//
//    for (int i = 0; adv_time_int + i <= play_time_int + 1; i++)
//    {
//        long long watch_time = time_line[adv_time_int + i] - time_line[i];
//        if (watch_time > max_watch_time)
//        {
//            max_watch_time = watch_time;
//            answer = i;
//        }
//    }
//
//    return reconv(answer);
//}

//// 다른 사람 풀이
//// 더 빠름
//#include <bits/stdc++.h>
//using namespace std;
//
//int get_time(const string& s) {
//    int ret = ((s[0] - 48) * 10 + s[1] - 48) * 3600 +
//        ((s[3] - 48) * 10 + s[4] - 48) * 60 +
//        (s[6] - 48) * 10 + s[7] - 48;
//    return ret;
//}
//string solution(string play_time, string adv_time, vector<string> logs) {
//    long long psum_[360005]{}, * psum = psum_ + 2; // 배열 접근점을 조절함
//    int T = get_time(play_time);
//    int len = get_time(adv_time);
//
//    // 누적합
//    for (int i = 0; i < logs.size(); ++i) {
//        string& now = logs[i];
//        int L = get_time(now.substr(0, 8));
//        int R = get_time(now.substr(9, 8));
//
//        psum[L]++;
//        psum[R]--;
//    }
//
//    //// 처음 도는 건 누적합
//    //for (int i = 0; i <= T; ++i) psum[i] += psum[i - 1];
//    //// 두 번째 도는 건 시청 시간 누적 - 한 번 돌 때 한 번에 해도 됨
//    //for (int i = 0; i <= T; ++i) psum[i] += psum[i - 1];
//
//    // 이렇게 하면 됨
//    for (int i = 0; i <= T; ++i)
//    {
//        psum[i] += psum[i - 1];
//        psum[i - 1] += psum[i - 2];
//    }
//
//    int ans = -1;
//    long long mx = 0;
//    for (int i = 0; i + len <= T; ++i) {
//        long long hold = psum[i + len - 1] - psum[i - 1];
//        if (mx < hold) {
//            mx = hold;
//            ans = i;
//        }
//    }
//
//    string ret;
//    ret += ans / 3600 / 10 + 48;
//    ret += ans / 3600 % 10 + 48;
//    ret += ':';
//    ret += ans % 3600 / 60 / 10 + 48;
//    ret += ans % 3600 / 60 % 10 + 48;
//    ret += ':';
//    ret += ans % 60 / 10 + 48;
//    ret += ans % 60 % 10 + 48;
//
//    return ret;
//}