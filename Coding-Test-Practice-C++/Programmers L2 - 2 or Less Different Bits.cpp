//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<long long> solution(vector<long long> numbers) {
//    vector<long long> answer(numbers.size());
//	long long number;
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		number = numbers[i];
//		for (int n = 0; n < 63; n++)
//		{
//			if (number & ((long long)1 << n))
//				continue;
//
//			number += ((long long)1 << n);
//			if (n - 1 >= 0)
//				number -= ((long long)1 << (n - 1));
//			break;
//		}
//
//		answer[i] = number;
//	}
//
//    return answer;
//}

//// 다른 사람 풀이
//#include <vector>
//std::vector<long long> solution(std::vector<long long> numbers) {
//    std::vector<long long> answer;
//    for (long long number : numbers) {
//        long long bit = 1;
//        while ((number & bit) > 0) bit <<= 1;
//        // 1의 자리인 경우 오르쪽으로 비트 연산을 하면 0이 돼서 그대로 써도 됨
//        answer.push_back(number + bit - (bit >> 1));
//    }
//    return answer;
//}


//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//
//vector<long long> solution(vector<long long> numbers) {
//    vector<long long> answer;
//    // 레퍼런스로 받으면 복사하지 않는 다는 뜻 같음, 레퍼런스 없이 그냥 사용해도 복사하지 않아서 큰 차이를 모르겠음
//    for (ll& n : numbers) {
//        // ~n = 1의 보수, -~n = 1의 보수의 2의 보수 - 값이 1 커짐
//        // -~n = 1감소, ~-n = 1증가
//        // 아래 AND 연산을 하면 1을 더했을 때 올려진 자리 부분만 1인 비트가 나옴
//        ll idx = (~n & -~n);
//        // 해당 인덱스를 더해주고 한 자리 아래를 빼주면 2비트가 차이나면서 원래 값보다 큰 수 중 최솟값이 됨 (1의 자리부터 1이 연속되는 곳이 끝나는 부분에서 1자리 올림한 것과 같음)
//        ll ans = n + idx - (idx >> 1);
//        answer.push_back(ans);
//    }
//    return answer;
//}