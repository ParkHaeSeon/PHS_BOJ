#include <stdio.h>
#include <malloc.h>

int mini = 0;

int min(int a, int b)
{
	if (a >= b) return b;
	else return a;
}

int main(void)
{
	int input = 0, i = 0, value = 0, price[3];
	int N[1000][3] = { 0, };

	scanf("%d", &input);

	scanf("%d %d %d", &N[0][0], &N[0][1], &N[0][2]);

	for (i = 1; i < input; i++)
	{
		scanf("%d %d %d", &price[0], &price[1], &price[2]);

		N[i][0] = min(N[i-1][1], N[i-1][2]) + price[0];
		N[i][1] = min(N[i-1][0], N[i-1][2]) + price[1];
		N[i][2] = min(N[i-1][0], N[i-1][1]) + price[2];
	}

	printf("%d\n", min(min(N[i-1][0], N[i-1][1]), N[i-1][2]));
	
	return 0;
}
