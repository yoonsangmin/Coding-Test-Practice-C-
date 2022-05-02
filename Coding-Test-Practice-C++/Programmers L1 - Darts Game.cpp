//#include <string>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//int solution(string dartResult) {
//    vector<int> scores(3, 0);
//    int idx = 0;
//
//    int score = 0;
//
//    for (int i = 0; i < dartResult.length(); i++)
//    {
//        switch (dartResult[i])
//        {
//        case 'D':
//            score = pow(score, 2); 
//            break;
//        case 'T':
//            score = pow(score, 3);
//            break;
//        case '#':
//            score *= -1;
//            break;
//        case '*':
//            score *= 2;
//            if (idx - 1 >= 0)
//                scores[idx - 1] *= 2;
//            break;
//        default:
//            if (isdigit(dartResult[i]))
//            {
//                score = dartResult[i] - '0';
//                if (isdigit(dartResult[i + 1]))
//                {
//                    score *= 10;
//                    i++;
//                }
//            }
//            break;
//        }
//
//        if (i + 1 == dartResult.length() || isdigit(dartResult[i + 1]))
//        {
//            scores[idx++] = score;
//            score = 0;
//        }
//    }
//
//    return accumulate(scores.begin(), scores.end(), 0);
//}
//
//int main()
//{
//    solution("1D2S#10S");
//
//    return 0;
//}
//
//// 다른 사람 풀이
//// stringstream 쓰면 자료형에 맞게 알아서 잘라줌, 속도는 조금 더 들지만 이해하기 쉽고 간단함.
//#include <string>
//#include <sstream>
//#include <cmath>
//
//using namespace std;
//
//int solution(string dartResult) {
//    stringstream ss(dartResult);
//
//    int sum[3] = { 0, 0, 0 };
//    int options[3] = { 1, 1, 1 };
//    for (int i = 0; i < 3; i++) {
//        int score;
//        char bonus;
//        char option;
//
//        ss >> score;
//
//		  // stringstream에서 get을 하면 하나씩 얻을 수 있음
//        bonus = ss.get();
//        option = ss.get();
//
//        if (option != '*' && option != '#') {
//            ss.unget();
//        }
//
//        switch (bonus) {
//        case 'S':
//            sum[i] += pow(score, 1);
//            break;
//        case 'D':
//            sum[i] += pow(score, 2);
//            break;
//        case 'T':
//            sum[i] += pow(score, 3);
//            break;
//        default:
//            break;
//        }
//
//        switch (option) {
//        case '*':
//            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
//            options[i] *= 2;
//            break;
//        case '#':
//            options[i] = -options[i];
//            break;
//        default:
//            break;
//        }
//    }
//
//    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
//}