/*

#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

bool visit[2][1001][1001] = { false, }; // visit[0]~ : 벽 안 부셨을 때, visit[1]~ : 벽 부셨을 때

int map[1001][1001] = { 0, };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

queue<pair<pair<int, int>, int > > q;

int BFS()
{
	int ret = 1;

	visit[0][1][1] = true; // 벽을 안 부순 상태에서 (1, 1) 방문 처리

	q.push({ {1, 1}, 0 }); // 처음 (1, 1) 상태에서는 벽을 안 부순 상태

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int r = q.front().first.first;
			int c = q.front().first.second;
			int current = q.front().second;

			q.pop();

			if (r == N && c == M)
			{
				return ret;
			}

			for (int i = 0; i < 4; i++)
			{
				int y = r + dy[i];
				int x = c + dx[i];

				if (1 <= y && y <= N && 1 <= x && x <= M && !visit[current][y][x])
				{
					if (current == 0) // 벽을 안 부수었을 때, 그 다음의 벽을 부술 수도 있고, 안 부술 수도 있다.
					{
						if (map[y][x] == 0) // 그냥 길이면 그대로 간다.
						{
							visit[current][y][x] = true;
							q.push({ {y, x}, current });
						}
						else if (map[y][x] == 1) // 벽이면 부순다.
						{
							visit[current + 1][y][x] = true;
							q.push({ { y, x }, current + 1 });
						}
					}
					else if (current == 1) // 벽을 부수었을 때는, 그 다음의 모든 벽들을 부수지 못 한다.
					{
						if (map[y][x] == 0) // 그냥 길이면 그대로 간다.
						{
							visit[current][y][x] = true;
							q.push({ { y, x }, current });
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
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	cout << BFS() << '\n';

	return 0;
}


*/


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
