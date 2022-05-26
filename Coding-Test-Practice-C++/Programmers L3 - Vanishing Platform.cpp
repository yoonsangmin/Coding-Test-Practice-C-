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