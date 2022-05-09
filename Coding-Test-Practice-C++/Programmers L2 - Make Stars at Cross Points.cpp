//// 내 풀이
//#include <string>
//#include <vector>
//#include <cmath>
//#include <limits.h>
//
//using namespace std;
//
//vector<string> solution(vector<vector<int>> line) {
//    vector<string> answer;
//    vector<vector<long long>> points;
//
//    long long a1, b1, c1;
//    long long a2, b2, c2;
//    long long d1, d2;
//    long long x, y;
//
//    long long left = LLONG_MAX, right = LLONG_MIN, bottom = LLONG_MAX, top = LLONG_MIN;
//
//    for (int i = 0; i < line.size() - 1; i++)
//    {
//        a1 = line[i][0];
//        b1 = line[i][1];
//        c1 = line[i][2];
//        for (int j = i + 1; j < line.size(); j++)
//        {
//            a2 = line[j][0];
//            b2 = line[j][1];
//            c2 = line[j][2];
//
//            // 평행인 경우
//            d2 = a1 * b2 - a2 * b1;
//            if (d2 == 0)
//                continue;
//
//            d1 = c2 * b1 - c1 * b2;
//
//            if (d1 % d2 != 0)
//                continue;
//
//            x = d1 / d2;
//            
//            // y를 구하는 항등식을 만들어서 품
//            // y = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);
//
//            
//            // 두 방정식 중 하나에 집어넣어서 품
//            // 한 쪽의 y의 지수가 0인 경우 풀 수가 없음
//            if (b1 == 0)
//            {
//                d1 = -a2 * x - c2;
//                d2 = b2;
//
//                if (d1 % d2 != 0)
//                    continue;
//
//                y = d1 / d2;
//            }
//
//            if (b1 != 0)
//            {
//                d1 = -a1 * x - c1;
//                d2 = b1;
//
//                if (d1 % d2 != 0)
//                    continue;
//
//                y = d1 / d2;
//            }
//
//            points.push_back({ (long long)x, (long long)y });
//            left = min(left, (long long)x);
//            right = max(right, (long long)x);
//            bottom = min(bottom, (long long)y);
//            top = max(top, (long long)y);
//        }
//    }
//
//    int width = right - left + 1;
//    int height = top - bottom + 1;
//
//    for (int i = 0; i < height; i++)
//        answer.push_back(string(width, '.'));
//
//    for (vector<long long> point : points)
//        answer[top - point[1]][point[0] - left] = '*';
//
//    return answer;
//}
//
//int main()
//{
//    solution({{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}} );
//
//    return 0;
//}

//// 다른 사람 풀이
//#include <string>
//#include <vector>
//#include <iostream>
//#include <set>
//
//using namespace std;
//
//typedef struct POINT
//{
//    long long int x;
//    long long int y;
//};
//
//vector<string> solution(vector<vector<int>> line)
//{
//    POINT Min, Max;
//    set<pair<long long int, long long int>> cross;
//
//    long long int xLen = 0;
//    long long int yLen = 0;
//
//    Min.x = 10000000001;
//    Min.y = 10000000001;
//    Max.x = -10000000001;
//    Max.y = -10000000001;
//
//    for (int i = 0; i < line.size() - 1; i++)
//    {
//        for (int j = i + 1; j < line.size(); j++)
//        {
//            // 내 풀이도 이런식으로 x와 y를 구하는 식 모두 분모를 공통으로 만들어서 쓸 수 있었음
//            long long int AD_BC = (long long int)line[i][0] * (long long int)line[j][1] - (long long int)line[i][1] * (long long int)line[j][0];
//
//            if (AD_BC == 0) //평행 or 일치
//                continue;
//
//            long long int BF_ED = (long long int)line[i][1] * (long long int)line[j][2] - (long long int)line[i][2] * (long long int)line[j][1];
//
//            if (BF_ED % AD_BC == 0) //x
//            {
//                long long int EC_AF = (long long int)line[i][2] * (long long int)line[j][0] - (long long int)line[i][0] * (long long int)line[j][2];
//
//                if (EC_AF % AD_BC == 0) //y
//                {
//                    POINT temp;
//                    temp.x = BF_ED / AD_BC;
//                    temp.y = EC_AF / AD_BC;
//
//                    Min.x = min(Min.x, temp.x);
//                    Max.x = max(Max.x, temp.x);
//
//                    Min.y = min(Min.y, temp.y);
//                    Max.y = max(Max.y, temp.y);
//
//                    cross.emplace(temp.x, temp.y);
//                }
//            }
//        }
//    }
//
//    xLen = Max.x - Min.x + 1;
//    yLen = Max.y - Min.y + 1;
//
//    // string 초기화 시 vector처럼 한 번에 초기화 할 수 있음
//    vector<string> answer(yLen, string(xLen, '.'));
//
//    for (auto it : cross)
//        answer[yLen - 1 + Min.y - it.second][-Min.x + it.first] = '*';
//
//    return answer;
//}