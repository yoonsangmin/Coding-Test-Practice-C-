//// 내 풀이
//// 자료 구조를 사용해서 간단하게 품
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

// 다른 사람의 풀이
// c++ 컴파일러 버전에 따라 다른 점이 있는 건 알았지만 오늘 처음 버전을 바꿔봄
// pair를 [a, b] 이렇게 접근할 수 있는지 알게 됨
// unique 함수를 이용하면 중복된 것을 빠르고 편하게 제거할 수 있다는 것을 알게 됨
// 다른 사람들 코드 많이 보면서 새로운 기능들을 많이 배우기

//// gcc
//#include <bits/stdc++.h>

//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <sstream>
//// 아래 구문의 뜻 https://jaimemin.tistory.com/1521
//#define fastio cin.tie(0)->sync_with_stdio(0)
//using namespace std;
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    // 1.
//    const int n = id_list.size();
//    // convolution, 회선이라는 뜻
//    map<string, int> Conv;
//    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;
//
//    // 2.
//    vector<pair<int, int>> v;
//    sort(report.begin(), report.end());
//    // https://codingwell.tistory.com/26
//    // unique 함수는 중복된 원소들을 뒤로 밀어줌
//    // unique 함수는 중복된 원소들이 모여있는 뒷부분 첫 번째 원소의 주소를 리턴해줌
//    report.erase(unique(report.begin(), report.end()), report.end());
//    for (const auto& s : report) {
//        // stringstream 초기화시에 스트링을 넣어주면 in.str(s) 이렇게 사용하지 않아도 바로 사용 가능
//        stringstream in(s);
//        // ss 도 입력 연산자를 여려번 써서 한 번에 할당 가능
//        string a, b; in >> a >> b;
//        v.push_back({ Conv[a], Conv[b] });
//    }
//
//    // 3.
//    vector<int> cnt(n), ret(n);
//
//    // const auto& 에서 const 상수와 & 레퍼런스로 선언하지 않아도 작동은 함, const는 변경되지 않게 보장하는 역할인 것 같고 &는 빠르게 접근하기 위한 방법인 것 같음
//    for (const auto& [a, b] : v) cnt[b]++;  // 해당 라인을 없애고 위에서 순회하는 부분에 합쳐도 됨
//    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
//    return ret;
//}