//// �� Ǯ��
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//// ���� ������ �Ⱦ����� �ʹ� ���� �Ű� ������ ������
//// ���� solution �Լ��ȿ� �Լ��� �����ϰ� �������� ���� ķ���ϴ� �͵� ������ ����
//void dfs(vector<string>& grid, vector<int>& answer, set<pair<vector<int>, vector<int>>>& s, vector<int> pos, vector<int> dir, int n)
//{
//    // ���������� ���ƿԴ��� üũ
//    if (s.find({ pos, dir }) != s.end())
//    {
//        answer.push_back(n);
//        return;
//    }
//
//    // �湮 ���
//    s.insert({ pos, dir });
//
//    // pos �������� �̵�
//    pos[0] += dir[0];
//    if (pos[0] < 0) pos[0] = grid.size() - 1;
//    else if (pos[0] == grid.size()) pos[0] = 0;
//    pos[1] += dir[1];
//    if (pos[1] < 0) pos[1] = grid[0].size() - 1;
//    else if (pos[1] == grid[0].size()) pos[1] = 0;
//
//    // ���� ���� ���ϱ�
//    switch (grid[pos[0]][pos[1]])
//    {
//    case 'L':
//        dir = { -dir[1], dir[0] };
//        break;
//    case 'R':
//        dir = { dir[1], -dir[0] };
//        break;
//    default:
//        break;
//    }
//
//    // �������� ����
//    dfs(grid, answer, s, pos, dir, n + 1);
//}
//
//vector<int> solution(vector<string> grid) {
//    vector<int> answer;
//    vector<vector<int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//    set<pair<vector<int>, vector<int>>> s;
//
//    for (int x = 0; x < grid.size(); x++)
//        for (int y = 0; y < grid[0].size(); y++)
//            for (int i = 0; i < dirs.size(); i++)
//                if (s.find({ {x, y}, dirs[i] }) == s.end())
//                    dfs(grid, answer, s, { x, y }, dirs[i], 0);
//            
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <set>
//
//using namespace std;
//
//vector<int> solution(vector<string> grid) {
//    vector<int> answer;
//    vector<vector<int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//    set<pair<vector<int>, vector<int>>> s;
//
//    // �Լ� ���ο� �Լ� ��ü�� ����
//    function<void(vector<int> pos, vector<int> dir, int n)> dfs = [&](vector<int> pos, vector<int> dir, int n)
//    {
//        // ���������� ���ƿԴ��� üũ
//        if (s.find({ pos, dir }) != s.end())
//        {
//            answer.push_back(n);
//            return;
//        }
//
//        // �湮 ���
//        s.insert({ pos, dir });
//
//        // pos �������� �̵�
//        pos[0] += dir[0];
//        if (pos[0] < 0) pos[0] = grid.size() - 1;
//        else if (pos[0] == grid.size()) pos[0] = 0;
//        pos[1] += dir[1];
//        if (pos[1] < 0) pos[1] = grid[0].size() - 1;
//        else if (pos[1] == grid[0].size()) pos[1] = 0;
//
//        // ���� ���� ���ϱ�
//        switch (grid[pos[0]][pos[1]])
//        {
//        case 'L':
//            dir = { -dir[1], dir[0] };
//            break;
//        case 'R':
//            dir = { dir[1], -dir[0] };
//            break;
//        default:
//            break;
//        }
//
//        // �������� ����
//        dfs(pos, dir, n + 1);
//    };
//
//	for (int x = 0; x < grid.size(); x++)
//		for (int y = 0; y < grid[0].size(); y++)
//			for (int i = 0; i < dirs.size(); i++)
//				if (s.find({ {x, y}, dirs[i] }) == s.end())
//					dfs({ x, y }, dirs[i], 0);
//
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}

//// ���� �� �ٽ� ǰ
//#include <algorithm>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(vector<string> grid) {
//    vector<int> answer;
//    // ���ͷ� �����ؼ� ���̸� �ʹ� ũ�� �ʰ� ��Ÿ�ӿ��� ������ ��
//    vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));
//    int dirs[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
//
//    for (int i = 0; i < grid.size(); i++)
//        for (int j = 0; j < grid[0].size(); j++)
//            for (int k = 0; k < 4; k++)
//                if (!visited[i][j][k])
//                {
//                    int row = i, col = j, dir = k;
//                    int cnt = 0;
//                    while (!visited[row][col][dir])
//                    {
//                        cnt++;
//                        visited[row][col][dir] = true;
//                        if (grid[row][col] == 'L')
//                            // 4�� ���ϰ� ��ⷯ ������ �ϸ� ���� 0�� ��츦 üũ���� �ʾƵ� ��
//                            // dir = dir - 1 < 0 ? 3 : dir - 1;
//                            dir = (4 + dir - 1) % 4;
//                        else if (grid[row][col] == 'R')
//                            dir = (dir + 1) % 4;
//
//                        row = (grid.size() + row + dirs[dir][0]) % grid.size();
//                        col = (grid[0].size() + col + dirs[dir][1]) % grid[0].size();
//                    }
//                    answer.push_back(cnt);
//                }
//    
//    sort(answer.begin(), answer.end());
//
//    return answer;
//}
//
//int main()
//{
//    solution({ "S" });
//
//    return 0;
//}

//// �ٸ� ��� Ǯ��
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <tuple>
//using namespace std;
//
//int row, col;
//tuple<int, int, int> move_rotate(int r, int c, int d, vector<vector<char>>& grid_map) {
//    char pos = grid_map[r][c];
//    // 0 -> left, 1-> up, 2 -> right, 3 - > down
//    // R -> ++;
//    // L -> --;
//    int dx[4] = { -1,0,1,0 };
//    int dy[4] = { 0,1,0,-1 };
//
//    if (pos == 'R')  d = (d + 1) % 4;
//    else if (pos == 'L')   d = (d + 3) % 4;
//
//    r = r + dy[d];
//    c = c + dx[d];
//
//    if (r >= row) r = 0;
//    if (r < 0)   r = row - 1;
//
//    if (c >= col) c = 0;
//    if (c < 0)   c = col - 1;
//
//    return make_tuple(r, c, d);
//}
//
//
//vector<int> solution(vector<string> grid) {
//    vector<int> answer;
//
//    row = grid.size();
//    col = grid[0].size();
//
//    vector<vector<char>> grid_map(row, vector<char>(col, 0));
//
//    for (int r = 0; r < row; ++r) {
//        for (int c = 0; c < col; ++c)
//            grid_map[r][c] = grid[r][c];
//    }
//
//    // �湮 üũ�� �̸� ������ �迭�� üũ��
//    bool isVisited[500][500][4] = { false, };
//
//    for (int r = 0; r < row; ++r)
//        for (int c = 0; c < col; ++c)
//            for (int d = 0; d < 4; ++d) {
//                if (isVisited[r][c][d] == false) {
//                    int start_r = r;
//                    int start_c = c;
//                    int start_d = d;
//                    int cnt = 0;
//                    // dfs�� ��ͷ� �� �ʿ䰡 ���� while������ �湮�� ������ ���� ������ �ݺ��ϸ� ��
//                    while (!isVisited[r][c][d]) {
//                        isVisited[r][c][d] = true;
//                        cnt++;
//                        // �̵�
//                        tuple<int, int, int> temp = move_rotate(r, c, d, grid_map);
//                        r = get<0>(temp);
//                        c = get<1>(temp);
//                        d = get<2>(temp);
//                    }
//                    if (start_r == r && start_c == c && start_d == d) answer.push_back(cnt);
//                }
//            }
//    sort(answer.begin(), answer.end());
//    return answer;
//}

//// ���� ª�� Ǯ��
//#include <algorithm>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//bool is_visit[500][500][4];
//
//vector<int> solution(vector<string> grid) {
//    int dir[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
//    vector<int> answer;
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < grid.size(); j++)
//            for (int k = 0; k < grid[0].size(); k++)
//                if (is_visit[j][k][i] == false)
//                {
//                    int r = j, c = k, d = i, l = 1;
//                    is_visit[j][k][i] = true;
//                    while (1)
//                    {
//                        if (grid[r][c] == 'L') d = (d + 1) % 4;
//                        else if (grid[r][c] == 'R') d = (4 + d - 1) % 4;
//                        r = (grid.size() + r + dir[d][0]) % grid.size();
//                        c = (grid[0].size() + c + dir[d][1]) % grid[0].size();
//                        if (is_visit[r][c][d]) break;
//                        is_visit[r][c][d] = true;
//                        l++;
//                    }
//                    answer.push_back(l);
//                }
//    sort(answer.begin(), answer.end());
//    return answer;
//}
