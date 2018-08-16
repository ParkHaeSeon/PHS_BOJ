#include <cstdio>
#include <iostream>

int dp[101][10] = { 0, };
int N = 0;
long long sum = 0;

// https://www.acmicpc.net/problem/10844

void init()
{
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
}

int main(void)
{
	scanf("%d", &N);

	init();

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) dp[i][j] = dp[i-1][j + 1] % 1000000000;
			else if (j == 9) dp[i][j] = dp[i-1][j - 1] % 1000000000;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
		}
	}

	for (int k = 0; k <= 9; k++)
	{
		sum = (sum + dp[N][k]) % 1000000000;
	}

	printf("%d\n", sum%1000000000);

	return 0;
}
