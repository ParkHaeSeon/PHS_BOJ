#include <stdio.h>
#include <malloc.h>



int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int main(void)
{
	int n, i, grape[10001] = { 0, };
	int Dp[10001] = { 0, };

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &grape[i]);
	}

	Dp[1] = grape[1];

	Dp[2] = grape[1] + grape[2];

	if (n == 1 || n == 2)
	{
		printf("%d\n", Dp[n]);
		return 0;
	}

	for (i = 3; i <= n; i++)
	{
		Dp[i] = max(max(Dp[i-3]+grape[i - 1] + grape[i], Dp[n - 1]), Dp[i - 2]+ grape[i]);
		Dp[i] = max(Dp[i], Dp[i - 1]);
	}

	printf("%d\n", Dp[n]);

	return 0;
}