#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

bool visit[10001] = { false, };

int twelve(int n)
{
	int ret = 0;

	while (n != 0)
	{
		ret += n % 12;

		n /= 12;
	}

	return ret;
}

int sixteen(int n)
{
	int ret = 0;

	while (n != 0)
	{
		ret += n % 16;

		n /= 16;
	}

	return ret;
}

void four()
{
	for (int i = 2992; i < 10000; i++)
	{
		int one = i % 10;

		int ten = (i / 10) % 10;

		int hun = (i / 100) % 10;

		int tho = (i / 1000) % 10;

		int sum = one + ten + hun + tho;

		if (sum == twelve(i) && sum == sixteen(i))
		{
			visit[i] = true;
		}
	}
}

int main(void)
{
	four();

	for (int i = 2992; i < 10000; i++)
	{
		if (visit[i]) printf("%d\n", i);
	}

	return 0;
}