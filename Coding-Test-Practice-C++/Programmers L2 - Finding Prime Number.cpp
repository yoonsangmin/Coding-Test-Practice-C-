//#include <string>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//int solution(string numbers) {
//	int answer = 0;
//	set<int> number_set;
//
//	sort(numbers.begin(), numbers.end());
//
//	for (int r = 1; r <= numbers.size(); r++)
//	{
//		vector<bool> comb(numbers.size(), false);
//		for (int i = 0; i < r; i++)
//		{
//			comb[numbers.size() - 1 - i] = true;
//		}
//
//		do
//		{
//			string number_string = "";
//
//			for (int i = 0; i < numbers.size(); i++)
//			{
//				if (comb[i])	number_string += numbers[i];
//			}
//
//			sort(number_string.begin(), number_string.end());
//
//			do
//			{
//				int number = stoi(number_string);
//
//				if (find(number_set.begin(), number_set.end(), number) == number_set.end())
//				{
//					number_set.insert(number);
//
//					// 소수 체크
//
//					bool is_prime = true;
//
//					for (int i = 2; i <= ceil(number / 2); i++)
//					{
//						if (number % i == 0)
//						{
//							is_prime = false;
//							break;
//						}
//					}
//
//					if (number <= 1)
//						is_prime = false;
//
//					if (is_prime)
//					{
//						answer++;
//					}
//				}
//
//			} while (next_permutation(number_string.begin(), number_string.end()));
//		} while (next_permutation(comb.begin(), comb.end()));
//	}
// 
//    return answer;
//}