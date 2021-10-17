#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;

	int prev_pizza = 0, sum_pizza = n;
	while (prev_pizza != sum_pizza)
	{
		prev_pizza = sum_pizza;

		sum_pizza = n + sum_pizza / m;
	}

	cout << sum_pizza;

	return 0;
}