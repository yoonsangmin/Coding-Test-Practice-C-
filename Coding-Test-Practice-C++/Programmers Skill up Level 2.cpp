//// 1번 문제 - 못 품
//// 점프 배터리 1, 순간 이동 - 지금까지 온 거리 만큼
//// 옛날에 풀었던 문제였음
// #include <iostream>
//using namespace std;
//
//int solution(int n)
//{
//    int ans = 1;
//
//    while (1 < n)
//    {
//        if (n % 2 == 1)
//        {
//            ans++;
//        }
//
//        n >>= 1;
//    }
//
//    return ans;
//}

//// 2번 문제 - 틀림
//// 효율 좋게 풀려고 했는데 머리로 생각하기 힘들어짐
//// 효율이 조금 떨어지더라도 일단 논리에 맞게 빠르게 풀어보기
//#include <string>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//int rotate(int& rows, int& columns, vector<vector<int>>& matrix, const vector<int>& query)
//{
//    int min_elem = 10000;
//
//    int temp_up = 0;
//    int temp_down = 0;
//    // vertical
//    for (int i = 0; i <= query[2] - query[0]; i++)
//    {
//        swap(matrix[query[0] + i - 1][query[3] - 1], temp_down);
//        swap(matrix[query[2] - i - 1][query[1] - 1], temp_up);
//
//        min_elem = min(min_elem, min(temp_down, temp_up));
//    }
//
//    // horizontal
//	for (int i = 1; i <= query[3] - query[1]; i++)
//	{
//		swap(matrix[query[0] - 1][query[1] + i - 1], temp_up);
//		swap(matrix[query[2] - 1][query[3] - i - 1], temp_down);
//
//		min_elem = temp_down != 0 ? min(min_elem, temp_down) : min_elem;
//		min_elem = temp_up != 0 ? min(min_elem, temp_up) : min_elem;
//	}
//
//    return min_elem;
//}
//
//vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
//    vector<int> answer;
//    vector<vector<int>> matrix(rows, vector<int>(columns));
//
//    int number = 1;
//    for (int x = 0; x < rows; x++)
//        for (int y = 0; y < columns; y++)
//            matrix[x][y] = number++;
//
//    for (const vector<int> query : queries)
//        answer.push_back(rotate(rows, columns, matrix, query));
//
//    return answer;
//}
//
//int main()
//{
//    solution(3, 3, {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}} );
//
//    return 0;
//}