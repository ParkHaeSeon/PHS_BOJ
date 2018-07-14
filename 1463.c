#include <stdio.h>
#include <stdbool.h>

int dp[1000001];

int min(int a, int b)
{
	if (a <= b) return a;
	else return b;
}

int main(void)
{
	int input=0, n=0, i=0;

	scanf("%d", &input);

	dp[1] = 0;

	for (i = 2; i <= input; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);

		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);

	}

	printf("%d\n", dp[input]);

	return 0;
}
