//#include<iostream>
//#include<stack>
//#include<unordered_map>
//#include<unordered_set>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    string removeDuplicateLetters(string s) {
//        unordered_map<char, int> counter;
//        unordered_set<char> seen;
//        stack<char> letters;
//
//        for (char i = 'a'; i <= 'z'; i++)
//        {
//            counter[i] = count(s.begin(), s.end(), i);
//        }
//
//        for (auto letter : s)
//        {
//            counter[letter]--;
//
//            if (seen.find(letter) != seen.end())
//                continue;
//
//            while (!letters.empty() && letters.top() > letter && counter[letters.top()] > 0)
//            {
//                seen.erase(letters.top());
//                letters.pop();
//            }
//
//            letters.emplace(letter);
//            seen.emplace(letter);
//        }
//
//        string answer = "";
//
//        while(!letters.empty())
//        {
//            answer = letters.top() + answer;
//            letters.pop();
//        }
//
//        return answer;
//    }
//};
//
//
//int main()
//{
//    Solution s;
//
//    cout << s.removeDuplicateLetters("bcabc");
//
//    return 0;
//}