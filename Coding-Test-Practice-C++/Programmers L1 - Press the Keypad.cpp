//// ���� �ٽ� Ǯ���

//// �� Ǯ��
//// ��û �������ϰ� ������ Ǭ ������ ����
//// ���� ó���� �ʹ� ����
//// ���� ��� �� ���� ��
//// �׷��� �ٸ� ��� Ǯ�� ���� ������ Ǯ�̷� ������ ������ �ƴϾ��� �� ����
//// �ϴ� ����ϰ� �� Ǯ �� ������ ������� ���� ������ Ǯ��� �͵� ���ƺ���
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(vector<int> numbers, string hand) {
//    string answer = "";
//    int left = 10, right = 12;
//    
//    for (int number : numbers)
//    {
//        if (number % 3 == 1)
//        {
//            answer.push_back('L');
//            left = number;
//        }
//        else if (number % 3 == 0 && number != 0)
//        {
//            answer.push_back('R');
//            right = number;
//        }
//        else
//        {
//            int cur_left = left / 3, cur_right = right % 3 == 0 ? (right / 3) - 1 : right / 3;
//
//            if (left == 0)  cur_left = 3;
//            if (right == 0)  cur_right = 3;
//
//            int des = number == 0 ? 3 : number / 3;
//            int dis_left = abs(des - cur_left), dis_right = abs(des - cur_right);
//
//            if (left % 3 == 1)
//            {
//                dis_left++;
//            }
//
//            if (right % 3 == 0 && right != 0)
//            {
//                dis_right++;
//            }
//
//            if (dis_left == dis_right)
//            {
//                if (hand == "left")
//                {
//                    answer.push_back('L');
//                    left = number;
//                }
//                else
//                {
//                    answer.push_back('R');
//                    right = number;
//                }
//            }
//            else if (dis_left < dis_right)
//            {
//                answer.push_back('L');
//                left = number;
//            }
//            else
//            {
//                answer.push_back('R');
//                right = number;
//            }
//        }
//    }
//
//    return answer;
//}

//// �ٸ� ��� Ǯ��
//// ��ǥ ����ϰ� ǰ
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int nx[12] = {  /*0*/ 1,
//                0, 1, 2,
//                0, 1 ,2,
//                0, 1 ,2,
//    /*��*/ 0,
//    /*#*/ 2 };
//
//int ny[12] = {  /*0*/ 3,
//                0, 0, 0,
//                1, 1 ,1,
//                2, 2 ,2,
//    /*��*/ 3,
//    /*#*/ 3 };
//
//int lx, ly, rx, ry = 0;
//
//
//string addAnswer(string next, int arr)
//{
//    if (next == "L")
//    {
//        lx = nx[arr];
//        ly = ny[arr];
//    }
//    else
//    {
//        rx = nx[arr];
//        ry = ny[arr];
//    }
//
//    return next;
//}
//
//string solution(vector<int> numbers, string hand)
//{
//    string answer = "";
//    addAnswer("L", 10);
//    addAnswer("R", 11);
//
//    for (auto i : numbers)
//    {
//        if (i == 1 || i == 4 || i == 7)
//            answer += addAnswer("L", i);
//        else if (i == 3 || i == 6 || i == 9)
//            answer += addAnswer("R", i);
//        else
//        {
//            int leftGap = abs(nx[i] - lx) + abs(ny[i] - ly);
//            int rightGap = abs(nx[i] - rx) + abs(ny[i] - ry);
//
//            if (leftGap < rightGap)
//                answer += addAnswer("L", i);
//            else if (leftGap > rightGap)
//                answer += addAnswer("R", i);
//            else
//            {
//                if (hand == "left")
//                    answer += addAnswer("L", i);
//                else
//                    answer += addAnswer("R", i);
//            }
//        }
//    }
//
//    return answer;
//}

//// �� �ٸ� ��� Ǯ��
//// ���Ϳ� ��ǥ�� ������ �־���, �ٸ� ������� �־�� �� �� ����
//#include <iostream>
//#include <map>
//#include <vector>
//#include <algorithm>
//#include <string.h>
//#include <sstream>
//#include <set>
//#include <utility>
//
//using namespace std;
//
//vector<pair<int, int>> m;
//
//string solution(vector<int> numbers, string hand) {
//    string answer = "";
//    int cur_L, cur_R;
//    m.push_back(make_pair(3, 1));
//    m.push_back(make_pair(0, 0));
//    m.push_back(make_pair(0, 1));
//    m.push_back(make_pair(0, 2));
//    m.push_back(make_pair(1, 0));
//    m.push_back(make_pair(1, 1));
//    m.push_back(make_pair(1, 2));
//    m.push_back(make_pair(2, 0));
//    m.push_back(make_pair(2, 1));
//    m.push_back(make_pair(2, 2));
//    m.push_back(make_pair(3, 0)); //*
//    m.push_back(make_pair(3, 2)); //#
//    cur_L = 10;
//    cur_R = 11;
//    for (int i = 0; i < numbers.size(); i++) {
//        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
//            cur_L = numbers[i];
//            answer.push_back('L');
//        }
//        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
//            cur_R = numbers[i];
//            answer.push_back('R');
//        }
//        else {
//            if (abs(m[cur_L].first - m[numbers[i]].first) + abs(m[cur_L].second - m[numbers[i]].second) < abs(m[cur_R].first - m[numbers[i]].first) + abs(m[cur_R].second - m[numbers[i]].second)) {
//                cur_L = numbers[i];
//                answer.push_back('L');
//            }
//            else if (abs(m[cur_L].first - m[numbers[i]].first) + abs(m[cur_L].second - m[numbers[i]].second) > abs(m[cur_R].first - m[numbers[i]].first) + abs(m[cur_R].second - m[numbers[i]].second)) {
//                cur_R = numbers[i];
//                answer.push_back('R');
//            }
//            else {
//                if (hand == "right") {
//                    cur_R = numbers[i];
//                    answer.push_back('R');
//                }
//                else if (hand == "left") {
//                    cur_L = numbers[i];
//                    answer.push_back('L');
//                }
//            }
//        }
//    }
//    return answer;
//}

//// ��Ư�� Ǯ�� �����ؾ� ��
//// Coord �� �ִ� �Ű� ���� int coord[] �� ������� ������ �� �ְ� ����� ����
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int Abs(int x) {
//    if (x < 0) return -x;
//    return x;
//}
//
//void Coord(int coord[], int num) {
//    coord[0] = (num - 1) / 3;
//    coord[1] = (num - 1) % 3;
//}
//
//int Dist(int thm[], int num) {
//    int coord[2];
//    Coord(coord, num);
//    return Abs(thm[0] - coord[0]) + Abs(thm[1] - coord[1]);
//}
//
//string Char(int l_thm[], int r_thm[], int num, string hand) {
//    if (num == 0) num = 11;
//    int subt = Dist(l_thm, num) - Dist(r_thm, num);
//    if ((num - 1) % 3 == 0) {
//        Coord(l_thm, num);
//        return "L";
//    }
//    if ((num - 1) % 3 == 2) {
//        Coord(r_thm, num);
//        return "R";
//    }
//    if (subt < 0) {
//        Coord(l_thm, num);
//        return "L";
//    }
//    if (subt > 0) {
//        Coord(r_thm, num);
//        return "R";
//    }
//    if (hand == "left") {
//        Coord(l_thm, num);
//        return "L";
//    }
//    if (hand == "right") {
//        Coord(r_thm, num);
//        return "R";
//    }
//}
//
//string solution(vector<int> numbers, string hand) {
//    string answer = "";
//    int l_thm[2] = { 3, 0 }, r_thm[2] = { 3, 2 };
//    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
//        answer += Char(l_thm, r_thm, *it, hand);
//    }
//    return answer;
//}

//// ���� ���� ����� Ǯ��
//#include <string>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//
//string solution(vector<int> numbers, string hand) {
//    string answer = "";
//
//    int curr_L = 10;
//    int curr_R = 12;
//    for (int i = 0; i < numbers.size(); i++) {
//        if (numbers[i] % 3 == 1) {
//            answer += "L";
//            curr_L = numbers[i];
//        }
//        else if (numbers[i] % 3 == 0 && numbers[i] != 0) {
//            answer += "R";
//            curr_R = numbers[i];
//        }
//        else {
//
//            // �̺κи� ���� �ٸ� ������ ����� ��
//            int tmp = numbers[i];
//            if (numbers[i] == 0) tmp = 11;
//
//            int dist_L, dist_R;
//
//            if (curr_L % 3 == 1) dist_L = abs(tmp - curr_L - 1) / 3 + 1;
//            else dist_L = abs(tmp - curr_L) / 3;
//
//            if (curr_R % 3 == 0) dist_R = abs(tmp - curr_R + 1) / 3 + 1;
//            else dist_R = abs(tmp - curr_R) / 3;
//
//            // �̺κ�
//
//            if (dist_L == dist_R) {
//                if (hand[0] == 'l') {
//                    answer += "L";
//                    curr_L = tmp;
//                }
//                else {
//                    answer += "R";
//                    curr_R = tmp;
//                }
//            }
//            else {
//                if (dist_L < dist_R) {
//                    answer += "L";
//                    curr_L = tmp;
//                }
//                else {
//                    answer += "R";
//                    curr_R = tmp;
//                }
//            }
//        }
//    }
//    return answer;
//}