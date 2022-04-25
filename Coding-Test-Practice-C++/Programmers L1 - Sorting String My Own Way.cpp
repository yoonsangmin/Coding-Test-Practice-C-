//#include <string>
//#include <vector>
//
//using namespace std;
//
//// 버블 정렬, 따로 sorting 알고리즘을 안 쓰고 구현해봄
//// 같은 경우도 체크해주기 때문에 굳이 안정성이 있는 버블 정렬 외에도 선택 정렬(안정성이 없음, 최솟값의 인덱스를 탐색), 삽입 정렬(안정성이 있음, 탐색 중인 곳 까지의 정렬을 완료하는 것, 새로운 숫자의 위치를 바로바로 체크해서 삽입함)을 사용해도 됨
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

// 안정성을 유지해 주는 stable_sort도 있음

//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	// 삽입 정렬
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
//	// 한 번 정렬 후 n을 기준으로 다시 정렬함 - 정렬 알고리즘이 안정성이 있어야함
//	sort(strings.begin(), strings.end());
//
//	// 버블 정렬 - 안정성이 있음
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

//// 전역 변수 사용하는 방법, 전역 변수를 사용하는 방법은 좋은 방법은 아닌 것 같음
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

//// 람다 함수를 사용해서 함수 안에 함수를 쓰면 좋을 것 같음
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer;
//
//	// [] 대문자 안의 값은 캡쳐 목록 &모든 값을 참조형으로, =모든 값을 복사로 캡쳐
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
//	// 람다식을 사용하면 굳이 객체로 만들지 않아도 바로 사용할 수도 있음
//	sort(strings.begin(), strings.end(), [n](auto s1, auto s2) { return s1[n] == s2[n] ? s1 < s2 : s1[n] < s2[n]; });
//	answer = strings;
//
//	return answer;
//}

//// functional도 사용해보면 좋을 것 같음
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
//	// [] 대문자 안의 값은 캡쳐 목록 &모든 값을 참조형으로, =모든 값을 복사로 캡쳐 = 람다와 마찬가지 - 함수를 객체로 가리킬 수 있다는 것만 다른 듯
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
//// c++에서는 ()를 붗여 호출할 수 있는 모든 것을 callable로 정의
//// S는 함수가 아님에도 함수처럼 호출할 수 있음
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

//// callable들을 객체의 형태로 보관할 수 있는 것이 function 클래스
//#include <functional>
//#include <iostream>
//#include <string>
//
//int some_func1(const std::string& a) {
//	std::cout << "Func1 호출! " << a << std::endl;
//	return 0;
//}
//
//struct S {
//	void operator()(char c) { std::cout << "Func2 호출! " << c << std::endl; }
//};
//
//int main() {
//	// 함수
//	std::function<int(const std::string&)> f1 = some_func1;
//	// 구조체 S의 오퍼레이터()
//	std::function<void(char)> f2 = S();
//	// 람다식
//	std::function<void()> f3 = []() { std::cout << "Func3 호출! " << std::endl; };
//
//	f1("hello");
//	f2('c');
//	f3();
//}

//// 다른 사람 풀이
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int i;
//
//bool compare(string a, string b) {
//    // 삼항 연산자를 사용하면 간단해짐
//    return a[i] == b[i] ? a < b : a[i] < b[i];
//}
//
//vector<string> solution(vector<string> strings, int n) {
//    i = n;
//    sort(strings.begin(), strings.end(), compare);
//    return strings;
//}

//// 나도 생각한 방법이나 람다식을 잘 사용할 수 있다면 굳이인 방법
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