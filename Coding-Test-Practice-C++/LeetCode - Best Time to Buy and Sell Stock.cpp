//#include<vector>
//
//using namespace std;
//
//int maxProfit(vector<int>& prices) {
//
//    int max_diff = 0;
//    int min_value = INT_MAX;
//
//    for (int i = 0; i < prices.size(); ++i)
//    {
//        min_value = min(min_value, prices[i]);
//        max_diff = max(max_diff, prices[i] - min_value);
//    }
//
//    return max_diff;
//}