//// 내 풀이
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr, int divisor) {
//    vector<int> answer;
//
//    for (int number : arr)
//    {
//        if (number % divisor == 0) answer.push_back(number);
//    }
//
//    if (answer.empty()) return { -1 };
//
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}
//
//// 다른 사람 풀이
//// 삼항 연산자 사용하면 줄 수를 줄일 수 있음
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr, int divisor) {
//    vector<int> answer;
//    sort(arr.begin(), arr.end());
//
//    for (int i = 0; i < arr.size(); i++)
//    {
//        if (arr[i] % divisor == 0)
//            answer.push_back(arr[i]);
//    }
//
//    return answer.empty() ? vector<int>(1, -1) : answer;
//}