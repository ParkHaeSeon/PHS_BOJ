#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
	char s[6][17];

	int MAX = -1;

	for (int i = 0; i < 5; i++)
	{
		scanf("%s", s[i]);

		MAX = max(MAX, (int)strlen(s[i]));
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= strlen(s[j])) continue;

			printf("%c", s[j][i]);
		}
	}

	printf("\n");

	return 0;
}