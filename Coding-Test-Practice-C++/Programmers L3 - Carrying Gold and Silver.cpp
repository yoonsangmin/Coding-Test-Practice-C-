//// Ʋ�� Ǯ��
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
//    const int N = g.size();
//    long long answer = -1;
//    long long start = 0, end = 1e14 * 4 + 1e5;
//    long long mid;
//    answer = end;
//
//    while (start <= end)
//    {
//        mid = (start + end) / 2;
//
//        double a_temp = 0, b_temp = 0;
//        long long amount;
//        double a_ratio, b_ratio;
//
//        for (int i = 0; i < N; i++)
//        {
//            amount = (mid / t[i]);
//            amount & 1 ? amount = amount / 2 + 1 : amount = amount / 2;
//            amount *= w[i];
//
//            a_ratio = (double)amount * a / (a + b);
//            b_ratio = (double)amount - a_ratio;
//
//            // ���� �ű� �� �ִ� �纸�� ���� ��
//            if (g[i] < a_ratio)
//            {
//                // g[i]�� ��� �ű�
//                a_temp += g[i];
//                // ���� ���� �ű� �� �ִ� �纸�� ������ �ű� �� �ִ� ���� ��� �ű�� �ű� �� �ִ� �纸�� ������ ���� ���� ��� �ű�
//                b_temp += (s[i] > b_ratio + a_ratio - g[i] ? b_ratio + a_ratio - g[i] : s[i]);
//            }
//            // ���� �ű� �� �ִ� �纸�� ���� ��
//            else if (s[i] < b_ratio)
//            {
//                // s[i]�� ��� �ű�
//                b_temp += s[i];
//                // ���� ���� �ű� �� �ִ� �纸�� ������ �ű� �� �ִ� ���� ��� �ű�� �ű� �� �ִ� �纸�� ������ ���� ���� ��� �ű�
//                a_temp += (g[i] > a_ratio + b_ratio - s[i] ? a_ratio + b_ratio - s[i] : g[i]);
//            }
//            // �ݰ� ���� ��� ����� ��
//            else
//            {
//                a_temp += a_ratio;
//                b_temp += b_ratio;
//            }
//        }
//
//        if (a_temp >= a && b_temp >= b)
//        {
//            end = mid - 1;
//            answer = min(answer, mid);
//        }
//        else
//            start = mid + 1;
//    }
//
//    return answer;
//}

//// �ٸ� ��� Ǯ�� ���� �� �ٽ� ǰ
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
//    const int N = g.size();
//
//    long long answer = -1;
//    long long start = 0;
//    long long end = 1e14 * 4 + 1e5;
//    answer = end;
//
//    while (start <= end)
//    {
//        long long mid = (start + end) / 2;
//
//        long long gold_amount = 0;
//        long long silver_amount = 0;
//        long long total_amount = 0;
//
//        for (int i = 0; i < N; i++)
//        {
//            // t[i]�� ���ϰ� ������ ������ ����� �ʿ� ���� t[i]�� �������� �� Ȧ��(��, �պ��� �� �� �� �� �� �ִ� ���)�� ��� 1�� �� ū ���� ���� �� ����
//            // ���� ��
//            long long move_cnt = (mid + t[i]) / (t[i] * 2);
//
//            // ���� ��
//            /*long long move_cnt = mid / (t[i] * 2);
//            if (mid % (t[i] * 2) >= t[i]) move_cnt++;*/
//            long long max_carrying = move_cnt * w[i];
//
//            gold_amount += min((long long)g[i], max_carrying);
//            silver_amount += min((long long)s[i], max_carrying);
//            total_amount += min((long long)g[i] + (long long)s[i], max_carrying);
//        }
//
//        // ���� ������ �ʿ� ������ ���� �� ��Ż���� �� ��ݷ��� ���� �ִ� ��� ������ �� ��ݷ��� �ȴ�.
//        // ��, �� ��ݷ�, �� ��ݷ��� �������� ���� ��ü ��ݷ��� �� ��ݷ�, �� ��ݷ� �� �� �ϳ��� �����ϸ� ��� �����ϴٴ� ��(������ �ϳ��� total���� �ٸ� �ϳ��� �A �Ͱ� ���ų� ŭ)
//        // (������ �ϳ��� total���� �ٸ� �ϳ��� �A �Ͱ� ���ų� ŭ) - ���� ���� ���ÿ� �ݰ� ���� �� ��ĥ ��
//        if (gold_amount >= a && silver_amount >= b && total_amount >= a + b)
//        {
//            end = mid - 1;
//            answer = min(answer, mid);
//        }
//        else
//            start = mid + 1;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution(90, 500, { 70, 70, 0 }, { 0, 0, 500 }, { 100, 100, 2 }, { 4, 8, 1 });
//
//    return 0;
//}

//// �ٸ� ��� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//// typedef�� ���ϰ� using���� Ÿ�� �̸��� �ٲ� �� �� ����
//using lld = long long int;
//int n;
//bool valid(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, lld x) {
//    vector<lld> c(n, 0);
//    vector<lld> d(n, 0);
//    vector<lld> e(n, 0);
//    int i, j, k;
//    lld silver = 0;
//    lld gold = 0;
//    for (i = 0; i < n; i++) {
//        // t[i]�� ���ϰ� ������ ������ ����� �ʿ� ���� t[i]�� �������� �� Ȧ��(��, �պ��� �� �� �� �� �� �ִ� ���)�� ��� 1�� �� ū ���� ���� �� ����
//        c[i] = (x + t[i]) / (2 * t[i]);
//        lld cmax = c[i] * w[i];
//        // ���� �ִ��� ����
//        d[i] = min((lld)g[i], cmax);
//        // ���� ��� �ڸ��� ������ ���� ����
//        e[i] = min((lld)s[i], cmax - d[i]);
//        gold += d[i];
//        silver += e[i];
//        //printf("%lld %lld %lld\n",c[i], d[i], e[i]);
//    }
//    lld remg = a - gold;
//    //printf("%lld %lld\n",gold, silver);
//    // ���� �����ϸ� false
//    if (remg > 0)return false;
//    if (silver >= b)return true;
//    // ���̸� ����� ��ȯ, ���� ���� ����
//    remg = -remg;
//    // �迭�� ���鼭 
//    for (i = 0; remg > 0 && i < n; i++) {
//        // ���ÿ��� ���� �� �־��� ���� �ִ� ���� ���� (���� �� �־��� �� ��ü�� ��, ���� ���� ���� �� ���� ���� ���� �߰��� ����)
//        lld me = min(d[i], (lld)s[i] - e[i]);
//        //printf("%lld %lld %lld\n",c[i], d[i], e[i]);
//        // �� ��ſ� ���� �� �־��� ���� ����
//        me = min(me, remg);
//        // ���� ������ ��ȯ��
//        remg -= me;
//        silver += me;
//        // ���� ������ ����ϸ� true
//        if (silver >= b)return true;
//    }
//    return false;
//}
//lld solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
//    lld res = 0;
//    n = g.size();
//    lld l = 0;
//    lld r = 30000009000000009LL;
//    while (l < r) {
//        lld mid = (l + r) / 2;
//        if (valid(a, b, g, s, w, t, mid))r = mid;
//        else l = mid + 1;
//    }
//    return l;
//}