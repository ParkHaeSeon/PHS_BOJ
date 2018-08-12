#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0, M = 0, H = 0;

int a = 0, b = 0;

int map[31][12] = { 0, };

int result = -1;


void BackTracking(int cnt, int total)
{
	if (result != -1) return;

	if (cnt >= total)
	{
		for (int column = 1; column <= N; column++)
		{
			int arrive = column;

			for (int row = 1; row <= H; row++)
			{
				if (map[row][arrive] == 0) continue;

				if (map[row][arrive] > 0)
				{
					if (map[row][arrive] == 1)
					{
						++arrive;
						continue;
					}
					else
					{
						--arrive;
						continue;
					}
				}
			}

			if (arrive != column) return;
			else continue;
		}

		result = total;

		return;
	}

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (map[i][j] == 0 && map[i][j + 1] == 0)
			{
				map[i][j] = 1;
				map[i][j + 1] = 2;

				BackTracking(cnt + 1, total);

				map[i][j] = 0;
				map[i][j + 1] = 0;

			}
		}
	}
}

int main(void)
{
	// 2 ¡Â N ¡Â 10, 1 ¡Â H ¡Â 30, 0 ¡Â M ¡Â (N-1)¡¿H

	scanf("%d %d %d", &N, &M, &H); // N : column, H : row

	int input_cnt = M;

	while (input_cnt--)
	{
		scanf("%d %d", &a, &b); // a is row and (b, b+1)

		map[a][b] = 1;
		map[a][b + 1] = 2;
	}

	for (int i = 0; i < 4; i++)
	{
		BackTracking(0, i);

		if (result != -1) break;
	}

	printf("%d\n", result);

	return 0;
}