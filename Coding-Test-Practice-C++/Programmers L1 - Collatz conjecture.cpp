//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int num)
//{
//	if (num == 1) return 0;
//	long long number = num;
//	for (int i = 1; i <= 500; i++)
//	{
//		number = number & 1 ? number * 3 + 1 : number / 2;
//		if (number == 1) return i;
//	}
//
//    return -1;
//}