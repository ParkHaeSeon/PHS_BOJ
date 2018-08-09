#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int map[1001][1001] = { 0, };

bool visit[1001][1001][2] = { false, };

int N = 0, M = 0;

queue<pair<pair<int, int>, int> > q;

int BFS()
{
	q.push({ {1, 1}, 0});

	visit[1][1][0] = true;

	int ret = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int sit = q.front().second;

			q.pop();

			if (y == N && x == M)
			{
				return ret;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if (ny <= 0 || ny > N || nx <= 0 || nx > M || visit[ny][nx][sit]) continue;

				if (sit == 1)
				{
					if (map[ny][nx] == 0)
					{
						q.push({ {ny, nx}, 1 });
						visit[ny][nx][1] = 1;
					}
				}
				else if (sit == 0)
				{
					if (map[ny][nx] == 1)
					{
						q.push({ { ny, nx }, 1 });
						visit[ny][nx][1] = 1;
					}
					else if (map[ny][nx] == 0)
					{
						q.push({ { ny, nx }, 0 });
						visit[ny][nx][0] = 1;
					}
				}
			}
		}

		++ret;
	}

	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d\n", BFS());

	return 0;
}
