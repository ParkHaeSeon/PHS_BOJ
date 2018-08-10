#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int r = 0, c = 0;

int map[101][101]{ 0, };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

bool visit[101][101] = { false, };

void DFS(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y < 0 || Y >= r || X < 0 || X >= c || visit[Y][X]) continue;

		if (map[Y][X] == 0)
		{
			DFS(Y, X);
		}

		if (map[Y][X] == 1)
		{
			map[Y][X] = 2;
		}	
	}
}

int chageCheese()
{
	int cnt = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 2)
			{
				++cnt;

				map[i][j] = 0;
			}
		}
	}

	return cnt;
}

int main(void)
{
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	int time = 0;
	int save_num = 0;

	while (1)
	{
		memset(visit, false, sizeof(visit));

		DFS(0, 0);

		int num = chageCheese();

		if (num == 0) break;

		save_num = num;

		++time;
	}

	printf("%d\n%d\n", time, save_num);

	return 0;
}
