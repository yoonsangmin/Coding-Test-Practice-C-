//// 내 풀이
//// 시간 초과 - 한 칸씩 움직이는 것을 쿼리 대로 한 번에 움직이게 수정하기
//#include <vector>
//
//using namespace std;
//
//int dx[] = { 0, 0, -1, 1 };
//int dy[] = { -1, 1, 0, 0 };
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//    long long answer = 0;
//	long long  x_range[] = { 0, n - 1 };
//	long long y_range[] = { 0, m - 1 };
//	long long accumulated[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
//
//	for (vector<int> query : queries)
//	{
//		long long dir = query[0];
//		long long num = query[1];
//
//		x_range[0] += dx[dir] * num;
//		x_range[1] += dx[dir] * num;
//
//		y_range[0] += dy[dir] * num;
//		y_range[1] += dy[dir] * num;
//
//		if (x_range[0] < 0)
//		{
//			// 둘 다 음수인 경우
//			if (x_range[1] <= 0)
//			{
//				// 같은 경우는 상관 없는데 다른 경우 - 합쳐짐
//				if (x_range[0] < x_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// 가운데랑 합쳐질 때
//						accumulated[0][j] += accumulated[1][j] * (-x_range[0] + x_range[1] - 1);
//
//						// 끝과 끝이 합쳐질 때
//						accumulated[0][j] += accumulated[2][j];
//						accumulated[1][j] = accumulated[0][j];
//						accumulated[2][j] = accumulated[0][j];
//					}
//				}
//				x_range[1] = 0;
//			}
//			// 혼자 음수가 됐을 때
//			else
//				for (int j = 0; j < 3; j++)
//					accumulated[0][j] += accumulated[1][j] * -x_range[0];
//
//			x_range[0] = 0;
//		}
//		else if (x_range[1] >= n)
//		{
//			// 둘 다 범위 밖인 경우
//			if (x_range[0] >= n - 1)
//			{
//				// 같은 경우는 상관 없는데 다른 경우 - 합쳐짐
//				if (x_range[0] < x_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// 가운데랑 합쳐질 때
//						accumulated[2][j] += accumulated[1][j] * (x_range[1] - x_range[0] - 1);
//
//						// 끝과 끝이 합쳐질 때
//						accumulated[2][j] += accumulated[0][j];
//						accumulated[1][j] = accumulated[2][j];
//						accumulated[0][j] = accumulated[2][j];
//					}
//				}
//				x_range[0] = n - 1;
//			}
//			// 혼자 범위를 벗어난 경우
//			else
//				for (int j = 0; j < 3; j++)
//					accumulated[2][j] += accumulated[1][j] * (x_range[1] - n + 1);
//
//			x_range[1] = n - 1;
//		}
//		else if (y_range[0] < 0)
//		{
//			// 둘 다 음수인 경우
//			if (y_range[1] <= 0)
//			{
//				// 같은 경우는 상관 없는데 다른 경우 - 합쳐짐
//				if (y_range[0] < y_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// 가운데랑 합쳐질 때
//						accumulated[j][0] += accumulated[j][1] * (-y_range[0] + y_range[1] - 1);
//
//						// 끝과 끝이 합쳐질 때
//						accumulated[j][0] += accumulated[j][2];
//						accumulated[j][1] = accumulated[j][0];
//						accumulated[j][2] = accumulated[j][0];
//					}
//				}
//				y_range[1] = 0;
//			}
//			// 혼자 음수가 됐을 때
//			else
//				for (int j = 0; j < 3; j++)
//					accumulated[j][0] += accumulated[j][1] * -y_range[0];
//
//			y_range[0] = 0;
//		}
//		else if (y_range[1] >= m)
//		{
//			// 둘 다 범위 밖인 경우
//			if (y_range[0] >= m - 1)
//			{
//				// 같은 경우는 상관 없는데 다른 경우 - 합쳐짐
//				if (y_range[0] < y_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// 가운데랑 합쳐질 때
//						accumulated[j][2] += accumulated[j][1] * (y_range[1] - y_range[0] - 1);
//
//						// 끝과 끝이 합쳐질 때
//						accumulated[j][2] += accumulated[j][0];
//						accumulated[j][1] = accumulated[j][2];
//						accumulated[j][0] = accumulated[j][2];
//					}
//				}
//				y_range[0] = m - 1;
//			}
//			// 혼자 범위를 벗어난 경우
//			else
//				for (int j = 0; j < 3; j++)
//					accumulated[j][2] += accumulated[j][1] * (y_range[1] - m + 1);
//
//			y_range[1] = m - 1;
//		}
//	}
//
//	if (x_range[0] > x_range[1])
//		swap(x_range[0], x_range[1]);
//
//	if (y_range[0] > y_range[1])
//		swap(y_range[0], y_range[1]);
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
//
//int main()
//{
//	solution(2, 5, 0, 1, { {3, 1},{2, 2},{1, 1},{2, 3},{0, 1},{2, 1} });
//
//	return 0;
//}
//
//
//// 다른 사람 풀이 - 역순으로 안 풀고 순서대로 품
//#include <string>
//#include <vector>
//
//using namespace std;
//using lld = long long int;
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> q) {
//	int sx, sy;
//	int ex, ey;
//	int sxc, syc;
//	int exc, eyc;
//	sx = 0; sy = 0;
//	ex = n - 1; ey = m - 1;
//	sxc = syc = exc = eyc = 1;
//	lld rp, rq;
//	for (auto& op : q) {
//		switch (op[0]) {
//		case 0:
//		{
//			sy -= op[1];
//			ey -= op[1];
//			if (sy < 0) {
//				syc -= sy;
//				sy = 0;
//			}
//			if (ey < 0) {
//				ey = 0;
//			}
//			break;
//		}
//		case 1:
//		{
//			sy += op[1];
//			ey += op[1];
//			if (sy >= m) {
//				sy = m - 1;
//			}
//			if (ey >= m) {
//				eyc += ey - m + 1;
//				ey = m - 1;
//			}
//			break;
//		}
//		case 2:
//		{
//			sx -= op[1];
//			ex -= op[1];
//			if (sx < 0) {
//				sxc -= sx;
//				sx = 0;
//			}
//			if (ex < 0) {
//				ex = 0;
//			}
//			break;
//		}
//		case 3:
//		{
//			sx += op[1];
//			ex += op[1];
//			if (sx >= n) {
//				sx = n - 1;
//			}
//			if (ex >= n) {
//				exc += ex - n + 1;
//				ex = n - 1;
//			}
//			break;
//		}
//		}
//	}
//	if (sx == ex) { sxc = exc = n; }
//	if (sy == ey) { syc = eyc = m; }
//	if (x < sx || ex < x)rp = 0;
//	else {
//		if (x == sx)rp = sxc;
//		else if (x == ex)rp = exc;
//		else rp = 1;
//	}
//	if (y < sy || ey < y)rq = 0;
//	else {
//		if (y == sy)rq = syc;
//		else if (y == ey)rq = eyc;
//		else rq = 1;
//	}
//	return rp * rq;
//}