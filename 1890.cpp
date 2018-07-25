#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

long long game[101][101] = { 0, };
long long dp[101][101] = { 0, };

int N = 0; // 게임 판의 크기

void Path()
{
	dp[1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dp[i][j] == 0 || game[i][j] == 0 || (i==N && j==N)) continue;

			int dist = game[i][j];

			int right = dist + j;

			int down = dist + i;

			if (right <= N)
			{
				dp[i][right] += dp[i][j];
			}

			if (down <= N)
			{
				dp[down][j] += dp[i][j];
			}
		}
	}

	printf("%lld\n", dp[N][N]);
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%lld", &game[i][j]);
		}
	}

	Path();


	return 0;
}