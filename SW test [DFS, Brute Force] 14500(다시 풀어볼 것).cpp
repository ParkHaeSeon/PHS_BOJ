#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N = 0;
int M = 0;

int paper[501][501] = { 0, };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int visit[501][501] = { 0, };

int DFS(int r, int c, int Cnt)
{
	if (Cnt == 4)
	{
		return paper[r][c];
	}

	int MAX = 0;

	for (int i = 0; i < 4; i++)
	{
		// ★ y, x, r, c 변수 구분 잘 할 것!

		int y = r + dy[i];
		int x = c + dx[i];

		if (y < 0 || x < 0 || y >= N || x >= M || visit[y][x] == 1) continue;

		visit[y][x] = 1; // 다음 DFS를 진행할 때는 방문 표시를 해야한다.

		MAX = max(MAX, paper[r][c] + DFS(y, x, Cnt + 1));

		visit[y][x] = -1; 
		// 하지만 4칸의 계산이 완료된다면(1 X 1 칸 4개를 더한 것), 방문 표시를 '-1'로 바꿔줘야한다. For 다음 진행.
	}

	return MAX; // MAX 값을 return 해줘야하는데 실수로 안 했다.
}

int DFS_exception(int r, int c) // ㅗ shape
{
	int m = 0;

	// ㅗ
	if (r - 1 >= 0 && c - 1 >= 0 && c + 1 < M)
	{
		m = max(m, paper[r][c] + paper[r][c + 1] + paper[r][c - 1] + paper[r - 1][c]);
	}

	// ㅏ
	if (r + 1 < N && r - 1 >= 0 && c + 1 < M)
	{
		m = max(m, paper[r - 1][c] + paper[r][c] + paper[r + 1][c] + paper[r][c + 1]);
	}

	// ㅜ
	if (r + 1 < N && c + 1 < M && c - 1 >= 0)
	{
		m = max(m, paper[r][c] + paper[r + 1][c] + paper[r][c + 1] + paper[r][c - 1]);
	}

	// ㅓ
	if (r + 1 < N && r - 1 >= 0 && c - 1 >= 0)
	{
		m = max(m, paper[r][c - 1] + paper[r][c] + paper[r - 1][c] + paper[r + 1][c]);
	}

	return m;
}

int main(void)
{
	int result = 0;

	memset(visit, -1, sizeof(visit));

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) // 오타주의. N이 아니라 M이다.
		{
			if (visit[i][j] == -1)
			{
				visit[i][j] = 1;
				result = max(result, DFS(i, j, 1));
				result = max(result, DFS_exception(i, j));
				visit[i][j] = -1;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}