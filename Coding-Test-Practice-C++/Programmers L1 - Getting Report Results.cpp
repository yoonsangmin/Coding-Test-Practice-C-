//// �� Ǯ��
//// �ڷ� ������ ����ؼ� �����ϰ� ǰ
//
//#include <string>
//#include <vector>
//#include <map>
//#include <set>
//#include <sstream>
//
//using namespace std;
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    vector<int> answer(id_list.size(), 0);
//    map<string, set<string>> results;
//    map<string, int> id_idx;
//
//    for (int i = 0; i < id_list.size(); i++)
//    {
//        id_idx[id_list[i]] = i;
//    }
//
//    for (string elem : report)
//    {
//        stringstream ss;
//
//        ss.str(elem);
//
//        string reporter, reported;
//        ss >> reporter;
//        ss >> reported;
//
//        results[reported].insert(reporter);
//    }
//
//    for (string id : id_list)
//    {
//        if (results[id].size() >= k)
//        {
//            for (string reporter : results[id])
//            {
//                answer[id_idx[reporter]]++;
//            }
//        }
//    }
//
//    return answer;
//}

// �ٸ� ����� Ǯ��
// c++ �����Ϸ� ������ ���� �ٸ� ���� �ִ� �� �˾����� ���� ó�� ������ �ٲ㺽
// pair�� [a, b] �̷��� ������ �� �ִ��� �˰� ��
// unique �Լ��� �̿��ϸ� �ߺ��� ���� ������ ���ϰ� ������ �� �ִٴ� ���� �˰� ��
// �ٸ� ����� �ڵ� ���� ���鼭 ���ο� ��ɵ��� ���� ����

//// gcc
//#include <bits/stdc++.h>

//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <sstream>
//// �Ʒ� ������ �� https://jaimemin.tistory.com/1521
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    // 1.
//    const int n = id_list.size();
//    // convolution, ȸ���̶�� ��
//    map<string, int> Conv;
//    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;
//
//    // 2.
//    vector<pair<int, int>> v;
//    sort(report.begin(), report.end());
//    // https://codingwell.tistory.com/26
//    // unique �Լ��� �ߺ��� ���ҵ��� �ڷ� �о���
//    // unique �Լ��� �ߺ��� ���ҵ��� ���ִ� �޺κ� ù ��° ������ �ּҸ� ��������
//    report.erase(unique(report.begin(), report.end()), report.end());
//    for (const auto& s : report) {
//        // stringstream �ʱ�ȭ�ÿ� ��Ʈ���� �־��ָ� in.str(s) �̷��� ������� �ʾƵ� �ٷ� ��� ����
//        stringstream in(s);
//        // ss �� �Է� �����ڸ� ������ �Ἥ �� ���� �Ҵ� ����
//        string a, b; in >> a >> b;
//        v.push_back({ Conv[a], Conv[b] });
//    }
//
//    // 3.
//    vector<int> cnt(n), ret(n);
//
//    // const auto& ���� const ����� & ���۷����� �������� �ʾƵ� �۵��� ��, const�� ������� �ʰ� �����ϴ� ������ �� ���� &�� ������ �����ϱ� ���� ����� �� ����
//    for (const auto& [a, b] : v) cnt[b]++;  // �ش� ������ ���ְ� ������ ��ȸ�ϴ� �κп� ���ĵ� ��
//    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
//    return ret;
//}