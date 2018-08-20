#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int in[4] = { 0, };
int out[4] = { 0, };

int main(void)
{
	int MAX = 0;
	
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &out[i], &in[i]);
	}

	int ans[4] = { 0, };

	ans[0] = in[0];

	/*
	ans[1] = ans[0] + in[1] - out[1];
	ans[2] = ans[1] + in[2] - out[2];
	ans[3] = ans[2] + in[3] - out[3];
	*/

	for (int i = 1; i < 4; i++)
	{
		ans[i] = ans[i - 1] + in[i] - out[i];

		MAX = max(MAX, ans[i]);
	}

	printf("%d\n", MAX);

	return 0;
}
