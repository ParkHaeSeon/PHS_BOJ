#include <stdio.h>

int one=0, zero = 0;

int fibonacci(int n)
{
	if (n == 0)
	{
		zero++;
		return 0;
	}

	else if (n == 1)
	{
		one++;
		return 1;
	}

	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main(void)
{
	int input = 0, count = 0;

	scanf("%d", &count);

	while (count > 0)
	{
		scanf("%d", &input);

		fibonacci(input);

		printf("%d %d\n", zero, one);

		zero = 0;
		one = 0;

		--count;
	}

	return 0;
}