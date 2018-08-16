#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int N = 0;
int num[1001] = { 0, };
int dp[1001] = { 0, };

using namespace std;

// https://www.acmicpc.net/problem/11055

int main(void)
{
	int max = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i] = num[i];

		for (int j = 1; j < i; j++)
		{
			if (num[i] > num[j] && dp[j] + num[i] > dp[i])
			{
				dp[i] = dp[j] + num[i];
			}
		}

		if (max < dp[i]) max = dp[i];
	}

	printf("%d\n", max);

	return 0;
}
