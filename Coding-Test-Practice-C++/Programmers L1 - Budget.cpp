//// 내 풀이
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> d, int budget) {
//    int answer = 0;
//
//    sort(d.begin(), d.end());
//    
//    for (int i = 0; i < d.size(); i++)
//    {
//        if (d[i] > budget)
//            break;
//        budget -= d[i];
//        answer++;
//    }
//
//    return answer;
//}

//// 다른 사람 풀이
//// 반복문을 최대한 줄일 수 있음
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> d, int budget) {
//    sort(d.begin(), d.end());
//    int i;
//    // for (i = 0; (budget = budget - d[i]) >= 0 && i < d.size(); i++);
//    for (i = 0; i < d.size() && (budget = budget - d[i]) >= 0; i++);
//    return i;
//}
//
//int main()
//{
//    solution({ 1, 2, 3 }, 6);
//
//    return 0;
//}