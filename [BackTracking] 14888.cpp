#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;

int A[13] = { 0, };

int oper[4] = { 0, };

int max_num = -987654321, min_num = 987654321;

void DFS(int pos, int sum)
{
	if (pos == N - 1)
	{
		max_num = max(max_num, sum);
		min_num = min(min_num, sum);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] != 0)
		{
			if (i == 0)
			{
				oper[i]--;
				DFS(pos + 1, sum + A[pos + 1]);
				oper[i]++;
			}
			else if (i == 1)
			{
				oper[i]--;
				DFS(pos + 1, sum - A[pos + 1]);
				oper[i]++;
			}
			else if (i == 2)
			{
				oper[i]--;
				DFS(pos + 1, sum * A[pos + 1]);
				oper[i]++;
			}
			else if (i == 3)
			{
				oper[i]--;
				DFS(pos + 1, sum / A[pos + 1]);
				oper[i]++;
			}
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &oper[i]);
	}

	DFS(0, A[0]);

	printf("%d\n%d\n", max_num, min_num);

	return 0;
}