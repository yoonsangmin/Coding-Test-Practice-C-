//// 내 풀이
//// unique 사용 시 sort해야 하는 거 주의
//// erase할 때 범위를 정하지 않으면 한 값만 지워짐 - 주의
//// 스탠다드 라이브러리 사용법 정확하게 숙지하기
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> nums)
//{
//    int answer = nums.size() / 2;
//    
//    sort(nums.begin(), nums.end());
//    nums.erase(unique(nums.begin(), nums.end()), nums.end());
//
//    answer = min(answer, (int)nums.size());
//
//    return answer;
//}

//// 다른 사람 풀이
//// 중복을 허용하지 않는 set을 사용해서 바로 사이즈를 구할 수 있음
//// set을 바로 초기화할 수 있음
//#include <bits/stdc++.h>
//using namespace std;
//
//int solution(vector<int> nums) {
//    unordered_set<int> s(nums.begin(), nums.end());
//
//    return min(nums.size() / 2, s.size());
//}