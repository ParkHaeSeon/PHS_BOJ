#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;

int arr[101][101] = { 0, };
int result[101][101] = { 0, };

bool visit[101] = { false, };

void DFS(int start, int next_vertex)
{
	if (visit[next_vertex]) return;

	visit[next_vertex] = true;

	result[start][next_vertex] = 1;

	for (int i = 0; i < N; i++)
	{
		if (arr[next_vertex][i] == 1)
		{
			DFS(start, i);
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1)
			{
				memset(visit, false, sizeof(visit));
				DFS(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", result[i][j]);
		}

		printf("\n");
	}

	return 0;
}