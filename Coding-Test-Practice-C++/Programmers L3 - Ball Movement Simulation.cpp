//// 내 풀이
//// 시간 초과
//// 한 칸씩 움직이는 것을 쿼리 대로 한 번에 움직이게 수정하기
//#include <vector>
//
//using namespace std;
//
//int dx[] = { 0, 0, -1, 1 };
//int dy[] = { -1, 1, 0, 0 };
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//    long long answer = 0;
//	int x_range[] = { 0, n - 1 };
//	int y_range[] = { 0, m - 1 };
//	long long accumulated[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
//
//	for (vector<int> query : queries)
//	{
//		int dir = query[0];
//		int num = query[1];
//
//		for (int i = 0; i < num; i++)
//		{
//			x_range[0] += dx[dir];
//			x_range[1] += dx[dir];
//
//			y_range[0] += dy[dir];
//			y_range[1] += dy[dir];
//
//			if (x_range[0] == -1)
//			{
//				if (x_range[1] == -1)
//					x_range[1]++;
//				else if (x_range[1] == 0)
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						accumulated[0][j] += accumulated[2][j];
//						accumulated[1][j] = accumulated[0][j];
//						accumulated[2][j] = accumulated[0][j];
//					}
//				}
//				else
//					for (int j = 0; j < 3; j++)
//						accumulated[0][j] += accumulated[1][j];
//
//				x_range[0]++;
//			}
//			else if (x_range[1] == n)
//			{
//				if (x_range[0] == n)
//					x_range[1]--;
//				else if (x_range[0] == n - 1)
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						accumulated[0][j] += accumulated[2][j];
//						accumulated[1][j] = accumulated[0][j];
//						accumulated[2][j] = accumulated[0][j];
//					}
//				}
//				else
//					for (int j = 0; j < 3; j++)
//						accumulated[2][j] += accumulated[1][j];
//
//				x_range[1]--;
//			}
//			else if (y_range[0] == -1)
//			{
//				if (y_range[1] == -1)
//					y_range[1]++;
//				else if (y_range[0] == 0)
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						accumulated[j][0] += accumulated[j][2];
//						accumulated[j][1] = accumulated[j][0];
//						accumulated[j][2] = accumulated[j][0];
//					}
//				}
//				else
//					for (int j = 0; j < 3; j++)
//						accumulated[j][0] += accumulated[j][1];
//
//				y_range[0]++;
//			}
//			else if (y_range[1] == m)
//			{
//				if (y_range[0] == m)
//					y_range[0]--;
//				else if (y_range[0] == m - 1)
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						accumulated[j][0] += accumulated[j][2];
//						accumulated[j][1] = accumulated[j][0];
//						accumulated[j][2] = accumulated[j][0];
//					}
//				}
//				else
//					for (int j = 0; j < 3; j++)
//						accumulated[j][2] += accumulated[j][1];
//
//				y_range[1]--;
//			}
//		}
//	}
//
//	int x_value, y_value;
//	
//	if (x_range[0] == x)
//		x_value = 0;
//	else if (x_range[0] < x && x < x_range[1])
//		x_value = 1;
//	else if (x == x_range[1])
//		x_value = 2;
//	else
//		x_value = -1;
//
//	if (y_range[0] == y)
//		y_value = 0;
//	else if (y_range[0] < y && y < y_range[1])
//		y_value = 1;
//	else if (y == y_range[1])
//		y_value = 2;
//	else
//		y_value = -1;
//
//	if (x_value == -1 || y_value == -1)
//		return 0;
//
//	answer = accumulated[x_value][y_value];
//
//    return answer;
//}