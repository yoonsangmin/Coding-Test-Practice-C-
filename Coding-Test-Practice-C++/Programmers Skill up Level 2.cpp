//// 1번 문제 - 못 품
//// 점프 배터리 1, 순간 이동 - 지금까지 온 거리 만큼
//// 옛날에 풀었던 문제였음
// #include <iostream>
//using namespace std;
//
//int solution(int n)
//{
//    int ans = 1;
//
//    while (1 < n)
//    {
//        if (n % 2 == 1)
//        {
//            ans++;
//        }
//
//        n >>= 1;
//    }
//
//    return ans;
//}

//// 2번 문제 - 틀림
//// 효율 좋게 풀려고 했는데 머리로 생각하기 힘들어짐
//// 효율이 조금 떨어지더라도 일단 논리에 맞게 빠르게 풀어보기
//#include <string>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//int rotate(int& rows, int& columns, vector<vector<int>>& matrix, const vector<int>& query)
//{
//    int min_elem = 10000;
//
//    int temp_up = 0;
//    int temp_down = 0;
//    // vertical
//    for (int i = 0; i <= query[2] - query[0]; i++)
//    {
//        swap(matrix[query[0] + i - 1][query[3] - 1], temp_down);
//        swap(matrix[query[2] - i - 1][query[1] - 1], temp_up);
//
//        min_elem = min(min_elem, min(temp_down, temp_up));
//    }
//
//    // horizontal
//	for (int i = 1; i <= query[3] - query[1]; i++)
//	{
//		swap(matrix[query[0] - 1][query[1] + i - 1], temp_up);
//		swap(matrix[query[2] - 1][query[3] - i - 1], temp_down);
//
//		min_elem = temp_down != 0 ? min(min_elem, temp_down) : min_elem;
//		min_elem = temp_up != 0 ? min(min_elem, temp_up) : min_elem;
//	}
//
//    return min_elem;
//}
//
//vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
//    vector<int> answer;
//    vector<vector<int>> matrix(rows, vector<int>(columns));
//
//    int number = 1;
//    for (int x = 0; x < rows; x++)
//        for (int y = 0; y < columns; y++)
//            matrix[x][y] = number++;
//
//    for (const vector<int> query : queries)
//        answer.push_back(rotate(rows, columns, matrix, query));
//
//    return answer;
//}
//
//int main()
//{
//    solution(3, 3, {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}} );
//
//    return 0;
//}


//// 2회차
//// 1번 문제
//// 다음 큰 숫자
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int pop_count(int n)
//{
//    int ret = 0;
//
//    while (n)
//    {
//        n = n & (n - 1);
//        ret++;
//    }
//
//    return ret;
//}
//
//int solution(int n) {
//    int answer = 0;
//    int one_count = pop_count(n);
//
//    for (int i = n + 1; ; i++)
//    {
//        if (one_count == pop_count(i))
//        {
//            answer = i;
//            break;
//        }
//    }
//
//    return answer;
//}

//#include <string>
//#include <vector>
//#include <stdio.h>
//
//using namespace std;
//
//int pop_count(int n)
//{
//    int ret = 0;
//
//    while (n)
//    {
//        n = n & (n - 1);
//        ret++;
//    }
//
//    return ret;
//}
//
//int solution(int n) {
//    int answer = 0;
//    // int one_count = pop_count(n);
//    int one_count = __builtin_popcount(n);
//
//    for (int i = n + 1; ; i++)
//    {
//        // if(one_count == pop_count(i))
//        if (one_count == __builtin_popcount(i))
//        {
//            answer = i;
//            break;
//        }
//    }
//
//    return answer;
//}

//// 해당 방법으로 1의 개수를 빠르게 계산할 수 있음, 분할 정복 알고리즘
//// https://velog.io/@springkim/C-1%EB%B9%84%ED%8A%B8%EC%88%98-%EC%84%B8%EA%B8%B0
//// 이해하면 간단함
//// 1 0 1 1 0 1 0 0
////  01  10  01  00
//// 비트 각각 나눠서 두 개 씩 더하면 1의 개수가 나옴
//// 01 10 01 00
////  0011  0001
//// 그음엔 2비트 씩 묶어서 더함 - 반복 - 각각 구간의 1의 개수를 더하는 것
////  0011  0001
////        0100
//// 문서에선 10진수화 해서 더한다고 했는데 10진수라고 생각하지 않고
//// 나눈 비트를 각 구간의 1의 개수로 생각하고 그것을 모두 더한다고 생각하면 됨
//int BitCnt4(int v) {
//	v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
//	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
//	v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
//	v = (v & 0x00ff00ff) + ((v >> 8) & 0x00ff00ff);
//	v = (v & 0x0000ffff) + ((v >> 16) & 0x0000ffff);
//	return v;
//}

// 다른 사람 풀이
//// bitset이라는 방법으로 비트 수를 계산할 수 있음
//#include <bitset>
//
//using namespace std;
//
//int solution(int n) {
//    int num = bitset<20>(n).count();
//
//    while (bitset<20>(++n).count() != num);
//    return n;
//}

//// 독특한 풀이
//// 처음 1을 만나는 곳부터 1이 연속된 개수를 셈
//// 1이 끝나는 지점까지 다 0으로 만들고 한 자릿수 위에 1을 추가함 00001100 -> 00010000
//// 1이 연속되어 있던 개수만큼 밑에 1을 추가함
//// 하나씩 올려가면서 개수를 세는 것이 아니라 속도가 매우 빠를 듯
//// 비트 |= or 연산을 비트를 더해주는 느낌으로 사용할 수 있음
//#include<iostream>
//using namespace std;
//
//int nextBigNumber(int n)
//{
//    int low = 0, count = 0;
//    bool flag = false;
//
//    while (n != 0) {
//        if (n & 0x01) {
//            // 처음 1이 사작하는 곳을 체크함
//            if (!flag) {
//                low = count;
//                flag = true;
//            }
//        }
//        else {
//            // 연속된 1이 끝나는 곳에서 탈출함 - count는 연속된 마지막 1이 있는 곳을 가리킴
//            if (flag) {
//                break;
//            }
//        }
//
//        n >>= 1;
//        ++count;
//    }
//
//    // 연속된 1이 끝나는 자리까지 모두 0을 채워서 원래 자릿수로 만듦
//    n <<= count;
//    // 한 자릿수 위에 1을 추가함
//    n |= 1 << count;
//
//    // 1이 연속되어 있던 개수만큼 1을 오른쪽에서부터 채움
//    for (int i = 0; i < count - low - 1; ++i) {
//        n |= 1 << i;
//    }
//
//    return n;
//}

//// 2번 문제
//// 문자열 나눠서 최대값 최솟값 구하기
//// include <limits>
//// INT_MAX; 이런식으로 씀
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <sstream>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//    vector<int> nums;
//
//    stringstream ss(s);
//    string temp;
//    while (ss >> temp)
//        nums.push_back(stoi(temp));
//
//    answer = to_string(*min_element(nums.begin(), nums.end())) + " " + to_string(*max_element(nums.begin(), nums.end()));
//
//    return answer;
//}

//// 다른 사람 풀이
//// 독특한 풀이
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//    int len = s.length();
//    vector <int> arr;
//    int cnt = 1;
//    int temp = 0;
//    int k;
//    bool minus = false;
//
//    // stringstream 쓰지 않고 직접 string을 숫자로 변환
//    for (int i = 0; i < len; i++) {
//        // 공백 문자가 들어오면 지금까지 저장한 temp를 arr배열에 넣음
//        // 플래그도 초기화시킴
//        if (s[i] == ' ') {
//            temp = temp / 10;
//            arr.push_back(temp);
//            temp = 0;
//            minus = false;
//            cnt = 1;
//            continue;
//        }
//        // 문자열이 -로 시작하면 flag를 체크해줌
//        if (s[i] == '-') {
//            minus = true;
//            continue;
//        }
//        // 해당 숫자가 -로 시작했다면 빼줌
//        if (minus == true) {
//            k = s[i] - '0';
//            temp = (temp - k) * 10;
//        }
//        // 해당 숫자가 -로 시작하지 않았다면 더해줌
//        else {
//            k = s[i] - '0';
//            temp = (temp + k) * 10;
//        }
//        // 문자열 마지막이라면 바로 배열에 넣어줌
//        if (i == len - 1) {
//            temp = temp / 10;
//            arr.push_back(temp);
//        }
//        //cnt = cnt*10;        
//    }
//    // 최댓값, 최솟값 구하기
//    int arr_len = arr.size();
//    int min = arr[0];
//    int max = arr[0];
//    for (int i = 0; i < arr_len; i++) {
//        if (arr[i] < min) {
//            min = arr[i];
//        }
//        else if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//    answer = to_string(min) + " " + to_string(max);
//    return answer;
//}

//// 내 옛날 풀이
//// stringstream을 int에 넣으면 알아서 int로 변환해줌
//#include <string>
//#include <vector>
//#include <sstream>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//
//    stringstream ss;
//
//    ss.str(s);
//
//    int temp;
//
//    ss >> temp;
//
//    int big = temp;
//    int small = temp;
//
//    while (ss >> temp)
//    {
//        if (big < temp)
//            big = temp;
//        else if (small > temp)
//            small = temp;
//    }
//
//    answer = to_string(small) + " " + to_string(big);
//
//    return answer;
//}