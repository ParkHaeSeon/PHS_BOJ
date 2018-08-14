#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

int N = 0;

// <string> ¡æ atoi : from char to int, stoi : from string to int

bool IsPrimeNumber(int n)
{
	if (n == 1) return false;

	int sqrtn = sqrt(n);

	for (int i = 2; i <= sqrtn; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

void BackTracking(string s, int len)
{
	if (len == N)
	{
		cout << s << '\n';
	}

	for (int i = 1; i <= 9; i++)
	{
		string temp = s;

		temp += i + '0';

		int var = stoi(temp);

		if (IsPrimeNumber( var ))
		{
			BackTracking(temp, len + 1);
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	BackTracking("", 0);

	return 0;
}