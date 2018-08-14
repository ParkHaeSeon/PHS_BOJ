#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

int N = 0, S = 0;
int num[21] = { 0, };
int result = 0;

void DFS_BackTracking(int cnt, int sum)
{
	if (cnt == N)
	{
		if (sum == S)
		{
			++result;
		}

		return;
	}

	DFS_BackTracking(cnt + 1, sum + num[cnt]);

	DFS_BackTracking(cnt + 1, sum);
}

void other_solving_DFS_BackTracking(int index, int sum)
{
	sum += num[index];

	if (index >= N) return;

	if (sum == S) ++result;

	other_solving_DFS_BackTracking(index + 1, sum - num[index]);
	other_solving_DFS_BackTracking(index + 1, sum);
}

int main(void)
{
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	DFS_BackTracking(0, 0);

	if (S == 0) --result;

	printf("%d\n", result);

	/*
	other_solving_DFS_BackTracking(0, 0);

	printf("%d\n", result);
	*/

	return 0;
}