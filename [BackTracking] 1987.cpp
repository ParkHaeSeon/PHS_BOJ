#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int R = 0, C = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

char board[21][21];

bool visit[21][21] = { false, };

bool chk[27] = { false, };

int result = -987654321;

void DFS(int r, int c, int depth)
{
	result = max(result, depth);

	for (int i = 0; i < 4; i++)
	{
		int y = r + dy[i];
		int x = c + dx[i];

		if (y < 0 || y >= R || x < 0 || x >= C || chk[board[y][x]-'A']) continue;

		chk[board[y][x] - 'A'] = true;
		DFS(y, x, depth + 1);
		chk[board[y][x] - 'A'] = false;
	}
}

int main(void)
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	chk[board[0][0] - 'A'] = true;

	DFS(0, 0, 1);

	printf("%d\n", result);

	return 0;
}