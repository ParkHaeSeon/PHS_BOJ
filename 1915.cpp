#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int sq[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int n = 0, m = 0;

int main(void)
{
	int MAX = 0;

	memset(sq, 0, sizeof(sq));
	memset(dp, 0, sizeof(dp));

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &sq[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (sq[i][j] != 0)
			{
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), + dp[i][j - 1]) + 1;
				MAX = max(dp[i][j], MAX);
			}
		}
	}

	printf("%d\n", MAX*MAX);

	return 0;
}