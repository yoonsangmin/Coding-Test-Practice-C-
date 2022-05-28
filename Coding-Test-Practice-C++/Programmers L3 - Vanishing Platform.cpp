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
//    // 발판 체크 - 현재 서있던 곳의 발판이 없어졌으면 졌다고 알려줌
//    if (board[aloc[0]][aloc[1]] == 0)
//    {
//        depth = cnt;
//        cout << cnt << " a 발판 없어 " << depth << endl << endl;
//        return false;
//    }
//    // 발판을 없앰
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
//        // 움직일 수 있는지 체크
//        // 보드 밖
//        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
//            continue;
//        else if (board[nextloc[0]][nextloc[1]] == 1)
//        {
//            canmove = true;
//            int child;
//            // bmove 호출
//            bool result = bmove(board, nextloc, bloc, cnt + 1, child);
//            // 상대방이 한 번이라도 졌으면 canwin = true, 상대방이 모두 이겼으면 canwin = false;
//            canwin |= !result;
//
//            // 상대 방이 이기면 나는 짐
//            if (result)
//                loses.push_back(child);
//            // 상대 방이 지면 나는 이김
//            else
//                    wins.push_back(child);
//        }
//    }
//
//    // 발판 다시 만듦
//    board[aloc[0]][aloc[1]] = 1;
//
//    // a가 움직일 수 없는 경우
//    if (!canmove)
//    {
//        depth = cnt;
//        return false;
//    }
//    // a가 이긴 경우
//    else if (canwin)
//    {
//        depth = *min_element(wins.begin(), wins.end());
//        return true;
//    }
//    // a가 진 경우
//    else
//    {
//        depth = *max_element(loses.begin(), loses.end());
//        return false;
//    }
//}
//
//bool bmove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth)
//{
//    // 발판 체크 - 현재 서있던 곳의 발판이 없어졌으면 졌다고 알려줌
//    if (board[bloc[0]][bloc[1]] == 0)
//    {
//        depth = cnt;
//        cout << cnt << " b 발판 없어 " << depth << endl << endl;
//        return false;
//    }
//    // 발판을 없앰
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
//        // 움직일 수 있는지 체크
//        // 보드 밖
//        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
//            continue;
//        else if (board[nextloc[0]][nextloc[1]] == 1)
//        {
//            canmove = true;
//            int child; 
//            // amove 호출
//            bool result = amove(board, aloc, nextloc, cnt + 1, child);
//            // 상대방이 한 번이라도 졌으면 canwin = true, 상대방이 모두 이겼으면 canwin = false;
//            canwin |= !result;
//
//            // 상대 방이 이기면 나는 짐
//            if (result)
//                loses.push_back(child);
//            // 상대 방이 지면 나는 이김
//            else
//                wins.push_back(child);
//        }
//    }
//
//    // 발판 다시 만듦
//    board[bloc[0]][bloc[1]] = 1;
//
//    // b가 움직일 수 없는 경우
//    if (!canmove)
//    {
//        depth = cnt;
//        return false;
//    }
//    // b가 이긴 경우
//    else if (canwin)
//    {
//        depth = *min_element(wins.begin(), wins.end());
//        return true;
//    }
//    // b가 진 경우
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

//// 다른 사람 풀이
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
//// 함수를 하나로 만들어서 현재 플레이어를 표시해 줌
//pii DFS(vvi& board, Player p1, int x1, int y1, int x2, int y2) { // { winner, cnt } in current state
//    Player p2 = p1 == A ? B : A;
//    pii ret{ p2, 0 };
//    // 현재 서있는 곳에 발판이 있는지 체크
//    if (board[x1][y1]) for (int d = 0; d < 4; d++) {
//        // 1012에 나온 char에 '1'을 빼줌 - int로는 0 -1 0 1 이 됨
//        // 이동
//        const int nx = x1 + "1012"[d] - '1';
//        const int ny = y1 + "2101"[d] - '1';
//        // 범위 벗어났는지, 갈 곳에 발판이 없는지 체크
//        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) continue;
//        // 현재 서 있는 곳의 발판을 없앰
//        board[x1][y1] = 0;
//        // 위치를 서로 바꿔서 보냄
//        auto [win, cnt] = DFS(board, p2, x2, y2, nx, ny);
//        // 발판 다시 만듦
//        board[x1][y1] = 1;
//        
//        // 내가 이긴 경우
//        if (win == p1) {
//            // ret.first는 처음엔 상대, ret.first == p1 - 내가 이길 경우가 하나보다 많을 때 - 이기는 노드들 중 최솟값을 고름
//            if (ret.first == p1) ret.second = min(ret.second, cnt + 1);
//            // (상대가 진 적) 내가 이길 경우가 하나라도 있으면 ret.firs가 내가 됨 - 이긴 경우의 노드를 바로 골라서 cnt를 사용
//            else ret = { win, cnt + 1 };
//        }
//        // 상대가 이긴 경우, ret.first가 상대인 경우 - 내가 이길 경우가 아직 없을 때만 - 다음 노드들 중 최댓값
//        else if (ret.first == p2) ret.second = max(ret.second, cnt + 1);
//    }
//    // pair를 써서 이긴 플레이어, cnt를 한 번에 반환함
//    return ret;
//}
//
//int solution(vvi board, vi aloc, vi bloc) {
//    const int ax = aloc[0], ay = aloc[1];
//    const int bx = bloc[0], by = bloc[1];
//    return DFS(board, A, ax, ay, bx, by).second;
//}