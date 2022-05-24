#include <string>
#include <vector>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool amove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int acnt, int bcnt, int& answer)
{
    // ��� �� �� ���� �̱� ���� �ִ� ���� - ���� ��� ���� �� ���� ����
    // ��� �� �̱� �� �ִ� �������� ������ ������ ���� ��

    // ���� ��忡�� �ٽ� �������� - ���� ���� ���� ��� �ۿ� �� - ��밡 �� �� ��� - ���� �̱�
    // ���� ������ ���ų� �� ���� ������ ���� ��    
    // ��밡 �̱� �� �ִ� ��찡 �ִٸ� ��
    // ��� ��� ��밡 ���� ��� �̱�


    // ���� üũ - ���� ���ִ� ���� ������ ���������� ���ٰ� �˷���
    if (board[aloc[0]][aloc[1]] == 0)
        return false;

    for (int i = 0; i < 4; i++)
    {
        vector<int> nextloc = { aloc[0] + dx[i], aloc[1] + dy[i] };
        // ������ �� �ִ��� üũ
        // ���� ��
        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
            continue;
        else if (board[nextloc[0]][nextloc[1]] == 1)
        {
            board[nextloc[0]][nextloc[1]] = 0;
            // bmove ȣ��
            bmove(board, nextloc, bloc, acnt + 1, bcnt, answer);

            board[nextloc[0]][nextloc[1]] = 1;
        }
    }

    // ���� ��� ������ �̵��ϵ� ���� ��� ��밡 �¸�
    return true;
}

bool bmove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int acnt, int bcnt, int& answer)
{

    // ���� üũ - ���� ���ִ� ���� ������ ���������� ���ٰ� �˷���
    if (board[bloc[0]][bloc[1]] == 0)
        return false;

    for (int i = 0; i < 4; i++)
    {
        vector<int> nextloc = { bloc[0] + dx[i], bloc[1] + dy[i] };
        // ������ �� �ִ��� üũ
        // ���� ��
        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
            continue;
        else if (board[nextloc[0]][nextloc[1]] == 1)
        {
            board[nextloc[0]][nextloc[1]] = 0;
            // amove ȣ��
            amove(board, aloc, nextloc, acnt, bcnt + 1, answer);

            board[nextloc[0]][nextloc[1]] = 1;
        }
    }

    // ������ �� �ִ� ���� ���� �� - �й�(���� ���� �ʿ�)
    return true;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;

    amove(board, aloc, bloc, 0, 0, answer);

    return answer;
}