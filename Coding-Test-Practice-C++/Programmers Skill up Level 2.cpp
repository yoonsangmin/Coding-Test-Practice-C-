//// 1�� ���� - �� ǰ
//// ���� ���͸� 1, ���� �̵� - ���ݱ��� �� �Ÿ� ��ŭ
//// ������ Ǯ���� ��������
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

//// 2�� ���� - Ʋ��
//// ȿ�� ���� Ǯ���� �ߴµ� �Ӹ��� �����ϱ� �������
//// ȿ���� ���� ���������� �ϴ� ���� �°� ������ Ǯ���
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


//// 2ȸ��
//// 1�� ����
//// ���� ū ����
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

//// �ش� ������� 1�� ������ ������ ����� �� ����, ���� ���� �˰���
//// https://velog.io/@springkim/C-1%EB%B9%84%ED%8A%B8%EC%88%98-%EC%84%B8%EA%B8%B0
//// �����ϸ� ������
//// 1 0 1 1 0 1 0 0
////  01  10  01  00
//// ��Ʈ ���� ������ �� �� �� ���ϸ� 1�� ������ ����
//// 01 10 01 00
////  0011  0001
//// ������ 2��Ʈ �� ��� ���� - �ݺ� - ���� ������ 1�� ������ ���ϴ� ��
////  0011  0001
////        0100
//// �������� 10����ȭ �ؼ� ���Ѵٰ� �ߴµ� 10������� �������� �ʰ�
//// ���� ��Ʈ�� �� ������ 1�� ������ �����ϰ� �װ��� ��� ���Ѵٰ� �����ϸ� ��
//int BitCnt4(int v) {
//	v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
//	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
//	v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
//	v = (v & 0x00ff00ff) + ((v >> 8) & 0x00ff00ff);
//	v = (v & 0x0000ffff) + ((v >> 16) & 0x0000ffff);
//	return v;
//}

// �ٸ� ��� Ǯ��
//// bitset�̶�� ������� ��Ʈ ���� ����� �� ����
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

//// ��Ư�� Ǯ��
//// ó�� 1�� ������ ������ 1�� ���ӵ� ������ ��
//// 1�� ������ �������� �� 0���� ����� �� �ڸ��� ���� 1�� �߰��� 00001100 -> 00010000
//// 1�� ���ӵǾ� �ִ� ������ŭ �ؿ� 1�� �߰���
//// �ϳ��� �÷����鼭 ������ ���� ���� �ƴ϶� �ӵ��� �ſ� ���� ��
//// ��Ʈ |= or ������ ��Ʈ�� �����ִ� �������� ����� �� ����
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
//            // ó�� 1�� �����ϴ� ���� üũ��
//            if (!flag) {
//                low = count;
//                flag = true;
//            }
//        }
//        else {
//            // ���ӵ� 1�� ������ ������ Ż���� - count�� ���ӵ� ������ 1�� �ִ� ���� ����Ŵ
//            if (flag) {
//                break;
//            }
//        }
//
//        n >>= 1;
//        ++count;
//    }
//
//    // ���ӵ� 1�� ������ �ڸ����� ��� 0�� ä���� ���� �ڸ����� ����
//    n <<= count;
//    // �� �ڸ��� ���� 1�� �߰���
//    n |= 1 << count;
//
//    // 1�� ���ӵǾ� �ִ� ������ŭ 1�� �����ʿ������� ä��
//    for (int i = 0; i < count - low - 1; ++i) {
//        n |= 1 << i;
//    }
//
//    return n;
//}

//// 2�� ����
//// ���ڿ� ������ �ִ밪 �ּڰ� ���ϱ�
//// include <limits>
//// INT_MAX; �̷������� ��
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

//// �ٸ� ��� Ǯ��
//// ��Ư�� Ǯ��
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
//    // stringstream ���� �ʰ� ���� string�� ���ڷ� ��ȯ
//    for (int i = 0; i < len; i++) {
//        // ���� ���ڰ� ������ ���ݱ��� ������ temp�� arr�迭�� ����
//        // �÷��׵� �ʱ�ȭ��Ŵ
//        if (s[i] == ' ') {
//            temp = temp / 10;
//            arr.push_back(temp);
//            temp = 0;
//            minus = false;
//            cnt = 1;
//            continue;
//        }
//        // ���ڿ��� -�� �����ϸ� flag�� üũ����
//        if (s[i] == '-') {
//            minus = true;
//            continue;
//        }
//        // �ش� ���ڰ� -�� �����ߴٸ� ����
//        if (minus == true) {
//            k = s[i] - '0';
//            temp = (temp - k) * 10;
//        }
//        // �ش� ���ڰ� -�� �������� �ʾҴٸ� ������
//        else {
//            k = s[i] - '0';
//            temp = (temp + k) * 10;
//        }
//        // ���ڿ� �������̶�� �ٷ� �迭�� �־���
//        if (i == len - 1) {
//            temp = temp / 10;
//            arr.push_back(temp);
//        }
//        //cnt = cnt*10;        
//    }
//    // �ִ�, �ּڰ� ���ϱ�
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

//// �� ���� Ǯ��
//// stringstream�� int�� ������ �˾Ƽ� int�� ��ȯ����
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