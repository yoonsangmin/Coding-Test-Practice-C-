//// �� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//
//    int size = s.size();
//
//    // Ȧ���� true, ¦���� false;
//    // ��Ʈ �� ������ ��� 1�� ���� ��
//    // 1�� ��, 0�� ����
//    answer = size & 1 ? s.substr(size / 2, 1) : s.substr(size / 2 - 1, 2);
//
//    return answer;
//}

//// �ٸ� ��� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s) {
//    int size = s.size();
//    // ¦���� �� 1, Ȧ���� �� 2�� ���̸� ����
//    string answer = s.substr((size - 1) / 2, (size - 1) % 2 + 1);
//    return answer;
//}