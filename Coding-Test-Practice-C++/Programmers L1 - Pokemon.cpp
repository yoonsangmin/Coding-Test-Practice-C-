//// �� Ǯ��
//// unique ��� �� sort�ؾ� �ϴ� �� ����
//// erase�� �� ������ ������ ������ �� ���� ������ - ����
//// ���Ĵٵ� ���̺귯�� ���� ��Ȯ�ϰ� �����ϱ�
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

//// �ٸ� ��� Ǯ��
//// �ߺ��� ������� �ʴ� set�� ����ؼ� �ٷ� ����� ���� �� ����
//// set�� �ٷ� �ʱ�ȭ�� �� ����
//#include <bits/stdc++.h>
//using namespace std;
//
//int solution(vector<int> nums) {
//    unordered_set<int> s(nums.begin(), nums.end());
//
//    return min(nums.size() / 2, s.size());
//}