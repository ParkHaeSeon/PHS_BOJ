#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

// 복습 필수
// https://www.acmicpc.net/problem/14890

int N = 0, L = 0;

int map[102][102] = { 0, };

int makePath_row(int row)
{
	int ret = 0;

	if (row == N)
	{
		return ret;
	}

	bool chk = true;

	int cnt = 1;

	for (int column = 0; column < N - 1; column++)
	{
		if (map[row][column] == map[row][column + 1])
		{
			cnt++;

			continue;
		}

		if (map[row][column + 1] - map[row][column] == 1)
		{
			if (cnt >= L)
			{
				cnt = 1;
			}
			else
			{
				chk = false;
				break;
			}

			continue;
		}

		if (map[row][column] - map[row][column + 1] == 1)
		{
			if (column + L >= N)
			{
				chk = false;
				break;
			}

			for (int t = 1; t <= L; t++)
			{
				if (map[row][column + t] != map[row][column + 1])
				{
					chk = false;
					break;
				}
			}

			if (!chk) break;

			cnt = 0;

			// important code for time saving
			column = column + L - 1;

			continue;
		}

		chk = false; // 2 이상 차이나는 경우 위의 if문에서 걸리는 것이 없기 때문에 바로 break
		break;
	}

	if (chk) ret += 1;

	ret += makePath_row(row + 1);

	return ret;
}

int makePath_column(int column)
{
	int ret = 0;

	if (column == N)
	{
		return ret;
	}

	bool chk = true;

	int cnt = 1;

	for (int row = 0; row < N - 1; row++)
	{
		if (map[row][column] == map[row + 1][column])
		{
			++cnt;
			continue;
		}

		if (map[row + 1][column] - map[row][column] == 1)
		{
			if (cnt >= L)
			{
				cnt = 1;
			}
			else
			{
				chk = false;
				break;
			}

			continue;
		}

		if (map[row][column] - map[row + 1][column] == 1)
		{
			if (row + L >= N)
			{
				chk = false;
				break;
			}

			for (int t = 1; t <= L; t++)
			{
				if (map[row + 1][column] != map[row + t][column])
				{
					chk = false;
					break;
				}
			}

			if (!chk) break;

			cnt = 0;

			// important code for time saving
			row = row + L - 1;

			continue;
		}

		chk = false; // 2 이상 차이나는 경우 위의 if문에서 걸리는 것이 없기 때문에 바로 break
		break;
	}


	if (chk) ret += 1;

	ret += makePath_column(column + 1);

	return ret;
}

int main(void)
{
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	int total = 0;

	total = makePath_row(0) + makePath_column(0);

	printf("%d\n", total);

	return 0;
}
