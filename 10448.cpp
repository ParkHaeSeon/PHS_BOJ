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

int Eureka[303] = { 0, };
int result[5050] = { 0, };

int main(void)
{
	int T = 0;

	for (int i = 1; i <= 300; i++)
	{
		Eureka[i] = i*(i + 1) / 2;
	}

	for (int a = 1; a <= 300; a++)
	{
		for (int b = 1; b <= 300; b++)
		{
			for (int c = 1; c <= 300; c++)
			{
				if (Eureka[a] + Eureka[b] + Eureka[c] > 5000) continue;

				result[Eureka[a] + Eureka[b] + Eureka[c]] = 1;
			}
		}
	}

	scanf("%d", &T);

	while(T--)
	{
		int n = 0;

		scanf("%d", &n);

		if (result[n] == 0) printf("0\n");
		else printf("1\n");
	}

	return 0;
}
