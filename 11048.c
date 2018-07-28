#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int room[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int N = 0; // 세로 = y
int M = 0; // 가로 = x

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &room[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + room[i][j];
		}
	}

	printf("%d\n", dp[N][M]);

	return 0;
}
