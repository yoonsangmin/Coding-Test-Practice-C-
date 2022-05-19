//// �� Ǯ��
//// ó������ ��� �α׵��� ������, ����, �÷��� ���� �� - 0, �÷��� �� ������ ���� ���̸�ŭ ��û�� ����� �ð��� ���ؼ� üũ�ߴµ� Ʋ��
//// ������� ��Ʈ�� ����µ� �����̵� ������� Ž���ؾ� ��
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
//    // ������ ��ũ
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
//        // ������
//        time_line[i] += time_line[i - 1];
//        sum += time_line[i];
//    }
//
//    max_watch_time = sum;
//
//    for (int i = adv_time_int; i < play_time_int; i++)
//    {
//        // ������
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

//// ��ɿ� ���� �������� ���� �� - �ݺ��� �� ȸ �� �ؼ� ���� ����
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
//    // ������ ��ũ
//    for (string log : logs)
//    {
//        time_line[conv(log.substr(0, 8))]++;
//        time_line[conv(log.substr(9, 8))]--;
//    }
//
//    for (int i = 1; i <= play_time_int; i++)
//        // ������
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

//// �ٸ� ��� Ǯ�� ���� �ٽ� ǰ
//// ������ �� �� ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int conv(const string& s)
//{
//    // substr �� ���� ���۷����� �޾ƿͼ� ó���ϴϱ� �ӵ��� ������
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
//    // �����̱� ������ 0�ʴ� �� �ð��� 0
//
//    // ������ ��ũ
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
//        // ������
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

//// �ٸ� ��� Ǯ��
//// �� ����
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
//    long long psum_[360005]{}, * psum = psum_ + 2; // �迭 �������� ������
//    int T = get_time(play_time);
//    int len = get_time(adv_time);
//
//    // ������
//    for (int i = 0; i < logs.size(); ++i) {
//        string& now = logs[i];
//        int L = get_time(now.substr(0, 8));
//        int R = get_time(now.substr(9, 8));
//
//        psum[L]++;
//        psum[R]--;
//    }
//
//    //// ó�� ���� �� ������
//    //for (int i = 0; i <= T; ++i) psum[i] += psum[i - 1];
//    //// �� ��° ���� �� ��û �ð� ���� - �� �� �� �� �� ���� �ص� ��
//    //for (int i = 0; i <= T; ++i) psum[i] += psum[i - 1];
//
//    // �̷��� �ϸ� ��
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