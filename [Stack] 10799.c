#include <stdio.h>
#include <string.h>

// https://www.acmicpc.net/problem/10799

int main(void)
{
	char s[100001];
	int sum = 0, cnt = 0, steel = 0, len = 0;

	scanf("%s", s);

	len = strlen(s);

	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(') ++cnt;
		else // )
		{
			--cnt;

			if (i>=1 && s[i - 1] == '(')
			{
				sum += cnt;
			}
			else // )
			{
				++steel;
			}
		}
	}

	printf("%d\n", sum + steel);

	return 0;
}
