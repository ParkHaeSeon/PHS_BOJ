#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/11052

int P[10001] = { 0, };
int dp[10001] = { 0, }; 

// dp[i] : 붕어빵 i개를 팔 때, 얻을 수 있는 최대 수익

int N = 0;

int main(void)
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &P[i]);
	}

	dp[1] = P[1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}
