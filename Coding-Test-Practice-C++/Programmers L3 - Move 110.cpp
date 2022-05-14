//// 내 풀이
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> solution(vector<string> s) {
//	vector<string> answer;
//	string result, temp;
//	int cnt;
//	bool is_inserted;
//
//	for (string elem : s)
//	{
//		result.clear();
//		temp.clear();
//		cnt = 0;
//		is_inserted = false;
//
//		for (int i = 0; i < elem.size(); i++)
//		{
//			if (elem[i] == '1')
//			{
//				result += '1';
//				continue;
//			}
//				
//			if (result.size() > 1 && result[result.size() - 2] == '1' && result.back() == '1')
//			{
//				result.erase(result.end() - 2, result.end());
//				cnt++;
//			}
//			else
//				result += '0';
//		}
//
//		for (int j = 0; j < cnt; j++)
//			temp += "110";
//
//		for (int i = result.size() - 1; i >= 0 ; i--)
//		{
//			// 0을 만나면 0 뒤에 삽입
//			if (result[i] == '0')
//			{
//				if (i + 1 != result.size())
//					temp += result.substr(i + 1);
//				result = result.substr(0, i + 1) + temp;
//
//				is_inserted = true;
//				break;
//			}
//		}
//		if (!is_inserted)
//			result = temp + result;
//
//		answer.push_back(result);
//	}
//	
//	return answer;
//}
//
//int main()
//{
//	solution({ "1110", "100111100", "0111111010" });
//
//	return 0;
//}

//// 다른 사람 풀이
//// 전체적인 풀이는 비슷함
//#include <bits/stdc++.h>
//using namespace std;
//
//vector<string> solution(vector<string> s) {
//	vector<string> answer;
//
//	for (auto& k : s) {
//		string tmp = ""; int cnt = 0;
//		for (int i = 0; i < k.size(); i++) {
//			tmp += k[i];
//			// 체크하는 부분을 뒤로 빼니까 넣고 다시 체크하긴 하지만 좀 더 간결해짐 - 오히려 비교 연산이 없어서 큰 차이가 안 날 것 같음 - 놉, 생각보다 많이 느림
//			// 듣기로는 string 삽입 삭제가 느리다고 들었음, 불필요한 삽입 삭제가 생겨서 더 느린 듯
//			if ((int)tmp.size() >= 3 && tmp.substr((int)tmp.size() - 3) == "110") { cnt++; tmp.erase((int)tmp.size() - 3, 3); }
//		}
//		string t = ""; while (cnt--) t += "110";
//		int idx; bool ok = false;
//		for (int i = (int)tmp.size() - 1; i >= 0; i--) if (tmp[i] == '0') { idx = i; ok = true; break; }
//
//		// 0이 없으면 맨 앞에 추가함
//		if (!ok) answer.push_back(t + tmp);
//		// substr이 길이보다 큰 범위라도 잘 작동함 - 아마 empty 스트링이 반환되는 것 같음
//		else answer.push_back(tmp.substr(0, idx + 1) + t + tmp.substr(idx + 1));
//	}
//
//	return answer;
//}