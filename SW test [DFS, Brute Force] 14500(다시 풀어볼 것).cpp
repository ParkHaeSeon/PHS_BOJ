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
		// �� y, x, r, c ���� ���� �� �� ��!

		int y = r + dy[i];
		int x = c + dx[i];

		if (y < 0 || x < 0 || y >= N || x >= M || visit[y][x] == 1) continue;

		visit[y][x] = 1; // ���� DFS�� ������ ���� �湮 ǥ�ø� �ؾ��Ѵ�.

		MAX = max(MAX, paper[r][c] + DFS(y, x, Cnt + 1));

		visit[y][x] = -1; 
		// ������ 4ĭ�� ����� �Ϸ�ȴٸ�(1 X 1 ĭ 4���� ���� ��), �湮 ǥ�ø� '-1'�� �ٲ�����Ѵ�. For ���� ����.
	}

	return MAX; // MAX ���� return ������ϴµ� �Ǽ��� �� �ߴ�.
}

int DFS_exception(int r, int c) // �� shape
{
	int m = 0;

	// ��
	if (r - 1 >= 0 && c - 1 >= 0 && c + 1 < M)
	{
		m = max(m, paper[r][c] + paper[r][c + 1] + paper[r][c - 1] + paper[r - 1][c]);
	}

	// ��
	if (r + 1 < N && r - 1 >= 0 && c + 1 < M)
	{
		m = max(m, paper[r - 1][c] + paper[r][c] + paper[r + 1][c] + paper[r][c + 1]);
	}

	// ��
	if (r + 1 < N && c + 1 < M && c - 1 >= 0)
	{
		m = max(m, paper[r][c] + paper[r + 1][c] + paper[r][c + 1] + paper[r][c - 1]);
	}

	// ��
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
		for (int j = 0; j < M; j++) // ��Ÿ����. N�� �ƴ϶� M�̴�.
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