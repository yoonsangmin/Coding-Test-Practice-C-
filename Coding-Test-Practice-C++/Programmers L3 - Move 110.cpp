//// �� Ǯ��
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
//			// 0�� ������ 0 �ڿ� ����
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

//// �ٸ� ��� Ǯ��
//// ��ü���� Ǯ�̴� �����
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
//			// üũ�ϴ� �κ��� �ڷ� ���ϱ� �ְ� �ٽ� üũ�ϱ� ������ �� �� �������� - ������ �� ������ ��� ū ���̰� �� �� �� ���� - ��, �������� ���� ����
//			// ���δ� string ���� ������ �����ٰ� �����, ���ʿ��� ���� ������ ���ܼ� �� ���� ��
//			if ((int)tmp.size() >= 3 && tmp.substr((int)tmp.size() - 3) == "110") { cnt++; tmp.erase((int)tmp.size() - 3, 3); }
//		}
//		string t = ""; while (cnt--) t += "110";
//		int idx; bool ok = false;
//		for (int i = (int)tmp.size() - 1; i >= 0; i--) if (tmp[i] == '0') { idx = i; ok = true; break; }
//
//		// 0�� ������ �� �տ� �߰���
//		if (!ok) answer.push_back(t + tmp);
//		// substr�� ���̺��� ū ������ �� �۵��� - �Ƹ� empty ��Ʈ���� ��ȯ�Ǵ� �� ����
//		else answer.push_back(tmp.substr(0, idx + 1) + t + tmp.substr(idx + 1));
//	}
//
//	return answer;
//}