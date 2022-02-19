//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool cmp(string n1, string n2)
//{
//    return n1 + n2 > n2 + n1;
//}
//
//string solution(vector<int> numbers) {
//    string answer = "";
//    vector<string> numbers_string;
//
//    for (int number : numbers)
//    {
//        numbers_string.push_back(to_string(number));
//    }
//
//    sort(numbers_string.begin(), numbers_string.end(), cmp);
//
//    for (string number : numbers_string)
//    {
//        answer += number;
//    }
//
//    while (answer[0] == '0')
//    {
//        answer.erase(answer.begin());
//    }
//
//    if (answer.empty())
//        return "0";
//
//    return answer;
//}

// 다른 사람 풀이
// stringstream으로 문자열을 쪼개는 거 뿐 아니라 합치는 것도 할 수 있음
// 실제로 곱해서 더해보고 값을 비교해보기

//#include <string>
//#include <vector>
//#include <algorithm>
//#include <sstream>
//
//using namespace std;
//
//bool compare(int left, int right)
//{
//    if (left == 0) return false;
//    if (right == 0) return true;
//
//    short i = 1, tmp = left;
//    for (; true; i *= 10)
//        if ((right / i) < 10)
//        {
//            left = left * i * 10 + right;
//            break;
//        };
//
//    for (i = 1; true; i *= 10)
//        if ((tmp / i) < 10)
//        {
//            right = right * i * 10 + tmp;
//            break;
//        };
//
//    if (left > right) return true;
//    else return false;
//}
//
//string solution(vector<int> numbers) {
//    sort(numbers.begin(), numbers.end(), compare);
//    stringstream ssInt;
//    bool is_zero = true;
//
//    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
//    {
//        if (*iter != 0) is_zero = false;
//        ssInt << *iter;
//    }
//
//    if (is_zero) return "0";
//    return ssInt.str();
//}