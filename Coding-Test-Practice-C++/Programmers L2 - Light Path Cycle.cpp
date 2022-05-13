//// 내 풀이
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//// 전역 변수를 안쓰려고 너무 많은 매개 변수가 들어왔음
//// 차라리 solution 함수안에 함수로 선언하고 변수들을 전부 캠쳐하는 것도 괜찮아 보임
//void dfs(vector<string>& grid, vector<int>& answer, set<pair<vector<int>, vector<int>>>& s, vector<int> pos, vector<int> dir, int n)
//{
//    // 시작점으로 돌아왔는지 체크
//    if (s.find({ pos, dir }) != s.end())
//    {
//        answer.push_back(n);
//        return;
//    }
//
//    // 방문 기록
//    s.insert({ pos, dir });
//
//    // pos 방향으로 이동
//    pos[0] += dir[0];
//    if (pos[0] < 0) pos[0] = grid.size() - 1;
//    else if (pos[0] == grid.size()) pos[0] = 0;
//    pos[1] += dir[1];
//    if (pos[1] < 0) pos[1] = grid[0].size() - 1;
//    else if (pos[1] == grid[0].size()) pos[1] = 0;
//
//    // 다음 방향 구하기
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
//    // 다음으로 보냄
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
//    // 함수 내부에 함수 객체로 선언
//    function<void(vector<int> pos, vector<int> dir, int n)> dfs = [&](vector<int> pos, vector<int> dir, int n)
//    {
//        // 시작점으로 돌아왔는지 체크
//        if (s.find({ pos, dir }) != s.end())
//        {
//            answer.push_back(n);
//            return;
//        }
//
//        // 방문 기록
//        s.insert({ pos, dir });
//
//        // pos 방향으로 이동
//        pos[0] += dir[0];
//        if (pos[0] < 0) pos[0] = grid.size() - 1;
//        else if (pos[0] == grid.size()) pos[0] = 0;
//        pos[1] += dir[1];
//        if (pos[1] < 0) pos[1] = grid[0].size() - 1;
//        else if (pos[1] == grid[0].size()) pos[1] = 0;
//
//        // 다음 방향 구하기
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
//        // 다음으로 보냄
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

//// 참고 후 다시 품
//#include <algorithm>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(vector<string> grid) {
//    vector<int> answer;
//    // 벡터로 선언해서 길이를 너무 크지 않게 런타임에서 세팅해 줌
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
//                            // 4를 더하고 모듈러 연산을 하면 굳이 0인 경우를 체크하지 않아도 됨
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

//// 다른 사람 풀이
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
//    // 방문 체크를 미리 선언한 배열에 체크함
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
//                    // dfs나 재귀로 할 필요가 없이 while문으로 방문한 지점이 나올 때까지 반복하면 됨
//                    while (!isVisited[r][c][d]) {
//                        isVisited[r][c][d] = true;
//                        cnt++;
//                        // 이동
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

//// 조금 짧은 풀이
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
