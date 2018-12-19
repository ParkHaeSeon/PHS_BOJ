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
	int T = 0, N = 0, M = 0, s = 0, e = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &N, &M);

		while (M--)
		{
			scanf("%d %d", &s, &e);
		}

		printf("%d\n", N - 1);
	}
	
	return 0;
}