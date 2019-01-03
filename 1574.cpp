#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 500

int R = 0, C = 0, N = 0;

int Map[MAX][MAX] = { 0, };

int row[MAX][MAX] = { 0, }; // 이름을 헷갈리면 안 된다.
int col[MAX][MAX] = { 0, }; // 이름을 헷갈리면 안 된다.

int Left[MAX] = { 0, };
int Right[MAX] = { 0, };

bool visit[MAX] = { false, };

vector<int> v[MAX];

bool DFS(int start)
{
	if (visit[start]) return false;

	visit[start] = true;

	for (auto next : v[start])
	{
		if (Right[next] == -1 || DFS(Right[next]))
		{
			Left[start] = next;
			Right[next] = start;

			return true;
		}
	}

	return false;
}

int bm()
{
	fill(Left, Left + MAX, -1);
	fill(Right, Right + MAX, -1);

	int ret = 0;

	// R을 '행'으로 보면 안 된다.
	for (int i = 1; i <= R; i++)
	{
		memset(visit, false, sizeof(visit));

		if (DFS(i)) ++ret;
	}

	return ret;
}

int main(void)
{
	for (int i = 0; i < MAX; i++) for (int j = 0; j < MAX; j++) Map[i][j] = 1;

	scanf("%d %d %d", &R, &C, &N);

	int y = 0, x = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &y, &x);

		Map[y][x] = 0; // 빈 칸에는 룩을 둘 수 없다.
	}

	int cnt = 1;

	// 행 기준 넘버링
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			row[i][j] = cnt;
		}

		++cnt;
	}

	cnt = 1;

	// 열 기준 넘버링
	for (int j = 1; j <= C; j++) // 인덱스 조심
	{
		for (int i = 1; i <= R; i++)
		{
			col[i][j] = cnt;
		}

		++cnt;
	}

	int r = 0, c = 0;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (Map[i][j] == 1)
			{
				v[row[i][j]].push_back(col[i][j]);

				r = max(r, row[i][j]);
				c = max(c, col[i][j]);
			}
		}
	}
	
	// R과 C로 보면 안 된다.
	R = r;
	C = c;

	printf("%d\n", bm());

	return 0;
}