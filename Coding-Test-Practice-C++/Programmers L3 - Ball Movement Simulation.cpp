//// �� Ǯ��
//// �ð� �ʰ� - �� ĭ�� �����̴� ���� ���� ��� �� ���� �����̰� �����ϱ�
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
//			// �� �� ������ ���
//			if (x_range[1] <= 0)
//			{
//				// ���� ���� ��� ���µ� �ٸ� ��� - ������
//				if (x_range[0] < x_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// ����� ������ ��
//						accumulated[0][j] += accumulated[1][j] * (-x_range[0] + x_range[1] - 1);
//
//						// ���� ���� ������ ��
//						accumulated[0][j] += accumulated[2][j];
//						accumulated[1][j] = accumulated[0][j];
//						accumulated[2][j] = accumulated[0][j];
//					}
//				}
//				x_range[1] = 0;
//			}
//			// ȥ�� ������ ���� ��
//			else
//				for (int j = 0; j < 3; j++)
//					accumulated[0][j] += accumulated[1][j] * -x_range[0];
//
//			x_range[0] = 0;
//		}
//		else if (x_range[1] >= n)
//		{
//			// �� �� ���� ���� ���
//			if (x_range[0] >= n - 1)
//			{
//				// ���� ���� ��� ���µ� �ٸ� ��� - ������
//				if (x_range[0] < x_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// ����� ������ ��
//						accumulated[2][j] += accumulated[1][j] * (x_range[1] - x_range[0] - 1);
//
//						// ���� ���� ������ ��
//						accumulated[2][j] += accumulated[0][j];
//						accumulated[1][j] = accumulated[2][j];
//						accumulated[0][j] = accumulated[2][j];
//					}
//				}
//				x_range[0] = n - 1;
//			}
//			// ȥ�� ������ ��� ���
//			else
//				for (int j = 0; j < 3; j++)
//					accumulated[2][j] += accumulated[1][j] * (x_range[1] - n + 1);
//
//			x_range[1] = n - 1;
//		}
//		else if (y_range[0] < 0)
//		{
//			// �� �� ������ ���
//			if (y_range[1] <= 0)
//			{
//				// ���� ���� ��� ���µ� �ٸ� ��� - ������
//				if (y_range[0] < y_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// ����� ������ ��
//						accumulated[j][0] += accumulated[j][1] * (-y_range[0] + y_range[1] - 1);
//
//						// ���� ���� ������ ��
//						accumulated[j][0] += accumulated[j][2];
//						accumulated[j][1] = accumulated[j][0];
//						accumulated[j][2] = accumulated[j][0];
//					}
//				}
//				y_range[1] = 0;
//			}
//			// ȥ�� ������ ���� ��
//			else
//				for (int j = 0; j < 3; j++)
//					accumulated[j][0] += accumulated[j][1] * -y_range[0];
//
//			y_range[0] = 0;
//		}
//		else if (y_range[1] >= m)
//		{
//			// �� �� ���� ���� ���
//			if (y_range[0] >= m - 1)
//			{
//				// ���� ���� ��� ���µ� �ٸ� ��� - ������
//				if (y_range[0] < y_range[1])
//				{
//					for (int j = 0; j < 3; j++)
//					{
//						// ����� ������ ��
//						accumulated[j][2] += accumulated[j][1] * (y_range[1] - y_range[0] - 1);
//
//						// ���� ���� ������ ��
//						accumulated[j][2] += accumulated[j][0];
//						accumulated[j][1] = accumulated[j][2];
//						accumulated[j][0] = accumulated[j][2];
//					}
//				}
//				y_range[0] = m - 1;
//			}
//			// ȥ�� ������ ��� ���
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


//// �������� �ٽ� ǰ - ª��
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


//// �ٸ� ��� Ǯ�� - �������� �� Ǯ�� ������� ǰ
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
//	// c�� ������ ��
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
//	// ���� ��ǥ�� ������ = ��� ���� �� ���� ������ �� - ���̸�ŭ
//	if (sx == ex) { sxc = exc = n; }
//	if (sy == ey) { syc = eyc = m; }
//	// ���� ���� �� ���� ���� ������ 0
//	if (x < sx || ex < x)rp = 0;
//	else {
//		// ���� ��
//		if (x == sx)rp = sxc;
//		// �Ʒ��� ��
//		else if (x == ex)rp = exc;
//		// ���
//		else rp = 1;
//	}
//	// ���� ���� �� ���� ���� ������ 0
//	if (y < sy || ey < y)rq = 0;
//	else {
//		// ���� ��
//		if (y == sy)rq = syc;
//		// ������ ��
//		else if (y == ey)rq = eyc;
//		// ���
//		else rq = 1;
//	}
//	// ���� ��� ������ �� ���� �� ����
//	// �������� ��� ������ ǥ�� ������ - �������� ���� ���� �� - ������ ������ ����� ������..
//	return rp * rq;
//}

//// �ٸ� ��� Ǯ��
//// �������� Ǭ ���� �����
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
//        // 2�� ��� �������� ¦�� �̷� ���� ��ȯ�� - ¦���� 1 ũ�� Ȧ���� 1 �۰�
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
