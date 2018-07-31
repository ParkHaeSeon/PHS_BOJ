#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int map[101][101] = { 0, };

int visit[101][101] = { 0, };

int N = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int Connected_Component = 0;

void full(int water)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] <= water)
			{
				map[i][j] = 0; // be full of water(=0)
			}
		}
	}
}

void DFS(int y, int x)
{
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y <= 0 || Y > N || X <= 0 || X > N || map[Y][X] == 0 || visit[Y][X] == 1) continue;

		DFS(Y, X);
	}
}

int main(void)
{
	int MIN = 987654321, MAX = -987654321, ans = -987654321;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);

			MIN = min(MIN, map[i][j]);
			MAX = max(MAX, map[i][j]);
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

		full(i);

		for (int a = 1; a <= N; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				if (map[a][b] != 0 && visit[a][b] == 0)
				{
					++Connected_Component;

					DFS(a, b);
				}
			}
		}

		ans = max(ans, Connected_Component);
	}
	
	printf("%d\n", ans);

	return 0;
}
