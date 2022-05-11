//// �� Ǯ��
//#include <string>
//#include <vector>
//#include <map>
//#include <sstream>
//#include <cmath>
//
//using namespace std;
//
//vector<int> solution(vector<int> fees, vector<string> records) {
//    vector<int> answer;
//	map<int, int> parking;
//	map<int, int> time_sum;
//
//	stringstream ss;
//	string time_string;
//	int time_int;
//	int number;
//	string state;
//	
//	for (string record : records)
//	{
//		ss.clear();
//		ss.str(record);
//		
//		ss >> time_string;
//		ss >> number;
//		ss >> state;
//
//		time_int = stoi(time_string.substr(0, 2)) * 60;
//		time_int += stoi(time_string.substr(3, 2));
//
//		if (state == "IN")
//			parking[number] = time_int;
//		else
//		{
//			time_sum[number] += time_int - parking[number];
//			parking.erase(number);
//		}
//	}
//
//	for (pair car : parking)
//		time_sum[car.first] += (23 * 60 + 59) - car.second;
//
//	int fee;
//
//	for (pair car : time_sum)
//	{
//		fee = fees[1];
//			
//		if (car.second > fees[0])
//			fee += fees[3] * ceil(((float)(car.second - fees[0]) / fees[2]));
//
//		answer.push_back(fee);
//	}
//
//    return answer;
//}

//int main()
//{
//	solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
//
//	return 0;
//}

//// �ٸ� ��� Ǯ��
//// ����ϰ� �����ϰ� �� Ǯ����
//#include <bits/stdc++.h>
//using namespace std;
//
//// hh:mm���� ���ڿ��� �� ���� ���������� ��ȯ
//int conv(string& t) {
//    int h = (t[0] - 48) * 10 + t[1] - 48;
//    int m = (t[3] - 48) * 10 + t[4] - 48;
//    return h * 60 + m;
//}
//
//vector<int> solution(vector<int> fees, vector<string> records) {
//    // ���͸� �迭 �÷� ���� - 0���� 9999���� ��� �� ��ȣ�� ���� �迭�� �������
//    vector<int> vec[10000];
//    for (auto& record : records) {
//        // stringstream�� ���ο� ���������� �����ϸ� �ʱ�ȭ(clear)�� ���� �� ���൵ ��
//        stringstream ss(record);
//        string a, b, c;
//        // stringstream�� �� ���� ������ �� ����
//        ss >> a >> b >> c;
//        // ���Ϳ� ���ʴ�� ���� - ���� �ð� ���� �İ��� ���� üũ���� �ʾƵ� Ȧ�� ��°�� ���� �ð�, ¦�� ��°�� ���� �ð�
//        vec[stoi(b)].push_back(conv(a));
//    }
//
//    vector<int> ans;
//    for (int i = 0; i < 10000; ++i) if (!vec[i].empty()) {  // �� ��ȣ�� ������ ��
//        // ����� Ȧ���� ��� - ���� �ð��� ���ٴ� �� - ���� �ð��� �߰��� ��
//        if (vec[i].size() & 1) vec[i].push_back(23 * 60 + 59);
//
//        int sum = 0;
//        // �ش� ������ ���ؼ� �� �ð��̶� ���� �ð��� ¦ ��� ���ָ鼭 ���� �ð��� ����
//        for (int j = 1; j < vec[i].size(); j += 2) sum += vec[i][j] - vec[i][j - 1];
//
//        // �⺻ ���
//        int val = fees[1];
//        // �⺻ �ð� �ʰ� ��
//        // ceil�� ���� �ʰ� ������ �� �� �ø��ϴ� ��
//        // ������ ���� ���ؼ� ������ ���� 1 Ŀ��(������ �Ҽ����� ������ ������ �ø��� �� ȿ���� ����)
//        // ��, ������ ������ ��� ���� �������� 1 Ŀ���� ������ ������ �� ���� 1�� ���� ���� ������ ���� �Ҽ����� �ǰ� �ø��� �Ǳ� ������ ���� ���� ��
//        if (sum > fees[0]) val += (sum - fees[0] + fees[2] - 1) / fees[2] * fees[3];
//
//        ans.push_back(val);
//    }
//
//    return ans;
//}