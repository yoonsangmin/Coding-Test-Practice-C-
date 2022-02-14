#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2)
{
    return s1.length() > s2.length();
}


bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s;

    sort(phone_book.begin(), phone_book.end(), cmp);

    for (int i = 0; i < phone_book.size(); i++)
    {
        if (s.find(phone_book[i]) != s.end())
        {
            return false;
        }

        for (int j = 0; j < phone_book[i].size(); j++)
        {
            s.insert(phone_book[i].substr(0, j + 1));
        }
    }

    
    return answer;
}