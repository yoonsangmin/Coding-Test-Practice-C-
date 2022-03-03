//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// 내 풀이, 종료 지점을 기준으로 정렬한 후 이중 반복문으로 해당 범위 내에 있는 모든 차량들을 제거하고 카메라를 하나 설치함
//
//bool cmp(vector<int> v1, vector<int> v2)
//{
//    if (v1[1] == v2[1])
//    {
//        return v1[0] < v2[0];
//    }
//
//    return v1[1] < v2[1];
//}
//
//int solution(vector<vector<int>> routes) {
//    int answer = 0;
//
//    sort(routes.begin(), routes.end(), cmp);
//
//    int i = 0;
//
//    while (i < routes.size())
//    {
//        answer++;
//        
//        int j = i + 1;
//
//        while (j < routes.size())
//        {
//            if (routes[j][0] <= routes[i][1])
//            {
//                routes.erase(routes.begin() + j);
//            }
//            else
//                j++;
//        }
//
//        i++;
//    }
//
//    return answer;
//}

// 다른 사람 풀이

// gcc
//#include <bits/stdc++.h>

//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//// 다른 사람 풀이
//// 전체적으로 풀이 방법은 비슷함
//// 하지만 리미트라는 변수를 만들어서 리미트 변수보다 큰 시작점이 나온 경우에 새로운 카메라를 설치한다고 계산을 하고 해당 종료점을 리미트로 다시 설정함
//// 이렇게 하면 이중 포문으로 현재 차량에 대해 모든 차량을 비교할 필요가 없음
//// 그리고 지우는 연산도 불필요해짐
//// 리미트보다 시작점이 작으면 이미 설치한 카메라에 모두 커버가 되기 때문에 신경 쓸 필요가 없음
//
//// 이중 포문으로 만들 때보다 4배나 빠름
//// 이중 포문을 사용할 땐 항상 포문을 줄일 수 있는 방법을 강구해야 함
//
//bool cmp(vector<int> a, vector<int> b) { return a[1] < b[1]; }
//
//int solution(vector<vector<int>> routes) {
//    int answer = 0;
//    int limit = -30001;
//    sort(routes.begin(), routes.end(), cmp);
//    for (int i = 0; i < routes.size(); i++) {
//        if (limit < routes[i][0]) {
//            answer++;
//            limit = routes[i][1];
//        }
//    }
//    return answer;
//}
//
//// 다른 사람 해설
//// 이런식으로 문제를 논리적으로 생각할 필요가 있다.
//
//// 진출로에 설치하게 된다면,
//// 내가 진출하기 전까지, 해당 구간사이에 진입한 차가 있게되면, 해당 차량은 설치된 카메라를 통과한다는 보장은 없지만,
//// 적어도 진출지점이 카메라가 설치된 지점을 지나갈 확률이 있게됩니다. 이런점에서 카메라는 진출지점에 설치되어야합니다.
//
//// - 따라서 종료점에 설치하고 종료점 기준으로 정렬하면 됨
//
//// routes배열을 진출순서대로 오름차순으로 정렬한다.
//// 현재 카메라 설치위치를 나타내는 변수를 선언하고 값은 - 30001로 설정한다.
//// routes값을 for문으로 하나씩 탐색한다.
//// 만약 진입구간이 현재 카메라의 설치구간보다 작으면, 그냥 다음 값으로 넘어간다.
//// 아니라면, answer에 1을 더하고, 현재 카메라의 위치를 현재 종점위치로 갱신한다.


//// 다른 방식의 풀이
//// 속도가 제일 빠름
//// 오버랩 되는 부분들을 합치면서 구간들의 개수를 답으로 리턴 함
//// 값을 비교하고 최댓값 리턴하고 하는 부분이 for문 하나에 카메라의 개수의 팩토리얼 정도? 만큼 시간 복잡도가 들 것 같음
//// 카메라의 개수는 상수이긴 함
//// 그럼에도 시간이 빠른 것은 cmp가 시간이 더 드는지? - cmp가 시간이 더 듦
//
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<vector<int>> routes) {
//    int answer = 0;
//    vector<vector<int>> overlap;
//    sort(routes.begin(), routes.end());
//
//    for (int i = 0; i < routes.size(); i++)
//    {
//        if (routes[i][0] > routes[i][1]) //진입점이 진출점보다 클 경우
//        {
//            int t = routes[i][0];
//            routes[i][0] = routes[i][1];
//            routes[i][1] = t;
//        }
//
//        if (overlap.empty())
//        {
//            //answer++;
//            overlap.push_back(routes[i]);
//        }
//        else
//        {
//            bool flag = false;
//            for (int j = 0; j < overlap.size(); j++)
//            {
//                if ((overlap[j][0] <= routes[i][0] && routes[i][0] <= overlap[j][1]) ||
//                    (overlap[j][0] <= routes[i][1] && routes[i][1] <= overlap[j][1]) ||
//                    (routes[i][0] <= overlap[j][0] && routes[i][1] >= overlap[j][1])) //겹치는 부분이 있으면
//                {
//                    vector<int> v;
//                    v.push_back(max(routes[i][0], overlap[j][0]));
//                    v.push_back(min(routes[i][1], overlap[j][1]));
//                    overlap[j] = v;
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag == false) //겹치는 부분이 없으면
//            {
//                //answer++;
//                overlap.push_back(routes[i]);
//            }
//        }
//
//
//    }
//
//    answer = overlap.size();
//    return answer;
//}