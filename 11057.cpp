#include <cstdio>
#include <iostream>

int dp[1001][10] = { 0, };
int N = 0;
long long sum = 0;

void init()
{
	for (int i = 0; i <= 9; i++)
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
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];

				dp[i][j] %= 10007;
			}
		}
	}

	for (int k = 0; k <= 9; k++)
	{
		sum = (sum + dp[N][k]) % 10007;
	}

	printf("%d\n", sum%10007);

	return 0;
}

/*
#include <cstdio>
#include <iostream>

int dp[1001][10] = { 0, };
int N = 0;
long long sum = 0;

void init()
{
for (int i = 0; i <= 9; i++)
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
dp[i][0] = dp[i - 1][0];

for (int j = 1; j <= 9; j++)
{
dp[i][j] = (dp[i][j-1] + dp[i - 1][j]) % 10007;
}
}

for (int k = 0; k <= 9; k++)
{
sum = (sum + dp[N][k]) % 10007;
}

printf("%d\n", sum%10007);

return 0;
}
*/