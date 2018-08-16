#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int num[10000 + 1] = { 0, };

int N = 0;

int max_num = 0;

void sortNum()
{
	for (int i = 1; i <= max_num; i++)
	{
		if (num[i] == 0) continue;

		for (int j = 0; j < num[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}

int main(void)
{
	int input_num = 0;

	scanf("%d", &N);

	while (N--)
	{
		scanf("%d\n", &input_num);

		max_num = max(max_num, input_num);

		++num[input_num];
	}
	
	sortNum();

	return 0;
}