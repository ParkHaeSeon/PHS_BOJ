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

bool num[1001] = { false, };

void HanSoo()
{
	for (int i = 1; i <= 999; i++)
		if (i <= 99) num[i] = true;	
		else if (100 <= i && i <= 999)
		{
			int hun = i / 100;
			int ten = (i % 100) / 10;
			int one = (i % 100) % 10;

			if (hun - ten == ten - one)
				if (one - ten == ten - hun)
					num[i] = true;			
		}
}

int main(void)
{
	int N = 0, cnt = 0;

	HanSoo();

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		if (num[i]) ++cnt;
	
	printf("%d\n", cnt);

	return 0;
}