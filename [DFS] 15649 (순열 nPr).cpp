#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

bool used[10] = { false, };

int num[10] = { 0, };

void DFS(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < cnt; i++)
		{
			printf("%d ", num[i]);
		}

		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			num[cnt] = i;
			DFS(cnt + 1);
			used[i] = false;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	DFS(0);

	return 0;
}
