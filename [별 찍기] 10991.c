#include <stdio.h>

// https://www.acmicpc.net/problem/10991

int main(void)
{
	int n = 0, c=0;
	int var = 0;
	int i, j, k;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = i; j < n; j++)
		{
			printf(" ");
		}

		for (k = 1; k <= 2*i-1; k++)
		{
			if(k%2 == 0) printf(" ");
			else printf("*");
		}

		printf("\n");
	}

	
	return 0;
}
