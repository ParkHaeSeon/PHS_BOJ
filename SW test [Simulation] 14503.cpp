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
	else if (d == West) // 서
	{
		if (fourVectorChk() >= 4) // 로봇이 있는 현재 위치에서 상하좌우 모두 벽이거나 방문했던 곳이라면
		{
			++x; // 뒤로 한 칸

			if (x >= M || map[y][x] == Wall) // 근데 뒤로 한 칸한 위치도 벽이라면
			{
				printf("%d\n", zero_count); // 끝
				exit(0);
			}
			else // 벽이 아니라면
			{
				rx = x;

				if (!visit[ry][rx]) // 근데 후진한 뒤가 청소를 안 한 곳이라면
				{
					if (map[ry][rx] == 0) ++zero_count;
					visit[ry][rx] = true;
				}
			}
		}
		else // 상하좌우 이동할 곳이 있는데 무조건 왼쪽부터.
		{
			if (canMoveLeft(d)) // 왼쪽에 이동한 가능한 곳이 있다면
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
	else if (d == South) // 남
	{
		if (fourVectorChk() >= 4) // 로봇이 있는 현재 위치에서 상하좌우 모두 벽이거나 방문했던 곳이라면
		{
			--y; // 뒤로 한 칸

			if (y < 0 || map[y][x] == Wall) // 근데 뒤로 한 칸한 위치도 벽이라면
			{
				printf("%d\n", zero_count); // 끝
				exit(0);
			}
			else // 벽이 아니라면
			{
				ry = y;

				if (!visit[ry][rx]) // 근데 후진한 뒤가 청소를 안 한 곳이라면
				{
					if (map[ry][rx] == 0) ++zero_count;
					visit[ry][rx] = true;
				}
			}
		}
		else // 상하좌우 이동할 곳이 있는데 무조건 왼쪽부터.
		{
			if (canMoveLeft(d)) // 왼쪽에 이동한 가능한 곳이 있다면
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
	else if (d == North) // 북
	{

		if (fourVectorChk() >= 4) // 로봇이 있는 현재 위치에서 상하좌우 모두 벽이거나 방문했던 곳이라면
		{
			++y; // 뒤로 한 칸

			if (y >= N || map[y][x] == Wall) // 근데 뒤로 한 칸한 위치도 벽이라면
			{
				printf("%d\n", zero_count); // 끝
				exit(0);
			}
			else // 벽이 아니라면
			{
				ry = y;

				if (!visit[ry][rx]) // 근데 후진한 뒤가 청소를 안 한 곳이라면
				{
					if (map[ry][rx] == 0) ++zero_count;
					visit[ry][rx] = true;
				}
			}
		}
		else // 상하좌우 이동할 곳이 있는데 무조건 왼쪽부터.
		{
			if (canMoveLeft(d)) // 왼쪽에 이동한 가능한 곳이 있다면
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