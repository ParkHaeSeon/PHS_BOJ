#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int sudoku[10][10] = { 0, }; // input

bool width[10][10] = { false, }; // same row line 1 ~ 9 exist bool

bool height[10][10] = { false, }; // same column line  1 ~ 9 exist bool

bool square[10][10] = { false, }; // same square place  1 ~ 9 exist bool

bool complete = false;

vector<pair<int, int> > v; // zero position (y, x) push

void square_check(int r, int c, int area)
{
	for (int i = r; i < r + 3; i++)
	{
		for (int j = c; j < c + 3; j++)
		{
			square[area][sudoku[i][j]] = true;			
		}
	}
}

void DFS_BackTracking(int Cnt)
{
	if (complete) return;

	if (Cnt == v.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", sudoku[i][j]);
			}

			printf("\n");
		}

		complete = true;

		return;
	}

	int y = v[Cnt].first;
	int x = v[Cnt].second;
	int area = 3 * (y / 3) + (x / 3);

	for (int i = 1; i <= 9; i++)
	{
		if (!width[y][i] && !height[x][i] && !square[area][i])
		{
			width[y][i] = true;
			height[x][i] = true;
			square[area][i] = true;
			sudoku[y][x] = i;

			DFS_BackTracking(Cnt + 1);

			width[y][i] = false;
			height[x][i] = false;
			square[area][i] = false;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &sudoku[i][j]);

			width[i][sudoku[i][j]] = true;
			height[j][sudoku[i][j]] = true;

			if (sudoku[i][j] == 0)
			{
				v.push_back({ i ,j });
			}
		}
	}

	int cnt = -1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			++cnt;

			square_check(i * 3, j * 3, cnt);
		}
	}

	DFS_BackTracking(0);

	return 0;
}