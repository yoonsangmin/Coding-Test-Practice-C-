//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//    vector<string> answer;
//
//	for (int i = 0; i < n; i++)
//	{
//		int sum = arr1[i] | arr2[i];
//		string row = "";
//		for (int j = n - 1; j >= 0; j--)
//		{
//			// 해당 자리가 1이면 0이 아닌 값이 나옴, 0이 아니면 true
//			if (sum & 1 << j)
//				row += "#";
//			else
//				row += " ";
//		}
//
//		answer.push_back(row);
//	}
//
//    return answer;
//}