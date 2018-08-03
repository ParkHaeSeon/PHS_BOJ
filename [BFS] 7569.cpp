#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int tomato[102][102][102] = { 0, };
int visit[102][102][102] = { 0, };

int dy[6] = { -1, 0, 1, 0, 0, 0 };
int dx[6] = { 0, -1, 0, 1, 0 ,0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int M = 0, N = 0, h = 0;

queue < pair<pair<int, int>, int> > q;

int BFS()
{
	int day = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int r = q.front().first.first;
			int c = q.front().first.second;
			int h2 = q.front().second;

			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int R = r + dy[i];
				int C = c + dx[i];
				int H = h2 + dz[i];

				if (R < 0 || R >= N || C < 0 || C >= M || H < 0 || H >= h || tomato[R][C][H] == -1 || tomato[R][C][H] == 1 || visit[R][C][H] == 1) continue;
															
				visit[R][C][H] = 1;

				tomato[R][C][H] = 1;

				q.push(make_pair(make_pair(R, C), H));
			}
			
		}

		++day;
	}

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (tomato[i][j][k] == 0) day = 0;
			}
		}
	}

	return day;
}

int main(void)
{
	memset(visit, -1, sizeof(visit));

	scanf("%d %d %d", &M, &N, &h);

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &tomato[i][j][k]);

				if (tomato[i][j][k] == 1)
				{
					q.push(make_pair(make_pair(i, j), k));
				}
			}
		}
	}

	printf("%d\n", BFS()-1);

	return 0;
}