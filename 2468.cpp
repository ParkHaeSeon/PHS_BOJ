#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int visit[101][101] = { 0, };
int region[101][101] = { 0, };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N = 0;

int MIN = 987654321;
int MAX = -987654321;
int safe_Cnt = -987654321;
int Connected_Component = 1;

void beforeBFS(int m)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (region[i][j] <= m) // 이하
			{
				region[i][j] = 0; // 물에 잠김 = 0
			}
		}
	}
}

void DFS(int start, int end)
{
	visit[start][end] = 1; // 방문 처리

	for (int i = 0; i < 4; i++)
	{
		int y = start + dy[i];
		int x = end + dx[i];

		if (y <= 0 || x <= 0 || y > N || x > N || region[y][x] == 0 || visit[y][x] == 1) continue;

		DFS(y, x);
	}
}

int main(void)
{
	int a = 0, b = 0;

	scanf("%d\n", &N);

	for (int i = 1; i <= N; i++) // 세로
	{
		for (int j = 1; j <= N; j++) // 가로
		{
			scanf("%d", &region[i][j]);

			MIN = min(MIN, region[i][j]);
			MAX = max(MAX, region[i][j]);
		}
	}

	if (MIN == MAX)
	{
		printf("1\n");

		return 0;
	}

	for (int i = MIN; i <= MAX; i++)
	{
		Connected_Component = 0;

		memset(visit, 0, sizeof(visit));

		beforeBFS(i);

		for (a = 1; a <= N; a++)
		{
			for (b = 1; b <= N; b++)
			{
				if (region[a][b] != 0 && visit[a][b] == 0)
				{
					++Connected_Component;

					DFS(a, b);
				}
			}
		}

		safe_Cnt = max(safe_Cnt, Connected_Component);
	}

	printf("%d\n", safe_Cnt);

	return 0;
}
