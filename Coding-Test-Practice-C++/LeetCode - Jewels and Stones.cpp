//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int numJewelsInStones(string jewels, string stones) {
//        unordered_map<char, int> jewels_count;
//        int max_size = 0;
//
//        for (char jewel : jewels)
//        {
//            for (char stone : stones)
//            {
//                if (jewel == stone)
//                {
//                    jewels_count[jewel]++;
//                }
//            }
//        }
//
//        for (auto value : jewels_count)
//        {
//            max_size += value.second;
//        }
//
//        return max_size;
//    }
//};