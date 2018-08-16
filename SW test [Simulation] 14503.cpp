#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

#define North 0
#define East 1
#define South 2
#define West 3
#define Clear 4
#define Wall 5

using namespace std;

int map[53][53] = { 0, };

int dy[4] = { 0,  0, 1, -1 }; // E, W, S, N
int dx[4] = { 1, -1, 0, 0 };  // E, W, S, N

int ry = 0, rx = 0, d = 0; // Roboy position, direction

int N = 0, M = 0;

bool visit[53][53] = { false, };

int zero_count = 0; // answer

int fourVectorChk()
{
	int ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int r = ry + dy[i];
		int c = rx + dx[i];

		if (0 <= r && r < N && 0 <= c && c < M)
		{
			if (map[r][c] == Wall || visit[r][c])
			{
				++ret;
			}
		}
	}

	return ret;
}

bool canMoveLeft(int current)
{
	int y = ry, x = rx;

	if (current == East)
	{
		--y;

		if (0 <= y && !visit[y][x] && map[y][x] != Wall) return true;
		else return false;
	}
	else if (current == West)
	{
		++y;

		if (y < N && !visit[y][x] && map[y][x] != Wall) return true;
		else return false;
	}
	else if (current == South)
	{
		++x;

		if (x < M && !visit[y][x] && map[y][x] != Wall) return true;
		else return false;
	}
	else if (current == North)
	{
		--x;

		if (0 <= x && !visit[y][x] && map[y][x] != Wall) return true;
		else return false;
	}
}

void moveRobot(int current)
{
	int y = 0;
	int x = 0;

	y = ry;
	x = rx;

	if (d == East)
	{
		if (fourVectorChk() >= 4)
		{
			--x;

			if (x < 0 || map[y][x] == Wall)
			{
				printf("%d\n", zero_count);
				exit(0);
			}
			else
			{
				rx = x;

				if (!visit[ry][rx])
				{
					if (map[ry][rx] == 0) ++zero_count;
					visit[ry][rx] = true;
				}
			}
		}
		else
		{
			if (canMoveLeft(d))
			{
				--ry;

				visit[ry][rx] = true;

				if (map[ry][rx] == 0) ++zero_count;

				d = North;
			}
			else
			{
				d = North;
			}
		}

	}
	else if (d == West) // ��
	{
		if (fourVectorChk() >= 4) // �κ��� �ִ� ���� ��ġ���� �����¿� ��� ���̰ų� �湮�ߴ� ���̶��
		{
			++x; // �ڷ� �� ĭ

			if (x >= M || map[y][x] == Wall) // �ٵ� �ڷ� �� ĭ�� ��ġ�� ���̶��
			{
				printf("%d\n", zero_count); // ��
				exit(0);
			}
			else // ���� �ƴ϶��
			{
				rx = x;

				if (!visit[ry][rx]) // �ٵ� ������ �ڰ� û�Ҹ� �� �� ���̶��
				{
					if (map[ry][rx] == 0) ++zero_count;
					visit[ry][rx] = true;
				}
			}
		}
		else // �����¿� �̵��� ���� �ִµ� ������ ���ʺ���.
		{
			if (canMoveLeft(d)) // ���ʿ� �̵��� ������ ���� �ִٸ�
			{
				++ry;

				visit[ry][rx] = true;

				if (map[ry][rx] == 0) ++zero_count;

				d = South;
			}
			else
			{
				d = South;
			}
		}
	}
	else if (d == South) // ��
	{
		if (fourVectorChk() >= 4) // �κ��� �ִ� ���� ��ġ���� �����¿� ��� ���̰ų� �湮�ߴ� ���̶��
		{
			--y; // �ڷ� �� ĭ

			if (y < 0 || map[y][x] == Wall) // �ٵ� �ڷ� �� ĭ�� ��ġ�� ���̶��
			{
				printf("%d\n", zero_count); // ��
				exit(0);
			}
			else // ���� �ƴ϶��
			{
				ry = y;

				if (!visit[ry][rx]) // �ٵ� ������ �ڰ� û�Ҹ� �� �� ���̶��
				{
					if (map[ry][rx] == 0) ++zero_count;
					visit[ry][rx] = true;
				}
			}
		}
		else // �����¿� �̵��� ���� �ִµ� ������ ���ʺ���.
		{
			if (canMoveLeft(d)) // ���ʿ� �̵��� ������ ���� �ִٸ�
			{
				++rx;

				visit[ry][rx] = true;

				if (map[ry][rx] == 0) ++zero_count;

				d = East;
			}
			else
			{
				d = East;
			}
		}
	}
	else if (d == North) // ��
	{

		if (fourVectorChk() >= 4) // �κ��� �ִ� ���� ��ġ���� �����¿� ��� ���̰ų� �湮�ߴ� ���̶��
		{
			++y; // �ڷ� �� ĭ

			if (y >= N || map[y][x] == Wall) // �ٵ� �ڷ� �� ĭ�� ��ġ�� ���̶��
			{
				printf("%d\n", zero_count); // ��
				exit(0);
			}
			else // ���� �ƴ϶��
			{
				ry = y;

				if (!visit[ry][rx]) // �ٵ� ������ �ڰ� û�Ҹ� �� �� ���̶��
				{
					if (map[ry][rx] == 0) ++zero_count;
					visit[ry][rx] = true;
				}
			}
		}
		else // �����¿� �̵��� ���� �ִµ� ������ ���ʺ���.
		{
			if (canMoveLeft(d)) // ���ʿ� �̵��� ������ ���� �ִٸ�
			{
				--rx;

				visit[ry][rx] = true;

				if (map[ry][rx] == 0) ++zero_count;

				d = West;
			}
			else
			{
				d = West;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	scanf("%d %d %d", &ry, &rx, &d);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	visit[ry][rx] = true;

	if (map[ry][rx] == 0) ++zero_count;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
			{
				map[i][j] = Wall;
			}
		}
	}

	while (true)
	{
		if (d == East)
		{
			moveRobot(d);
		}
		else if (d == West)
		{
			moveRobot(d);
		}
		else if (d == South)
		{
			moveRobot(d);
		}
		else if (d == North)
		{
			moveRobot(d);
		}
	}

	return 0;
}