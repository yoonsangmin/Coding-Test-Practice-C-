//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int max_size = 0;
//
//        for (int i = 0; i < s.length(); i++)
//        {
//            unordered_map<char, bool> is_contained;
//
//            for (int j = i; j <= s.length(); j++)
//            {
//                if (j != s.length() && !is_contained[s[j]])
//                {
//                    is_contained[s[j]] = true;
//                }
//                else
//                {
//                    max_size = max(max_size, j - i);
//                    break;
//                }
//            }
//        }
//
//        return max_size;
//    }
//};