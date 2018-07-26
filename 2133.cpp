#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int N = 0;

long long dp[31] = { 0, };

int main(void)
{
	scanf("%d", &N);

	dp[0] = 1;

	dp[1] = 0;

	dp[2] = 3;

	if (N % 2 == 0)
	{
		for (int i = 4; i <= N; i+=2)
		{
			dp[i] = 3 * dp[i - 2];

			for (int j = 4; i-j>=0 ;j+=2)
			{
				dp[i] += 2 * dp[i - j];
			}
		}

		printf("%lld\n", dp[N]);
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
