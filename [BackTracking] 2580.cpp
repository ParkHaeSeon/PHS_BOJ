#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int map[10][10] = { 0, };

bool row[10][10] = { false, };
bool column[10][10] = { false, };
bool square[10][10] = { false, };

bool stop = false;

vector<pair<int, int> > zero;

void square_check(int y, int x, int area)
{
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			square[area][map[i][j]] = true;
		}
	}
}

void print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", map[i][j]);
		}

		printf("\n");
	}
}

void BackTracking(int index)
{
	if (stop) return;
	
	if (index == zero.size())
	{
		stop = true;

		print();

		return;
	}

	int y = zero[index].first;
	int x = zero[index].second;
	int area = 3 * (y / 3) + x / 3;

	for (int i = 1; i <= 9; i++)
	{
		if (!row[y][i] && !column[x][i] && !square[area][i])
		{
			row[y][i] = true;
			column[x][i] = true;
			square[area][i] = true;
			map[y][x] = i;

			BackTracking(index + 1);

			row[y][i] = false;
			column[x][i] = false;
			square[area][i] = false;
			map[y][x] = 0;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &map[i][j]);

			row[i][map[i][j]] = true;
			column[j][map[i][j]] = true;

			if (map[i][j] == 0)
			{
				zero.push_back({ i,j });
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

	BackTracking(0);

	return 0;
}
