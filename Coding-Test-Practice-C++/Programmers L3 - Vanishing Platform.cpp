//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//bool amove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth);
//bool bmove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth);
//
//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, 1, 0, -1 };
//
//bool amove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth)
//{
//    // ���� üũ - ���� ���ִ� ���� ������ ���������� ���ٰ� �˷���
//    if (board[aloc[0]][aloc[1]] == 0)
//    {
//        depth = cnt;
//        cout << cnt << " a ���� ���� " << depth << endl << endl;
//        return false;
//    }
//    // ������ ����
//    else
//        board[aloc[0]][aloc[1]] = 0;
//
//    bool canwin = false;
//    bool canmove = false;
//    vector<int> wins;
//    vector<int> loses;
//
//    for (int i = 0; i < 4; i++)
//    {
//        vector<int> nextloc = { aloc[0] + dx[i], aloc[1] + dy[i] };
//        // ������ �� �ִ��� üũ
//        // ���� ��
//        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
//            continue;
//        else if (board[nextloc[0]][nextloc[1]] == 1)
//        {
//            canmove = true;
//            int child;
//            // bmove ȣ��
//            bool result = bmove(board, nextloc, bloc, cnt + 1, child);
//            // ������ �� ���̶� ������ canwin = true, ������ ��� �̰����� canwin = false;
//            canwin |= !result;
//
//            // ��� ���� �̱�� ���� ��
//            if (result)
//                loses.push_back(child);
//            // ��� ���� ���� ���� �̱�
//            else
//                    wins.push_back(child);
//        }
//    }
//
//    // ���� �ٽ� ����
//    board[aloc[0]][aloc[1]] = 1;
//
//    // a�� ������ �� ���� ���
//    if (!canmove)
//    {
//        depth = cnt;
//        return false;
//    }
//    // a�� �̱� ���
//    else if (canwin)
//    {
//        depth = *min_element(wins.begin(), wins.end());
//        return true;
//    }
//    // a�� �� ���
//    else
//    {
//        depth = *max_element(loses.begin(), loses.end());
//        return false;
//    }
//}
//
//bool bmove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth)
//{
//    // ���� üũ - ���� ���ִ� ���� ������ ���������� ���ٰ� �˷���
//    if (board[bloc[0]][bloc[1]] == 0)
//    {
//        depth = cnt;
//        cout << cnt << " b ���� ���� " << depth << endl << endl;
//        return false;
//    }
//    // ������ ����
//    else
//        board[bloc[0]][bloc[1]] = 0;
//
//    bool canwin = false;
//    bool canmove = false;
//    vector<int> wins;
//    vector<int> loses;
//
//    for (int i = 0; i < 4; i++)
//    {
//        vector<int> nextloc = { bloc[0] + dx[i], bloc[1] + dy[i] };
//        // ������ �� �ִ��� üũ
//        // ���� ��
//        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
//            continue;
//        else if (board[nextloc[0]][nextloc[1]] == 1)
//        {
//            canmove = true;
//            int child; 
//            // amove ȣ��
//            bool result = amove(board, aloc, nextloc, cnt + 1, child);
//            // ������ �� ���̶� ������ canwin = true, ������ ��� �̰����� canwin = false;
//            canwin |= !result;
//
//            // ��� ���� �̱�� ���� ��
//            if (result)
//                loses.push_back(child);
//            // ��� ���� ���� ���� �̱�
//            else
//                wins.push_back(child);
//        }
//    }
//
//    // ���� �ٽ� ����
//    board[bloc[0]][bloc[1]] = 1;
//
//    // b�� ������ �� ���� ���
//    if (!canmove)
//    {
//        depth = cnt;
//        return false;
//    }
//    // b�� �̱� ���
//    else if (canwin)
//    {
//        depth = *min_element(wins.begin(), wins.end());
//        return true;
//    }
//    // b�� �� ���
//    else
//    {
//        depth = *max_element(loses.begin(), loses.end());
//        return false;
//    }
//}
//
//int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
//    int answer = 0;
//
//    amove(board, aloc, bloc, 0, answer);
//
//    return answer;
//}
//
//int main()
//{
//    cout << solution({ {1, 1, 1, 0},{1, 1, 0, 1},{1, 0, 1, 1},{0, 1, 1, 1} }, { 0, 0 }, { 3, 3 });
//
//    // 8
//
//    return 0;
//}

//// �ٸ� ��� Ǯ��
//#include <vector>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//using vi = vector<int>;
//using vvi = vector<vi>;
//using pii = pair<int, int>;
//
//enum Player { A, B };
//
//// �Լ��� �ϳ��� ���� ���� �÷��̾ ǥ���� ��
//pii DFS(vvi& board, Player p1, int x1, int y1, int x2, int y2) { // { winner, cnt } in current state
//    Player p2 = p1 == A ? B : A;
//    pii ret{ p2, 0 };
//    // ���� ���ִ� ���� ������ �ִ��� üũ
//    if (board[x1][y1]) for (int d = 0; d < 4; d++) {
//        // 1012�� ���� char�� '1'�� ���� - int�δ� 0 -1 0 1 �� ��
//        // �̵�
//        const int nx = x1 + "1012"[d] - '1';
//        const int ny = y1 + "2101"[d] - '1';
//        // ���� �������, �� ���� ������ ������ üũ
//        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) continue;
//        // ���� �� �ִ� ���� ������ ����
//        board[x1][y1] = 0;
//        // ��ġ�� ���� �ٲ㼭 ����
//        auto [win, cnt] = DFS(board, p2, x2, y2, nx, ny);
//        // ���� �ٽ� ����
//        board[x1][y1] = 1;
//        
//        // ���� �̱� ���
//        if (win == p1) {
//            // ret.first�� ó���� ���, ret.first == p1 - ���� �̱� ��찡 �ϳ����� ���� �� - �̱�� ���� �� �ּڰ��� ��
//            if (ret.first == p1) ret.second = min(ret.second, cnt + 1);
//            // (��밡 �� ��) ���� �̱� ��찡 �ϳ��� ������ ret.firs�� ���� �� - �̱� ����� ��带 �ٷ� ��� cnt�� ���
//            else ret = { win, cnt + 1 };
//        }
//        // ��밡 �̱� ���, ret.first�� ����� ��� - ���� �̱� ��찡 ���� ���� ���� - ���� ���� �� �ִ�
//        else if (ret.first == p2) ret.second = max(ret.second, cnt + 1);
//    }
//    // pair�� �Ἥ �̱� �÷��̾�, cnt�� �� ���� ��ȯ��
//    return ret;
//}
//
//int solution(vvi board, vi aloc, vi bloc) {
//    const int ax = aloc[0], ay = aloc[1];
//    const int bx = bloc[0], by = bloc[1];
//    return DFS(board, A, ax, ay, bx, by).second;
//}