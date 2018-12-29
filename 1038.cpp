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

long long ans[10] = { 0, };

void calc(long long n, long long p)
{
	while (n > 0)
	{
		ans[n % 10] += p;
		n /= 10;
	}
}

int main(void)
{
	long long Start = 1;
	long long End = 0;
	long long p = 1;

	scanf("%lld", &End);

	while (Start <= End)
	{
		while (Start % 10 != 0 && Start <= End)
		{
			calc(Start, p);
			++Start;
		}

		if (Start > End) break;

		while (End % 10 != 9 && Start <= End)
		{
			calc(End, p);
			--End;
		}

		long long cnt = (End / 10 - Start / 10 + 1);

		for (int i = 0; i <= 9; i++)
		{
			ans[i] += cnt*p;
		}

		Start /= 10;
		End /= 10;
		p *= 10LL;
	}

	for (int i = 0; i <= 9; i++)
	{
		printf("%d ", ans[i]);
	}

	printf("\n");

	return 0;
}