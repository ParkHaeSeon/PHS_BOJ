#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

long long N = 0, M = 0;

void getChe(long long m, long long n)
{
	long long *arr;

	arr = (long long *)malloc(sizeof(long long) * n);

	for (long long i = 2; i <= n; i++)
	{
		arr[i] = i;
	}

	long long sqrtnum = sqrt(n);

	for (long long i = 2; i <= sqrtnum; i++)
	{
		if (arr[i] == 0) continue; 

		for (long long j = 2 * i; j <= n; j += i)
		{
			arr[j] = 0;
		}
	}

	for (long long i = m; i <= n; i++)
	{
		if (i == 1 || arr[i] == 0) continue;

		printf("%lld\n", arr[i]);
	}
}

int main(void)
{
	long long M = 0, N = 0;

	scanf("%lld %lld", &M, &N);

	getChe(M, N);

	return 0;
}