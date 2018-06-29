#include <stdio.h>
#include <malloc.h>

int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int main(void)
{
	int input, i, j;
	int *fishper, *sum;
	int fishcount;

	scanf("%d", &fishcount);

	fishper = (int)malloc(sizeof(int)*(fishcount+1));
	sum = (int)malloc(sizeof(int)*(fishcount+1));

	for (i = 1; i <= fishcount; i++)
	{
		scanf("%d", &fishper[i]);
	}

	sum[0] = 0;

	for (i = 1; i <= fishcount; i++)
	{
		sum[i] = 0;

		for (j = 1; j <= i; j++)
		{
			sum[i] = max(sum[i - j] + fishper[j], sum[i]);
		}
	}


	printf("%d\n", sum[fishcount]);






	return 0;
}