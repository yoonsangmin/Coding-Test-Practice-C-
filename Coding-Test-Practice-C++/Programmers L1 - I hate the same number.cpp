// 내 풀이
// 정렬하지 않고 unique로 연속된 중복만 제거해봄
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr)
//{
//    vector<int> answer;
//
//    arr.erase(unique(arr.begin(), arr.end()), arr.end());
//
//    answer = arr;
//
//    return answer;
//}

//// unique를 사용하지 않은 풀이 1
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr)
//{
//    vector<int> answer;
//	
//	answer.push_back(arr[0]);
//
//	for (int i = 1; i < arr.size(); i++)
//	{
//		if (arr[i - 1] == arr[i]) continue;
//
//		answer.push_back(arr[i]);
//	}
//
//    return answer;
//}

//// unique를 사용하지 않은 풀이 2
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr)
//{
//	vector<int> answer;
//
//	answer.push_back(arr[0]);
//	for (int i = 1; i < arr.size(); i++)
//	{
//		if (answer.back() == arr[i]) continue;
//
//		answer.push_back(arr[i]);
//	}
//
//	return answer;
//}

//// unique를 사용하지 않은 풀이 3
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr)
//{
//	vector<int> answer;
//
//	answer.push_back(arr[0]);
//	for (int i = 1; i < arr.size(); i++)
//	{
//		if (answer.back() != arr[i])
//			answer.push_back(arr[i]);
//	}
//
//	return answer;
//}