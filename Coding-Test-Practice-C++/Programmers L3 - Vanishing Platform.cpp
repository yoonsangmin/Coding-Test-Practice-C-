#include <string>
#include <vector>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool amove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int acnt, int bcnt, int& answer)
{
    // 모두 다 질 수도 이길 수도 있는 상태 - 졌을 경우 가장 긴 것을 선택
    // 모두 다 이길 수 있는 선택지가 있으면 무조건 골라야 함

    // 리프 노드에서 다시 생각하자 - 리프 노드는 지는 경우 밖에 모름 - 상대가 다 진 경우 - 내가 이김
    // 현재 발판이 없거나 갈 곳이 없으면 내가 짐    
    // 상대가 이길 수 있는 경우가 있다면 짐
    // 모든 경우 상대가 졌을 경우 이김


    // 발판 체크 - 현재 서있던 곳의 발판이 없어졌으면 졌다고 알려줌
    if (board[aloc[0]][aloc[1]] == 0)
        return false;

    for (int i = 0; i < 4; i++)
    {
        vector<int> nextloc = { aloc[0] + dx[i], aloc[1] + dy[i] };
        // 움직일 수 있는지 체크
        // 보드 밖
        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
            continue;
        else if (board[nextloc[0]][nextloc[1]] == 1)
        {
            board[nextloc[0]][nextloc[1]] = 0;
            // bmove 호출
            bmove(board, nextloc, bloc, acnt + 1, bcnt, answer);

            board[nextloc[0]][nextloc[1]] = 1;
        }
    }

    // 내가 어느 곳으로 이동하든 지는 경우 상대가 승리
    return true;
}

bool bmove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int acnt, int bcnt, int& answer)
{

    // 발판 체크 - 현재 서있던 곳의 발판이 없어졌으면 졌다고 알려줌
    if (board[bloc[0]][bloc[1]] == 0)
        return false;

    for (int i = 0; i < 4; i++)
    {
        vector<int> nextloc = { bloc[0] + dx[i], bloc[1] + dy[i] };
        // 움직일 수 있는지 체크
        // 보드 밖
        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
            continue;
        else if (board[nextloc[0]][nextloc[1]] == 1)
        {
            board[nextloc[0]][nextloc[1]] = 0;
            // amove 호출
            amove(board, aloc, nextloc, acnt, bcnt + 1, answer);

            board[nextloc[0]][nextloc[1]] = 1;
        }
    }

    // 움직일 수 있는 곳이 없을 때 - 패배(리턴 수정 필요)
    return true;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;

    amove(board, aloc, bloc, 0, 0, answer);

    return answer;
}