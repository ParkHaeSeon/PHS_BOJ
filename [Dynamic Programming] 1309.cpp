#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/1309

int N = 0;

long long dp[100001][3] = { 0, };

long long animal[100001][3] = { 0, };

int main(void)
{
	long long Sum = 0;

	scanf("%d", &N);


	for (int i = 0; i <= 2; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][0] % 9901 + dp[i - 1][1] % 9901 + dp[i - 1][2] % 9901;

		dp[i][1] = dp[i - 1][0] % 9901 + dp[i - 1][2] % 9901;

		dp[i][2] = dp[i - 1][0] % 9901 + dp[i - 1][1] % 9901;
	}

	Sum = dp[N][0] % 9901 + dp[N][1] % 9901 + dp[N][2] % 9901;

	printf("%d\n", Sum % 9901);

	return 0;
}
