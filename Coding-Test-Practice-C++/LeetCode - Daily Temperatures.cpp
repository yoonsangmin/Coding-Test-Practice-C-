//#include<vector>
//#include<stack>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        vector<int> answer(temperatures.size(), 0);
//        stack<int> temps_indeces;
//
//        for (int i = 0; i < temperatures.size(); i++)
//        {
//            while (!temps_indeces.empty() && temperatures[temps_indeces.top()] < temperatures[i])
//            {
//                answer[temps_indeces.top()] = i - temps_indeces.top();
//                temps_indeces.pop();
//            }
//
//            temps_indeces.push(i);
//        }
//
//        return answer;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int> v;
//    s.dailyTemperatures(v);
//
//    return 0;
//}