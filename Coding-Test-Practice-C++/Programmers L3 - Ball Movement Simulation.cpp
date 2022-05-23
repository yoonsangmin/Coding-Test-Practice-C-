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


//// 역순으로 다시 품 - 짧음
//#include <vector>
//
//using namespace std;
//
//// inverted
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//	int sx, sy, ex, ey;
//	sx = ex = x;
//	sy = ey = y;
//
//	for (int i = queries.size() - 1; i >= 0; i--)
//	{
//		if (sx != 0) sx = max(0, sx + dx[queries[i][0]] * queries[i][1]);
//		if (ex != n - 1) ex = min(n - 1, ex + dx[queries[i][0]] * queries[i][1]);
//		if (sy != 0) sy = max(0, sy + dy[queries[i][0]] * queries[i][1]);
//		if (ey != m - 1) ey = min(m - 1, ey + dy[queries[i][0]] * queries[i][1]);
//		if (ex < 0 || sx > n - 1 || ey < 0 || sy > m - 1) return 0;
//	}
//
//    return (long long)(ex - sx + 1) * (ey - sy + 1);
//}
//
//int main()
//{
//	solution(2, 5, 0, 1, { {3, 1}, {2, 2}, {1, 1}, {2, 3}, {0, 1}, {2, 1} });
//
//	return 0;
//}


//// 다른 사람 풀이 - 역순으로 안 풀고 순서대로 품
//#include <string>
//#include <vector>
//
//using namespace std;
//using lld = long long int;
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> q) {
//	// start x, start y
//	int sx, sy;
//	// end x, end y
//	int ex, ey;
//	int sxc, syc;
//	int exc, eyc;
//	sx = 0; sy = 0;
//	ex = n - 1; ey = m - 1;
//	// c는 축적한 값
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
//	// 축의 좌표가 같으면 = 모든 값이 한 곳에 축적이 됨 - 길이만큼
//	if (sx == ex) { sxc = exc = n; }
//	if (sy == ey) { syc = eyc = m; }
//	// 값이 모일 수 없는 곳에 있으면 0
//	if (x < sx || ex < x)rp = 0;
//	else {
//		// 위쪽 변
//		if (x == sx)rp = sxc;
//		// 아래쪽 변
//		else if (x == ex)rp = exc;
//		// 가운데
//		else rp = 1;
//	}
//	// 값이 모일 수 없는 곳에 있으면 0
//	if (y < sy || ey < y)rq = 0;
//	else {
//		// 왼쪽 변
//		if (y == sy)rq = syc;
//		// 오른쪽 변
//		else if (y == ey)rq = eyc;
//		// 가운데
//		else rq = 1;
//	}
//	// 변인 경우 곱으로 다 구할 수 있음
//	// 꼭지점인 경우 곱으로 표현 가능함 - 꼭지점은 변의 값으 곱 - 접히는 순서는 상관이 없었음..
//	return rp * rq;
//}

//// 다른 사람 풀이
//// 역순으로 푼 것은 비슷함
//#include <string>
//#include <vector>
//using namespace std;
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//    int point[4] = { y, y + 1, x, x + 1 };
//    int dir[4] = { -1, 1, -1, 1 };
//    int boundary[4] = { 0, m, 0, n };
//    int limit[4] = { m, m, n, n };
//
//    for (int i = queries.size() - 1; i >= 0; --i)
//    {
//        int command = queries[i][0];
//        int dx = queries[i][1];
//
//        // 2의 배수 기준으로 짝을 이루어서 서로 변환함 - 짝수는 1 크게 홀수는 1 작게
//        int reverse = command ^ 1;
//        point[reverse] += dir[reverse] * dx;
//        point[reverse] = max(min(point[reverse], limit[reverse]), 0);
//
//        if (point[command] != boundary[command])
//        {
//            point[command] += dir[reverse] * dx;
//            point[command] = max(min(point[command], limit[command]), 0);
//        }
//
//        if (point[0] == m || point[1] == 0 || point[2] == n || point[3] == 0)
//            return 1LL * 0;
//    }
//    return (1LL * point[1] - point[0]) * (1LL * point[3] - point[2]);
//}
