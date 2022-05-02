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
//// 다른 사람 풀이
//// min_element 함수로 최솟값의 반복자를 리턴받았는데 굳이 다시 find나 remove로 찾아서 지울 필요는 없는 것 같음
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
//        //// 왜 erase안에 remove를 적었나?
//        //// remove는 지워야할 원소들을 unique처럼 컨테이너 맨 뒤에 보내버리고 지워야할 원소의 반복자를 리턴함
//        //// 지워야할 값이 여러개인 경우 다 지워버림
//        //answer.erase(std::remove(answer.begin(), answer.end(), delvalue), answer.end());
//
//        //// find는 맨 앞의 하나만 찾아서 지움
//        //answer.erase(find(answer.begin(), answer.end(), delvalue));
//
//        // 한 꺼번에 찾는 기능은 filter 기능도 있음
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