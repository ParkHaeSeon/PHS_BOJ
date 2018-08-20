#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int X = 0;

int main(void)
{
	int ans = 0;

	int len = 64;

	scanf("%d", &X);

	while (X != 0)
	{
		if (X % 2 == 1) ++ans;

		X /= 2;
	}

	/*while (X > 0)
	{
		if (len > X) len /= 2;
		else
		{
			++ans;
			X -= len;
		}
	}*/

	printf("%d\n", ans);

	return 0;
}
