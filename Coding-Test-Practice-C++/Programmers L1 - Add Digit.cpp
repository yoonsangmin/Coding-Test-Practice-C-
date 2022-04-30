//using namespace std;
//int solution(int n)
//{
//    int answer = 0;
//
//    while (n > 0)
//    {
//        answer += n % 10;
//        n /= 10;
//    }
//
//    return answer;
//}

//// 다른 사람 풀이
//// 생각은 했던 방법이나 저번에 시도했을 때 to_string의 속도가 매우 느렸음
//#include <iostream>
//#include <string>
//
//using namespace std;
//int solution(int n)
//{
//    int answer = 0;
//
//    string s = to_string(n);
//
//    for (int i = 0; i < s.size(); i++) answer += (s[i] - '0');
//
//    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
//    cout << "Hello Cpp" << endl;
//
//    return answer;
//}