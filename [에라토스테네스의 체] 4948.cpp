#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 2 * 123456 + 1

bool prime[MAX] = { true, };

void primeNumber() // 소수이면 true, 소수가 아니면 false
{
	int sqrtMax = sqrt(MAX);

	for (int i = 2; i <= sqrtMax; i++)
	{
		if (!prime[i]) continue;

		for (int j = 2 * i; j <= MAX; j += i)
		{
			prime[j] = false;
		}
	}
}

int main(void)
{
	memset(prime, true, sizeof(prime));

	primeNumber();

	int N = 0, ans = 0;

	while (1)
	{
		scanf("%d", &N);

		if (N == 0) break;

		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (prime[i]) ++ans;
		}

		printf("%d\n", ans);

		ans = 0;
	}

	return 0;
}