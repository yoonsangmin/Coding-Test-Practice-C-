//#include <string>
//#include <vector>
//
//using namespace std;
//
//// ���� ����, ���� sorting �˰����� �� ���� �����غ�
//// ���� ��쵵 üũ���ֱ� ������ ���� �������� �ִ� ���� ���� �ܿ��� ���� ����(�������� ����, �ּڰ��� �ε����� Ž��), ���� ����(�������� ����, Ž�� ���� �� ������ ������ �Ϸ��ϴ� ��, ���ο� ������ ��ġ�� �ٷιٷ� üũ�ؼ� ������)�� ����ص� ��
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	for (int i = 0; i < strings.size() - 1; i++)
//	{
//		for (int j = 1; j < strings.size() - i; j++)
//		{
//			if (strings[j - 1][n] > strings[j][n])
//			{
//				swap(strings[j - 1], strings[j]);
//			}
//			else if (strings[j - 1][n] == strings[j][n])
//			{
//				if (strings[j - 1] > strings[j])
//				{
//					swap(strings[j - 1], strings[j]);
//				}
//			}
//		}
//	}
//
//	answer = strings;
//
//	return answer;
//}
//

// �������� ������ �ִ� stable_sort�� ����

//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	// ���� ����
//	for (int i = 0; i < strings.size(); i++)
//	{
//		answer.push_back(strings[i]);
//
//		for (int j = answer.size() - 1; j >= 1; j--)
//		{
//			if (answer[j - 1][n] > answer[j][n])
//			{
//				swap(answer[j - 1], answer[j]);
//			}
//			else if (answer[j - 1][n] == answer[j][n])
//			{
//				if (answer[j - 1] > answer[j])
//				{
//					swap(answer[j - 1], answer[j]);
//				}
//			}
//			else
//				break;
//		}
//	}
//
//	return answer;
//}

//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//    vector<string> answer;
//
//	// �� �� ���� �� n�� �������� �ٽ� ������ - ���� �˰����� �������� �־����
//	sort(strings.begin(), strings.end());
//
//	// ���� ���� - �������� ����
//	for (int i = 0; i < strings.size() - 1; i++)
//	{
//		for (int j = 1; j < strings.size() - i; j++)
//		{
//			if (strings[j - 1][n] > strings[j][n])
//			{
//				swap(strings[j - 1], strings[j]);
//			}
//		}
//	}
//
//	answer = strings;
//
//    return answer;
//}

//// ���� ���� ����ϴ� ���, ���� ������ ����ϴ� ����� ���� ����� �ƴ� �� ����
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//
//bool cmp(string s1, string s2)
//{
//	if (s1[N] == s2[N])
//	{
//		return s1 < s2;
//	}
//
//	return s1[N] < s2[N];
//}
//
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	N = n;
//
//	sort(strings.begin(), strings.end(), cmp);
//	answer = strings;
//
//	return answer;
//}

//// ���� �Լ��� ����ؼ� �Լ� �ȿ� �Լ��� ���� ���� �� ����
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	// [] �빮�� ���� ���� ĸ�� ��� &��� ���� ����������, =��� ���� ����� ĸ��
//	auto cmp = [n](string s1, string s2) {
//		if (s1[n] == s2[n])
//		{
//			return s1 < s2;
//		}
//
//		return s1[n] < s2[n];
//	};
//
//	sort(strings.begin(), strings.end(), cmp);
//	answer = strings;
//
//	return answer;
//}
 
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	// ���ٽ��� ����ϸ� ���� ��ü�� ������ �ʾƵ� �ٷ� ����� ���� ����
//	sort(strings.begin(), strings.end(), [n](auto s1, auto s2) { return s1[n] == s2[n] ? s1 < s2 : s1[n] < s2[n]; });
//	answer = strings;
//
//	return answer;
//}

//// functional�� ����غ��� ���� �� ����
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <functional>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	// [] �빮�� ���� ���� ĸ�� ��� &��� ���� ����������, =��� ���� ����� ĸ�� = ���ٿ� �������� - �Լ��� ��ü�� ����ų �� �ִٴ� �͸� �ٸ� ��
//	// function cmp = [n](string s1, string s2) {
//	// function<bool(string s1, string s2)> cmp = [n](string s1, string s2) {
//	function<bool(string, string)> cmp = [n](string s1, string s2) {
//		if (s1[n] == s2[n])
//		{
//			return s1 < s2;
//		}
//
//		return s1[n] < s2[n];
//	};
//
//	sort(strings.begin(), strings.end(), cmp);
//	answer = strings;
//
//	return answer;
//}

//// functional
//// https://modoocode.com/254
//// c++������ ()�� �ʿ� ȣ���� �� �ִ� ��� ���� callable�� ����
//// S�� �Լ��� �ƴԿ��� �Լ�ó�� ȣ���� �� ����
//#include <iostream>
//
//
//struct S {
//	void operator()(int a, int b) { std::cout << "a + b = " << a + b << std::endl; }
//};
//
//int main() {
//	S some_obj;
//
//	some_obj(3, 5);
//}

//// callable���� ��ü�� ���·� ������ �� �ִ� ���� function Ŭ����
//#include <functional>
//#include <iostream>
//#include <string>
//
//int some_func1(const std::string& a) {
//	std::cout << "Func1 ȣ��! " << a << std::endl;
//	return 0;
//}
//
//struct S {
//	void operator()(char c) { std::cout << "Func2 ȣ��! " << c << std::endl; }
//};
//
//int main() {
//	// �Լ�
//	std::function<int(const std::string&)> f1 = some_func1;
//	// ����ü S�� ���۷�����()
//	std::function<void(char)> f2 = S();
//	// ���ٽ�
//	std::function<void()> f3 = []() { std::cout << "Func3 ȣ��! " << std::endl; };
//
//	f1("hello");
//	f2('c');
//	f3();
//}

//// �ٸ� ��� Ǯ��
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int i;
//
//bool compare(string a, string b) {
//    // ���� �����ڸ� ����ϸ� ��������
//    return a[i] == b[i] ? a < b : a[i] < b[i];
//}
//
//vector<string> solution(vector<string> strings, int n) {
//    i = n;
//    sort(strings.begin(), strings.end(), compare);
//    return strings;
//}

//// ���� ������ ����̳� ���ٽ��� �� ����� �� �ִٸ� ������ ���
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <functional>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//    vector<pair<char, string>> container;
//    for (int i = 0; i < strings.size(); i++)
//        container.push_back(make_pair(strings[i][n], strings[i]));
//    sort(container.begin(), container.end());
//
//    vector<string> answer;
//    for (int i = 0; i < container.size(); i++)
//        answer.push_back(container[i].second);
//    return answer;
//}