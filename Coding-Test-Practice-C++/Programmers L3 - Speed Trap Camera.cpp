//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// �� Ǯ��, ���� ������ �������� ������ �� ���� �ݺ������� �ش� ���� ���� �ִ� ��� �������� �����ϰ� ī�޶� �ϳ� ��ġ��
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

// �ٸ� ��� Ǯ��

// gcc
//#include <bits/stdc++.h>

//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//// �ٸ� ��� Ǯ��
//// ��ü������ Ǯ�� ����� �����
//// ������ ����Ʈ��� ������ ���� ����Ʈ �������� ū �������� ���� ��쿡 ���ο� ī�޶� ��ġ�Ѵٰ� ����� �ϰ� �ش� �������� ����Ʈ�� �ٽ� ������
//// �̷��� �ϸ� ���� �������� ���� ������ ���� ��� ������ ���� �ʿ䰡 ����
//// �׸��� ����� ���굵 ���ʿ�����
//// ����Ʈ���� �������� ������ �̹� ��ġ�� ī�޶� ��� Ŀ���� �Ǳ� ������ �Ű� �� �ʿ䰡 ����
//
//// ���� �������� ���� ������ 4�質 ����
//// ���� ������ ����� �� �׻� ������ ���� �� �ִ� ����� �����ؾ� ��
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
//// �ٸ� ��� �ؼ�
//// �̷������� ������ �������� ������ �ʿ䰡 �ִ�.
//
//// ����ο� ��ġ�ϰ� �ȴٸ�,
//// ���� �����ϱ� ������, �ش� �������̿� ������ ���� �ְԵǸ�, �ش� ������ ��ġ�� ī�޶� ����Ѵٴ� ������ ������,
//// ��� ���������� ī�޶� ��ġ�� ������ ������ Ȯ���� �ְԵ˴ϴ�. �̷������� ī�޶�� ���������� ��ġ�Ǿ���մϴ�.
//
//// - ���� �������� ��ġ�ϰ� ������ �������� �����ϸ� ��
//
//// routes�迭�� ���������� ������������ �����Ѵ�.
//// ���� ī�޶� ��ġ��ġ�� ��Ÿ���� ������ �����ϰ� ���� - 30001�� �����Ѵ�.
//// routes���� for������ �ϳ��� Ž���Ѵ�.
//// ���� ���Ա����� ���� ī�޶��� ��ġ�������� ������, �׳� ���� ������ �Ѿ��.
//// �ƴ϶��, answer�� 1�� ���ϰ�, ���� ī�޶��� ��ġ�� ���� ������ġ�� �����Ѵ�.


//// �ٸ� ����� Ǯ��
//// �ӵ��� ���� ����
//// ������ �Ǵ� �κе��� ��ġ�鼭 �������� ������ ������ ���� ��
//// ���� ���ϰ� �ִ� �����ϰ� �ϴ� �κ��� for�� �ϳ��� ī�޶��� ������ ���丮�� ����? ��ŭ �ð� ���⵵�� �� �� ����
//// ī�޶��� ������ ����̱� ��
//// �׷����� �ð��� ���� ���� cmp�� �ð��� �� �����? - cmp�� �ð��� �� ��
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
//        if (routes[i][0] > routes[i][1]) //�������� ���������� Ŭ ���
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
//                    (routes[i][0] <= overlap[j][0] && routes[i][1] >= overlap[j][1])) //��ġ�� �κ��� ������
//                {
//                    vector<int> v;
//                    v.push_back(max(routes[i][0], overlap[j][0]));
//                    v.push_back(min(routes[i][1], overlap[j][1]));
//                    overlap[j] = v;
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag == false) //��ġ�� �κ��� ������
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