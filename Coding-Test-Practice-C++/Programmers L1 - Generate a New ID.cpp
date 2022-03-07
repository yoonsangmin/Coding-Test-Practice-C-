// 내 풀이
// 문자 하나 하나씩 넘어가면서 푸는 풀이
// 예외적으로 처리해야 할 것이 많으나 반복문을 한 번만 순회하게 풀어봤음
// 예외 처리해야 할 것이 많이 미처 생각하지 못 했던 번례가 너무 많았음 - 그래서 예제 테스트 케이스 결과를 보고 수정함
// 아예 돌려볼 기회가 없으면 조금 위험함
// 
// #include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string new_id) {
//    string answer = "";
//
//	for (int i = 0; i < new_id.size() && answer.size() < 15; i++)
//	{
//		char letter = new_id[i];
//
//		if (answer == "" && letter == '.')
//		{
//			continue;
//		}
//
//		// 대문자 -> 소문자
//		if ('A' <= letter && letter <= 'Z')
//		{
//			letter -= ('A' - 'a');
//		}
//		// 문자인 경우
//		else if (!(('a' <= letter && letter <= 'z') || ('0' <= letter && letter <= '9')))
//		{
//			// 가능한 문자가 아니면 스킵
//			if (letter != '-' && letter != '_' && letter != '.')
//			{
//				continue;
//			}
//			// . 인 경우 연속 되었으면 스킵
//			else if (letter == '.' && (answer == "" || answer.back() == '.'))
//			{
//				continue;
//			}
//		}
//		else if (letter == ' ')
//		{
//			letter = 'a';
//		}
//
//		if (answer.size() == 14 && letter == '.') break;
//		else answer += letter;
//	}
//	
//	while (answer.back() == '.')
//	{
//		answer.pop_back();
//	}
//
//	while (answer.size() < 3)
//	{
//		if (answer == "") answer.push_back('a');
//		answer += answer.back();
//	}
//
//    return answer;
//}

//// 단계 별로 푸는 풀이
//// 반복문을 두 번 더 돌고 erase 연산이 있어서 시간이 조금 더 걸림
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string new_id) {
//    // 1 단계
//    for (int i = 0; i < new_id.length(); i++)
//    {
//        if ('A' <= new_id[i] && new_id[i] <= 'Z')
//        {
//            new_id[i] -= 'A' - 'a';
//        }
//    }
//
//    // 2 단계
//    for (int i = 0; i < new_id.length();)
//    {
//        if (!('a' <= new_id[i] && new_id[i] <= 'z') && !('0' <= new_id[i] && new_id[i] <= '9') && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.')
//        {
//            new_id.erase(new_id.begin() + i);
//        }
//        else
//        {
//            i++;
//        }
//    }
//
//    // 3 단계
//    for (int i = 0; i < new_id.length(); i++)
//    {
//        if (new_id[i] == '.')
//        {
//            while (i + 1 < new_id.length() && new_id[i + 1] == '.')
//            {
//                new_id.erase(new_id.begin() + i + 1);
//            }
//        }
//    }
//
//    // 4 단계
//    if (new_id.front() == '.') new_id.erase(new_id.begin());
//    // 6 단계에서 확인 가능 또 확인 하긴 하지만 5단계 때문에 여기서도 해야 함
//    if (new_id.back() == '.') new_id.pop_back();
//
//    // 5 단계
//    if (new_id == "") new_id = "a";
//
//    // 6 단계
//    new_id = new_id.substr(0, 15);
//    if (new_id.back() == '.') new_id.pop_back();
//
//    while (new_id.length() < 3)
//    {
//        new_id += new_id.back();
//    }
//        
//    return new_id;
//}

//// 다른 사람 풀이
//// 규칙 순서대로 품 - 예외 처리 없이 그대로 풀면 돼서 좋은 듯
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string new_id) {
//
//    // bit 연산자
//    // ch = ch | 32; 줄인 표현
//    // 왜 32랑 | 하면 대문자가 소문자가 되는가?
//    // 32 == 'a' - 1 임
//    // 즉 'A' 와 'a'의 차이 만큼 빼는 거랑 비슷한 게 아닐까
//    // 'a' - 'A' 의 차이 만큼 더하는 거랑 같은 의미
//    // tolower, toupper도 있음
//    // 32를 더해야 소문자임, 32를 더하는 것과 같은 의미
//    // https://hoho325.tistory.com/314
//    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;
//
//
//    // 문자열에서 문자 검색 함수
//    // 못 찾은 경우 nullptr 찾은 경우 주소를 넘겨줌
//    // 필요 없는 문자 제외함
//    // https://blockdmask.tistory.com/389
//    string ret;
//    for (char& ch : new_id) {
//        if ('a' <= ch && ch <= 'z' ||
//            '0' <= ch && ch <= '9' ||
//            strchr("-_.", ch)) ret += ch;
//    }
//
//    // 리턴에다 저장하다가 리턴을 다시 연산할 곳에 넣고 리턴을 비움
//    // 이것 때문에 for 문 돌다가 else 부분에만 i++ 같은 부분을 안 해도 되고
//    // erase 연산이 없어도 되기 때문에 시간도 빨라지는 것 같음
//    new_id = ret;
//    ret.clear();
//    // . 이 연속된 경우 제외
//    for (char& ch : new_id) {
//        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
//        ret += ch;
//    }
//
//    // 시작 부분 끝 부분 . 제거
//    if (ret.front() == '.') ret.erase(ret.begin());
//    if (ret.back() == '.') ret.pop_back();
//
//    // 제거 후 비어 있으면 a 추가
//    if (ret.empty()) ret = "a";
//    // 사이즈 넘는 부분 제거
//    if (ret.size() >= 16) ret = ret.substr(0, 15);
//    // 끊은 후에 15줄 넘으면 . 제거
//    if (ret.back() == '.') ret.pop_back();
//    // 내 풀이랑 비슷 사이즈가 3이 될 때까지 마지막 문자 반복
//    while (ret.size() <= 2) ret += ret.back();
//
//    return ret;
//}