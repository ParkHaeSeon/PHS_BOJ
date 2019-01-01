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
	long long R = 0, B = 0;

	scanf("%lld %lld", &R, &B);

	long long sum = R + B;

	for (long long i = 3; i <= sum / 2; i++)
	{
		if (i < sum / i) continue;
		
		if (sum % i == 0)
		{
			long long j = sum / i;

			long long b = (i - 2) * (j - 2);

			long long r = sum - b;

			if (b == B && r == R)
			{
				printf("%lld %lld\n", i, j);

				return 0;
			}
		}
	}

	return 0;
}