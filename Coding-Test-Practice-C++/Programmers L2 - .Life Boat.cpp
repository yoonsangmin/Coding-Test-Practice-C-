//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//// 내 풀이
//// 반대로 생각을 했다. 큰 거 부터 보내고 작은 거 같이 보낼 수 있을 때 보내면 간단한데
//// 작은 거 보내고 큰 거 같이 못 보내면 못 보낸 만큼 따로 answer에 더해줬다.
//// 시간이 더 적게 걸리거나 하진 않았다.
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

// 다른 사람 풀이

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	// 배운 사람들은 answer 대신에 res 또는 ret을 많이 쓰는 모양 result, return
	int res = 0;
	// 그리고 배운 사람들은 클래스의 멤버 변수를 많이 부르지 않기 위해서인지 코드 가독성을 위해서인지 새로운 변수로 선언을 많이 함 size, N
	// 아마 컴파일러 구조 상 지역 변수이기 때문에 스택 영역에 저장 - 공간 차지는 매우 조금이라 괜찮
	// 반대로 변수 선언 안하고 사용해도 한 번 호출하면 캐시에 저장돼서 속도는 별로 차이 안 날 것 같음 - 클래스 멤버 변수 접근이 더 느리다고 함
	// https://complexz.tistory.com/5
	int N = people.size();
	sort(people.begin(), people.end(), greater<>());

	//// 같은 라인인데 리버스라는 기능도 있다는 걸 상기 시키기 위해 적어봄
	//// 시간은 좀 더 오래 걸림
	//sort(people.begin(), people.end());
	//reverse(people.begin(), people.end());

	// for 문 조건에 변수 초기화 한 번에 해보기
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