//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr) {
//    if (arr.size() == 1)
//        return {-1};
//
//    arr.erase(min_element(arr.begin(), arr.end()));
//
//    return arr;
//}
//
//// �ٸ� ��� Ǯ��
//// min_element �Լ��� �ּڰ��� �ݺ��ڸ� ���Ϲ޾Ҵµ� ���� �ٽ� find�� remove�� ã�Ƽ� ���� �ʿ�� ���� �� ����
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr) {
//    vector<int> answer = arr;
//    if (arr.size() == 1)
//        return { -1 };
//    else {
//        int delvalue = *min_element(answer.begin(), answer.end());
//        //// �� erase�ȿ� remove�� ������?
//        //// remove�� �������� ���ҵ��� uniqueó�� �����̳� �� �ڿ� ���������� �������� ������ �ݺ��ڸ� ������
//        //// �������� ���� �������� ��� �� ��������
//        //answer.erase(std::remove(answer.begin(), answer.end(), delvalue), answer.end());
//
//        //// find�� �� ���� �ϳ��� ã�Ƽ� ����
//        //answer.erase(find(answer.begin(), answer.end(), delvalue));
//
//        // �� ������ ã�� ����� filter ��ɵ� ����
//        // https://stackoverflow.com/questions/27454831/find-all-matching-elements-in-stdlist
//
//        answer.erase(find(answer.begin(), answer.end(), delvalue));
//        return answer;
//    }
//}
//
//int main()
//{
//    solution({ 1, 2, 5, 5, 1 ,5 ,1 });
//
//    return 0;
//}