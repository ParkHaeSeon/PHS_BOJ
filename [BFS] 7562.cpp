#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int T = 0; // 테스트 케이스

int l = 0; // 한 변의 길이

int BFS(int sy, int sx, int ey, int ex)
{
	queue<pair<int, int> > q;

	bool visit[301][301] = { false, };

	int ret = 0;

	q.push({ sy, sx });

	visit[sy][sx] = true;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int y = q.front().first;
			int x = q.front().second;

			q.pop();

			if (y == ey && x == ex)
			{
				return ret;
			}

			if (x - 1 >= 0 && y - 2 >= 0 && !visit[y - 2][x - 1])
			{
				q.push({ y - 2, x - 1 });
				visit[y - 2][x - 1] = true;
			}

			if (x - 2 >= 0 && y - 1 >= 0 && !visit[y - 1][x - 2])
			{
				q.push({ y - 1, x - 2 });
				visit[y - 1][x - 2] = true;
			}

			if (x - 2 >= 0 && y + 1 < l && !visit[y + 1][x - 2])
			{
				q.push({ y + 1, x - 2 });
				visit[y + 1][x - 2] = true;
			}

			if (x - 1 >= 0 && y + 2 < l && !visit[y + 2][x - 1])
			{
				q.push({ y + 2, x - 1 });
				visit[y + 2][x - 1] = true;
			}

			if (x + 1 < l && y + 2 < l && !visit[y + 2][x + 1])
			{
				q.push({ y + 2, x + 1 });
				visit[y + 2][x + 1] = true;
			}

			if (x + 2 < l && y + 1 < l && !visit[y + 1][x + 2])
			{
				q.push({ y + 1, x + 2 });
				visit[y + 1][x + 2] = true;
			}

			if (x + 2 < l && y - 1 >= 0 && !visit[y - 1][x + 2])
			{
				q.push({ y - 1, x + 2 });
				visit[y - 1][x + 2] = true;
			}

			if (x + 1 < l && y - 2 >= 0 && !visit[y - 2][x + 1])
			{
				q.push({ y - 2, x + 1 });
				visit[y - 2][x + 1] = true;
			}
		}

		++ret;
	}
}

int main(void)
{
	int start[2] = { 0, }; // [0] : y(행), [1] : x(열)

	int end[2] = { 0, }; // 나이트가 이동하려는 칸(도착지)

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &l);

		scanf("%d %d", &start[0], &start[1]);

		scanf("%d %d", &end[0], &end[1]);

		printf("%d\n", BFS(start[0], start[1], end[0], end[1]));
	}

	return 0;
}
