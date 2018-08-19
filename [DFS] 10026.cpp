#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int N = 0;

char map[101][101];

int cnt[3] = { 0, }; // 0 : R, 1 : G, 2 : B

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

char color[3];

bool visit[101][101] = { false, };

void DFS(int r, int c, char alpha)
{
	visit[r][c] = true;

	for (int i = 0; i < 4; i++)
	{
		int y = r + dy[i];
		int x = c + dx[i];

		if (0 <= y && y < N && 0 <= x && x < N && map[y][x] == alpha && !visit[y][x])
		{
			DFS(y, x, alpha);
		}
	}
}

int main(void)
{
	color[0] = 'R';
	color[1] = 'G';
	color[2] = 'B';

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	int three = 0;

	while (three < 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j] && color[three] == map[i][j])
				{
					++cnt[three];

					DFS(i, j, color[three]);
				}
			}
		}

		++three;
	}

	int total[2] = { 0, };
	
	total[0]= cnt[0] + cnt[1] + cnt[2];

	memset(visit, false, sizeof(visit));
	memset(cnt, 0, sizeof(cnt));

	color[0] = 'R';
	color[1] = 'B';

	int two = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'G')
			{
				map[i][j] = 'R';
			}
		}
	}

	while (two < 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j] && color[two] == map[i][j])
				{
					++cnt[two];

					DFS(i, j, color[two]);
				}
			}
		}

		++two;
	}

	total[1] = cnt[0] + cnt[1];

	for (int i = 0; i < 2; i++)
	{
		printf("%d ", total[i]);
	}

	printf("\n");

	return 0;
}
