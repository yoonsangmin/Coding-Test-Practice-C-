//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int solution(vector<vector<string>> clothes) {
//    int answer = 1;
//    map<string, int> cloth_count;
//
//    for (vector<string> cloth : clothes)
//    {
//        cloth_count[cloth[1]]++;
//    }
//
//    for (pair<string, int> elem : cloth_count)
//    {
//        answer *= elem.second + 1;
//    }
//
//    
//    return answer - 1;
//}