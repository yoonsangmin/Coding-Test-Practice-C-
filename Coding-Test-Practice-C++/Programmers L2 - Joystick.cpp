//#include <string>
//#include <vector>
//
//using namespace std;
//
//int shortest;
//
//// �� Ǯ��
//// bfs�� ��� ��� �� ã��
//void bfs(string& name, vector<bool> visited, vector<int> q, int num)
//{
//    int cur = q.front();
//    q.erase(q.begin());
//
//    visited[cur] = true;
//    bool is_last = true;
//
//    for (int i = 1; i < name.size(); i++)
//    {
//        int temp = cur + i;
//
//        if (temp >= name.size()) temp -= name.size();
//
//        if (!visited[temp])
//        {
//            q.push_back(temp);
//            bfs(name, visited, q, num + i);
//
//            q.pop_back();
//            is_last = false;
//            break;
//        }
//    }
//
//    if (is_last)
//    {
//        if (shortest > num)  shortest = num;
//
//        return;
//    }
//
//    for (int i = 1; i < name.size(); i++)
//    {
//        int temp = cur - i;
//
//        if (temp < 0) temp += name.size();
//
//        if (!visited[temp])
//        {
//            q.push_back(temp);
//            bfs(name, visited, q, num + i);
//
//            q.pop_back();
//            break;
//        }
//    }
//}
//
//int solution(string name) {
//    int answer = 0;
//
//    for (char letter : name)
//    {
//        int up = letter - 'A', down = 26 - up;
//        
//        if (up < down) answer += up;
//        else answer += down;
//    }
//
//    shortest = name.size();
//    vector<bool> visited(name.size(), true);
//
//    for (int i = 1; i < name.size(); i++)
//    {
//        if (name[i] != 'A') visited[i] = false;
//    }
//
//    bfs(name, visited, {0}, 0);
//
//    answer += shortest;
//
//    return answer;
//}
//
//int main()
//{
//    solution("JEROEN");
//
//    return 0;
//}

//// �ٸ� ��� Ǯ��, ������ �� �κ� �����ϴµ� ���� �ɸ�
//// ���ӵ� A�� ���� ������ ���� �Ǵ� ���������� �� ���� �ٽ� �ݴ�� ���� ���ӵ� A�� �ݴ� �κб��� �� �� �������� ���� �� ���� �� ���������� ���� �� ���� �� üũ
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
//
//int solution(string name) {
//    int answer = 0;
//    for (auto ch : name)
//        answer += LUT[ch - 'A'];
//    int len = name.length();
//    int left_right = len - 1;
//    for (int i = 0; i < len; ++i) {
//        int next_i = i + 1;
//        while (next_i < len && name[next_i] == 'A')
//            next_i++;
//        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
//    }
//    answer += left_right;
//    return answer;
//}