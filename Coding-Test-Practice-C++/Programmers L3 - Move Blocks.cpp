//// ù ��° Ǯ��
//// ���� ���¿� ���� ���¸� ���� board�� ���� ������
//// #include <string>
//#include <vector>
//#include <queue>
//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//enum class Orientation
//{
//    HORIZONTAL,
//    VERTICAL
//};
//
//struct robot
//{
//    int i, j, cnt;
//    Orientation o;
//};
//
//int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//int hor_to_ver[2][2] = {{0, 0}, {-1, 0}};
//int ver_to_hor[2][2] = {{0, 0}, {0, -1}};
//
//int solution(vector<vector<int>> board) {
//    const int n = board.size();
//    vector<vector<bool>> hor_board(n, vector<bool>(n - 1, false));
//    vector<vector<bool>> ver_board(n - 1, vector<bool>(n, false));
//    
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//        {
//            if (j != n - 1)
//                if (board[i][j] == 1 || board[i][j + 1] == 1)
//                    hor_board[i][j] = true;
//            
//            if (i != n - 1)
//                if (board[i][j] == 1 || board[i + 1][j] == 1)
//                    ver_board[i][j] = true;
//        }
//
//    queue<robot> s;
//
//    s.push({ 0, 0, 0, Orientation::HORIZONTAL });
//    hor_board[0][0] = true;
//
//    while (!s.empty())
//    {
//        robot r = s.front();
//        s.pop();
//
//        //// Ȯ��
//        //if (r.o == Orientation::HORIZONTAL && r.i == n - 1 && r.j == n - 2)
//        //    return r.cnt;
//        //else if (r.o == Orientation::VERTICAL && r.i == n - 2 && r.j == n - 1)
//        //    return r.cnt;
//
//        if (r.o == Orientation::HORIZONTAL)
//        {
//            // 4������ �̵�
//            for (int k = 0; k < 4; k++)
//            {
//                int next_i = r.i + dir[k][0], next_j = r.j + dir[k][1];
//
//                if ((next_i + n) / n == 1 && (next_j + n - 1) / (n - 1) == 1)
//                {
//                    if (!hor_board[next_i][next_j])
//                    {
//                        // Ȯ��
//                        if (next_i == n - 1 && next_j == n - 2)
//                            return r.cnt + 1;
//
//                        hor_board[next_i][next_j] = true;
//                        s.push({ next_i, next_j, r.cnt + 1, Orientation::HORIZONTAL });
//                    }
//                }
//            }
//            // ȸ��
//            for (int k = 0; k < 2; k++)
//            {
//                int next_i = r.i + hor_to_ver[k][0], next_j = r.j + hor_to_ver[k][1];
//
//                if ((next_i + n - 1) / (n - 1) == 1 && (next_j + 1 + n) / n == 1)
//                {
//                    if ((board[next_i][next_j] != 1 && board[next_i + 1][next_j] != 1)
//                        && (board[next_i][next_j + 1] != 1 && board[next_i + 1][next_j + 1] != 1))
//                    {                        
//                        if (!ver_board[next_i][next_j])
//                        {
//                            // Ȯ��
//                            if (next_i == n - 2 && next_j == n - 1)
//                                return r.cnt + 1;
//
//                            ver_board[next_i][next_j] = true;
//                            s.push({ next_i, next_j, r.cnt + 1, Orientation::VERTICAL });
//                        }
//                        if (!ver_board[next_i][next_j + 1])
//                        {
//                            // Ȯ��
//                            if (next_i == n - 2 && next_j + 1 == n - 1)
//                                return r.cnt + 1;
//
//                            ver_board[next_i][next_j + 1] = true;
//                            s.push({ next_i, next_j + 1, r.cnt + 1, Orientation::VERTICAL });
//                        }
//                    }
//                }
//            }
//        }
//        else
//        {
//            // 4������ �̵�
//            for (int k = 0; k < 4; k++)
//            {
//                int next_i = r.i + dir[k][0], next_j = r.j + dir[k][1];
//
//                if ((next_i + n - 1) / (n - 1) == 1 && (next_j + n) / n == 1)
//                {
//                    if (!ver_board[next_i][next_j])
//                    {
//                        // Ȯ��
//                        if (next_i == n - 2 && next_j == n - 1)
//                            return r.cnt + 1;
//
//                        ver_board[next_i][next_j] = true;
//                        s.push({ next_i, next_j, r.cnt + 1, Orientation::VERTICAL });
//                    }
//                }
//            }
//            // ȸ��
//            for (int k = 0; k < 2; k++)
//            {
//                int next_i = r.i + ver_to_hor[k][0], next_j = r.j + ver_to_hor[k][1];
//
//                if ((next_i + 1 + n) / n == 1 && (next_j + n - 1) / (n - 1) == 1)
//                {
//                    if (board[next_i][next_j] != 1 && (board[next_i][next_j + 1] != 1)
//                        && (board[next_i + 1][next_j] != 1 && board[next_i + 1][next_j + 1] != 1))
//                    {
//                        if (!hor_board[next_i][next_j])
//                        {
//                            // Ȯ��
//                            if (next_i == n - 1 && next_j == n - 2)
//                                return r.cnt + 1;
//
//                            hor_board[next_i][next_j] = true;
//                            s.push({ next_i, next_j, r.cnt + 1, Orientation::HORIZONTAL });
//                        }
//                        if (!hor_board[next_i + 1][next_j])
//                        {
//                            // Ȯ��
//                            if (next_i + 1 == n - 1 && next_j == n - 2)
//                                return r.cnt + 1;
//
//                            hor_board[next_i + 1][next_j] = true;
//                            s.push({ next_i + 1, next_j, r.cnt + 1, Orientation::HORIZONTAL });
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    return -1;
//}
//
//int main()
//{
//    cout << solution({{0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 0}} );
//
//    return 0;
//}

//#include <queue>
//#include <vector>
//
//using namespace std;
//
//enum class Orientation
//{
//    HORIZONTAL = 0,
//    VERTICAL,
//};
//
//struct robot
//{
//    int i, j, cnt;
//    Orientation o;
//};
//
//int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//int check[4][2] = { {0, 0}, {0, -1}, { -1, -1}, {-1, 0} };
//int hor_to_ver[2][2] = {{0, 0}, {1, 0}};
//int ver_to_hor[2][2] = {{0, 0}, {0, 1}};
//
//int solution(vector<vector<int>> board) {
//    const int n = board.size();
//    vector < vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
//
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//        {
//            if (j == 0 || board[i][j] == 1 || (j - 1 >= 0 && board[i][j - 1] == 1))
//                visited[i][j][(int)Orientation::HORIZONTAL] = true;
//            if (i == 0 || board[i][j] == 1 || (i - 1 >= 0 && board[i - 1][j] == 1))
//                visited[i][j][(int)Orientation::VERTICAL] = true;
//        }
//
//    queue<robot> s;
//    s.push({ 0, 1, 0, Orientation::HORIZONTAL });
//    visited[0][1][(int)Orientation::HORIZONTAL] = true;;
//
//    while (!s.empty())
//    {
//        robot r = s.front();
//        s.pop();
//        
//        // �̵�
//        for (int k = 0; k < 4; k++)
//        {
//            int next_i = r.i + dir[k][0], next_j = r.j + dir[k][1];
//
//            if ((next_i + n) / n != 1 || (next_j + n) / n != 1)
//                continue;
//
//            if (visited[next_i][next_j][(int)r.o])
//                continue;
//
//            // ���� üũ
//            if (next_i == n - 1 && next_j == n - 1)
//                return r.cnt + 1;
//
//            visited[next_i][next_j][(int)r.o] = true;
//            s.push({ next_i, next_j, r.cnt + 1, r.o });
//        }
//
//        // ȸ��
//        if (r.o == Orientation::HORIZONTAL)
//        {
//            for (int k = 0; k < 2; k++)
//            {
//                int next_i = r.i + hor_to_ver[k][0], next_j = r.j + hor_to_ver[k][1];
//
//                if (next_i == 0 || next_i == n)
//                    continue;
//
//                bool flag = false;
//
//                for (int m = 0; m < 4; m++)
//                    if (board[next_i + check[m][0]][next_j + check[m][1]] == 1)
//                    {
//                        flag = true;
//                        break;
//                    }
//                if (flag)
//                    continue;
//
//                if (!visited[next_i][next_j][(int)Orientation::VERTICAL])
//                {
//                    // ���� üũ
//                    if (next_i == n - 1 && next_j == n - 1)
//                        return r.cnt + 1;
//
//                    visited[next_i][next_j][(int)Orientation::VERTICAL] = true;
//                    s.push({ next_i, next_j, r.cnt + 1, Orientation::VERTICAL });
//                }
//
//                if (!visited[next_i][next_j - 1][(int)Orientation::VERTICAL])
//                {
//                    // ���� üũ
//                    if (next_i == n - 1 && next_j - 1 == n - 1)
//                        return r.cnt + 1;
//
//                    visited[next_i][next_j - 1][(int)Orientation::VERTICAL] = true;
//                    s.push({ next_i, next_j - 1, r.cnt + 1, Orientation::VERTICAL });
//                }
//            }
//        }
//        else
//        {
//            for (int k = 0; k < 2; k++)
//            {
//                int next_i = r.i + ver_to_hor[k][0], next_j = r.j + ver_to_hor[k][1];
//
//                if (next_j == 0 || next_j == n)
//                    continue;
//
//                bool flag = false;
//
//                for (int m = 0; m < 4; m++)
//                    if (board[next_i + check[m][0]][next_j + check[m][1]] == 1)
//                    {
//                        flag = true;
//                        break;
//                    }
//                if (flag)
//                    continue;
//
//                if (!visited[next_i][next_j][(int)Orientation::HORIZONTAL])
//                {
//                    // ���� üũ
//                    if (next_i == n - 1 && next_j == n - 1)
//                        return r.cnt + 1;
//
//                    visited[next_i][next_j][(int)Orientation::HORIZONTAL] = true;
//                    s.push({ next_i, next_j, r.cnt + 1, Orientation::HORIZONTAL });
//                }
//
//                if (!visited[next_i - 1][next_j][(int)Orientation::HORIZONTAL])
//                {
//                    // ���� üũ
//                    if (next_i - 1 == n - 1 && next_j == n - 1)
//                        return r.cnt + 1;
//
//                    visited[next_i - 1][next_j][(int)Orientation::HORIZONTAL] = true;
//                    s.push({ next_i - 1, next_j, r.cnt + 1, Orientation::HORIZONTAL });
//                }
//            }
//        }
//    }
//
//    return -1;
//}
//
//int main()
//{
//    solution({ {0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 0} });
//
//    return 0;
//}

//// �ٸ� ��� Ǯ��
//// ���� �ʹ� ��ư� ��������, �� �ܼ��ϰ� �����ؾ� ��
////#include <bits/stdc++.h>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const int dx[] = { -1, 0, 1, 0 };
//const int dy[] = { 0, 1, 0, -1 };
//const int ddx[] = { 0, 1 };
//const int ddy[] = { 1, 0 };
//
//int N;
//// ������ ����
//// 200���� ���� ���� ��
//// 200���� ���� ������ �߿��� (0 - 198����) 2�� ���� ���� ��
//// 2�� ���� �������� 0-����, 1-����
//int conv(int a, int b, int c) {
//    return a * 200 + b * 2 + c;
//}
//bool check(int x, int y, vector<vector<int>>& board) {
//    // x�� y�� ������ ����� �ʾҴ���?, �̵��Ϸ��� ���� ���� ���� ������ üũ
//    return x >= 0 && x < N&& y >= 0 && y < N&& board[x][y] == 0;
//}
//int solution(vector<vector<int>> board) {
//    N = board.size();
//    // {}�� ����ؼ� �ʱ�ȭ �� - 0���� �ʱ�ȭ ��
//    bool visit[100][100][2]{}; // 0-����, 1-����
//    visit[0][0][0] = 1;
//
//    queue<int> Q;
//    Q.push(conv(0, 0, 0));
//
//    int ans = 0;
//    while (!Q.empty()) {
//        // ���� �ݺ����� ����ؼ� �̵� Ƚ���� ���� �̵��� ���� �ݺ������� ���� �� ans(�̵� Ƚ��)�� ����
//        int szQ = Q.size();
//        while (szQ--) {
//            int x, y, d, K = Q.front(); Q.pop();
//            // ����� �����Ϳ��� �� ���ϱ�
//            x = K / 200;
//            y = K % 200 / 2;
//            d = K % 2;
//
//            // �κ��� �����ϴ� �ٸ� ���� ��ġ
//            int x2 = x + ddx[d];
//            int y2 = y + ddy[d];
//
//            // �κ��� ��ü�� �Ϻΰ� ���������� �� ��ȯ
//            // ���� ť�� ���� ������ ó������� �װ� �ڵ�� ���������� ����ȭ�� �Ѵٰ� �����ߴµ� ������ �ڵ尡 ������������ �����ϱ� �ʹ� ���������
//            // �ð��� ũ�� ���̰� ���� ������ �������� �����ϱ� ���� �ڵ尡 �� ���� �ڵ��� ������
//            if (x == N - 1 && y == N - 1 ||
//                x2 == N - 1 && y2 == N - 1) return ans;
//
//            // �̵�
//            for (int i = 0; i < 4; ++i) {
//                int nx = x + dx[i];
//                int ny = y + dy[i];
//                int nx2 = x2 + dx[i];
//                int ny2 = y2 + dy[i];
//                // �̵��� �� ���� ��
//                if (!check(nx, ny, board) || !check(nx2, ny2, board)) continue;
//
//                // �ܼ� �̵�
//                // ���� ���� �������� �̵��ߴ��� üũ
//                if (!visit[nx][ny][d]) {
//                    visit[nx][ny][d] = 1;
//                    Q.push(conv(nx, ny, d));
//                }
//            }
//
//            // ȸ�� �̵�
//            // ������ ���
//            if (d == 0) {
//                // ���� ȸ���� ��� - ���� �� ���� ���� �ȿ� ���� �ϰ� ���� �ƴϾ�� ��
//                if (check(x - 1, y, board) && check(x2 - 1, y2, board)) {
//                    if (!visit[x - 1][y][1]) {
//                        Q.push(conv(x - 1, y, 1));
//                        visit[x - 1][y][1] = 1;
//                    }
//                    if (!visit[x - 1][y + 1][1]) {
//                        Q.push(conv(x - 1, y + 1, 1));
//                        visit[x - 1][y + 1][1] = 1;
//                    }
//                }
//                // �Ʒ��� ȸ���� ��� - �Ʒ��� �� ���� ���� �ȿ� ���� �ϰ� ���� �ƴϾ�� ��
//                if (check(x + 1, y, board) && check(x2 + 1, y2, board)) {
//                    if (!visit[x][y][1]) {
//                        Q.push(conv(x, y, 1));
//                        visit[x][y][1] = 1;
//                    }
//                    if (!visit[x][y + 1][1]) {
//                        Q.push(conv(x, y + 1, 1));
//                        visit[x][y + 1][1] = 1;
//                    }
//                }
//            }
//            // ������ ���
//            else {
//                // ���������� ȸ���� ��� - �������� �� ���� ���� �ȿ� ���� �ϰ� ���� �ƴϾ�� ��
//                if (check(x, y + 1, board) && check(x2, y2 + 1, board)) {
//                    if (!visit[x][y][0]) {
//                        Q.push(conv(x, y, 0));
//                        visit[x][y][0] = 1;
//                    }
//                    if (!visit[x + 1][y][0]) {
//                        Q.push(conv(x + 1, y, 0));
//                        visit[x + 1][y][0] = 1;
//                    }
//                }
//                // �������� ȸ���� ��� - ������ �� ���� ���� �ȿ� ���� �ϰ� ���� �ƴϾ�� ��
//                if (check(x, y - 1, board) && check(x2, y2 - 1, board)) {
//                    if (!visit[x][y - 1][0]) {
//                        Q.push(conv(x, y - 1, 0));
//                        visit[x][y - 1][0] = 1;
//                    }
//                    if (!visit[x + 1][y - 1][0]) {
//                        Q.push(conv(x + 1, y - 1, 0));
//                        visit[x + 1][y - 1][0] = 1;
//                    }
//                }
//            }
//        }
//
//        ++ans;
//    }
//
//    return -1;
//}