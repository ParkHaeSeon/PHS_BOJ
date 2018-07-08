#include <stdio.h>
#include <malloc.h>


int min(int a, int b)
{
	if (a >= b) return b;
	else return a;
}

int main(void)
{
	int n = 0, value, i, count = 0;

	scanf("%d", &count);

	while (count--)
	{
		int Num[12] = { 0, };

		scanf("%d", &n);

		Num[0] = 1;

		for (i = 1; i <= n; i++)
		{
			if (i >= 1)
			{
				Num[i] += Num[i - 1];
			}

			if (i >= 2)
			{
				Num[i] += Num[i - 2];
			}

			if (i >= 3)
			{
				Num[i] += Num[i - 3];
			}
		}

		printf("%d\n", Num[i-1]);
	}
	

	return 0;
}
