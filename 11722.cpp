#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int N = 0; // 수열의 크기
int num[1001] = { 0, };
int dp[1001] = { 0, };

using namespace std;

int main(void)
{
	int MIN = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;

		for (int j = 1; j < i; j++)
		{
			if (num[i] < num[j] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}

		if (MIN < dp[i]) MIN = dp[i];
	}

	printf("%d\n", MIN);

	return 0;
}