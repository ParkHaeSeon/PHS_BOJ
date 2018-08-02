// https://www.acmicpc.net/problem/15683

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[101][101] = { 0, };
int visit[101][101] = { -1, };

int r = 0;
int c = 0;

int hour = 0;
int cnt = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int Check()
{
	int ret = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 2)
			{
				++ret;

				map[i][j] = 0;
			}
		}
	}

	return ret;
}

void DFS(int row, int column)
{
	visit[row][column] = 1;

	for (int i = 0; i < 4; i++)
	{
		int y = row + dy[i];
		int x = column + dx[i];

		if (y >= 0 && y < r && x >= 0 && x < c && map[y][x] == 0 && visit[y][x] == -1)
		{
			DFS(y, x);
		}

		if (map[y][x] == 1) map[y][x] = 2;
	}
}

int main()
{
	int cnt_tmp = 0;

	memset(map, 0, sizeof(map));

	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	while (1)
	{
		memset(visit, -1, sizeof(visit));

		DFS(0, 0);

		cnt_tmp = Check();

		if (cnt_tmp == 0) break;

		++hour;

		cnt = cnt_tmp;
	}

	printf("%d\n", hour);
	printf("%d\n", cnt);

	return 0;
}