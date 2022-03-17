//// �� Ǯ��
//// ��� sizes�� ���鼭 max ���� �����ص� ������ max_element�� �ѹ� �Ẹ�� �;���
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes) {
//    vector<int> x;
//    vector<int> y;
//
//    for (int i = 0; i < sizes.size(); i++)
//    {
//        if (sizes[i][0] < sizes[i][1])
//        {
//            x.push_back(sizes[i][1]);
//            y.push_back(sizes[i][0]);
//        }
//        else
//        {
//            x.push_back(sizes[i][0]);
//            y.push_back(sizes[i][1]);
//        }
//    }
//
//    return *max_element(x.begin(), x.end()) * *max_element(y.begin(), y.end());
//}

//// ��� sizes ���鼭 max�� �����ϱ�
//// �̰� �ݺ����� �� ���� ���Ƽ� �׷��� �� ����
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes) {
//    int answer = 0;
//	int x_max = 0, y_max = 0;
//
//
//	for (int i = 0; i < sizes.size(); i++)
//	{
//		if (sizes[i][1] < sizes[i][0])
//		{
//			x_max = max(x_max, sizes[i][0]);
//			y_max = max(y_max, sizes[i][1]);
//		}
//		else
//		{
//			x_max = max(x_max, sizes[i][1]);
//			y_max = max(y_max, sizes[i][0]);
//		}
//	}
//
//    return x_max * y_max;
//}

//// �񱳹��� ���� �����ڷ� ���̰� if ������ �ݺ��� �ּ������� �ٿ���
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes) {
//	int answer = 0;
//	int x_max = 0, y_max = 0;
//
//	int bigger = 0, smaller = 1;
//
//	for (int i = 0; i < sizes.size(); i++)
//	{
//		bigger = sizes[i][0] > sizes[i][1] ? 0 : 1;
//		smaller = 1 - bigger;
//
//		x_max = max(x_max, sizes[i][bigger]);
//		y_max = max(y_max, sizes[i][smaller]);
//	}
//
//	return x_max * y_max;
//}

//// �ٸ� ��� Ǯ��
//// �ݺ��� ���� �����
//// �񱳸� �� �� �ص� �ӵ��� ������ ������ ����
//// �񱳰� ū �ӵ� ���� ���� �ʳ� �� - �ƴϸ� max ������ �� ���꺸�� ���� ��
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes)
//{
//    int answer = 0;
//
//    int w = 0, h = 0;
//    for (int i = 0; i < sizes.size(); i++)
//    {
//        w = max(w, min(sizes[i][0], sizes[i][1]));
//        h = max(h, max(sizes[i][0], sizes[i][1]));
//    }
//    answer = w * h;
//
//    return answer;
//}

//// �� �ڵ�� ����ѵ� �񱳸� �� �� ��
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> sizes)
//{
//    int l = 0, u = 0;
//
//    for (const auto& i : sizes)
//    {
//        int lt = i[0] < i[1] ? i[0] : i[1];
//        int ut = i[1] >= i[0] ? i[1] : i[0];
//
//        l = lt > l ? lt : l;
//        u = ut > u ? ut : u;
//    }
//
//    return l * u;
//}