// 

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int M = 0;
int py = 0, px = 0;
int visit[51][51][1 << 7] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

char map[51][51];

queue<pair<pair<int, int>, int> >q;

bool rangeBool(int y, int x)
{
	return 0 < y && y <= N && 0 < x && x <= M;
}

int BFS()
{
	int cnt = 0;

	q.push(make_pair(make_pair(py, px), 0));

	visit[py][px][0] = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int z = q.front().second;

			q.pop();

			if (map[y][x] == '1')
			{
				return cnt;
			}

			for (int j = 0; j < 4; j++)
			{
				int Y = y + dy[j];
				int X = x + dx[j];

				if (!rangeBool(Y, X) || map[Y][X] == '#') continue;

				if ('a' <= map[Y][X] && map[Y][X] <= 'f')
				{
					int Z = z | (1 << (map[Y][X] - 'a'));

					if (visit[Y][X][Z] == 1) continue;

					visit[Y][X][Z] = 1;
					q.push(make_pair(make_pair(Y, X), Z));
				}
				else if ('A' <= map[Y][X] && map[Y][X] <= 'Z' && visit[Y][X][z] == 0)
				{
					if (z & (1 << map[Y][X] - 'A') )
					{
						visit[Y][X][z] = 1;
						q.push(make_pair(make_pair(Y, X), z));
					}
				}
				else if (visit[Y][X][z] == 0)
				{
					visit[Y][X][z] = 1;
					q.push(make_pair(make_pair(Y, X), z));
				}
			}
		}

		++cnt;
	}

	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		getchar();

		for (int j = 1; j <= M; j++)
		{
			scanf("%c", &map[i][j]);

			if (map[i][j] == '0')
			{
				py = i;
				px = j;
			}
		}
	}

	printf("%d\n", BFS());

	return 0;
}
