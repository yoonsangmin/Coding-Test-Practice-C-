//// 내 풀이
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

//// 다른 사람 풀이
//// 깔끔하고 간결하게 잘 풀었음
//#include <bits/stdc++.h>
//using namespace std;
//
//// hh:mm꼴의 문자열을 분 단위 정수형으로 변환
//int conv(string& t) {
//    int h = (t[0] - 48) * 10 + t[1] - 48;
//    int m = (t[3] - 48) * 10 + t[4] - 48;
//    return h * 60 + m;
//}
//
//vector<int> solution(vector<int> fees, vector<string> records) {
//    // 백터를 배열 꼴로 만듦 - 0부터 9999까지 모든 차 번호에 대해 배열을 만들었음
//    vector<int> vec[10000];
//    for (auto& record : records) {
//        // stringstream을 내부에 지역변수로 선언하면 초기화(clear)를 굳이 안 해줘도 됨
//        stringstream ss(record);
//        string a, b, c;
//        // stringstream을 한 번에 대입할 수 있음
//        ss >> a >> b >> c;
//        // 벡터에 차례대로 넣음 - 들어온 시간 나간 식간을 굳이 체크하지 않아도 홀수 번째는 들어온 시간, 짝수 번째는 나간 시간
//        vec[stoi(b)].push_back(conv(a));
//    }
//
//    vector<int> ans;
//    for (int i = 0; i < 10000; ++i) if (!vec[i].empty()) {  // 차 번호가 존재할 때
//        // 사이즈가 홀수인 경우 - 나간 시간이 없다는 뜻 - 나간 시간을 추가해 줌
//        if (vec[i].size() & 1) vec[i].push_back(23 * 60 + 59);
//
//        int sum = 0;
//        // 해당 차량에 대해서 들어간 시간이랑 나간 시간을 짝 지어서 빼주면서 누적 시간을 구함
//        for (int j = 1; j < vec[i].size(); j += 2) sum += vec[i][j] - vec[i][j - 1];
//
//        // 기본 요금
//        int val = fees[1];
//        // 기본 시간 초과 시
//        // ceil을 쓰지 않고 나눗셈 할 때 올림하는 법
//        // 나누는 값을 더해서 나누면 값이 1 커짐(원래는 소숫점을 버리기 때문에 올림을 한 효과가 있음)
//        // 단, 나누어 떨어질 경우 값이 원래보다 1 커지기 때문에 나누기 전 값에 1을 빼면 원래 값보다 작은 소수값이 되고 올림이 되기 때문에 원래 값이 됨
//        if (sum > fees[0]) val += (sum - fees[0] + fees[2] - 1) / fees[2] * fees[3];
//
//        ans.push_back(val);
//    }
//
//    return ans;
//}