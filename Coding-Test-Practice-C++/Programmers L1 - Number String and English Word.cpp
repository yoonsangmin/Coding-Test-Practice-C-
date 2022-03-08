//// �� Ǯ��
//// ���ڸ� ��� ���� ���ΰ�
//// ������ ù ���ڸ� ���� ���̽� ���� ������ ����� ���?
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(string s) {
//    string number_s = "";
//
//    for (int i = 0; i < s.length(); i++)
//    {
//        if ('0' <= s[i] && s[i] <= '9')
//        {
//            number_s += s[i];
//            continue;
//        }
//
//        switch (s[i])
//        {
//        case 'z':
//            number_s += '0';
//            i += 3;
//            break;
//        case 'o':
//            number_s += '1';
//            i += 2;
//            break;
//        case 't':
//            if (s.substr(i, 3) == "two")
//            {
//                number_s += '2';
//                i += 2;
//            }
//            else
//            {
//                number_s += '3';
//                i += 4;
//            }
//            break; 
//        case 'f':
//            if (s.substr(i, 4) == "four")
//            {
//                number_s += '4';
//                i += 3;
//            }
//            else
//            {
//                number_s += '5';
//                i += 3;
//            }
//            break;
//        case 's':
//            if (s.substr(i, 3) == "six")
//            {
//                number_s += '6';
//                i += 2;
//            }
//            else
//            {
//                number_s += '7';
//                i += 4;
//            }
//            break;
//        case 'e':
//            number_s += '8';
//            i += 4;
//            break;
//        case 'n':
//            number_s += '9';
//            i += 3;
//            break;
//        default:
//            break;
//        }
//    }
//
//    return stoi(number_s);
//}

//// �ٸ� ��� Ǯ��
//// ���� �����ϰ� ����� Ǯ��
// 
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string strs[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
//
//int solution(string s) {
//    int answer = 0;
//    for (int i = 0; i < s.size();) {
//        if (s[i] < '0' || s[i] > '9') {
//            for (int j = 0; j < 10; j++) {
//                if (i + strs[j].size() <= s.size()) {
//                    if (s.substr(i, strs[j].size()) == strs[j]) {
//                        answer = answer * 10 + j;
//                        i += strs[j].size();
//                        break;
//                    }
//                }
//            }
//        }
//        else {
//            answer = answer * 10 + (s[i] - '0');
//            i++;
//        }
//    }
//    return answer;
//}
// 
// 
//// ���� ǥ���� regular expression�� ����� ġȯ�� �ؼ� ���� Ǭ ����� ����
//
////#include <bits/stdc++.h>
//#include <string>
//#include <regex>
//using namespace std;
//
//int solution(string s) {
//    s = regex_replace(s, regex("zero"), "0");
//    s = regex_replace(s, regex("one"), "1");
//    s = regex_replace(s, regex("two"), "2");
//    s = regex_replace(s, regex("three"), "3");
//    s = regex_replace(s, regex("four"), "4");
//    s = regex_replace(s, regex("five"), "5");
//    s = regex_replace(s, regex("six"), "6");
//    s = regex_replace(s, regex("seven"), "7");
//    s = regex_replace(s, regex("eight"), "8");
//    s = regex_replace(s, regex("nine"), "9");
//    return stoi(s);
//}

//// boost�ε� ����ϰ� Ǯ �� ����
//#include <string>
//#include <boost/algorithm/string/replace.hpp>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int solution(string s) {
//    int answer = 0;
//    boost::replace_all(s, "zero", "0");
//    boost::replace_all(s, "one", "1");
//    boost::replace_all(s, "two", "2");
//    boost::replace_all(s, "three", "3");
//    boost::replace_all(s, "four", "4");
//    boost::replace_all(s, "five", "5");
//    boost::replace_all(s, "six", "6");
//    boost::replace_all(s, "seven", "7");
//    boost::replace_all(s, "eight", "8");
//    boost::replace_all(s, "nine", "9");
//    cout << s;
//    answer = stoi(s);
//    return answer;
//}

//// �ƴϸ� �ݺ����� find�� �Ἥ �����ϰ� Ǫ�� ����� ����
//// �Ź� find�� 10�� �� ���� ������ ���ʿ��� ������ ���� �� ����
//// �ܾ �� ã���� npos�� ��ȯ�Ѵٰ� ��
//#include <string>
//
//using namespace std;
//
//int solution(string s) {
//    while (s.find("o") != string::npos || s.find("i") != string::npos || s.find("e") != string::npos) {
//        if (s.find("zero") != string::npos) s.replace(s.find("zero"), 4, "0");
//        if (s.find("one") != string::npos) s.replace(s.find("one"), 3, "1");
//        if (s.find("two") != string::npos) s.replace(s.find("two"), 3, "2");
//        if (s.find("three") != string::npos) s.replace(s.find("three"), 5, "3");
//        if (s.find("four") != string::npos) s.replace(s.find("four"), 4, "4");
//        if (s.find("five") != string::npos) s.replace(s.find("five"), 4, "5");
//        if (s.find("six") != string::npos) s.replace(s.find("six"), 3, "6");
//        if (s.find("seven") != string::npos) s.replace(s.find("seven"), 5, "7");
//        if (s.find("eight") != string::npos) s.replace(s.find("eight"), 5, "8");
//        if (s.find("nine") != string::npos) s.replace(s.find("nine"), 4, "9");
//    }
//
//    int t = stoi(s);
//    return t;
//}

//// regex ���͸� ���� Ǯ ���� ����
//// Ǯ� �� ���� �׳� �ݺ������� ���� ��
//#include <string>
//#include <vector>
//#include <regex>
//using namespace std;
//
//int solution(string s) {
//    vector<regex> dc{ regex("zero"),regex("one"),regex("two"),regex("three"),regex("four"),regex("five"),regex("six"),regex("seven"),regex("eight"),regex("nine") };
//    for (int i = 0; i < dc.size(); i++)
//        s = regex_replace(s, dc[i], to_string(i));
//    return stoi(s);
//}

//// ���̳� ��� �ƴϸ� ��̸� ����� Ǫ�� ����� ����
//// �ƴϸ� 3���� ���ڸ� ���� Ǫ�� ����� �־���

//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(string s) {
//
//    vector<int> a;
//
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] < 58) a.push_back(s[i]);
//        else {
//            if (s.substr(i, 3) == "zer") a.push_back('0');
//            else if (s.substr(i, 3) == "one") a.push_back('1');
//            else if (s.substr(i, 3) == "two") a.push_back('2');
//            else if (s.substr(i, 3) == "thr") a.push_back('3');
//            else if (s.substr(i, 3) == "fou") a.push_back('4');
//            else if (s.substr(i, 3) == "fiv") a.push_back('5');
//            else if (s.substr(i, 3) == "six") a.push_back('6');
//            else if (s.substr(i, 3) == "sev") a.push_back('7');
//            else if (s.substr(i, 3) == "eig") a.push_back('8');
//            else if (s.substr(i, 3) == "nin") a.push_back('9');
//        }
//    }
//
//    reverse(a.begin(), a.end());
//
//    int answer = 0;
//    int decimal = 1;
//
//    for (int i = 0; i < a.size(); i++) {
//        answer += (a[i] - 48) * decimal;
//        decimal *= 10;
//    }
//
//
//    return answer;
//}

//// ��Ư�ϰ� �Ӹ� ���� ����� ���� ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string check(string num) {
//    if (num == "zero") return "0";
//    else if (num == "one") return "1";
//    else if (num == "two") return "2";
//    else if (num == "three") return "3";
//    else if (num == "four") return "4";
//    else if (num == "five") return "5";
//    else if (num == "six") return "6";
//    else if (num == "seven") return "7";
//    else if (num == "eight") return "8";
//    else if (num == "nine") return "9";
//    else return "";
//}
//
//int solution(string s) {
//    int answer = 0;
//    string ans = "";
//    string num = "";
//    for (int i = 0; i < s.length(); i++) {
//        if (s[i] >= '0' && s[i] <= '9') {
//            ans += check(num);
//            ans += s[i];
//            num.clear();
//        }
//        else {
//            num += s[i];
//            if (check(num) != "") {
//                ans += check(num);
//                num.clear();
//            }
//
//        }
//    }
//    answer = stoi(ans);
//    return answer;
//}