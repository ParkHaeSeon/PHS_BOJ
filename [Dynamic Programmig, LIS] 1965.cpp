#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int N = 0; // 수열의 크기
int num[1001] = { 0, };
int dp[1001] = { 0, };

using namespace std;

// https://www.acmicpc.net/problem/1965

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
		dp[i] = 1; // 길이(숫자 하나 당 그 길이를 1로 본다.)

		for (int j = 1; j < i; j++) // 그 전의 것들을 하나씩 다 비교. i-1까지.
		{
			if (num[i] > num[j] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}

		if (max < dp[i]) max = dp[i];
	}

	printf("%d\n", max);

	return 0;
}
