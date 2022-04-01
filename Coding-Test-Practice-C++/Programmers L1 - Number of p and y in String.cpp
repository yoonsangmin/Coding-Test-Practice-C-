#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int p = 0;
	int y = 0;

	for (char letter : s)
	{
		if (letter == 'p' || letter == 'P')
			p++;
		else if (letter == 'y' || letter == 'Y')
			y++;
	}

    return p == y ? true : false;
}