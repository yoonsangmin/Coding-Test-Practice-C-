//// 1�� ����
//// īī�� ī�� ����
//// �� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void find_second(vector<vector<int>>& board, int r, int c)
//{
//    int selected_num = board[r][c];
//    int first_r = r, first_c = c;
//
//
//    // erase
//    board[first_r][first_c] = 0;
//    board[r][c] = 0;
//}
//
//// ���� ��ġ���� ���� ����� ���� �ϳ� ����
//int set_first(vector<vector<int>>& board, int r, int c)
//{
//
//    find_second(board, r, c);
//}
//
//int solution(vector<vector<int>> board, int r, int c) {
//    int answer = 0;
//    int remain = 0;
//
//    for (int x = 0; x < 4; x++)
//        for (int y = 0; y < 4; y++)
//            if (board[x][y] != 0) remain++;
//    remain >>= 1;
//
//    for (remain; remain > 0; remain--)
//        set_first(board, r, c);
//
//    return answer;
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