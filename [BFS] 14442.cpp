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

bool visit[1001][1001][11] = { false, };

int N = 0, M = 0, K = 0;

queue<pair<pair<int, int>, int> > q;
// {y, x}, K}

int BFS()
{
	q.push({ {1, 1}, 0 });

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
				
				if (ny <= 0 || ny > N || nx <= 0 || nx > M) continue;

				if (sit == 0) // 벽을 안 부셨을 경우
				{
					if (map[ny][nx] == 0 && !visit[ny][nx][sit]) // 길이면 그냥 이동
					{
						q.push({ { ny, nx }, sit});
						visit[ny][nx][sit] = true;
					}
					else if (map[ny][nx] == 1 && !visit[ny][nx][sit+1]) // 벽을 부시지 않았는데, 그 다음 위치가 벽인 경우
					{
						q.push({ { ny, nx }, sit + 1 });
						visit[ny][nx][sit+1] = true;
					}
				}
				else // 벽을 부셨을 경우
				{
					if (map[ny][nx] == 0 && !visit[ny][nx][sit]) // 길이면 그냥 이동
					{
						q.push({ { ny, nx }, sit });
						visit[ny][nx][sit] = true;
					}
					else if (map[ny][nx] == 1) // 벽을 부셨는데 그 다음 벽을 만나는 경우
					{
						if (sit < K) // 주어진 K 미만 일 때만 더 부실 수 있음.
						{
							if (!visit[ny][nx][sit + 1])
							{
								q.push({ { ny, nx }, sit + 1 });
								visit[ny][nx][sit + 1] = true;
							}
						}
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
	scanf("%d %d %d", &N, &M, &K);

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