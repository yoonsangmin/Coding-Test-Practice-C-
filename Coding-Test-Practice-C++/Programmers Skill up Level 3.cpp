//// 1�� ����
//// īī�� ī�� ����
//// �� Ǯ��
//// Ʋ�� �� �ؼ����� �ٽ� ǰ
//#include <string>
//#include <vector>
//#include <map>
//#include <queue>
//#include <algorithm>
//#define INF 10000000
//
//using namespace std;
//
//int D[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
//
//struct Point
//{
//    int r, c, cnt;
//};
//
//int bfs(vector<vector<int>>& board, vector<int> dpt, vector<int> dst)
//{
//    int visited[4][4] = { false };
//
//    queue<Point> q;
//    q.push({ dpt[0], dpt[1], 0});
//
//    while (!q.empty())
//    {
//        Point cur = q.front();
//        q.pop();
//
//        if (cur.r == dst[0] && cur.c == dst[1])
//            return cur.cnt;
//
//        for (int* dir : D)
//        {
//            int next_r = cur.r + dir[0], next_c = cur.c + dir[1];
//
//            if (next_r < 0 || next_r > 3 || next_c < 0 || next_c > 3)
//                continue;
//
//            if (!visited[next_r][next_c])
//            {
//                visited[next_r][next_c] = true;
//                q.push({ next_r, next_c, cur.cnt + 1 });
//            }
//
//            for (int i = 0; i < 2; i++)
//            {
//                if (board[next_r][next_c] != 0)
//                    break;
//
//                if (next_r + dir[0] < 0 || next_r + dir[0] > 3 || next_c + dir[1] < 0, next_c + dir[1] > 3)
//                    break;
//
//                next_r += dir[0];
//                next_c += dir[1];
//            }
//
//            if (!visited[next_r][next_c])
//            {
//                visited[next_r][next_c] = true;
//                q.push({ next_r, next_c, cur.cnt + 1 });
//            }
//        }
//    }
//
//    return INF;
//}
//
//map<int, vector<vector<int>>> make_card_map(vector<vector<int>>& board)
//{
//    map<int, vector<vector<int>>> m;
//
//    for (int r = 0; r < 4; r++)
//        for (int c = 0; c < 4; c++)
//        {
//            if (board[r][c] == 0)
//                continue;
//
//            m[board[r][c]].push_back({ r, c, 0 });
//        }
//    return m;
//}
//
//int traverse_permutation(vector<vector<int>>& board, vector<int> cur)
//{
//    map<int, vector<vector<int>>> cards = make_card_map(board);
//
//    if (cards.empty())
//        return 0;
//
//    int ret = INF;
//
//    for (auto &[key, value] : cards)
//    {
//        int card1 = bfs(board, cur, value[0]) + bfs(board, value[0], value[1]) + 2;
//        int card2 = bfs(board, cur, value[1]) + bfs(board, value[1], value[0]) + 2;
//
//        for (int i = 0; i <= 1; i++)
//            board[value[i][0]][value[i][1]] = 0;
//
//        ret = min(ret, card1 + traverse_permutation(board, value[1]));
//        ret = min(ret, card2 + traverse_permutation(board, value[0]));
//
//        for (int i = 0; i <= 1; i++)
//            board[value[i][0]][value[i][1]] = key;
//    }
//
//    return ret;
//}
//
//int solution(vector<vector<int>> board, int r, int c) {
//    int answer = traverse_permutation(board, { r, c });
//
//    return answer;
//}
//
//int main()
//{
//    solution({ {1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0} }, 1, 0);
//
//    return 0;
//}

//// �ٸ� ��� Ǯ��
//// next_permutation �� ��
//#include <bits/stdc++.h>
//using namespace std;
//using pii = pair<int, int>;
//#define X first
//#define Y second
//
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//
//bool OOB(int x, int y) {
//    return x < 0 || x > 3 || y < 0 || y > 3;
//}
//
//int dist(vector<vector<int>>& board, pii src, pii dst) {
//    int d[4][4];
//    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) d[i][j] = -1;
//    d[src.X][src.Y] = 0;
//    queue<pii> q;
//    q.push(src);
//    while (!q.empty()) {
//        auto cur = q.front(); q.pop();
//        for (int dir = 0; dir < 4; dir++) {
//            int en = 0; // dir �������� ������ �� ī�� Ȥ�� ������ ������ �Ÿ�
//            while (true) {
//                int nx = cur.X + dx[dir] * en;
//                int ny = cur.Y + dy[dir] * en;
//                if (OOB(nx + dx[dir], ny + dy[dir]) || (en != 0 && board[nx][ny] != 0)) break;
//                en++;
//            }
//            for (int z : {1, en}) {
//                int nx = cur.X + dx[dir] * z;
//                int ny = cur.Y + dy[dir] * z;
//                if (OOB(nx, ny)) continue;
//                if (d[nx][ny] == -1)
//                {
//                    d[nx][ny] = d[cur.X][cur.Y] + 1;
//                    q.push({ nx,ny });
//                }
//            }
//        }
//    }
//    return d[dst.X][dst.Y];
//}
//int solution(vector<vector<int>> board, int r, int c) {
//    vector<pii> occur[7];
//
//    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
//        if (board[i][j] == 0) continue;
//        occur[board[i][j]].push_back({ i,j });
//    }
//
//    vector<int> p;
//    for (int i = 1; i <= 6; i++) {
//        if (!occur[i].empty()) p.push_back(i);
//    }
//    int n = p.size(); // ī�� ������ ����
//    int ans = 987654321;
//    do { // ������ ������ ������ ���� permutation
//        vector<vector<int>> myboard = board;
//        int d[6][2];
//        d[0][0] = dist(myboard, { r, c }, occur[p[0]][0]) + dist(myboard, occur[p[0]][0], occur[p[0]][1]);
//        d[0][1] = dist(myboard, { r, c }, occur[p[0]][1]) + dist(myboard, occur[p[0]][1], occur[p[0]][0]);
//        myboard[occur[p[0]][0].X][occur[p[0]][0].Y] = 0;
//        myboard[occur[p[0]][1].X][occur[p[0]][1].Y] = 0;
//        for (int i = 1; i < n; i++) {
//            d[i][0] = min(d[i - 1][0] + dist(myboard, occur[p[i - 1]][1], occur[p[i]][0]), d[i - 1][1] + dist(myboard, occur[p[i - 1]][0], occur[p[i]][0])) + dist(myboard, occur[p[i]][0], occur[p[i]][1]);
//            d[i][1] = min(d[i - 1][0] + dist(myboard, occur[p[i - 1]][1], occur[p[i]][1]), d[i - 1][1] + dist(myboard, occur[p[i - 1]][0], occur[p[i]][1])) + dist(myboard, occur[p[i]][1], occur[p[i]][0]);
//            myboard[occur[p[i]][0].X][occur[p[i]][0].Y] = 0;
//            myboard[occur[p[i]][1].X][occur[p[i]][1].Y] = 0;
//        }
//        ans = min({ ans, d[n - 1][0], d[n - 1][1] });
//    } while (next_permutation(p.begin(), p.end()));
//    return ans + 2 * n;
//}

//// https://www.youtube.com/watch?v=4bwz9yOUGWM
//// �ִ��� ��ü�� Ǯ� Ǫ�� �� ���� ��
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//#define INF 987654321
//
//struct Point {
//    int row, col, cnt;
//};
//
//vector<vector<int>> Board;
//int D[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
//
//int bfs(Point src, Point dst) {
//    bool visited[4][4] = { false };
//    queue<Point> q;
//    q.push(src);
//    while (!q.empty()) {
//        Point curr = q.front();
//        q.pop();
//        if (curr.row == dst.row && curr.col == dst.col)
//            return curr.cnt;
//
//        for (int i = 0; i < 4; i++) {
//            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
//            if (nr < 0 || nr>3 || nc < 0 || nc>3) continue;
//
//            if (!visited[nr][nc]) {
//                visited[nr][nc] = true;
//                q.push({ nr,nc,curr.cnt + 1 });
//            }
//
//            for (int j = 0; j < 2; j++) {
//                if (Board[nr][nc] != 0) break;
//                if (nr + D[i][0] < 0 || nr + D[i][0]>3 || nc + D[i][1] < 0 || nc + D[i][1]>3)
//                    break;
//
//                nr += D[i][0];
//                nc += D[i][1];
//            }
//
//            if (!visited[nr][nc]) {
//                visited[nr][nc] = true;
//                q.push({ nr,nc,curr.cnt + 1 });
//            }
//        }
//    }
//    return INF;
//}
//
//int permutate(Point src) {
//    int ret = INF;
//    for (int num = 1; num <= 6; num++) {
//        vector<Point> card;
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                if (Board[i][j] == num) {
//                    card.push_back({ i,j,0 });
//                }
//            }
//        }
//        if (card.empty()) continue;
//
//        int one = bfs(src, card[0]) + bfs(card[0], card[1]) + 2;
//        int two = bfs(src, card[1]) + bfs(card[1], card[0]) + 2;
//
//        for (int i = 0; i < 2; i++)
//            Board[card[i].row][card[i].col] = 0;
//
//        ret = min(ret, one + permutate(card[1]));
//        ret = min(ret, two + permutate(card[0]));
//
//        for (int i = 0; i < 2; i++)
//            Board[card[i].row][card[i].col] = num;
//    }
//    if (ret == INF)
//        return 0;
//
//    return ret;
//}
//
//int solution(vector<vector<int>> board, int r, int c) {
//    Board = board;
//
//    return permutate({ r,c,0 });
//}


//// 2�� ����
//// �ǹ� ���ݰ� ȸ�� ��ų
//// �� Ǯ��
//// ó���� brutal force�� ���� �����ָ鼭 Ǯ���µ� �ð� �ʰ��� ��
//// �� Ǭ �� �ؼ� �� �� ���� ���� Ǯ�
//// �������� ����ؼ� Ǯ���µ� 1�������θ� Ǯ�� �ð��� ���� ���� ����
//// 0  7  0  0 -7  0  0 ->
//// 0  7  7  7  0  0  0
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void apply_skill(vector<vector<int>>& board, vector<vector<int>>& sum, const vector<int>& elem)
//{
//    int x1 = elem[1], y1 = elem[2], x2 = elem[3], y2 = elem[4];
//    int degree = (elem[0] * 2 - 3) * elem[5];
//
//    bool is_y2_small_than_size = y2 + 1 < board[0].size() ? true : false;
//
//    for (int x = x1; x <= x2; x++)
//    {
//        sum[x][y1] += degree;
//        if (is_y2_small_than_size)
//            sum[x][y2 + 1] -= degree;
//    }
//}
//
//int solution(vector<vector<int>> board, vector<vector<int>> skill) {
//    int answer = 0;
//    vector<vector<int>> sum(board.size(), vector<int>(board[0].size(), 0));
//
//    for (const vector<int> elem : skill)
//        apply_skill(board, sum, elem);
//
//
//    for (int x = 0; x < board.size(); x++)
//    {
//        board[x][0] += sum[x][0];
//        if (board[x][0] > 0)
//            answer++;
//
//        for (int y = 1; y < board[0].size(); y++)
//        {
//            sum[x][y] += sum[x][y - 1];
//
//            board[x][y] += sum[x][y];
//            if (board[x][y] > 0)
//                answer++;
//        }
//    }
//
//    return answer;
//}

//// 2�������� �������� �������
//// 0�� �ƴ� ������ �Ʒ��� �����ְ� ���������� ���� ��
//// 0  0  0  0  0  0  0  0       0  0  0  0  0  0  0  0
//// 0  7  0  0 -7  0  0  0       0  7  7  7  0  0  0  0
//// 0  0  0  0  0  0  0  0  ->   0  7  7  7  0  0  0  0
//// 0  0  0 (0) 0  0  0  0       0  7  7  7  0  0  0  0
//// 0 -7  0  0  7  0  0  0       0  0  0  0  0  0  0  0
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void apply_skill(vector<vector<int>>& board, vector<vector<int>>& sum, const vector<int>& elem)
//{
//    int x1 = elem[1], y1 = elem[2], x2 = elem[3], y2 = elem[4];
//    int degree = (elem[0] * 2 - 3) * elem[5];
//
//    bool is_x2_small_than_size = x2 + 1 < board.size() ? true : false;
//    bool is_y2_small_than_size = y2 + 1 < board[0].size() ? true : false;
//
//    sum[x1][y1] += degree;
//    if (is_x2_small_than_size) 
//        sum[x2 + 1][y1] -= degree;
//    if (is_y2_small_than_size)
//        sum[x1][y2 + 1] -= degree;
//    if (is_x2_small_than_size && is_y2_small_than_size)
//        sum[x2 + 1][y2 + 1] += degree;
//}
//
//int solution(vector<vector<int>> board, vector<vector<int>> skill) {
//    int answer = 0;
//    vector<vector<int>> sum(board.size(), vector<int>(board[0].size(), 0));
//
//    for (const vector<int> elem : skill)
//        apply_skill(board, sum, elem);
//
//
//    for (int x = 0; x < board.size(); x++)
//    {
//        if (sum[x][0] != 0 && x + 1 < board.size())
//            sum[x + 1][0] += sum[x][0];
//
//        board[x][0] += sum[x][0];
//        if (board[x][0] > 0)
//            answer++;
//
//        for (int y = 1; y < board[0].size(); y++)
//        {
//            // �����ֱ� ���� ���� ���� 0�� �ƴ϶�� �Ʒ��ε� �������� ����
//            if (sum[x][y] != 0 && x + 1 < board.size())
//                sum[x + 1][y] += sum[x][y];
//
//            sum[x][y] += sum[x][y - 1];
//
//            board[x][y] += sum[x][y];
//            if (board[x][y] > 0)
//                answer++;
//        }
//    }
//
//    return answer;
//}

//// �ٸ� ��� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> board, vector<vector<int>> skill) {
//    int answer = 0;
//    // ������ ��� �ൿ ���
//    // ����� 1 �� ũ�� �ؼ� x2, y2�� board ũ�⺸�� ������ ������ üũ������ �ʾƵ� ��
//    vector<vector<int>> query(board.size() + 1, vector<int>(board[0].size() + 1, 0));
//    for (auto s : skill) {
//        // ���ݽ�ų
//        if (s[0] == 1) {
//            query[s[1]][s[2]] -= s[5];
//            query[s[1]][s[4] + 1] += s[5];
//            query[s[3] + 1][s[2]] += s[5];
//            query[s[3] + 1][s[4] + 1] -= s[5];
//        }
//        else {// ȸ����ų
//            query[s[1]][s[2]] += s[5];
//            query[s[1]][s[4] + 1] -= s[5];
//            query[s[3] + 1][s[2]] -= s[5];
//            query[s[3] + 1][s[4] + 1] += s[5];
//        }
//    }
//
//    // ���������� �ѹ��� �������� ����
//    // �Ʒ� �κп� ��� �ݴ��� ���� ������༭ ���η� ���� �� ���η� �ѹ��� ���ָ� ��
//    // �ſ� �������̶� ���� �� ����
//    // 0  5  0  0 -5  0                    0  5  5  5  0  0                    0  5  5  5  0  0
//    // 0  0  0  0  0  0  ���� ������ ����  0  0  0  0  0  0  ���� ������ ����  0  5  5  5  0  0 
//    // 0 -5  0  0  5  0                    0 -5 -5 -5  0  0                    0  0  0  0  0  0
//    for (int i = 0; i < query.size(); i++)
//        for (int j = 1; j < query[i].size(); j++)
//            query[i][j] += query[i][j - 1];
//
//    // ���η� �ѹ� ��������
//    for (int j = 0; j < query[0].size(); j++)
//        for (int i = 1; i < query.size(); i++)
//            query[i][j] += query[i - 1][j];
//
//    // �������� ������ �ǹ��� üũ��, ������ �����տ��� �� ���� �ص� ��
//    for (int i = 0; i < board.size(); i++) {
//        for (int j = 0; j < board[i].size(); j++) {
//            if ((board[i][j] + query[i][j]) > 0)
//                answer++;
//        }
//    }
//    return answer;
//}

//// �ٸ� Ǯ��
//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[1001][1001];
//int solution(vector<vector<int>> board, vector<vector<int>> skill) {
//    int m = board.size(), n = board[0].size();
//    for (auto x : skill) {
//        if (x[0] == 1)
//        {
//            arr[x[1]][x[2]] -= x[5];
//            arr[x[1]][x[4] + 1] += x[5];
//            arr[x[3] + 1][x[2]] += x[5];
//            arr[x[3] + 1][x[4] + 1] -= x[5];
//        }
//        else
//        {
//            arr[x[1]][x[2]] += x[5];
//            arr[x[1]][x[4] + 1] -= x[5];
//            arr[x[3] + 1][x[2]] -= x[5];
//            arr[x[3] + 1][x[4] + 1] += x[5];
//        }
//    }
//
//    // ���κ��� ���κ��� �̸� ����ϰ� �߰� �κ��� ������ ������ ��� �� ������
//    for (int j = 1; j < n; j++)
//        arr[0][j] += arr[0][j - 1];
//    for (int i = 1; i < m; i++)
//        arr[i][0] += arr[i - 1][0];
//    for (int i = 1; i < m; i++)
//        for (int j = 1; j < n; j++)
//            arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
//
//    int answer = 0;
//    for (int i = 0; i < m; i++)
//        for (int j = 0; j < n; j++)
//            answer += (arr[i][j] + board[i][j] >= 1);
//    return answer;
//}