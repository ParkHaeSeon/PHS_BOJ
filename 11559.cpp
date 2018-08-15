// https://www.acmicpc.net/problem/11559

// BOJ 11559 Puyo Puyo

#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

char map[12][6];

bool visit[12][6] = { false, };

int len = 0;

int cnt = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void DFS(int row, int column, char character)
{
	++len;

	visit[row][column] = true;

	for (int i = 0; i < 4; i++)
	{
		int y = row + dy[i];
		int x = column + dx[i];

		if (0 <= y && y < 12 && 0 <= x && x < 6 && !visit[y][x] && map[y][x] == character)
		{
			DFS(y, x, character);
		}
	}
}

void mapEdit(int row, int column, char character) // DFS
{
	map[row][column] = '.';

	for (int i = 0; i < 4; i++)
	{
		int y = row + dy[i];
		int x = column + dx[i];

		if (0 <= y && y < 12 && 0 <= x && x < 6 && map[y][x] == character)
		{
			mapEdit(y, x, character);
		}
	}
}

int main(void)
{
	int ans = 0;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> map[i][j];
		}
	}

	while (true)
	{
		memset(visit, false, sizeof(visit));

		cnt = 0;

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (!visit[i][j] && map[i][j] != '.') // Before DFS, Remember condition
				{
					len = 0;

					DFS(i, j, map[i][j]);

					if (len >= 4)
					{
						++cnt;

						mapEdit(i, j, map[i][j]); // from character to '.'
					}
				}
			}
		}

		// map change
		for (int column = 0; column < 6; column++)
		{
			for (int row = 11; row >= 0; row--)
			{
				if (map[row][column] == '.')
				{
					int replace_row = row - 1;

					while (replace_row - 1 >= 0 && map[replace_row][column] == '.')
					{
						--replace_row;

						if (map[replace_row][column] != '.')
						{
							swap(map[replace_row][column], map[row][column]);

							break;
						}
					}
			}
		}

		if (cnt == 0) break;
		else ++ans;
	}

	printf("%d\n", ans);

	return 0;
}