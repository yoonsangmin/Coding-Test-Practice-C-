//// �� Ǯ��
//// accumulate�� ���� ����� ���� �����ϰ� ���� �� �ִٴ� ���� �˰� ��
//#include <string>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 45;  // (9 + 0) * 10 / 2
//
//    answer -= accumulate(numbers.begin(), numbers.end(), 0);	// for �� ���鼭 ���� ��
//
//    return answer;
//}

//// �������� ���� ��� Ǭ �ڵ�
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (find(numbers.begin(), numbers.end(), i) == numbers.end())
//        {
//            answer += i;
//        }
//    }
//
//    return answer;
//}

//// �������� ���� ��� Ǭ �ڵ� - ���� ����
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//    map<int, bool> number_dic;
//
//    for (auto number : numbers)
//    {
//        number_dic[number] = true;
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (!number_dic[i])
//        {
//            answer += i;
//        }
//    }
//
//    return answer;
//}
//
//// �ٸ� ��� Ǯ��
//// ���� ������ �ڵ� �ʱ�ȭ ��
//// ���� ������ ���� �ʱ�ȭ �ؾ� �ϳ� ���� �迭 ������ int a[10] = {}; �� �ڵ� �ʱ�ȭ �� �� ����
//#include <string>
//#include <vector>
//
//using namespace std;
//int a[10];
//int solution(vector<int> numbers) {
//    int answer = 0;
//
//    for (int i = 0; i < numbers.size(); i++) {
//        a[numbers[i]] = 1;
//    }
//    for (int i = 0; i < 10; i++) {
//        if (a[i] == 0) answer += i;
//    }
//    return answer;
//}


//// �ٸ� ��� Ǯ��
//// ���� �ϰ� �;��� ��
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//
//    sort(numbers.begin(), numbers.end());
//
//    int index = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (i != numbers[index])
//        {
//            answer += i;
//        }
//        else
//            index++;
//    }
//
//
//    return answer;
//}

//// �ٸ� ��� Ǯ��
//// ��Ư�� Ǯ���̳� insert ������ ���� Ǯ�̴� �ƴ� ��, ���� Ǯ�̶� ����ؼ� ���� Ǯ�̸� ���� ��
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> numbers) {
//    int answer = 0;
//    sort(numbers.begin(), numbers.end());
//    for (int i = 0; i < 10; i++) {
//        if (i == numbers.size() || numbers[i] != i) {
//            answer += i;
//            numbers.insert(numbers.begin() + i, i);
//        }
//    }
//
//    return answer;
//}