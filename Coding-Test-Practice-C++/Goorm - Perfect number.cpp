#include <iostream>
using namespace std;
int main() {
	int start = 0, end = 0;
	cin >> start >> end;

	for (int i = start; i <= end; i++)
	{
		if (i == 1)
			continue;

		int sum = 1;

		int last = i;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				if (last == j)
					break;

				sum += j;
				sum += i / j;

				last = i / j;
			}
		}

		if (sum == i)
		{
			cout << i << " ";
		}
	}

	return 0;
}