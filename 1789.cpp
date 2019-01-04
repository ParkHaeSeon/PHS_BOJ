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
	long long N = 0;

	scanf("%lld", &N);

	long long i = 1;

	while (1)
	{
		long long left = (i*i) / 2 - i / 2 + 2 * i;
		long long right = (i + 1)*(i + 1) / 2 - (i + 1) / 2 + 2 * (i + 1);

		if (left < N && N <= right) break;

		if (left >= N)
		{
			--i;

			break;
		}
		
		++i;
	}

	printf("%lld\n", i + 1);

	return 0;
}
