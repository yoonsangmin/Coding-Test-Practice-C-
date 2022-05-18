//// 틀린 풀이
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
//            // 금이 옮길 수 있는 양보다 적을 때
//            if (g[i] < a_ratio)
//            {
//                // g[i]는 모두 옮김
//                a_temp += g[i];
//                // 은의 양이 옮길 수 있는 양보다 많으면 옮길 수 있는 양을 모두 옮기고 옮길 수 있는 양보다 적으면 남은 은을 모두 옮김
//                b_temp += (s[i] > b_ratio + a_ratio - g[i] ? b_ratio + a_ratio - g[i] : s[i]);
//            }
//            // 은이 옮길 수 있는 양보다 적을 때
//            else if (s[i] < b_ratio)
//            {
//                // s[i]는 모두 옮김
//                b_temp += s[i];
//                // 금의 양이 옮길 수 있는 양보다 많으면 옮길 수 있는 양을 모두 옮기고 옮길 수 있는 양보다 적으면 남은 금을 모두 옮김
//                a_temp += (g[i] > a_ratio + b_ratio - s[i] ? a_ratio + b_ratio - s[i] : g[i]);
//            }
//            // 금과 은이 모두 충분할 때
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

//// 다른 사람 풀이 참고 후 다시 품
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
//            // t[i]를 더하고 나누면 나머지 계산할 필요 없이 t[i]로 나누었을 때 홀수(즉, 왕복을 한 번 더 할 수 있는 경우)인 경우 1이 더 큰 값을 얻을 수 있음
//            // 수정 후
//            long long move_cnt = (mid + t[i]) / (t[i] * 2);
//
//            // 수정 전
//            /*long long move_cnt = mid / (t[i] * 2);
//            if (mid % (t[i] * 2) >= t[i]) move_cnt++;*/
//            long long max_carrying = move_cnt * w[i];
//
//            gold_amount += min((long long)g[i], max_carrying);
//            silver_amount += min((long long)s[i], max_carrying);
//            total_amount += min((long long)g[i] + (long long)s[i], max_carrying);
//        }
//
//        // 금의 개수가 필요 개수와 같을 때 토탈에서 금 운반량을 빼면 최대 운반 가능한 은 운반량이 된다.
//        // 즉, 금 운반량, 은 운반량에 얽메이지 말고 전체 운반량과 금 운반량, 은 운반량 둘 중 하나만 만족하면 운반 가능하다는 뜻(나머지 하나는 total에서 다른 하나를 뺸 것과 같거나 큼)
//        // (나머지 하나는 total에서 다른 하나를 뺸 것과 같거나 큼) - 같을 때는 도시에 금과 은이 안 겹칠 때
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

//// 다른 사람 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//// typedef를 안하고 using으로 타입 이름을 바꿔 쓸 수 있음
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
//        // t[i]를 더하고 나누면 나머지 계산할 필요 없이 t[i]로 나누었을 때 홀수(즉, 왕복을 한 번 더 할 수 있는 경우)인 경우 1이 더 큰 값을 얻을 수 있음
//        c[i] = (x + t[i]) / (2 * t[i]);
//        lld cmax = c[i] * w[i];
//        // 금을 최대한 담음
//        d[i] = min((lld)g[i], cmax);
//        // 금을 담고 자리가 남으면 은을 담음
//        e[i] = min((lld)s[i], cmax - d[i]);
//        gold += d[i];
//        silver += e[i];
//        //printf("%lld %lld %lld\n",c[i], d[i], e[i]);
//    }
//    lld remg = a - gold;
//    //printf("%lld %lld\n",gold, silver);
//    // 금이 부족하면 false
//    if (remg > 0)return false;
//    if (silver >= b)return true;
//    // 차이를 양수로 전환, 남는 금의 개수
//    remg = -remg;
//    // 배열을 돌면서 
//    for (i = 0; remg > 0 && i < n; i++) {
//        // 도시에서 실을 수 있었던 은의 최대 값을 구함 (실을 수 있었던 금 전체의 양, 남은 은의 개수 중 작은 값의 은을 추가로 실음)
//        lld me = min(d[i], (lld)s[i] - e[i]);
//        //printf("%lld %lld %lld\n",c[i], d[i], e[i]);
//        // 금 대신에 실을 수 있었던 은의 개수
//        me = min(me, remg);
//        // 금을 은으로 전환함
//        remg -= me;
//        silver += me;
//        // 은의 개수가 충분하면 true
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