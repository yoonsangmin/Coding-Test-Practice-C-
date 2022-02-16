//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//    vector<int> answer;
//    int day = 0;
//    int release_count = 0;
//
//    for (int i = 0; i < progresses.size(); i++)
//    {
//        int cur = (int)ceil((double)(100 - progresses[i]) / speeds[i]);
//
//        //int cur = 1;
//        //int temp = 100 - progresses[i];
//        //while ((temp -= speeds[i]) > 0)
//        //{
//        //    cur++;
//        //}
//
//        if (cur > day)
//        {
//            day = cur;
//            if (release_count != 0)
//                answer.push_back(release_count);
//            release_count = 1;
//        }
//        else
//        {
//            release_count++;
//        }
//    }
//    if (release_count != 0)
//        answer.push_back(release_count);
//
//    return answer;
//}