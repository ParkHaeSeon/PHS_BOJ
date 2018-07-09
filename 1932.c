#include <stdio.h>
#include <malloc.h>

int t[501][501] = { 0, };
int N;

int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int main(void)
{
	int  i, j, M=0;

	scanf("%d", &N);

	/*for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &t[i][j]);
		}
	} */

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &t[i][j]);

			if (j == 1) t[i][j] = t[i-1][j] + t[i][j];
			else if (i == j) t[i][j] = t[i - 1][j - 1] + t[i][j];
			else t[i][j] = max(t[i - 1][j], t[i - 1][j - 1]) + t[i][j];

			if (M < t[i][j]) M = t[i][j];
		}
	}

	printf("%d\n", M);
	
	return 0;
}
