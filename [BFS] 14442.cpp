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

				if (sit == 0) // ���� �� �μ��� ���
				{
					if (map[ny][nx] == 0 && !visit[ny][nx][sit]) // ���̸� �׳� �̵�
					{
						q.push({ { ny, nx }, sit});
						visit[ny][nx][sit] = true;
					}
					else if (map[ny][nx] == 1 && !visit[ny][nx][sit+1]) // ���� �ν��� �ʾҴµ�, �� ���� ��ġ�� ���� ���
					{
						q.push({ { ny, nx }, sit + 1 });
						visit[ny][nx][sit+1] = true;
					}
				}
				else // ���� �μ��� ���
				{
					if (map[ny][nx] == 0 && !visit[ny][nx][sit]) // ���̸� �׳� �̵�
					{
						q.push({ { ny, nx }, sit });
						visit[ny][nx][sit] = true;
					}
					else if (map[ny][nx] == 1) // ���� �μ̴µ� �� ���� ���� ������ ���
					{
						if (sit < K) // �־��� K �̸� �� ���� �� �ν� �� ����.
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