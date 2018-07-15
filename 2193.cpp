#include <cstdio>
#include <iostream>

long long dp[91] = { 0, };
int N = 0;

long long fibo(int n)
{
	if (n <= 2) return 1;

	if (dp[n] != 0) return dp[n];

	dp[n] = fibo(n - 1) + fibo(n - 2);

	return dp[n];
}

int main(void)
{
	int sum = 0;

	scanf("%d", &N);

	printf("%lld\n", fibo(N));

	return 0;
}