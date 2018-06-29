#include <stdio.h>
#include <malloc.h>

int num[100001];
int Max[100001];
int var=0;

int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int main(void)
{
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	
	Max[0] = num[0];

	for (i = 1; i < n; i++)
	{
		if (Max[i - 1] + num[i] > num[i]) Max[i] = Max[i - 1] + num[i];
		else Max[i] = num[i];
	}

	var = Max[0];

	for (i = 1; i < n; i++)
	{
		if (var <= Max[i]) var = Max[i];
	}


	printf("%d\n", var);

	return 0;
}