// �� Ǯ��
// ���� �ϳ� �ϳ��� �Ѿ�鼭 Ǫ�� Ǯ��
// ���������� ó���ؾ� �� ���� ������ �ݺ����� �� ���� ��ȸ�ϰ� Ǯ�����
// ���� ó���ؾ� �� ���� ���� ��ó �������� �� �ߴ� ���ʰ� �ʹ� ������ - �׷��� ���� �׽�Ʈ ���̽� ����� ���� ������
// �ƿ� ������ ��ȸ�� ������ ���� ������
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
//		// �빮�� -> �ҹ���
//		if ('A' <= letter && letter <= 'Z')
//		{
//			letter -= ('A' - 'a');
//		}
//		// ������ ���
//		else if (!(('a' <= letter && letter <= 'z') || ('0' <= letter && letter <= '9')))
//		{
//			// ������ ���ڰ� �ƴϸ� ��ŵ
//			if (letter != '-' && letter != '_' && letter != '.')
//			{
//				continue;
//			}
//			// . �� ��� ���� �Ǿ����� ��ŵ
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

//// �ܰ� ���� Ǫ�� Ǯ��
//// �ݺ����� �� �� �� ���� erase ������ �־ �ð��� ���� �� �ɸ�
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string new_id) {
//    // 1 �ܰ�
//    for (int i = 0; i < new_id.length(); i++)
//    {
//        if ('A' <= new_id[i] && new_id[i] <= 'Z')
//        {
//            new_id[i] -= 'A' - 'a';
//        }
//    }
//
//    // 2 �ܰ�
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
//    // 3 �ܰ�
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
//    // 4 �ܰ�
//    if (new_id.front() == '.') new_id.erase(new_id.begin());
//    // 6 �ܰ迡�� Ȯ�� ���� �� Ȯ�� �ϱ� ������ 5�ܰ� ������ ���⼭�� �ؾ� ��
//    if (new_id.back() == '.') new_id.pop_back();
//
//    // 5 �ܰ�
//    if (new_id == "") new_id = "a";
//
//    // 6 �ܰ�
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

//// �ٸ� ��� Ǯ��
//// ��Ģ ������� ǰ - ���� ó�� ���� �״�� Ǯ�� �ż� ���� ��
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string new_id) {
//
//    // bit ������
//    // ch = ch | 32; ���� ǥ��
//    // �� 32�� | �ϸ� �빮�ڰ� �ҹ��ڰ� �Ǵ°�?
//    // 32 == 'a' - 1 ��
//    // �� 'A' �� 'a'�� ���� ��ŭ ���� �Ŷ� ����� �� �ƴұ�
//    // 'a' - 'A' �� ���� ��ŭ ���ϴ� �Ŷ� ���� �ǹ�
//    // tolower, toupper�� ����
//    // 32�� ���ؾ� �ҹ�����, 32�� ���ϴ� �Ͱ� ���� �ǹ�
//    // https://hoho325.tistory.com/314
//    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;
//
//
//    // ���ڿ����� ���� �˻� �Լ�
//    // �� ã�� ��� nullptr ã�� ��� �ּҸ� �Ѱ���
//    // �ʿ� ���� ���� ������
//    // https://blockdmask.tistory.com/389
//    string ret;
//    for (char& ch : new_id) {
//        if ('a' <= ch && ch <= 'z' ||
//            '0' <= ch && ch <= '9' ||
//            strchr("-_.", ch)) ret += ch;
//    }
//
//    // ���Ͽ��� �����ϴٰ� ������ �ٽ� ������ ���� �ְ� ������ ���
//    // �̰� ������ for �� ���ٰ� else �κп��� i++ ���� �κ��� �� �ص� �ǰ�
//    // erase ������ ��� �Ǳ� ������ �ð��� �������� �� ����
//    new_id = ret;
//    ret.clear();
//    // . �� ���ӵ� ��� ����
//    for (char& ch : new_id) {
//        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
//        ret += ch;
//    }
//
//    // ���� �κ� �� �κ� . ����
//    if (ret.front() == '.') ret.erase(ret.begin());
//    if (ret.back() == '.') ret.pop_back();
//
//    // ���� �� ��� ������ a �߰�
//    if (ret.empty()) ret = "a";
//    // ������ �Ѵ� �κ� ����
//    if (ret.size() >= 16) ret = ret.substr(0, 15);
//    // ���� �Ŀ� 15�� ������ . ����
//    if (ret.back() == '.') ret.pop_back();
//    // �� Ǯ�̶� ��� ����� 3�� �� ������ ������ ���� �ݺ�
//    while (ret.size() <= 2) ret += ret.back();
//
//    return ret;
//}