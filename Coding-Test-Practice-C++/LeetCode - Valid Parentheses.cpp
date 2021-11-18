//#include<string>
//#include<stack>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char> parenthese;
//        unordered_map<char, char> table = { {')', '('}, {'}', '{'}, {']', '['} };
//
//        for (auto letter : s)
//        {
//            if (table[letter] == table[' '])
//            {
//                parenthese.emplace(letter);
//                continue;
//            }
//
//            if(parenthese.empty() || parenthese.top() != table[letter])
//            {
//                return false;
//            }
//
//            parenthese.pop();
//        }
//
//        return parenthese.size() == 0;
//    }
//};