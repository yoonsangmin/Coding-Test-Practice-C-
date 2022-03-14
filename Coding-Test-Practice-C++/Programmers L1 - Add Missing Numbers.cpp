//// 내 풀이
//// accumulate로 벡터 요소의 합을 간단하게 구할 수 있다는 것을 알게 됨
//#include <string>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 45;  // (9 + 0) * 10 / 2
//
//    answer -= accumulate(numbers.begin(), numbers.end(), 0);	// for 문 돌면서 빼도 됨
//
//    return answer;
//}

//// 느리지만 문제 대로 푼 코드
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (find(numbers.begin(), numbers.end(), i) == numbers.end())
//        {
//            answer += i;
//        }
//    }
//
//    return answer;
//}

//// 느리지만 문제 대로 푼 코드 - 조금 수정
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//    map<int, bool> number_dic;
//
//    for (auto number : numbers)
//    {
//        number_dic[number] = true;
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (!number_dic[i])
//        {
//            answer += i;
//        }
//    }
//
//    return answer;
//}
//
//// 다른 사람 풀이
//// 전역 변수는 자동 초기화 됨
//// 지역 변수는 직접 초기화 해야 하나 지역 배열 변수는 int a[10] = {}; 로 자동 초기화 할 수 있음
//#include <string>
//#include <vector>
//
//using namespace std;
//int a[10];
//int solution(vector<int> numbers) {
//    int answer = 0;
//
//    for (int i = 0; i < numbers.size(); i++) {
//        a[numbers[i]] = 1;
//    }
//    for (int i = 0; i < 10; i++) {
//        if (a[i] == 0) answer += i;
//    }
//    return answer;
//}


//// 다른 사람 풀이
//// 내가 하고 싶었던 것
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//
//    sort(numbers.begin(), numbers.end());
//
//    int index = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (i != numbers[index])
//        {
//            answer += i;
//        }
//        else
//            index++;
//    }
//
//
//    return answer;
//}

//// 다른 사람 풀이
//// 독특한 풀이이나 insert 때문에 좋은 풀이는 아닌 듯, 위의 풀이랑 비슷해서 위의 풀이를 쓰면 됨
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//    sort(numbers.begin(), numbers.end());
//    for (int i = 0; i < 10; i++) {
//        if (i == numbers.size() || numbers[i] != i) {
//            answer += i;
//            numbers.insert(numbers.begin() + i, i);
//        }
//    }
//
//    return answer;
//}