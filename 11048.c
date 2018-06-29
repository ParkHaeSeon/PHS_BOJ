#include <stdio.h>
#include <malloc.h>

int room[1001][1001];
int Dp[1001][1001];

int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int main(void)
{
	int N, M, i, j, Max=0;

	scanf("%d %d", &N, &M);


	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%d", &room[i][j]);
		}
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			Max = max(max(Dp[i - 1][j], Dp[i][j - 1]), Dp[i - 1][j - 1]);
			Dp[i][j] = Max + room[i][j];
		}
	}

	printf("%d\n", Dp[N][M]);


	return 0;
}