#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
	long long n = end - begin + 1;
	vector<int> answer(n, 0);

	for (long long i = 0; i < n; i++)
	{
		long long num = begin + i;

		for (long long j = 2; j < sqrt(num); j++)
		{
			if (num % j == 0)
			{
				answer[i] = num / j;
			}
		}
	}

    return answer;
}