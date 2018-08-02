// https://www.acmicpc.net/problem/15683

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[8][8] = { 0, };
int cctv_direction[6] = { 0, 4, 2, 4, 4, 1 };

int N = 0; // row y
int M = 0; // column x

int ans = 0;

vector<pair<int, int> > cctv;

void fill_map(int y, int x, int dy, int dx, int add_val)
{
	int ny = y + dy;
	int nx = x + dx;

	while (nx >= 0 && ny >= 0 && nx < M && ny < N && map[ny][nx] != 6)
	{
		if (map[ny][nx] == 0 || map[ny][nx] >= 100)
		{
			map[ny][nx] += add_val;
		}

		ny += dy;
		nx += dx;
	}
}

void makeMap(int y, int x, int number, int direction, int add_val)
{
	if (number == 1)
	{
		if (direction == 0)
		{
			fill_map(y, x, 0, 1, add_val);
		}
		else if (direction == 1)
		{
			fill_map(y, x, 1, 0, add_val);
		}
		else if (direction == 2)
		{
			fill_map(y, x, 0, -1, add_val);
		}
		else if (direction == 3)
		{
			fill_map(y, x, -1, 0, add_val);
		}
	}
	else if (number == 2)
	{
		if (direction == 0)
		{
			fill_map(y, x, 0, -1, add_val);
			fill_map(y, x, 0, 1, add_val);
		}
		else if (direction == 1)
		{
			fill_map(y, x, -1, 0, add_val);
			fill_map(y, x, 1, 0, add_val);
		}
	}
	else if (number == 3)
	{
		if (direction == 0)
		{
			fill_map(y, x, 0, 1, add_val);
			fill_map(y, x, -1, 0, add_val);
		}
		else if (direction == 1)
		{
			fill_map(y, x, 1, 0, add_val);
			fill_map(y, x, 0, -1, add_val);
		}
		else if (direction == 2)
		{
			fill_map(y, x, -1, 0, add_val);
			fill_map(y, x, 0, -1, add_val);
		}
		else if (direction == 3)
		{
			fill_map(y, x, 1, 0, add_val);
			fill_map(y, x, 0, 1, add_val);
		}
	}
	else if (number == 4)
	{
		if (direction == 0)
		{
			fill_map(y, x, -1, 0, add_val);
			fill_map(y, x, 0, 1, add_val);
			fill_map(y, x, 1, 0, add_val);
		}
		else if (direction == 1)
		{
			fill_map(y, x, 0, -1, add_val);
			fill_map(y, x, 1, 0, add_val);
			fill_map(y, x, 0, 1, add_val);
		}
		else if (direction == 2)
		{
			fill_map(y, x, 1, 0, add_val);
			fill_map(y, x, 0, -1, add_val);
			fill_map(y, x, -1, 0, add_val);
		}
		else if (direction == 3)
		{
			fill_map(y, x, 0, -1, add_val);
			fill_map(y, x, -1, 0, add_val);
			fill_map(y, x, 0, 1, add_val);
		}
	}
	else if (number == 5)
	{
		fill_map(y, x, 0, 1, add_val);
		fill_map(y, x, 1, 0, add_val);
		fill_map(y, x, -1, 0, add_val);
		fill_map(y, x, 0, -1, add_val);
	}
}

int getSize()
{
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				++ret;
			}
		}
	}

	return ret;
}

void getMin(int cctv_num)
{
	if (cctv_num == cctv.size())
	{
		int cur_size = getSize();

		if (cur_size < ans)
		{
			ans = cur_size;
		}

		return;
	}

	int y = cctv[cctv_num].first;
	int x = cctv[cctv_num].second;
	int number = map[y][x];

	for (int i = 0; i < cctv_direction[number]; i++)
	{
		makeMap(y, x, number, i, 100);
		getMin(cctv_num + 1);
		makeMap(y, x, number, i, -100);
	}
}

int main() 
{
	ans = 100;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);

			if (1 <= map[i][j] && map[i][j] <= 5)
			{
				cctv.push_back(make_pair(i, j));
			}
		}
	}

	getMin(0);

	printf("%d\n", ans);

	return 0;
}