#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int temp = 1;
	int sum = 0;

	while (temp <= (n / temp))
	{
		if (n % temp == 0)
		{
			sum += temp;
			if(temp != n / temp)
				sum += (n / temp);
		}
		++temp;
	}

	cout << sum;

	return 0;
}