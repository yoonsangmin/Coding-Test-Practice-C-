//#include <iostream>
//#include <map>
//using namespace std;
//int main() {
//	int num, prime_count = 0;
//	cin >> num;
//	
//	map<int, bool> mem; // true = ¼Ò¼ö°¡ ¾Æ´Ô
//
//	for (int i = 2; i < num; i++)
//	{
//		if (mem[i] == false)
//		{
//			for (int j = 2; i * j < num; j++)
//			{
//				mem[i * j] = true;
//			}
//
//			prime_count++;
//		}
//	}
//
//	cout << prime_count;
//
//	return 0;
//}