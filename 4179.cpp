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

int R = 0, C = 0, jy = 0, jx = 0;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

vector<pair<int, int> > f;

char Map[1001][1001];

queue<pair< pair<int, int>, int > > q;
// 0 = ม๖ศฦ, 1 = บา

bool Fire[1001][1001] = { false, };
bool Jee[1001][1001] = { false, };

int BFS()
{
	// ม๖ศฦ
	q.push({ { jy, jx }, 0 });
	Jee[jy][jx] = true;

	int ret = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int p = q.front().second;

			q.pop();

			if ((x == 0 || x == C - 1 || y == 0 || y == R - 1) && p == 0)
			{
				return ret;
			}

			if (p == 0) // ม๖ศฦ
			{
				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny < 0 || ny >= R || nx < 0 || nx >= C || Jee[ny][nx]) continue;

					if (Map[ny][nx] == '.')
					{
						q.push({ { ny, nx }, 0 });
						Jee[ny][nx] = true;
					}
				}
			}
			else if (p == 1) // บา
			{
				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny < 0 || ny >= R || nx < 0 || nx >= C || Fire[ny][nx]) continue;

					if (Map[ny][nx] == '.')
					{
						q.push({ { ny, nx }, 1 });
						Fire[ny][nx] = true;
						Map[ny][nx] = 'F';
					}
				}
			}

			printf("==============\n");
			for (int i = 0; i < R; i++)
			{
				for(int j=0; j<C; j++)
				{
					cout << Map[i][j];
				}
				printf("\n");
			}
		}

		++ret;
	}

	return -1;
}

int main(void)
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 'J')
			{
				jy = i;
				jx = j;
				Map[i][j] = '.';
			}
			else if (Map[i][j] == 'F')
			{
				q.push({ { i, j }, 1 }); // บา
				Fire[i][j] = true;
			}
		}
	}

	int r = BFS();

	if (r != -1) printf("%d\n", r);
	else printf("IMPOSSIBLE\n");

	return 0;
}