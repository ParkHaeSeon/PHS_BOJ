#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int map[303][303] = { 0, };
int copy_map[303][303] = { 0, };

int N = 0, M = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

bool visit[303][303] = { false, };

int cnt = 0;

int connection = 0;

void afterTime(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int y = r + dy[i];
		int x = c + dx[i];

		if (y >= 0 && y < N && x >= 0 && x < M && map[y][x] == 0)
		{
			++cnt;
		}
	}
}

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copy_map[i][j] = map[i][j];
		}
	}
}

void counter_init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = copy_map[i][j];
		}
	}
}

bool zero_check()
{
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0)
			{
				++ret;
			}
		}
	}

	if (ret == 0) return true;
	else return false;
}

void DFS(int r, int c)
{
	visit[r][c] = true;

	for (int i = 0; i < 4; i++)
	{
		int y = r + dy[i];
		int x = c + dx[i];

		if (y >= 0 && y < N && x >= 0 && x < M && map[y][x] != 0 && !visit[y][x])
		{
			DFS(y, x);
		}
	}
}

int main(void)
{
	int ans = 0;

	memset(map, 0, sizeof(map));

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	while (true)
	{
		memset(visit, false, sizeof(visit));

		connection = 0;

		if (zero_check())
		{
			if (ans >= 1) ans = 0;
			break;
		}

		init();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] != 0)
				{
					cnt = 0;

					afterTime(i, j);

					copy_map[i][j] -= cnt;

					if (copy_map[i][j] <= 0) copy_map[i][j] = 0;
				}
			}
		}

		++ans;

		counter_init();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visit[i][j] && map[i][j] != 0)
				{
					++connection;

					DFS(i, j);
				}
			}

		}

		if (connection >= 2) break;
	}

	printf("%d\n", ans);
	
	return 0;
}