#include <stdio.h>
#include <string.h>

int T = 0; // test case
int k = 0; // floor
int n = 0; // room number

int cnt[15][15] = { 0, };

void people(int floor, int number)
{
	for (int f = 1; f <= floor; f++)
	{
		for (int f_n = 1; f_n <= number; f_n++)
		{
			cnt[f][f_n] = cnt[f][f_n - 1] + cnt[f - 1][f_n]; //[floor][room number]
		}
	}
}

int main(void)
{
	for (int i = 1; i <= 14; i++)
	{
		cnt[0][i] = i;
	}

	scanf("%d", &T);

	while (T > 0)
	{
		scanf("%d", &k);

		scanf("%d", &n);
		
		people(k, n);

		printf("%d\n", cnt[k][n]);

		--T;
	}

	return 0;
}
