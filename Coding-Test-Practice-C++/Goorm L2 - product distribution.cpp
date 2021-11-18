#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	unsigned long long c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int cases_num = 0;

	cin >> cases_num;

	for (int i = 0; i < cases_num; i++)
	{
		int countries = 0;
		unsigned long long amount = 0;

		unsigned long long denominator = 1;

		cin >> countries >> amount;

		for (int j = 0; j < countries; j++)
		{
			int tax_rate = 0;

			cin >> tax_rate;

			amount = amount * 100 - amount * tax_rate;
			denominator *= 100;

			unsigned long long gcd_num = gcd(amount, denominator);

			amount /= gcd_num;
			denominator /= gcd_num;
		}

		cout << amount << '/' << denominator << endl;
	}

	return 0;
}