//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//// �� Ǯ��
//// �ݴ�� ������ �ߴ�. ū �� ���� ������ ���� �� ���� ���� �� ���� �� ������ �����ѵ�
//// ���� �� ������ ū �� ���� �� ������ �� ���� ��ŭ ���� answer�� �������.
//// �ð��� �� ���� �ɸ��ų� ���� �ʾҴ�.
//int solution(vector<int> people, int limit) {
//    int left = 0;
//    int right = people.size() - 1;
//	int answer = 0;
//
//	sort(people.begin(), people.end());
//
//	while (true)
//	{
//		if (people[left] > limit / 2)
//		{
//			answer += right - left + 1;
//			break;
//		}
//
//		int pass = 0;
//
//		while (people[left] + people[right - pass] > limit && left < right - pass)
//		{
//			pass++;
//		}
//
//		answer += pass;
//		right = right - pass - 1;
//		
//		answer++;
//		left++;
//
//		if (left > right)
//		{
//			break;
//		}
//		else if (left == right)
//		{
//			answer++;
//
//			break;
//		}
//	}
//    return answer;
//}

// �ٸ� ��� Ǯ��

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	// ��� ������� answer ��ſ� res �Ǵ� ret�� ���� ���� ��� result, return
	int res = 0;
	// �׸��� ��� ������� Ŭ������ ��� ������ ���� �θ��� �ʱ� ���ؼ����� �ڵ� �������� ���ؼ����� ���ο� ������ ������ ���� �� size, N
	// �Ƹ� �����Ϸ� ���� �� ���� �����̱� ������ ���� ������ ���� - ���� ������ �ſ� �����̶� ����
	// �ݴ�� ���� ���� ���ϰ� ����ص� �� �� ȣ���ϸ� ĳ�ÿ� ����ż� �ӵ��� ���� ���� �� �� �� ���� - Ŭ���� ��� ���� ������ �� �����ٰ� ��
	// https://complexz.tistory.com/5
	int N = people.size();
	sort(people.begin(), people.end(), greater<>());

	//// ���� �����ε� ��������� ��ɵ� �ִٴ� �� ��� ��Ű�� ���� ���
	//// �ð��� �� �� ���� �ɸ�
	//sort(people.begin(), people.end());
	//reverse(people.begin(), people.end());

	// for �� ���ǿ� ���� �ʱ�ȭ �� ���� �غ���
	for (int i = 0, j = N - 1; i <= j; i++)
	{
		if (people[i] + people[j] <= limit)
		{
			j--;
		}

		res++;
	}

	return res;
}