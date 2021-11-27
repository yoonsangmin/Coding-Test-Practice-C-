//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<algorithm>
//using namespace std;
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//    if (a.second == b.second) return a.first < b.first;
//
//    return a.second > b.second;
//}
//
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> nums_count;
//        vector<int> answer;
//
//        for (auto num : nums)
//        {
//            ++nums_count[num];
//        }
//
//        vector<pair<int, int>> nums_vec(nums_count.begin(), nums_count.end());
//
//        sort(nums_vec.begin(), nums_vec.end(), cmp);
//
//        for (int i = 0; i < k; i++)
//        {
//            answer.push_back(nums_vec[i].first);
//        }
//
//        return answer;
//    }
//};