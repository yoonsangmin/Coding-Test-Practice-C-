#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool amove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth);
bool bmove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth);

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool amove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth)
{
    // ���� üũ - ���� ���ִ� ���� ������ ���������� ���ٰ� �˷���
    if (board[aloc[0]][aloc[1]] == 0)
    {
        depth = cnt;
        cout << cnt << " a ���� ���� " << depth << endl << endl;
        return false;
    }
    // ������ ����
    else
        board[aloc[0]][aloc[1]] = 0;

    bool result = true;
    bool canmove = false;
    vector<int> childs;

    for (int i = 0; i < 4; i++)
    {
        vector<int> nextloc = { aloc[0] + dx[i], aloc[1] + dy[i] };
        // ������ �� �ִ��� üũ
        // ���� ��
        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
            continue;
        else if (board[nextloc[0]][nextloc[1]] == 1)
        {
            canmove = true;
            int child;

            // bmove ȣ��, ������ ��� ������ result = true, �� ���̶� �̰����� result = false;
            result &= !bmove(board, nextloc, bloc, cnt + 1, child);

            childs.push_back(child);
        }
    }

    // ���� �ٽ� ����
    board[aloc[0]][aloc[1]] = 1;

    // a�� ������ �� ���� ���
    if (!canmove)
    {
        depth = cnt;
        cout << cnt << " a �� ������ " << depth << endl << endl;
        return false;
    }
    // a�� �̱� ���
    else if (result)
    {
        depth = *min_element(childs.begin(), childs.end());
        cout << cnt << " a �̰�� ";
        for (int i = 0; i < childs.size(); i++)
        {
            cout << childs[i] << ", ";
        }
        cout << endl << endl;
        return true;
    }
    // a�� �� ���
    else
    {
        depth = *max_element(childs.begin(), childs.end());
        cout << cnt << " a ���� ";
        for (int i = 0; i < childs.size(); i++)
        {
            cout << childs[i] << ", ";
        }
        cout << endl << endl;
        return false;
    }
}

bool bmove(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, int cnt, int& depth)
{
    // ���� üũ - ���� ���ִ� ���� ������ ���������� ���ٰ� �˷���
    if (board[bloc[0]][bloc[1]] == 0)
    {
        depth = cnt;
        cout << cnt << " b ���� ���� " << depth << endl << endl;
        return false;
    }
    // ������ ����
    else
        board[bloc[0]][bloc[1]] = 0;

    bool result = true;
    bool canmove = false;
    vector<int> childs;

    for (int i = 0; i < 4; i++)
    {
        vector<int> nextloc = { bloc[0] + dx[i], bloc[1] + dy[i] };
        // ������ �� �ִ��� üũ
        // ���� ��
        if ((nextloc[0] + board.size()) / board.size() != 1 || (nextloc[1] + board[0].size()) / board[0].size() != 1)
            continue;
        else if (board[nextloc[0]][nextloc[1]] == 1)
        {
            canmove = true;
            int child; 

            // amove ȣ��, ������ ��� ������ result = true, �� ���̶� �̰����� result = false;
            amove(board, aloc, nextloc, cnt + 1, child);

            childs.push_back(child);
        }
    }

    // ���� �ٽ� ����
    board[bloc[0]][bloc[1]] = 1;

    // b�� ������ �� ���� ���
    if (!canmove)
    {
        depth = cnt;
        cout << cnt << " b �� ������ " << depth << endl << endl;
        return false;
    }
    // b�� �̱� ���
    else if (result)
    {
        depth = *min_element(childs.begin(), childs.end());
        cout << cnt << " b �̰�� ";
        for (int i = 0; i < childs.size(); i++)
        {
            cout << childs[i] << ", ";
        }
        cout << endl << endl;
        return true;
    }
    // b�� �� ���
    else
    {
        depth = *max_element(childs.begin(), childs.end());
        cout << cnt << " b ���� ";
        for (int i = 0; i < childs.size(); i++)
        {
            cout << childs[i] << ", ";
        }
        cout << endl << endl;
        return false;
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = 0;

    amove(board, aloc, bloc, 0, answer);

    return answer;
}

int main()
{
    cout << solution({ {1, 1, 1, 0},{1, 1, 0, 1},{1, 0, 1, 1},{0, 1, 1, 1} }, { 0, 0 }, { 3, 3 });

    // 8

    return 0;
}