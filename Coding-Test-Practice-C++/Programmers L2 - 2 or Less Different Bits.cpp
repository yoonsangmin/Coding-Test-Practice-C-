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

//// �ٸ� ��� Ǯ��
//#include <vector>
//std::vector<long long> solution(std::vector<long long> numbers) {
//    std::vector<long long> answer;
//    for (long long number : numbers) {
//        long long bit = 1;
//        while ((number & bit) > 0) bit <<= 1;
//        // 1�� �ڸ��� ��� ���������� ��Ʈ ������ �ϸ� 0�� �ż� �״�� �ᵵ ��
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
//    // ���۷����� ������ �������� �ʴ� �ٴ� �� ����, ���۷��� ���� �׳� ����ص� �������� �ʾƼ� ū ���̸� �𸣰���
//    for (ll& n : numbers) {
//        // ~n = 1�� ����, -~n = 1�� ������ 2�� ���� - ���� 1 Ŀ��
//        // -~n = 1����, ~-n = 1����
//        // �Ʒ� AND ������ �ϸ� 1�� ������ �� �÷��� �ڸ� �κи� 1�� ��Ʈ�� ����
//        ll idx = (~n & -~n);
//        // �ش� �ε����� �����ְ� �� �ڸ� �Ʒ��� ���ָ� 2��Ʈ�� ���̳��鼭 ���� ������ ū �� �� �ּڰ��� �� (1�� �ڸ����� 1�� ���ӵǴ� ���� ������ �κп��� 1�ڸ� �ø��� �Ͱ� ����)
//        ll ans = n + idx - (idx >> 1);
//        answer.push_back(ans);
//    }
//    return answer;
//}