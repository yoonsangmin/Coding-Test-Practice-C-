#include <string>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<vector<long long>> points;

    long long a1, b1, c1;
    long long a2, b2, c2;
    long long d1, d2;
    long long x, y;

    long long left = LLONG_MAX, right = LLONG_MIN, bottom = LLONG_MAX, top = LLONG_MIN;

    for (int i = 0; i < line.size() - 1; i++)
    {
        a1 = line[i][0];
        b1 = line[i][1];
        c1 = line[i][2];
        for (int j = i + 1; j < line.size(); j++)
        {
            a2 = line[j][0];
            b2 = line[j][1];
            c2 = line[j][2];

            // 평행인 경우
            d2 = a1 * b2 - a2 * b1;
            if (d2 == 0)
                continue;

            d1 = c2 * b1 - c1 * b2;

            if (d1 % d2 != 0)
                continue;

            x = d1 / d2;
            
            // y = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);

            
            if (b1 == 0)
            {
                d1 = -a2 * x - c2;
                d2 = b2;

                if (d1 % d2 != 0)
                    continue;

                y = d1 / d2;
            }

            if (b1 != 0)
            {
                d1 = -a1 * x - c1;
                d2 = b1;

                if (d1 % d2 != 0)
                    continue;

                y = d1 / d2;
            }

            points.push_back({ (long long)x, (long long)y });
            left = min(left, (long long)x);
            right = max(right, (long long)x);
            bottom = min(bottom, (long long)y);
            top = max(top, (long long)y);
        }
    }

    int width = right - left + 1;
    int height = top - bottom + 1;

    for (int i = 0; i < height; i++)
        answer.push_back(string(width, '.'));

    for (vector<long long> point : points)
        answer[top - point[1]][point[0] - left] = '*';

    return answer;
}

int main()
{
    solution({{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}} );

    return 0;
}