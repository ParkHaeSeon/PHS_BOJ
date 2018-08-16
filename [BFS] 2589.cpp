#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

bool visit[51][51] = { false, };

char map[51][51];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N = 0, M = 0;

queue<pair<int, int> > position;

int result = -987654321;

void init()
{
	memset(visit, false, sizeof(visit));
}

int BFS()
{
	queue<pair<int, int> > q;

	int dist[51][51] = { 0, };

	memset(dist, -1, sizeof(dist));

	q.push({position.front()});

	position.pop();

	visit[q.front().first][q.front().second] = true;

	int ret = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int r = q.front().first;
			int c = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int y = r + dy[i];
				int x = c + dx[i];

				if (y < 0 || y >= N || x < 0 || x >= M || dist[y][x] > -1 || map[y][x] == 'W') continue;

				dist[y][x] = dist[r][c] + 1;

				q.push({ y,x });
			}
			
		}
	}

	int m = -987654321;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			m = max(m, dist[i][j] + 1);
		}
	}

	return m;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'L')
			{
				position.push({ i,j });
			}
		}
	}

	int pSize = position.size();

	while (pSize--)
	{
		result = max(result, BFS());
	}

	printf("%d\n", result);
	
	return 0;
}