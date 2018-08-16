#include <stdio.h>

// https://www.acmicpc.net/problem/10992

int main(void)
{
	int n = 0, c=0;
	int var = 0;
	int i, j, k, h;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = i; j < n; j++)
		{
			printf(" ");
		}

		if (i != n)
		{
			for (k = 1; k <= 2 * i - 1; k++)
			{
				if (k == 1 || k == 2 * i - 1) printf("*");
				else printf(" ");
			}
		}
		else
		{

			for (h = 0; h < 2 * n - 1; h++)
			{
				printf("*");
			}
		}

		printf("\n");
	}

	printf("\n");
	
	return 0;
}
